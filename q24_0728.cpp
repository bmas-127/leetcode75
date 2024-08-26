#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int end = 0;

        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '*'){
                end --;
            }else{
                s[end++] = s[i];
            }
        }

        return s.substr(0, end);
    }
};