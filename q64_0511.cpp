#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int matrix_width = text1.length() + 1;
        int matrix_height = text2.length() + 1;
        vector<int> dp(matrix_width * matrix_height, 0);

        for(int i = 1; i < matrix_height; i ++){
            for(int j = 1; j < matrix_width; j ++){
                int match = (text2[i-1] == text1[j-1]) ? 1 : 0;

                dp[i * matrix_width + j] = max(dp[(i-1) * matrix_width + j - 1] + match,
                    max(dp[(i-1) * matrix_width + j], dp[i * matrix_width + j - 1])
                );
            }
        }

        return dp[matrix_width * matrix_height -1];
    }
};


int main(){
    Solution s;

    cout << s.longestCommonSubsequence("abcde", "ace") << endl;
    cout << s.longestCommonSubsequence("abc", "abc") << endl;
    cout << s.longestCommonSubsequence("abc", "def") << endl;

    return 0;
}