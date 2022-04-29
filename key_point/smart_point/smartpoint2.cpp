//
// Created by 周天斌 on 2022/1/5.
//

#include <iostream>
#include <string>
#include <memory>

int main() {
    using namespace std;
    shared_ptr<string> films[5] =
            {
                    auto_ptr<string>(new string("Fowl Balls")),
                    auto_ptr<string>(new string("Duck Walks")),
                    auto_ptr<string>(new string("Chicken Runs")),
                    auto_ptr<string>(new string("Turkey Errors")),
                    auto_ptr<string>(new string("Goose Eggs"))
            };
    // core 如果使用auto 或者 unique， films[2] loses ownership，将导致 films[2]不再引用字符串，造成空指针
    // auto_ptr<string> pwin;

    // share 可以
    // core unique 编译时就报错
    shared_ptr<string> pwin;
    // unique_ptr<string> pwin;
    pwin = films[2];

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;
    cout << "The winner is " << *pwin << "!\n";
    //cin.get();
    return 0;
}