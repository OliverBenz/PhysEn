#include <gtest/gtest.h>

#include "Parser/Lexer.hpp"

namespace PhysEn::GTest {

TEST(Lexer, ValidInput) {
    const std::string input = "8324.234975ab / -3.98c * 4.77 + 244x";
    Lexer lexer;

    EXPECT_TRUE(lexer.Lex(input));
}

TEST(Lexer, InvalidInput) {
    // Unknown symbol in string.
    const std::string input = "8324.234975ab /` -3.98c * 4.77 + 244x";
    Lexer lexer;

    EXPECT_FALSE(lexer.Lex(input));
}

}