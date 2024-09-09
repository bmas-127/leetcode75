#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ra;
        ra.push_back({});
        ra.push_back({});

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        int prev_i = -1001, prev_j = -1001;

        while(i < nums1.size() || j < nums2.size()){
            if(i == nums1.size()){
                for(; j < nums2.size(); j ++){
                    if(nums2[j] != prev_j){
                        prev_j = nums2[j];
                        ra[1].push_back(prev_j);
                    }
                }
            }else if(j == nums2.size()){
                for(; i < nums1.size(); i ++){
                    if(nums1[i] != prev_i){
                        prev_i = nums1[i];
                        ra[0].push_back(prev_i);
                    }
                }
            }else if(nums1[i] < nums2[j]){
                ra[0].push_back(nums1[i]);
                while(++i < nums1.size() && nums1[i] == nums1[i - 1]);
            }else if(nums1[i] > nums2[j]){
                ra[1].push_back(nums2[j]);
                while(++j < nums2.size() && nums2[j] == nums2[j - 1]);
            }else{
                prev_i = prev_j = nums1[i];
                while(++i < nums1.size() && nums1[i] == prev_i);
                while(++j < nums2.size() && nums2[j] == prev_j);
            }
        }




        return ra;
    }
};