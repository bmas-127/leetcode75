#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        m --;
        n --;

        int c = m + n;
        n = std::min(m, n);
        double rst = 1;

        for(int i = 0; i < n; i ++){
            rst *= (c - i);
            rst /= (i + 1);
        }

        return (int) rst;
    }
};

