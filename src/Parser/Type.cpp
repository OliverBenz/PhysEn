#include "Type.hpp"

namespace PhysEn {

char TypeToChar(const Type t) {
    switch(t){
        case Type::None: return '-';
        case Type::Invalid: return 'i';
        case Type::Number: return 'N';
        case Type::Variable: return 'V';
        case Type::Mul: return '*';
        case Type::Div: return '/';
        case Type::Add: return '+';
        case Type::Sub: return '-';
        default: return ' ';
    }
}

}