//
// Created by qwskyz on 22-5-2.
//
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
private:

    vector <string> split(const string &str, const string &delim) { //将分割后的子字符串存储在vector中
        vector <string> res;
        if ("" == str) return res;

        string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
        size_t pos;
        size_t size = strs.size();

        for (int i = 0; i < size; ++i) {
            pos = strs.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
            if (pos < size) { //如果查找到，如果没有查找到分隔符，pos为string::npos
                string s = strs.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
                res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
                i = pos + delim.size() - 1;
            }

        }
        return res;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "[]";
        string res = "[";
        queue < TreeNode * > que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node != nullptr) {
                res = res + to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            } else {
                res = res + "null,";
            }
        }
        res = res.substr(0, res.size() - 1);
        res = res + "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "[]") return nullptr;
        string str = data.substr(1, data.size() - 2);
        vector <string> strarr = split(str, ",");
        TreeNode *root = new TreeNode(stoi(strarr[0]));
        queue < TreeNode * > que;
        que.push(root);
        int i = 1;
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (strarr[i] != "null") {
                node->left = new TreeNode(stoi(strarr[i]));
                que.push(node->left);
            }
            i++;
            if (strarr[i] != "null") {
                node->right = new TreeNode(stoi(strarr[i]));
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};

TreeNode* init() {
    TreeNode* root = new TreeNode(1);
    TreeNode* l1 = new TreeNode(2);
    TreeNode* r1 = new TreeNode(3);
    TreeNode* r1l1 = new TreeNode(4);
    TreeNode* r1r1 = new TreeNode(5);
    root->left = l1;
    root->right = r1;
    r1->left = r1l1;
    r1->right = r1r1;
    return root;
}

int main() {
    TreeNode* root = init();
    Codec code;
    string str = code.serialize(root);
    cout << str << endl;
    TreeNode* node = code.deserialize(str);
    string str2 = code.serialize(node);
    cout << str2 << endl;
    return 0;
}