#pragma once

#include "Token.hpp"

#include <vector>
#include <iostream>

namespace PhysEn {

class Tree {
    Token token;
    std::vector<Tree> children;

    friend std::ostream& operator <<(std::ostream& os, const Tree& tree);

public:
    explicit Tree(Type t);
    Tree(const Type t, const std::string& str);

    //! Add a child token with specific type and value.
    void AddChild(Type t, std::string& val);

    //! Add a child token with specific type and no value.
    void AddChild(Type t);

    //! Return the type of the last child token.
    Type Last();
};

std::ostream& operator<<(std::ostream& os, const Tree& tree);

}