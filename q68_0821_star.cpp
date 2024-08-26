#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> S;

        for(auto& num : nums){
            if(S.find(num) == S.end()){
                S.insert(num);
            }else{
                S.erase(num);
            }
        }

        return *S.begin();
        
    }
};