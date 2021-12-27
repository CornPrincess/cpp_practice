//
// Created by 周天斌 on 2021/12/27.
//

#ifndef CPP_PRACTICE_STACKTP_H
#define CPP_PRACTICE_STACKTP_H
template <typename Type>
class Stack {
private:
    enum {MAX=10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type & item);
    bool pop(Type & item);
};

template <typename Type>
Stack<Type>::Stack() {
    top = 0;
}

template <typename Type>
bool Stack<Type>::isempty() {
    return top == 0;
}

template <typename Type>
bool Stack<Type>::isfull() {
    return top == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else{
        return false;
    }
}

template <typename Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}

#endif //CPP_PRACTICE_STACKTP_H
