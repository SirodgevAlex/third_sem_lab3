#include <iostream>
#include "Graph.h"
#include "assert.h"
#include "GraphFunctions.h"
#include <termcolor/termcolor.hpp>

#pragma once

using namespace std;

class Color {
private:
    int ColorNumber = 0;
public:
    Color() {

    }

    int GetColorNumber() {
        return this->ColorNumber;
    }

    void SetColorNumber(int ColorNumber) {
        this->ColorNumber = ColorNumber;
    }
};

ostream &operator<<(ostream &out, Color color) {
    if (color.GetColorNumber() == 0) out << termcolor::grey << "GREY(0)" << termcolor::reset;
    else if (color.GetColorNumber() == 1) out << termcolor::red << "RED(1)" << termcolor::reset;
    else if (color.GetColorNumber() == 2) out << termcolor::green << "GREEN(2)" << termcolor::reset;
    else if (color.GetColorNumber() == 3) out << termcolor::yellow << "YELLOW(3)" << termcolor::reset;
    else if (color.GetColorNumber() == 4) out << termcolor::blue << "BLUE(4)" << termcolor::reset;
    else if (color.GetColorNumber() == 5) out << termcolor::magenta << "MAGENTA(5)" << termcolor::reset;
    else if (color.GetColorNumber() == 6) out << termcolor::cyan << "CYAN(6)" << termcolor::reset;
    else if (color.GetColorNumber() == 7) out << termcolor::white << "WHITE(7)" << termcolor::reset;
    else out << color.GetColorNumber();
    return out;
};

class Colors {
private:
    vector<Color> colors;
public:
    Colors() {

    }

    Colors(int Length) {
        colors.resize(Length);
    }

    Colors(int Length, int value) {
        colors.resize(Length);
        for (int i = 0; i < Length; i++) {
            this->colors[i].SetColorNumber(value);
        }
    }

    Color Get(int index) {
        return this->colors[index];
    }

    int GetLength() {
        return this->colors.size();
    }

    int operator[](int index) {
        return Get(index).GetColorNumber();
    }

    void SetColorNumber(int NumberOfElement, int NumberOfColor) {
        this->colors[NumberOfElement].SetColorNumber(NumberOfColor);
    }
};



ostream &operator<<(ostream &out, Colors colors) {
    for (int i = 0; i < colors.GetLength(); i++) {
        out << "Vertex number " << i + 1 << ' ' << "has color number " << colors.Get(i) << '\n';
    }
    return out;
}


