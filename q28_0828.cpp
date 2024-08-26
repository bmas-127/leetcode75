#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        map<char, int> skip;
        map<char, bool> all_dead;
        
        skip['R'] = 0;
        skip['D'] = 0;

        vector<bool> is_dead(senate.size(), false);        

        while(true){
            all_dead['R'] = true;
            all_dead['D'] = true;

            int cnt = 0;
            for(auto& s : senate){
                if(skip[s] > 0 && !is_dead[cnt]){
                    skip[s] --;
                    is_dead[cnt] = true; 
                }

                if(!is_dead[cnt]){
                    auto rival = (s == 'R') ? 'D' : 'R';
                    all_dead[s] = false;
                    skip[rival] ++;
                }

                cnt ++;
            }

            if(all_dead['R'] == true){
                return "Dire";
            }else if(all_dead['D'] == true){
                return "Radiant";
            }

        }
        
    }
};