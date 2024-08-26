#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;

        if(s == "") return true;

        for(auto &c : t){
            if(c == s[idx]){
                idx ++;
                if(idx == s.size()){
                    return true;
                }
            }
        }

        return false;
        
    }
};