#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> rottenOrangeEdge;
        queue<int> rottenOrangeEdgeNext;
        int width = grid[0].size();
        int height = grid.size();
        int freshOrangeNum = 0;
        int cnt = 0;

        for(auto& it : grid){
            for(auto& entry : it){
                if(entry == 2){
                    rottenOrangeEdge.push(cnt);
                }else if(entry == 1){
                    freshOrangeNum ++;
                }

                cnt ++;
            }
        }
        
        int day = 0;
        do{
            while(!rottenOrangeEdge.empty()){
                int pos = rottenOrangeEdge.front();
                int i = pos/ width;
                int j = pos % width;
                rottenOrangeEdge.pop();


                if(i > 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    rottenOrangeEdgeNext.push(pos - width);
                    freshOrangeNum --;
                }
                if(i < height - 1 && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    rottenOrangeEdgeNext.push(pos + width);
                    freshOrangeNum --;
                }
                if(j > 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    rottenOrangeEdgeNext.push(pos - 1);
                    freshOrangeNum --;
                }
                if(j < width - 1 && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    rottenOrangeEdgeNext.push(pos + 1);
                    freshOrangeNum --;
                }
            }

            swap(rottenOrangeEdge, rottenOrangeEdgeNext);
            day ++;
        }while(!rottenOrangeEdge.empty());

        return (freshOrangeNum == 0) ? day - 1 : -1;
    }
};