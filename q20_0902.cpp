#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ra;
        ra.push_back({});
        ra.push_back({});

        for(auto& n1 : s1){
            if(s2.find(n1) == s2.end()){
                ra[0].push_back(n1);
            }
        }

        for(auto& n2 : s2){
            if(s1.find(n2) == s1.end()){
                ra[1].push_back(n2);
            }
        }

        return ra;
    }
};