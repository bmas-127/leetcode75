#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        if(chars.size() == 0){
            return 0;
        }

        chars.push_back(0);
        char prev = chars[0];
        int cons = 0;
        int sum = 0;

        for(const auto& c : chars){
            if(c == prev){
                ++ cons;
            }else{
                sum ++;
                if(cons != 1){
                    while(cons > 0){
                        sum ++;
                        cons /= 10;
                    }
                    cons = 1;
                }
            }

            prev = c;
        }
        
        return sum;
    }
};