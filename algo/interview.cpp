//
// Created by 周天斌 on 2022/5/13.
//

#include <map>
#include <queue>

struct A {
    int a;
    int b;
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val){}
};

int main() {
    std::map<int, int> map;
    auto iter = map.find(1);
    if (iter != map.end()) {
        //map.find(1)->second;
        map[1];
        iter->second;
    }
}

void sort() {
    std::vector<int> nums = {1 ,2 ,3, 4, 6,7,8,5};


}

void traversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
    }
}
