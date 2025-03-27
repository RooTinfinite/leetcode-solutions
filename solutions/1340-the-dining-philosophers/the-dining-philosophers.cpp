class DiningPhilosophers {
private:
    //array to track eating and nonEating philosophers
    bool eating[5]={};
    mutex m;
    condition_variable cv;
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        unique_lock<mutex> lock(m);
        //wait while any of 2 neighbours is eating
        while (eating[(philosopher+1)%5] || eating[(philosopher+4)%5]) cv.wait(lock);
		eating[philosopher] = true;

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        eating[philosopher] = false;
        cv.notify_all();
    }
};