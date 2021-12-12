#include <thread>
#include <mutex>
#include <atomic>

class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_atomic.store(1);
    }

    void second(function<void()> printSecond) {
        while(!first_atomic.load())
            continue;
        printSecond();
        second_atomic.store(1);
    }

    void third(function<void()> printThird) {
        while(!(first_atomic.load() && second_atomic.load()))
            continue;    
        printThird();
    }
private:
    std::atomic<int> first_atomic = 0;
    std::atomic<int> second_atomic = 0;
    std::atomic<int> third_atomic = 0;
};