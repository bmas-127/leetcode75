#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ra("");
        int i = 0;
        
        if(s == ""){
            return "";
        }else if(s[0] >= 'a'){
            while(s[i] >= 'a'){
                ra = ra + s[i++];
            }
            if(i == s.size()){
                return ra;
            }else{
                return ra + decodeString(s.substr(i, s.size() - i));
            }
        }

        int ratio = 0;
        for(i = 0; i < s.size() && s[i] >= '0' && s[i] <= '9'; i ++){
            ratio = ratio * 10 + (s[i] - '0');
        }

        int tmp_start = ++i;
        int left = 1;
        while(left > 0){
            if(s[i] == '['){
                left ++;
            }else if(s[i] == ']'){
                left --;
            }
            i ++;
        }

        string next = decodeString(s.substr(tmp_start, i - tmp_start - 1));
        while(ratio > 0){
            ra = ra + next;
            ratio --;
        }

        return ra + decodeString(s.substr(i, s.size() - i));
    }
};

int main(){
    string a("3[a]2[bc]"), b("3[a2[c]]"), c("2[abc]3[cd]ef");
    Solution S;

    cout << S.decodeString(a) << endl;
    cout << S.decodeString(b) << endl;
    cout << S.decodeString(c) << endl;

    return 0;
}