//
// Created by 周天斌 on 2021/11/16.
//

#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    struct inflatable guest = {
            "Glorious Gloria",
            1.78,
            2.99
    };
    // 可以不使用 struct 关键字
    inflatable pal = {
            "Audacious Arthur",
            3.12,
            32.99
    };
    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
// pal.name is the name member of the pal variable
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    // error array type 'char [20]' is not assignable
    // pal.name = "123456789123456789123456789";

    // test c++11
    inflatable cpp11 {};
    cout << "name:" << cpp11.name << "volume:" << cpp11.volume << ",price:" << cpp11.price << endl;
    return 0;
}