//
// Created by 周天斌 on 2021/11/17.
//

#include <iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guests[2] =          // initializing an array of structs
            {
                    {"Bambi", 0.5, 21.99},      // first structure in array
                    {"Godzilla", 2000, 565.99}  // next structure in array
            };

    cout << "The guests " << guests[0].name << " and " << guests[1].name
         << "\nhave a combined volume of "
         << guests[0].volume + guests[1].volume << " cubic feet.\n";
    char name[20];
    float volume;
    double price;
    cout << "sizeof char[20]: " << sizeof name << endl;
    cout << "sizeof float: " << sizeof volume << endl;
    cout << "sizeof double: " << sizeof price << endl;
    cout << "sizeof inflatable: " << sizeof (inflatable) << endl;
    cout << "sizeof guests: " << sizeof guests << endl;
    return 0;
}