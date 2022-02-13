#include "Tree.hpp"

namespace PhysEn {

// Constructors
Tree::Tree(const Type t, const std::string& str) : token({t,str})
{}
Tree::Tree(Type t) : token({t, ""})
{}

// Member functions
void Tree::AddChild(Type t, std::string& val) {
    children.emplace_back(Tree({t, val}));
}

void Tree::AddChild(Type t) {
    children.emplace_back(Tree({t, ""}));
}

Type Tree::Last() {
    return children.back().token.type;
}

// Friend functions
std::ostream& operator<<(std::ostream& os, const Tree& tree) {
    for (const Tree& t : tree.children)
        os << TypeToChar(t.token.type) << ": " << t.token.value << '\n';

    return os << '\n';
}

}