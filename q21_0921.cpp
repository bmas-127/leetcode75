#include <vector>
#include <map>
#include <set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        return mapMethod(arr);
    }

    bool sortMethod(std::vector<int> &arr){
        std::sort(arr.begin(), arr.end());
        std::set<int> occurence;

        int prev = arr[0] - 1;
        int cnt = 0;

        for(auto& cur : arr){
            if(prev == cur){
                cnt ++;
            }else{
                if(occurence.find(cnt) != occurence.end()){
                    return false;
                }

                occurence.insert(cnt);
                cnt = 1;
            }

            prev = cur;
        }

        return (occurence.find(cnt) != occurence.end());
    }

    bool mapMethod(std::vector<int>& arr){
        std::unordered_map <int, int> valueToOccurence;
        std::set<int> occurence;

        for(auto& a : arr){
            valueToOccurence[a] += 1;
        }

        for(auto& p : valueToOccurence){
            if(occurence.find(p.second) != occurence.end()){
                return false;
            }
            occurence.insert(p.second);
        }

        return true;
    }
};