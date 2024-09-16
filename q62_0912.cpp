class Solution {
public:
    int numTilings(int n) {
        long* tile = new long [n];

        tile[0] = 1;

        if(n > 1){
            tile[1] = 2;
        }

        if(n > 2){
            tile[2] = 5;
        }

        for(int i = 3; i < n; i ++){
            tile[i] = (2 * tile[i - 1] + tile[i - 3] )% 1000000007;
        }

        return (int) tile[n-1];
    }
};