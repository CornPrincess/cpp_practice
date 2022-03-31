//
// Created by 周天斌 on 2022/2/17.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        dum = new ListNode();
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode *curr = dum;
        // d 0 1 2 3    2
        //     c
        for (int i = 0; i <= index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        ListNode *temp = dum->next;
        dum->next = node;
        node->next = temp;
        size++;
    }

    void addAtTail(int val) {
        ListNode *curr = dum;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        ListNode *node = new ListNode(val);
        curr->next = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) {
            addAtHead(val);
        } else if (index >= size) {
            addAtTail(val);
        } else {
            // d 0 1 2
            //   c
            ListNode *curr = dum;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            ListNode *temp = curr->next;
            ListNode *node = new ListNode(val);
            curr->next = node;
            node->next = temp;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        ListNode *curr = dum;
        // d 0 1 2 3 4    2
        //       c
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        ListNode * to_delete = curr->next;
        curr->next = to_delete->next;
        delete to_delete;
        size--;
    }

private:
    int size;
    ListNode *dum;
};

int main() {
    MyLinkedList *test = new MyLinkedList();
    test->addAtHead(1);
    test->addAtTail(3);
    test->addAtIndex(1, 2);
    int a = test->get(1);
    test->deleteAtIndex(1);
    int b = test->get(1);
    return 0;
}