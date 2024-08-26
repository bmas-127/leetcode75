#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int *score = new int [(word1.length() + 1) * (word2.length() + 1)];
        int matrix_width = word2.length() + 1;

        for(int i = 0; i <= word1.length(); i ++){
            score[i * matrix_width] = i;
        }

        for(int j = 0; j < matrix_width; j ++){
            score[j] = j;
        }

        for(int i = 1; i <= word1.length(); i ++){
            for(int j = 1; j < matrix_width; j ++){
                int is_match = (word1[i-1] == word2[j-1]) ? 0 : 1;
                score[i * matrix_width + j] = min(score[(i-1) * matrix_width + j] + 1,
                    min(score[i * matrix_width + j - 1] + 1, score[(i-1) * matrix_width + j - 1] + is_match)
                );
            }
        }

        // print(score, word1.length(), word2.length());
        // cout << (word1.length() + 1) * matrix_width - 1 << endl;
        return score[(word1.length() + 1) * matrix_width - 1];
    }

    void print(int* score, int row, int col){
        for(int i = 0; i <= row; i ++){
            for(int j = 0; j <= col; j ++){
                cout << score[i * (col + 1) + j] << '\t';
            }
            cout << endl;
        }
    }
};

int main(){
    Solution s;

    cout << s.minDistance("horse", "ros") << endl;


    return 0;
}