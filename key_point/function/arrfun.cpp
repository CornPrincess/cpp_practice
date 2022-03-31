//
// Created by 周天斌 on 2022/2/8.
//


#include <iostream>

const int ArrSize = 8;
// prototype
int sum_arr(int arr[], int n);
int sum_arr2(int * arr, int n);

int main() {
    using namespace std;
    int cookies[ArrSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    std::cout << cookies << " = array address, ";
    std::cout << sizeof cookies << " = sizeof cookies\n";
    int sum = sum_arr(cookies, ArrSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;
    sum = sum_arr(cookies, 3);      // a lie
    std::cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, 4);  // another lie
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}


int sum_arr(int arr[], int n) {
    std::cout << arr << " = arr, ";
    std::cout << sizeof arr << " = sizeof arr\n";
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// This is ok
int sum_arr2(int * arr, int n) {
    std::cout << arr << " = arr, ";
    std::cout << sizeof arr << " = sizeof arr\n";

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += *(arr + i);
    }
    return total;
}