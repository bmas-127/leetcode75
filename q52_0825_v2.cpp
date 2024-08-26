#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // priority_queue<int, vector<int>, greater<int>> head, tail;
        long long total_cost = 0;
        cout << costs.size() << endl;
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
            k --;
            // cout << total_cost << endl;
            // cout << "--------" << endl;
            // cout << "l : " << *l_min_idx << endl;
            // cout << "r : " << *r_min_idx << endl;
            if(*l_min_idx <= *r_min_idx){
                total_cost += *l_min_idx;
                *l_min_idx = *l_begin;
                ++ l_begin;

                if(++l_end >= r_begin){
                    l_end = r_end;
                    break;
                }else{
                    l_min_idx = min_element(l_begin, l_end);
                }
            }else{
                total_cost += *r_min_idx;
                *r_min_idx = *(r_end - 1);
                -- r_end;

                if(--r_begin <= l_end){
                    l_end = r_end;
                    break;
                }else{
                    r_min_idx = min_element(r_begin, r_end);
                }

            }
        }

        sort(l_begin, l_end);

        while(k > 0){
            total_cost += *l_begin;
            ++ l_begin;
            k--;
        }
    
        return total_cost;
    }
};
