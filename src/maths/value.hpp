#pragma once

#include <complex>

template <typename T>
class value;

template <>
class value<double> {
    double m_value;

public:
    constexpr value(double val) : m_value(val) {};

    constexpr void operator=(const double val) {
        m_value = val;
    }
    friend constexpr value operator+(const value& val1, const value& val2) {
        return val1.m_value + val2.m_value;
    }
    constexpr operator double() const {
        return m_value;
    }
    constexpr operator double&() {
        return m_value;
    }
};

template <>
class value<float> {
    float m_value;

public:
    constexpr value(float val) : m_value(val) {};

    constexpr void operator=(const float val) {
        m_value = val;
    }
    friend constexpr value operator+(const value& val1, const value& val2) {
        return val1.m_value + val2.m_value;
    }
    constexpr operator float() const {
        return m_value;
    }
};

template<typename T>
class value<std::complex<T>> {
    std::complex<T> m_value;

public:
    constexpr value(std::complex<T> val) : m_value(val) {};

    constexpr void operator=(const std::complex<T> val) {
        m_value = val;
    }
    friend constexpr value operator+(const value& val1, const value& val2) {
        return val1.m_value + val2.m_value;
    }
    constexpr operator std::complex<T>() const {
        return m_value;
    }
};

