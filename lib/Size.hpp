#pragma once

struct Size{
    int rows, columns;

    Size();
    Size(int rows, int columns);

    friend bool operator==(Size &left, Size &right);
};