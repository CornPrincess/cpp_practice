//
// Created by qwskyz on 22-4-27.
//

#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class Animal {
private:
    string genus;
    string species;
    int age;
    double weight;
public:
    Animal(const string&, const string&, int, double){/*...*/ }
    Animal(){}
    ~Animal() {cout << "destruct" << endl;}
};

void MakeAnimals()
{
    // Use the Animal default constructor.
    unique_ptr<Animal> p1 = make_unique<Animal>();

    // Use the constructor that matches these arguments
    auto p2 = make_unique<Animal>("Felis", "Catus", 12, 16.5);

    // Create a unique_ptr to an array of 5 Animals
    unique_ptr<Animal[]> p3 = make_unique<Animal[]>(5);

    // Initialize the elements
    p3[0] = Animal("Rattus", "norvegicus", 3, 2.1);
    p3[1] = Animal("Corynorhinus", "townsendii", 4, 1.08);

    // auto p4 = p2; //C2280

    vector<unique_ptr<Animal>> vec;
    // vec.push_back(p2); //C2280
    // vector<unique_ptr<Animal>> vec2 = vec; // C2280

    // OK. p2 no longer points to anything
    vec.push_back(move(p2));

    // unique_ptr overloads operator bool
    //cout <<  p2 << endl; // Prints "true"

    // OK but now you have two pointers to the same memory location
    Animal* pAnimal = p2.get();

    // OK. p2 no longer points to anything
    Animal* p5 = p2.release();
    cout << p5 << endl;
}

int main() {
    MakeAnimals();
    return 0;
}