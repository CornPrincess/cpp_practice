//
// Created by 周天斌 on 2021/12/28.
//

#include <iostream>
#include <string>
template <typename T1, typename T2>
class Pair{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const {return a;}
    T2 second() const {return b;}
    Pair(const T1 & aval, const T2 & bval) :a(aval), b(bval) {}
    Pair() {}
};

template <typename T1, typename T2>
T1 & Pair<T1, T2>::first() {
    return a;
}

template<class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

int main() {
    using std::cout;
    using std::endl;
    using std::string;
    Pair<string, int> ratings[4] = {
            Pair<string, int>("The Purpled Duck", 5),
            Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
            Pair<string, int>("Cafe Souffle", 5),
            Pair<string, int>("Bertie's Eats", 3)
    };
    int joints = sizeof(ratings) / sizeof (Pair<string, int>);
    cout << "Rating:\t Eatery\n";
    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
             << ratings[i].first() << endl;
    cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    cout << ratings[3].second() << ":\t "
         << ratings[3].first() << endl;
    cout << sizeof ratings << endl;
    cout << sizeof (Pair<string, int>) << endl;
    return 0;
}