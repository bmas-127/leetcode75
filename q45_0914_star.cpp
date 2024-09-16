#include <map>
#include <vector>
#include <queue>

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::map<int, std::vector<int>> cityToConnectedEdgeId;
        std::queue<int> cityQueue;
        std::vector<bool> edgeUsed(connections.size(), false);
        int changeDirNum = 0;

        int i = 0;
        for(auto& it : connections){
            cityToConnectedEdgeId[it[0]].push_back(i);
            cityToConnectedEdgeId[it[1]].push_back(i);
            i++;
        }

        cityQueue.push(0);

        while(!cityQueue.empty()){
            auto city = cityQueue.front();
            cityQueue.pop();

            for(auto& connectedEdgeId : cityToConnectedEdgeId[city]){
                if(!edgeUsed[connectedEdgeId]){
                    if(connections[connectedEdgeId][0] == city){
                        cityQueue.push(connections[connectedEdgeId][1]);
                        changeDirNum ++;
                    }else{
                        cityQueue.push(connections[connectedEdgeId][0]);
                    }
                }
                edgeUsed[connectedEdgeId] = true;
            }
        }

        return changeDirNum;
    }
};
