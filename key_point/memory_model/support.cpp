//
// Created by 周天斌 on 2022/1/26.
//

#include <iostream>
// using warming from another file
extern double warming;

// function prototypes, optional
void update(double dt);
void local();

using std::cout;

// modified global variable
void update(double dt) {
    // optional redeclaration
    extern double warming;
    // uses global warming
    warming += dt;
    cout << "support Updating global warming to " << warming << " degrees.\n";
}

// use local variable
void local() {
    double warming = 0.8;   // new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
    // core Access global variable with the scope resolution operator
    cout << "But global warming = " << ::warming << " degrees.\n";
}