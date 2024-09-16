#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        if(chars.size() == 0){
            return 0;
        }

        chars.push_back(0);
        char prev = chars[0];
        int cons = 1;
        int sum = 0;
        int end = 0;

        for(int i = 1; i < chars.size(); i ++){
            if(chars[i] == chars[i-1]){
                ++ cons;
            }else{
                chars[end++] = chars[i-1];
                if(cons != 1){
                    auto intString = std::to_string(cons);
                    for(int j = 0; j < intString.size(); j ++, end ++){
                        chars[end] = intString[j];
                        sum ++;
                    }
                }
                sum ++;
                cons = 1;
            }
        }

        chars.resize(sum);

        return sum;
    }
};