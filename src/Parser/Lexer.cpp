#include "Lexer.hpp"

#include "LexMessages.hpp"

//#include <fmt/core.h>

namespace PhysEn {

namespace Utf {
constexpr inline bool isNumber(const char c) noexcept {
    constexpr char NUM_ZERO = 0x30;
    constexpr char NUM_NINE = 0x39;

    return c >= NUM_ZERO && c <= NUM_NINE;
}

constexpr inline bool isLetter(const char c) noexcept {
    constexpr char LETTER_A = 0x61;     // Lowercase A
    constexpr char LETTER_Z = 0x7a;     // Lowercase Z
    constexpr char LETTER_OFFSET = 32;  // Distance between capital and lowercase letters in UTF-8.

    return (c >= LETTER_A && c <= LETTER_Z) ||
            (c >= LETTER_A - LETTER_OFFSET && c <= LETTER_Z - LETTER_OFFSET);
}
}

bool Lexer::Lex(const std::string& input) {
    // Constants
    constexpr char SPACE = 0x20;
    constexpr char DOT = 0x2e;

    constexpr char OP_MUL = 0x2a;
    constexpr char OP_ADD = 0x2b;
    constexpr char OP_SUB = 0x2d;
    constexpr char OP_DIV = 0x2f;

    Type currentType = Type::None;
    std::string currentValue;

    //! Add the current value to tree is not Type::None and reset type.
    auto AddCurrentToTree = [&](){
        if(currentType != Type::None) {
            tokens.emplace_back(Token(currentType, currentValue));
            
            currentType = Type::None;
            currentValue = "";
        }
    };

    // Lex loop
    for(const char c : input) {
        // Check Number
        if(Utf::isNumber(c)) {
            if(currentType == Type::Number) {
                currentValue += c;
            } else {
                if(currentType != Type::None)
                    tokens.emplace_back(Token(currentType, currentValue));

                currentType = Type::Number;
                currentValue = std::string(1, c);
            }

            continue;
        }

        // Check decimal point
        if(c == DOT) {
            if(currentType == Type::Number){
                currentValue += c;
            } else {
                //fmt::print(LEX_ERROR_POSITION, 2, '.');
                return false;
            }

            continue;
        }

        // Check Variable
        if(Utf::isLetter(c)) {
                // Add current value
                if(currentType != Type::None) 
                    tokens.emplace_back(Token(currentType, currentValue));

                // Add implicit multiply symbol if no operator before
                if(currentType == Type::Variable || currentType == Type::Number)
                    tokens.emplace_back(Token(Type::Mul, std::string()));

                currentType = Type::Variable;
                currentValue = std::string(1, c);

            continue;
        }

        // Check operators / brackets
        switch(c) {
            case OP_ADD:
                AddCurrentToTree();
                tokens.emplace_back(Token(Type::Add, std::string()));
                break;

            case OP_SUB:
                AddCurrentToTree();

                // Support negative numbers
                if (tokens.back().type == Type::Mul || tokens.back().type == Type::Div || tokens.back().type == Type::Add) {
                    currentType = Type::Number;
                    currentValue = "-";
                } else {
                    tokens.emplace_back(Token(Type::Sub, std::string()));
                }
                break;
            
            case OP_MUL:
                AddCurrentToTree();
                tokens.emplace_back(Token(Type::Mul, std::string()));
                break;
            
            case OP_DIV:
                AddCurrentToTree();
                tokens.emplace_back(Token(Type::Div, std::string()));
                break;
            
            // TODO: Handle brackets

            // Ignore whitespace
            case SPACE:
                break;
    
            default:
                //fmt::print(LEX_ERROR_SYMBOL, c);
                return false;
                break;
        }
        // Nothing after switch statement!
    }

    // Finish remaining work
    if(currentType != Type::None)
        AddCurrentToTree();

    //for(const auto& t : tokens)
        //fmt::print("{} - {}\n", static_cast<int>(t.type), t.value);

    return true;
}

}