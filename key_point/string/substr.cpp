//
// Created by qwskyz on 22-5-2.
//

#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string>  split(const string& str,const string& delim) { //将分割后的子字符串存储在vector中
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

int main() {
    std::string str = "123";
    std::string str2 = str.substr(0, str.size() - 1);
    std::cout << str2 << std::endl;
    std::string ss = "[1,2,3,4,5,6,null,null]";
    string ss2 = ss.substr(1, ss.size() - 2);
    vector<string> vs = split(ss2, ",");
    for (auto s: vs) {
        cout << s << " ";
    }
    cout << endl;

    std::string ssa = "[1]";
    string ssa2 = ssa.substr(1, ssa.size() - 2);
    vector<string> vsa = split(ssa2, ",");
    for (auto s: vsa) {
        cout << s << " ";
    }
    return 0;
}