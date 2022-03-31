//
// Created by 周天斌 on 2021/12/27.
//

#ifndef CPP_PRACTICE_WORKERMI_H
#define CPP_PRACTICE_WORKERMI_H

#include <string>

// an abstract base class
class Worker {
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;

    virtual void Get();

public:
    Worker() : fullname("no one"), id(0L) {}

    Worker(const std::string &s, long n) : fullname(s), id(n) {}

    virtual ~Worker() = 0;

    virtual void Set() = 0;

    virtual void Show() const = 0;
};

// core 虚基类 virtual public
class Waiter : virtual public Worker {
private:
    int panache;
protected:
    void Data() const;

    void Get();

public:
    Waiter() : Worker(), panache(0) {}

    Waiter(const std::string &s, long n, int p = 0) : Worker(s, n), panache(p) {}

    Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}

    void Set();

    void Show() const;
};

class Singer : virtual public Worker {
protected:
    enum {
        other, alto, contralto, soprano,
        bass, baritone, tenor
    };
    enum {
        Vtypes = 7
    };

    void Data() const;

    void Get();

private:
    static char *pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other) {}

    Singer(const std::string &s, long n, int v = other)
            : Worker(s, n), voice(v) {}

    Singer(const Worker &wk, int v = other)
            : Worker(wk), voice(v) {}

    void Set();

    void Show() const;
};

// multiple inheritance
class SingerWaiter : public Waiter, public Singer {
protected:
    void Data() const;
    void Get();
public:
    SingerWaiter() {}
    SingerWaiter(const std::string &s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n,v) {}
    SingerWaiter(const Worker & wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk,v) {}
    SingerWaiter(const Waiter & wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt,v) {}
    SingerWaiter(const Singer & sg, int v = other) : Worker(sg), Waiter(sg), Singer(sg,v) {}
    void Set();
    void Show() const;
};

#endif //CPP_PRACTICE_WORKERMI_H
