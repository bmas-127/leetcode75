#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int initMax = 0;
        int windows = 0;
        for(int i = 0; i < s.size() && i < k; i ++){
            windows += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
        }   
        
        initMax = windows;

        for(int i = k; i < s.size(); i ++){
            windows += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
            windows -= (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u');
            initMax = std::max(initMax, windows);
        }

        return initMax;
    }
};