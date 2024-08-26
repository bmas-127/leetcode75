#include <vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int altitude = 0;
        int record = 0;

        for(auto& g : gain){
            altitude += g;
            record = std::max(record, altitude);
        }
        
        return record;
    }
};