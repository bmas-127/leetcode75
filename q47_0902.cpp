#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int width, height;
    int total_step = 0;
    int this_stage_size;
    int next_state_size = 0;
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;

        width = maze[0].size();
        height = maze.size();

        extend_first(maze, q, entrance[0], entrance[1]);
        this_stage_size = q.size();

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(is_boarder(i, j)){
                return total_step;
            }

            extend(maze, q, i, j);

            this_stage_size --;
            if(this_stage_size == 0){
                this_stage_size = q.size();
                total_step += 1;
            }
        }
        

        return -1;
    }

    void extend_first(vector<vector<char>>& maze, queue<pair<int, int>>&q, int i, int j){
        if(is_boarder(i, j)){
            if(j > 0 && maze[i][j-1] == '.'){
                maze[i][j-1] = '+';
                q.push({i, j-1});
            }
            if(j < width - 1 && maze[i][j+1] == '.'){
                maze[i][j+1] = '+';
                q.push({i, j+1});
            }
            if(i > 0 && maze[i-1][j] == '.'){
                maze[i-1][j] = '+';
                q.push({i-1, j});
            }
            if(i < height - 1 && maze[i+1][j] == '.'){
                maze[i+1][j] = '+';
                q.push({i+1, j});
            }

            maze[i][j] = '+';
            total_step += 1;
        }else{
            q.push({i, j});
        }
    }

    void extend(vector<vector<char>>& maze, queue<pair<int, int>>&q, int i, int j){
        if(maze[i-1][j] == '.'){
            maze[i-1][j] = '+';
            q.push({i-1, j});
        }
        if(maze[i+1][j] == '.'){
            maze[i+1][j] = '+';
            q.push({i+1, j});
        }
        if(maze[i][j-1] == '.'){
            maze[i][j-1] = '+';
            q.push({i, j-1});
        }
        if(maze[i][j+1] == '.'){
            maze[i][j+1] = '+';
            q.push({i, j+1});
        }

    }

    bool is_boarder(int i, int j){
        return (i == 0 || i == height - 1 || j == 0 || j == width - 1);
    }

    void print(vector<vector<char>>& maze){
        for(auto& it : maze){
            for(auto& jt : it){
                cout << jt;
            }
            cout << endl;
        }
    }
};