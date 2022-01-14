#pragma once

namespace PhysEn {

enum class Type {
    None = 0, // No selection
    Invalid,  // Invalid Input
    Number,
    Variable,

    Mul,
    Div,
    Add,
    Sub
};

char TypeToChar(const Type t);

}