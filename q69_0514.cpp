#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int case1 = (uint)(~a & ~b & c);
        int case2 = (uint)((a | b) & (~c));
        int case3 = (uint)((a & b & ~c));

        int cnt = 0;
        for(int i = 0; i < 32; i ++){
            cnt += (case1 % 2) ? 1 : 0;
            cnt += (case2 % 2) ? 1 : 0;
            cnt += (case3 % 2) ? 1 : 0;
            case1 /= 2;
            case2 /= 2;
            case3 /= 2;
        }
        
        return cnt;
    }
};

int main(){
    Solution s;

    cout << s.minFlips(2, 6, 5) << endl;
    cout << s.minFlips(1, 2, 3) << endl;


    return 0;
}