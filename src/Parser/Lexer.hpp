#pragma once

#include "Token.hpp"

#include <string>
#include <vector>

namespace PhysEn {

class Lexer {
    //! Resulting tokens after lexing.
    std::vector<Token> tokens;

public:
    bool Lex(const std::string& input);
};

}