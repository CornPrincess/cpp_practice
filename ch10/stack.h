//
// Created by 周天斌 on 2021/12/9.
//

#ifndef CPP_PRACTICE_STACK_H
#define CPP_PRACTICE_STACK_H

typedef unsigned long Item;

class Stack {
private:
    // const int MAX = 10; fail
    // static const int MAX = 10; OK
    enum {
        MAX = 10
    };
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
};

#endif //CPP_PRACTICE_STACK_H
