#include <vector>
#include <queue>

using namespace std;

class Solution {
    long long int total_cost;
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        total_cost = 0;

        if(candidates * 2 >= costs.size()){
            return single(costs, k);
        }

        int left_end = candidates, right_begin = costs.size() - candidates;
        priority_queue<int, vector<int>, greater<int>> front(costs.begin(), costs.begin() + left_end);
        priority_queue<int, vector<int>, greater<int>> back(costs.begin() + right_begin, costs.end());

        while(k > 0 && left_end != right_begin){
            if(front.top() <= back.top()){
                total_cost += front.top();
                front.pop();
                front.push(costs[left_end++]);
            }else{
                total_cost += back.top();
                back.pop();
                back.push(costs[--right_begin]);
            }

            k --;
        }


        while(k > 0){
            if(back.empty() || !front.empty() && front.top() <= back.top()){
                total_cost += front.top();
                front.pop();
            }else{
                total_cost += back.top();
                back.pop();
            }

            k --;
        }

        return total_cost;
    }

    long long single(vector<int>& costs, int k){
        priority_queue<int, vector<int>, greater<int>> merge(costs.begin(), costs.end());
        while(k > 0){
            total_cost += merge.top();
            merge.pop();
            k--;
        }

        return total_cost;
    }
};
