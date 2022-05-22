//
// Created by 周天斌 on 2022/5/16.
//
struct ListNode {
    int val;
    ListNode* left;
    ListNode* right;
    ListNode() = default;
    ListNode(int val):
};

ListNode* partition(ListNode* left, ListNode* right);

// 5 ,2 ,5 ,4 ,7 ,6 ,7
// 2
ListNode* sort(ListNode* head, ListNode* tail) {
    vector<ListNode*> node = partition(head, tail);
    sort(head, node[0]);
    sort(head, node[1]);

}

vector<ListNode*> partition(ListNode* left, ListNode* right) {

}



