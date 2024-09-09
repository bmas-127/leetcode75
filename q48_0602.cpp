#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> node_to_id;
        set<string> node_list;
        vector<double> ans;

        for(auto &eq : equations){
            node_list.insert(eq[0]);
            node_list.insert(eq[1]);
        }

        int cnt = 0;
        for(auto &s : node_list){
            node_to_id[s] = cnt++;
        }

        vector<double> value_table(cnt*cnt, 0);

        for(int n = 0; n < equations.size(); n ++){
            int i = node_to_id[equations[n][0]];
            int j = node_to_id[equations[n][1]];

            value_table[i * cnt + j] = values[n];
            value_table[j * cnt + i] = 1.0 / values[n];
        } 


        for(auto &q : queries){
            vector<bool> is_visited(cnt, false);
            queue<pair<int, double>> nodeq {};

            if(node_list.find(q[0]) == node_list.end() || node_list.find(q[1]) == node_list.end()){
                ans.push_back(-1);
                continue;
            }
            
            int start = node_to_id[q[0]];
            int end = node_to_id[q[1]];


            nodeq.push({start, 1.0});

            double result = -1.0;
            while(!nodeq.empty() && result == -1.0){
                auto node = nodeq.front();
                auto i = node.first;
                auto val = node.second;
                nodeq.pop();

                for(int n = cnt * i; n < cnt * (i + 1); n ++){
                    auto j = n - cnt * i;
                    if (value_table[n] != 0 && is_visited[j] == false){
                        auto next_val = val * value_table[n];
                        is_visited[j] = true;
                        if(n - cnt * i == end){
                            result = next_val;
                            break;
                        }
                        nodeq.push({j, next_val});
                    }
                }
            }
            
            ans.push_back(result);
        }

        return ans;   
    }
};