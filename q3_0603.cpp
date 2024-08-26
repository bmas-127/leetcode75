#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto max_candy = *max_element(candies.begin(), candies.end());
        vector<bool> ans{};

        for(auto &kid : candies){
            ans.push_back(kid + extraCandies >= max_candy);
        }

        return ans;
    }
};