#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ra;

        for(auto& ast : asteroids){
            if(s.empty()){
                s.push(ast);
            }else{
                while(true){
                    if(s.top() > 0 && ast < 0){
                        if(s.top() < abs(ast)){
                            s.pop();
                            if(s.empty()){
                                s.push(ast);
                                break;
                            }
                        }else if(s.top() > abs(ast)){
                                break;
                        }else{
                            s.pop();
                            break;
                        }
                    }else{
                        s.push(ast);
                        break;
                    }
                }
            }
        }

        ra.resize(s.size());

        for(int i = s.size() - 1; !s.empty(); s.pop(), i --){
            ra[i] = s.top();
        }
        
        return ra;
        
    }
};

int main(){



    return 0;
}