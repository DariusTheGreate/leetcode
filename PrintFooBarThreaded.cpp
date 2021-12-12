#include <atomic>
#include <condition_variable>
#include <mutex>

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(writer);
            while(!boo_written)
                condVar.wait(lck);
            printFoo();
            foo_written = 1;
            boo_written = 0;
            condVar.notify_all();
        }
        
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(writer);
            while(!foo_written){
                condVar.wait(lck);
            }
            printBar();
            foo_written = 0;
            boo_written = 1;
            condVar.notify_all();
        }
    }
    
private:
    int foo_written = 0;
    int boo_written = 1;
    std::condition_variable condVar;
    std::mutex writer;
};