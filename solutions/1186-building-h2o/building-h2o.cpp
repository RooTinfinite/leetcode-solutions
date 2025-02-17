class H2O {
public:
    H2O() {
        x=0;
    }
    std::mutex tt;
    std::condition_variable data_c;
    atomic<int> x;

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        {
        std::unique_lock<std::mutex> z(tt);
        data_c.wait(z, [&](){return x.load()<2;});
        releaseHydrogen();
        ++x;

        }
       // if(x ==2)
        data_c.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        std::unique_lock<std::mutex> m(tt);
        data_c.wait(m, [&](){return x.load()==2;});
        releaseOxygen();
        x.store(0);
        m.unlock();
        data_c.notify_all();
    }
};