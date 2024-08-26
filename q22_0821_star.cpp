#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> charNumMap1, charNumMap2;
        set<char> characterSet1, characterSet2;
        multiset<int> s1, s2;

        for(auto& c : word1){
            charNumMap1[c] += 1;
        }

        // for(auto& it : charNumMap1){
        //     cout << it.first << " : " << it.second << endl;
        // }

        for(auto& c : word2){
            charNumMap2[c] += 1;
        }

        if(charNumMap1.size() != charNumMap2.size()){
            return false;
        }

        for(auto it = charNumMap1.begin(), jt = charNumMap2.begin(); it != charNumMap1.end(); ++it, ++jt){
            if(it->first != jt->first){
                return false;
            }
            s1.insert(it->second);
            s2.insert(jt->second);
        }

        for(auto it = s1.begin(), jt = s2.begin(); it != s1.end(); ++it, ++jt){
            if(*it != *jt){
                return false;
            }
        }


        return true;        
    }
};

int main(){
    string a("sdj;lfkjsda;lfasjdf;dsajkf");
    string b("sdj;fasjdf;asajlfkjsda;lkf");


    Solution s;

    cout << s.closeStrings(a, b) << endl;
    cout << "---------" << endl;

    cout << s.closeStrings("a", "b") << endl;
    cout << "---------" << endl;
    cout << s.closeStrings("ACCCBB", "ABBBCC") << endl;
    cout << "---------" << endl;
    cout << s.closeStrings("abc", "cba") << endl;


    return 0;
}