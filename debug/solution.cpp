//
// Created by qwskyz on 22-5-8.
//
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeSpace(s);
        reverse(s, 0, s.size() - 1);
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] != ' ') {
                i++;
            }
            reverse(s, left, i - 1);
            left = i + 1;
        }
        return s;
    }

    void reverse(string &s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    void removeSpace(string &s) {
        int ptr = 0;
        for (int i = 0; i < s.size(); i++) {
            // 相当于删除所有的空格
            if (s[i] != ' ') {
                // 手动添加单词间的空格
                if (ptr != 0) {
                    s[ptr++] = ' ';
                }
                while (i < s.size() && s[i] != ' ') {
                    s[ptr++] = s[i++];
                }
            }
        }
        s.resize(ptr);
    }
};

int main() {
    Solution s;
    string test = "the blue sky";
    s.reverseWords(test);
    return 0;
}