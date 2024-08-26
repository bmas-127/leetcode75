#include <iostream>
#include <queue>

class RecentCounter {
    std::queue<int> window;
public:
    RecentCounter() {
        std::queue<int> empty;
        window = std::move(empty);
    }
    
    int ping(int t) {
        window.push(t);
        while(!window.empty() && window.front() < t - 3000){
            window.pop();
        }

        return window.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */