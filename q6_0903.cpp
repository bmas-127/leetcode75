#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string ra;
        int end_;
        bool contWordSearch = false;

        if(*(s.end()-1) == ' '){
            contWordSearch = false;
        }else{
            end_ = s.size();
            contWordSearch = true;
        }

        for(int i = s.size() - 2; i >= 0; i --){
            if(s[i] != ' ' && !contWordSearch){
                end_ = i + 1;
                contWordSearch = true;
            }else if(s[i] == ' ' && contWordSearch){
                ra += s.substr(i, end_ - i);
                contWordSearch = false;
            }
        }

        if(contWordSearch){
            ra = ra + " " + s.substr(0, end_);
        }
        
        return ra.substr(1, ra.size()-1);
    }
};