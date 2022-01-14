#pragma once

#include "Tree.hpp"
#include "Token.hpp"

#include <vector>

namespace PhysEn {

class Parser {
    //! Resulting parsed tree
    Tree result;

public:
    bool Parse(const std::vector<Token>& tokens);
};

}