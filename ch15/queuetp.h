//
// Created by 周天斌 on 2022/1/4.
//

#ifndef CPP_PRACTICE_QUEUETP_H
#define CPP_PRACTICE_QUEUETP_H

template<typename Item>
class QueueTP {
private:
    enum {
        Q_SIZE = 10
    };

    // Node is a nested class definition
    class Node {
    public:
        Item item;
        Node *next;

        Node(const Item &i) : item(i), next(0) {}
    };

    Node *front;
    Node *rear;
    int items;
    const int qsize;

    QueueTP(const QueueTP &q) : qsize(0) {}

    QueueTP &operator=(const QueueTP &q) { return *this; }

public:
    QueueTP(int qs = Q_SIZE);

    ~QueueTP();

    bool isempty() const {
        return items == 0;
    }

    bool isfull() const {
        return items == qsize;
    }

    int queuecount() const {
        return items;
    }

    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item &item);       // remove item from front
};

// QueueTP methods
template<class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs) {
    front = rear = 0;
    items = 0;
}

template<class Item>
QueueTP<Item>::~QueueTP() {
    Node *temp;
    while (front != 0)      // while queue is not yet empty
    {
        temp = front;       // save address of front item
        front = front->next;// reset pointer to next item
        delete temp;        // delete former front
    }
}

// Add item to queue
template<class Item>
bool QueueTP<Item>::enqueue(const Item &item) {
    if (isfull())
        return false;
    Node *add = new Node(item);
// on failure, new throws std::bad_alloc exception
    items++;
    if (front == 0)         // if queue is empty
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear
    rear = add;             // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
template<class Item>
bool QueueTP<Item>::dequeue(Item &item) {
    if (front == 0)
        return false;
    item = front->item;     // set item to first item in queue
    items--;
    Node *temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item
    if (items == 0)
        rear = 0;
    return true;
}

#endif //CPP_PRACTICE_QUEUETP_H
