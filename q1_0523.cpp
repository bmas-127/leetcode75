#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ra{""};
        int l1 = min(word1.length(), word2.length());
        int l2 = max(word1.length(), word2.length());


        for(int i = 0; i < l1; i++){
            ra = ra + word1[i] + word2[i];
        }

        string remain = (l2 == word1.length()) ? word1 : word2;
        for(int i = l1; i < l2; i ++){
            ra += remain[i];
        }

        return ra;
    }
};