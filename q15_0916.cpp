#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int initMax = 0;
        int windows = 0;
        for(int i = 0; i < s.size() && i < k; i ++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                windows++;
                s[i] = 'a';
            }
        }   
        
        initMax = windows;

        for(int i = k; i < s.size(); i ++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                windows++;
                s[i] = 'a';
            }
            windows -= (s[i-k] == 'a');
            initMax = std::max(initMax, windows);
        }

        return initMax;
    }
};