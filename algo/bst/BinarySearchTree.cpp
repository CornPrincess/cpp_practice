//
// Created by 周天斌 on 2022/5/15.
//

struct Node {
    int val;
    Node* left;
    Node* right;
    Node() = default;
    Node(int _val): val(_val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
public:
    Node* find(int data) {
        Node* cur = root;
        while (cur != nullptr) {
            if (cur->val == data) {
                return cur;
            } else if (cur->val > data){
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return nullptr;
    }

    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
            return;
        }
        Node* cur = root;
        while (cur != nullptr) {
            if (cur->val > data) {
                if (cur->left == nullptr) {
                    cur->left = new Node(data);
                    return;
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = new Node(data);
                    return;
                }
                cur = cur->right;
            }
        }
    }

//    void del(int data) {
//
//    }

    void del(int data) {
        Node* p = root; // p指向要删除的节点，初始化指向根节点
        Node* pp = nullptr; // pp记录的是p的父节点
        while (p != nullptr && p->val != data) {
            pp = p;
            if (data > p->val) p = p->right;
            else p = p->left;
        }
        if (p == nullptr) return; // 没有找到

        // 要删除的节点有两个子节点
        if (p->left != nullptr && p->right != nullptr) { // 查找右子树中最小节点
            Node* minP = p->right;
            Node* minPP = p; // minPP表示minP的父节点
            while (minP->left != nullptr) {
                minPP = minP;
                minP = minP->left;
            }
            p->val = minP->val; // 将minP的数据替换到p中
            p = minP; // 下面就变成了删除minP了
            pp = minPP;
        }

        // 删除节点是叶子节点或者仅有一个子节点
        Node* child; // p的子节点
        if (p->left != nullptr) child = p->left;
        else if (p->right != nullptr) child = p->right;
        else child = nullptr;

        if (pp == nullptr) root = child; // 删除的是根节点
        else if (pp->left == p) pp->left = child;
        else pp->right = child;
    }
};