#include <iostream>
#include <set>

using namespace std;

class SmallestInfiniteSet {
    set<int> heap{};
    int cur_num = 1;
    
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!heap.empty()){
            auto f = heap.begin();
            heap.erase(f);
            return *f;
        }else{
            return cur_num ++;
        }
    }
    
    void addBack(int num) {
        if(num < cur_num){
            heap.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */