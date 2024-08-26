#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    std::map<char, std::string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> rlist;
        bool first = true;

        for(auto &c : digits){
            if(first){
                for(auto &l : m[c]){
                    std::string f = "f";
                    f[0] = l;
                    rlist.push_back(f);
                }
                first = false;
            }else{
                vector<string> newlist;

                for(auto &it : rlist){
                    for(auto &l : m[c]){
                        newlist.push_back(it + l);
                    }
                }

                rlist = std::move(newlist);
            }
        }

        return rlist;
    }
};