#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int num = 0;

        multiset<vector<int>> s;

        for(auto &it : grid){
            s.insert(it);
        } 

        for(int i = 0; i < grid.size(); i ++){
            for(int j = i + 1; j < grid.size(); j ++){
                swap(grid[i][j], grid[j][i]);
            }
        }

        for(auto &it : grid){
            num += s.count(it);
        }

        return num;
    }
};