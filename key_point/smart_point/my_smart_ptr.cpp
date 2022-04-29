//
// Created by qwskyz on 22-4-27.
//

#include <utility>
#include <string>
#include <iostream>

using namespace std;

class shared_count {
public:
    shared_count() noexcept : count_(1) {}

    void add_count() noexcept {
        ++count_;
    }

    long reduce_count() noexcept {
        return --count_;
    }

    long get_count() noexcept {
        return count_;
    }
private:
    long count_;
};

template<typename T>
class my_smart_ptr {
public:

    template<typename U>
    friend class  my_smart_ptr;

    explicit my_smart_ptr(T* ptr = nullptr): ptr_(ptr) {
        if (ptr) {
            shared_count_ = new shared_count();
        }
    }

    ~my_smart_ptr() {
        if (ptr_ && !shared_count_->reduce_count()) {
            delete ptr_;
            delete shared_count_;
        }
    }

    my_smart_ptr(const my_smart_ptr& other) {
        cout << "my_ptr copy constructor" << endl;
        // copy ptr is the same
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template<typename U>
    my_smart_ptr(const my_smart_ptr<U>& other) noexcept {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template<typename U>
    my_smart_ptr(my_smart_ptr<U>&& other) noexcept {
        cout << "my_ptr move constructor" << endl;
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            // core move constructor
            other.ptr_ = nullptr;
        }
    }

    template<typename U>
    my_smart_ptr(const my_smart_ptr<U>& other, T* ptr) noexcept {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    my_smart_ptr& operator=(my_smart_ptr rhs) noexcept {
        rhs.swap(*this);
        return *this;
    }

    T* get() const noexcept {
        return ptr_;
    }

    long use_count() const noexcept {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }

    void swap(my_smart_ptr& rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    T& operator*() const noexcept{
        return *ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }

    operator bool() const noexcept {
        return ptr_;
    }


private:
    T* ptr_;
    shared_count* shared_count_;
};

template<typename T>
void swap(my_smart_ptr<T>& lhs, my_smart_ptr<T>& rhs) {
    lhs.swap(rhs);
}

template<typename T, typename U>
my_smart_ptr<T> static_pointer_cast(const my_smart_ptr<U> & other) noexcept {
    T* ptr = static_cast<T*>(other.get());
    return my_smart_ptr<T>(other, ptr);
}

template<typename T, typename U>
my_smart_ptr<T> reinterpret_pointer_cast(const my_smart_ptr<U> & other) noexcept {
    T* ptr = reinterpret_cast<T*>(other.get());
    return my_smart_ptr<T>(other, ptr);
}

template<typename T, typename U>
my_smart_ptr<T> const_pointer_cast(const my_smart_ptr<U> & other) noexcept {
    T* ptr = const_cast<T*>(other.get());
    return my_smart_ptr<T>(other, ptr);
}
template<typename T, typename U>
my_smart_ptr<T> dynamic_pointer_cast(const my_smart_ptr<U> & other) noexcept {
    T* ptr = dynamic_cast<T*>(other.get());
    return my_smart_ptr<T>(other, ptr);
}


class Person {
public:
    Person() = default;
    Person(const std::string& name): m_name(name) {
        cout << "created" << endl;
    }
    ~Person() {
        cout << "destroy" << endl;
    }
    void print() {
        cout << m_name << endl;
    }
private:
    std::string m_name;
};

int main() {
//    Person p1("hello");
//    p1.print();
    my_smart_ptr<Person> p1 = my_smart_ptr<Person>(new Person("hello"));
    my_smart_ptr<Person> p2(new Person("world"));
    //my_smart_ptr<Person> p3(p1);
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    //cout << p3.use_count() << endl;
    return 0;
}