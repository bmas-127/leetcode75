#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited_room(rooms.size(), false);
        queue<int> keys;
        int visit_cnt = 0;

        keys.push(0);

        while(!keys.empty()){
            int curr_room = keys.front();
            keys.pop();

            if(visited_room[curr_room]) continue;

            visit_cnt ++;
            visited_room[curr_room] = true;

            for(auto& k : rooms[curr_room]){
                if(visited_room[k]) continue;
                keys.push(k);
            }
        }

        return visit_cnt == rooms.size();
    }

    void parseAndSolve(string a){
        vector<vector<int>> ra;
        vector<int> buf;
        for(int i = 1; i < a.length()-1; i ++){
            if(a[i] == ']'){
                ra.push_back(buf);
                buf.clear();
            }else if (a[i] == ',' || a[i] == '['){
                continue;
            }else{
                buf.push_back((int)(a[i] - '0'));
            }
        }

        int c = canVisitAllRooms(ra);
        cout << c << endl;
    }

    void print(vector<vector<int>> a){
        for(auto & it : a){
            for(auto& e : it){
                cout << e << ' ';
            }
            cout << endl;
        }
    }
};

int main(){
    Solution s;

    // cout << s.canVisitAllRooms();

    s.parseAndSolve("[[1],[2],[3],[]]");
    s.parseAndSolve("[[1,3],[3,0,1],[2],[0]]");

    return 0;
}