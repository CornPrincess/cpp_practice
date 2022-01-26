//
// Created by 周天斌 on 2021/12/21.
// interface for a queue
#include <iostream>

#ifndef CPP_PRACTICE_QUEUE_H
#define CPP_PRACTICE_QUEUE_H

// This queue will contain Customer items
class Customer {
private:
    long arrive;
    int processtime;
public:
    Customer() {
        arrive = processtime = 0;
        std::cout << "Customer default constructor" << std::endl;
    }

    void set(long when);

    long when() const { return arrive; }

    int ptime() const { return processtime; }

    friend std::ostream & operator<<(std:: ostream &, const Customer &);
};


typedef Customer Item;

class Queue {
private:
    struct Node {
        Item item;
        struct Node * next;
    };
    enum {Q_SIZE=10};
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) {return *this;}

public:
    Queue(int qs=Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item &item);
};
#endif //CPP_PRACTICE_QUEUE_H
