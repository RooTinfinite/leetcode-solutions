#include <functional>
#include <condition_variable>
#include <mutex>

using namespace std;

class FizzBuzz {
private:
    int n;
    int cnt;
    mutex mtx;
    condition_variable fizzCV, buzzCV, fizzbuzzCV, numberCV;

public:
    FizzBuzz(int n) : n(n), cnt(1) {}

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            fizzCV.wait(lock, [this]() { return (cnt % 3 == 0 && cnt % 5 != 0) || cnt > n; });
            if (cnt > n) return;
            printFizz();
            cnt++;
            notify_next();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            buzzCV.wait(lock, [this]() { return (cnt % 5 == 0 && cnt % 3 != 0) || cnt > n; });
            if (cnt > n) return;
            printBuzz();
            cnt++;
            notify_next();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            fizzbuzzCV.wait(lock, [this]() { return (cnt % 3 == 0 && cnt % 5 == 0) || cnt > n; });
            if (cnt > n) return;
            printFizzBuzz();
            cnt++;
            notify_next();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            numberCV.wait(lock, [this]() { return (cnt % 3 != 0 && cnt % 5 != 0) || cnt > n; });
            if (cnt > n) return;
            printNumber(cnt);
            cnt++;
            notify_next();
        }
    }

private:
    void notify_next() {
        if (cnt > n) {
            fizzCV.notify_all();
            buzzCV.notify_all();
            fizzbuzzCV.notify_all();
            numberCV.notify_all();
            return;
        }
        if (cnt % 3 == 0 && cnt % 5 == 0) {
            fizzbuzzCV.notify_one();
        } else if (cnt % 3 == 0) {
            fizzCV.notify_one();
        } else if (cnt % 5 == 0) {
            buzzCV.notify_one();
        } else {
            numberCV.notify_one();
        }
    }
};