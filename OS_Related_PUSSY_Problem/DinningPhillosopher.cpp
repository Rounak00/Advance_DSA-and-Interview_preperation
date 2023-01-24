/** General semaphore with N permissions **/
class Semaphore {
	const size_t num_permissions;
	size_t avail;
	std::mutex m;
	std::condition_variable cv;
public:
	/** Default constructor. Default semaphore is a binary semaphore **/
	explicit Semaphore(const size_t& num_permissions = 4) : num_permissions(num_permissions), avail(num_permissions) { }

	/** Copy constructor. Does not copy state of mutex or condition variable,
		only the number of permissions and number of available permissions **/
	Semaphore(const Semaphore& s) : num_permissions(s.num_permissions), avail(s.avail) { }

	void acquire() {
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, [this] { return avail > 0; });
		avail--;
		// lk.unlock();
	}

	void release() {
		m.lock();
		avail++;
		m.unlock();
		cv.notify_one();
	}

	// size_t available() const {
	// 	return avail;
	// }
};

class DiningPhilosophers {

public:
        condition_variable waitUntilAvailable[5];
        mutex phil_mutex[5];
        Semaphore s;
public:
    DiningPhilosophers() {
        //semaphore use to make sure that only 4 philosophers are eating at any given time, do not exceed 4

    }

    int getLeft(int philosopher){
        int left = philosopher;
        return left;
    }

    int getRight(int philosopher){
        int right = (philosopher + 1) % 5;
        return right;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
    
    
    int left = getLeft(philosopher);

    int right = getRight(philosopher);

    s.acquire();

    unique_lock<mutex> lckLeft(phil_mutex[left]);
    unique_lock<mutex> lckRight(phil_mutex[right]);

    pickLeftFork();pickRightFork();eat();putLeftFork();putRightFork();

    lckLeft.unlock();
    lckRight.unlock();

    s.release();
		
    }
};