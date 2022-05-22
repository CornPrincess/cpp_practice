//
// Created by qwskyz on 22-5-1.
//

#include <mutex>
#include <atomic>
// 头文件
class singleton {
public:
    static singleton* instance();
    // other methods
private:
    // double check mutex lock
    static std::mutex lock_;
    // core atomic instance ptr
    static std::atomic<singleton*> inst_ptr_;
};

std::mutex singleton::lock_;
std::atomic<singleton*> singleton::inst_ptr_;

singleton* singleton::instance() {
    singleton* ptr = inst_ptr_.load(std::memory_order_acquire);
    if (ptr == nullptr) {
        std::lock_guard<std::mutex> guard{lock_};
        ptr = inst_ptr_.load(std::memory_order_relaxed);
        if (ptr == nullptr) {
            ptr = new singleton();
            // core it confirm new operator must end before inst_ptr_.store
            inst_ptr_.store(ptr, std::memory_order_release);
        }
    }
    return inst_ptr_;
}