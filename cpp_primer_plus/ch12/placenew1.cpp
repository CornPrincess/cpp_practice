//
// Created by 周天斌 on 2021/12/15.
//

#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting {
private:
    string words;
    int number;
public:
    JustTesting(const string &s = "Just Testing", int n = 0) {
        words = s;
        number = n;
        cout << words << " constructed\n";
    }

    ~JustTesting() {
        cout << words << " destroyed\n";
    }

    void Show() const {
        cout << words << ", " << number << endl;
    }
};

int main() {
    char * buffer = new char[BUF];
    JustTesting *pc1, *pc2;
    std::cin >> buffer;
    cout << buffer << endl;
    pc1 = new (buffer) JustTesting;
    pc2 = new JustTesting("Heap1", 20);
    cout << "Memory block addresses:\n" << "buffer: "
         << (void *) buffer << "    heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    cout << "=======================\n";
    pc1->Show();
    pc3->Show();
    cout << buffer << endl;

    delete pc2;                 // free Heap1
    delete pc4;                 // free Heap2
    delete [] buffer;           // free buffer
    cout << "Done\n";
    return 0;
}
