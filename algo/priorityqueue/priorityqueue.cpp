//
// Created by 周天斌 on 2022/5/16.
//

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

void test() {
    vector<int> nums = {1, 2, 36, 82, 45, 7, 132, 47, 134, 347, 9, 245, 8};
    // 默认是大根堆，底层使用 < 进行比较
    priority_queue<int> que;
    for (int num: nums) {
        que.push(num);
    }
    cout << que.top() << endl;

    // 小根堆，底层使用 > 进行比较
    priority_queue<int, vector<int>, greater<int>> que2(nums.begin(), nums.end());
    cout << que2.top() << endl;
    cout << "=====================" << endl;
}

class MyDate {
public:
    MyDate() = default;

    explicit MyDate(int year = 1994, int month = 1, int day = 31) : _year(year), _month(month), _day(day) {}

    bool operator<(const MyDate& d) const {
        return (_year < d._year) ||
               (_year == d._year && _month < d._month) ||
               (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const MyDate& d) const {
        return (_year > d._year) ||
               (_year == d._year && _month > d._month) ||
               (_year == d._year && _month == d._month && _day > d._day);
    }

    int getYear() const {
        return _year;
    }

    void setYear(int year) {
        _year = year;
    }

    int getMonth() const {
        return _month;
    }

    void setMonth(int month) {
        _month = month;
    }

    int getDay() const {
        return _day;
    }

    void setDay(int day) {
        _day = day;
    }

    friend ostream& operator<<(ostream& os, const MyDate& d) {
        os << d._year << "_" << d._month << "_" << d._day << endl;
        return os;
    }
private:
    int _year;
    int _month;
    int _day;
};

void test2() {
    priority_queue<MyDate> que;
    que.push(MyDate(2022, 10,1));
    que.push(MyDate(2021, 9,1));
    que.push(MyDate(2020, 8,1));
    cout << que.top() << endl;

    priority_queue<MyDate, vector<MyDate>, greater<MyDate>> que2;
    que2.push(MyDate(2022, 10,1));
    que2.push(MyDate(2021, 9,1));
    que2.push(MyDate(2020, 8,1));
    cout << que2.top() << endl;
    cout << "=====================" << endl;
}

class CmpByYear {
public:
    bool operator()(const MyDate& d1, const MyDate& d2) const {
        return (d1.getYear() > d2.getYear()) ||
               (d1.getYear() == d2.getYear() && d1.getMonth() > d2.getMonth()) ||
               (d1.getYear() == d2.getYear() && d1.getMonth() == d1.getMonth() && d1.getDay() > d2.getDay());
    }
};

void test3() {
    priority_queue<MyDate, vector<MyDate>,CmpByYear> que;
    que.push(MyDate(2022, 10,1));
    que.push(MyDate(2021, 9,1));
    que.push(MyDate(2020, 8,1));
    cout << que.top() << endl;
    cout << "=====================" << endl;
}

int main() {
    test();
    test2();
    test3();
    return 0;
}