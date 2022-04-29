//
// Created by qwskyz on 22-4-27.
//

#include <iostream>
#include <cstring>

using namespace std;
class String {
public:
    String() = default;
    String(const char* string) {
        m_size = strlen(string);
        m_data = new char[m_size + 1];
        strcpy(m_data, string);
        cout << "created" << endl;
    }
    String(const String& other) {
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        strcpy(m_data, other.m_data);
        cout << "copy" << endl;
    }
    String(String&& other) noexcept {
        m_size = other.m_size;
        m_data = other.m_data;

        other.m_data = nullptr;
        other.m_size = 0;
        cout << "move constructor" << endl;
    }

    String& operator=(String&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] m_data;
        m_size = other.m_size;
        m_data = other.m_data;

        other.m_data = nullptr;
        other.m_size = 0;
        cout << "move operator" << endl;
    }

    ~String() {
        delete m_data;
        cout << "delete" << endl;
    }

    void print() {
        cout << m_data << endl;
    }

private:
    char * m_data;
    int m_size;
};

class Entity {
public:
    Entity() = default;
    Entity(const String& name): m_name(name) {}
    Entity(String&& name): m_name(move(name)) {}
//    Entity(const Entity& other) {
//        cout << "entity copy" << endl;
//        m_name = other.m_name;
//    }

    void print() {
        cout << "My name is: ";
        m_name.print();
    }
private:
    // core this is object, not reference, so it will call copy constructor
    String m_name;
};

void test1(Entity& en) {
    cout << "test1" << endl;
    en.print();
}

void test2(Entity en) {
    cout << "test2" << endl;
    en.print();
}


int main() {
    // core will call String copy constructor
    Entity entity1(String("hello"));
    entity1.print();

//    cout << "Pharse 1 end" << endl;
//    test1(entity1);
//    test2(entity1);
    String s2 = "world";
    Entity entity2(s2);
    entity2.print();

    String s3 = "cpp";
    s3 = move(s2);
    String s4 = move(s3);
    cin.get();
    return 0;
}