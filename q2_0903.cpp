#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        vector<int> factor;
        
        int n1 = str1.size();
        int n2 = str2.size();

        int g = gcd(n1, n2);

        collectFactor2(factor, g);

        for(auto it = factor.crbegin(); it != factor.crend(); ++ it){
            auto len = *it;
            bool found = true;

            string g = str1.substr(0, len);
            int cnt = len;


            while(cnt < n1){
                if(str1.substr(cnt, len) != g){
                    found = false;
                    break;
                }
                cnt += len;
            }

            cnt = 0;
            while(found && cnt < n2){
                if(str2.substr(cnt, len) != g){
                    found = false;
                }
                cnt += len;
            }

            if(found){
                return g;
            }
        }

        

        return "";
    }

    void collectFactor(vector<int>& factor, int g){
        bool is_prime = false;
        factor.push_back(1);
        while(g > 1 && !is_prime){
            // cout << g << endl;
            for(int i = 2; i * i < g + 2; i ++){
                if(g % i == 0){
                    while(g % i == 0){
                        g /= i;
                    }
                    factor.push_back(i);
                    break;
                }
                is_prime = true;
            }
        }

        if(g != 1)
            factor.push_back(g);
    }


    void collectFactor2(vector<int>& factor, int g){
        for(int i = 1; i <= g; i ++){
            if(g % i == 0){
                factor.push_back(i);
            }
        }
    }

    int gcd(int n1, int n2){
        if(n2 == 0){
            return n1;
        }

        if(n2 > n1){
            return gcd(n1, n2 % n1);
        }else{
            return gcd(n2, n1 % n2);
        }
    }
};

int main(){
    Solution s;

    cout << s.gcdOfStrings("ABCABC", "ABC") << endl;
    cout << s.gcdOfStrings("ABABAB", "AB") << endl;
    cout << s.gcdOfStrings("LEET", "LEET") << endl;
    cout << s.gcdOfStrings("LEET", "CODE") << endl;
    cout << s.gcdOfStrings("LEETL", "CODELEL") << endl;


    return 0;
}
