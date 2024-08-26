#include <iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int *arr = new int [max(n+1, 4)];

        arr[0] = 0;
        arr[1] = arr[2] = 1;

        for(int i = 3; i <=n; i ++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }

        return arr[n];
    }
};

int main(){
    Solution s;

    cout << s.tribonacci(1) << endl;
    cout << s.tribonacci(25) << endl;

    return 0;
}