#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int beginIdx = 0;
        int endIdx = s.size() - 1;

        if(s.size() == 1){
            return s;
        }

        while(true){
            while(beginIdx < s.size() && !(s[beginIdx] == 'a' || s[beginIdx] == 'e' || s[beginIdx] == 'i' || s[beginIdx] == 'o' || s[beginIdx] == 'u' \
            || s[beginIdx] == 'A' || s[beginIdx] == 'E' || s[beginIdx] == 'I' || s[beginIdx] == 'O' || s[beginIdx] == 'U')){
                beginIdx ++;
            } 
            while(endIdx >= 0 && !(s[endIdx] == 'a' || s[endIdx] == 'e' || s[endIdx] == 'i' || s[endIdx] == 'o' || s[endIdx] == 'u' \
            || s[endIdx] == 'A' || s[endIdx] == 'E' || s[endIdx] == 'I' || s[endIdx] == 'O' || s[endIdx] == 'U')){
                endIdx --;
            } 

            if(beginIdx >= endIdx){
                break;
            }

            swap(s[beginIdx], s[endIdx]);
            beginIdx ++;
            endIdx --;
        }

        return s;
    }
};