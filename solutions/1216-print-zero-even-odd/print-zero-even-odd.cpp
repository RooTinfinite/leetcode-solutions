class ZeroEvenOdd {
private:
    int n;
    bool pzero = true;
    int next = 0;
    std::mutex mtx;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            std::unique_lock lk(mtx);
            cv.wait(lk, [this] {
                return pzero;
            });
            printNumber(0);
            pzero = false;
            ++next;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock lk(mtx);
            cv.wait(lk, [this] {
                return !pzero && next % 2 == 0;
            });
            printNumber(i);
            pzero = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock lk(mtx);
            cv.wait(lk, [this] {
                return !pzero && next % 2 == 1;
            });
            printNumber(i);
            pzero = true;
            cv.notify_all();
        }
    }
};