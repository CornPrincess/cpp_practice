//
// Created by 周天斌 on 2021/12/6.
// compile with external

#include <iostream>

// use warming from another file
extern double warming;

// function prototypes, optional
void update(double dt);

void local();

using std::cout;

// modified global variable
void update(double dt) {
    extern double warming;  // optional redeclaration
    warming += dt;          // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

// use local variable
void local() {
    double warming = 0.8;   // new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
    // Access global variable with the
    // scope resolution operator
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}