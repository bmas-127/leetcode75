#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> comb;
    vector<int> c;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        c.resize(k);
        findComb(0, k, n);

        return comb;
    }

    void findComb(int start_num, int k, int n){
        if(start_num < n && k > 0){
            if(k == 1 && n <= 9){
                *(c.end()-1) = n;
                print();
                comb.push_back(c);
            }

            for(int i = start_num + 1; i < 9; i ++){
                *(c.end()-k) = i;
                findComb(i, k-1, n-i);
            }
        }

    }

    void print(){
        for(auto a : c){
            cout << a << ' ';
        }
        cout << endl;
    }
};




int main(){
    Solution s;

    auto v = s.combinationSum3(3, 7);


    return 0;
}