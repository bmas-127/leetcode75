#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int skip[2] = {0}; // 0 -> R, 1 -> C


        while(senate.size() > 0){
            string nextRound("");

            for(auto&c : senate){
                auto s = (c == 'R') ? 0 : 1;
                auto rival = 1 - s;

                if(skip[s] > 0){
                    skip[s] --;
                }else{
                    skip[rival] ++;
                    nextRound.push_back(c);
                }
            }

            if(senate == nextRound){
                break;
            }


            senate = nextRound;

        }

        return (senate[0] == 'R') ? "Radiant" : "Dire";

    }
};