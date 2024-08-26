#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> barray(n + 1);
        barray[0] = 0;
        if(n == 0) return barray;
        barray[1] = 1;
        if(n == 1) return barray;

        int start = 2;
        while(start <= n){
            int up = min(start * 2, n + 1);
            for(int i = start; i < up; i ++){
                barray[i] = barray[i - start] + 1;
            }
            start *= 2;
        }

        return barray;
    }
};