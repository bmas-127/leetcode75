#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // priority_queue<int, vector<int>, greater<int>> head, tail;
        long long total_cost = 0;
        if(costs.size() <= k){
            for(auto& c : costs){
                total_cost += c;
            }
            return total_cost;
        }

        auto l_begin = costs.begin();
        auto l_end = costs.begin() + candidates;
        auto r_begin = costs.end() - candidates;
        auto r_end = costs.end();

        auto l_min_idx = min_element(l_begin, l_end);
        auto r_min_idx = min_element(r_begin, r_end);

        bool single = false;

        while(k > 0){
            // cout << total_cost << endl;
            // cout << "--------" << endl;
            // cout << "l : " << *l_min_idx << endl;
            // cout << "r : " << *r_min_idx << endl;
            if(single){
                total_cost += *l_min_idx;
                *l_min_idx = *l_begin;
                ++ l_begin;
                l_min_idx = min_element(l_begin, l_end);
            }else if(*l_min_idx < *r_min_idx){
                total_cost += *l_min_idx;
                *l_min_idx = *l_begin;
                ++ l_begin;

                if(++l_end >= r_begin){
                    single = true;
                    l_end = r_end;
                    l_min_idx = min_element(l_begin, l_end);
                }else{
                    l_min_idx = min_element(l_begin, l_end);
                }
            }else{
                total_cost += *r_min_idx;
                *r_min_idx = *(r_end - 1);
                -- r_end;

                if(--r_begin <= l_end){
                    single = true;
                    l_end = r_end;
                    l_min_idx = min_element(l_begin, l_end);
                }else{
                    r_min_idx = min_element(r_begin, r_end);
                }

            }

            k --;
        }
    
        return total_cost;
    }
};



int main(){
    Solution s;
    vector<int> a{17,12,10,2,7,2,11,20,8};
    vector<int> b{1,2,4,1};

    cout << s.totalCost(a, 3, 4) << endl;
    cout << s.totalCost(b, 3, 3) << endl;

    return 0;
}