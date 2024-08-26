#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> traversed(isConnected.size(), false);
        queue<int> q;
        
        int cnt = 0;
        for(int i = 0; i < traversed.size(); i ++){
            if(traversed[i] == false){
                q.push(i);
                while(!q.empty()){
                    int pt = q.front();
                    q.pop();
                    traversed[pt] = true;

                    for(int j = 0; j < isConnected.size(); j ++){
                        if(isConnected[pt][j] == 1 && traversed[j] == false){
                            q.push(j);
                        }
                    }

                }

                cnt ++;
            }
        }

        return cnt;
    }
};