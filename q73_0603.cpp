#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ballons{}; 
        
        for(auto &pt : points){
            ballons.push({pt[0], pt[1]});
        }

        auto ballon = ballons.top();
        ballons.pop();
        int start = ballon.second;

        int cnt = 1;
        while(!ballons.empty()){
            ballon = ballons.top();
            ballons.pop();

            if(ballon.first > start){
                start = ballon.second;
                cnt ++;
            }else{
                start = min(start, ballon.second);
            }
        }

        return cnt;
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> d;

    d.push_back({10, 6});
    d.push_back({2, 8});
    d.push_back({1, 6});
    d.push_back({7, 12});

    cout << s.findMinArrowShots(d) << endl;


    return 0;
}