#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        multiset<int> charNumSet1, charNumSet2;
        set<char> characterSet1, characterSet2;
        
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        countCharacter(word1, charNumSet1, characterSet1);
        countCharacter(word2, charNumSet2, characterSet2);

        // for(auto c : characterSet1){
        //     cout << c;
        // }
        // cout << endl;

        // for(auto c : characterSet2){
        //     cout << c;
        // }
        // cout << endl;

        // for(auto c : charNumSet1){
        //     cout << c;
        // }
        // cout << endl;

        // for(auto c : charNumSet2){
        //     cout << c;
        // }
        // cout << endl;


        // cout << charNumSet1.size() << endl;
        // cout << charNumSet2.size() << endl;
        // cout << characterSet1.size() << endl;
        // cout << characterSet2.size() << endl;

        if(charNumSet1.size() != charNumSet2.size() || characterSet1.size() != characterSet2.size()){
            return false;
        }

        for(auto it = charNumSet1.begin(), jt = charNumSet2.begin(); it != charNumSet1.end(); ++it, ++jt){
            if(*it != *jt){
                return false;
            }
        }


        for(auto it = characterSet1.begin(), jt = characterSet2.begin(); it != characterSet1.end(); ++it, ++jt){
            if(*it != *jt){
                return false;
            }
        }


        return true;
    }

    void countCharacter(const string& word1, multiset<int>& charNumSet1, set<char>& characterSet1){
        char prev = word1[0];
        int cnt = 0;
        for(auto& c : word1){
            if(c != prev){
                charNumSet1.insert(cnt);
                characterSet1.insert(prev);
                cnt = 0;
            }
            cnt ++;
            prev = c;
        }
        charNumSet1.insert(cnt);
        characterSet1.insert(*(word1.end()-1));
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