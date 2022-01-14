#pragma once

#include "Type.hpp"

#include <string>

namespace PhysEn {

struct Token {
    Type type;
    std::string value;

    Token(Type t, std::string s) : type(t), value(std::move(s))
    {};
};

}