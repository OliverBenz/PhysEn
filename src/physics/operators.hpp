#pragma once

#include "maths/matrix.hpp"

#include <numbers>

namespace phys {

constexpr double inv_sqrt2 = 1 / std::numbers::sqrt2;


//! Pauli X gate in z-basis.
constexpr matrix<2, 2> X() {
    return {{0, 1}, {1, 0}};
};

// TODO: std::complex matrix has to be possible.
// TODO: pauliY

//! Pauli Z gate in z-basis.
constexpr matrix<2, 2> Z() {
    return {{1, 0}, {0, -1}};
};

//! Hadamard gate in z-basis.
constexpr matrix<2,2> H() {
    return inv_sqrt2 * {{1, 1}, {1, -1}};
}

//! Controlled NOT gate in z-basis. First qubit is control qubit.
constexpr matrix<4, 4> CNOT() {
    return {{1,0,0,0}, {0,1,0,0}, {0,0,0,1}, {0,0,1,0}};
}

//! Controlled Pauli X gate (CNOT) in z-basis. First qubit is control qubit.
constexpr matrix<4, 4> CX() {
    return CNOT();
}

//! Controlled Pauli Z gate in z-basis. First qubit is control qubit.
constexpr matrix<4, 4> CZ() {
    return {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,-1}};
}

//! Swap gate for two qubits in z-basis.
constexpr matrix<4, 4> SWAP() {
    return {{1,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,0,0,1}};
}

}
