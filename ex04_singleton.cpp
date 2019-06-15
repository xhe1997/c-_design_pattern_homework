#include <functional>
using namespace std;

struct SingletonTester {
    template <typename T>
    bool is_singleton(function<T*()> factory) {
        // TODO
        T* instance1 = factory();
        T* instance2 = factory();
        return instance1 == instance2;
    }
};
