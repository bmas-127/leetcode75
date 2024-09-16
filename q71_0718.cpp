#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ra;

        sort(products.begin(), products.end());

        int startpoint = 0;

        for(int i = 0; i < searchWord.size(); i ++){
            vector<string> line{};
            char c = searchWord[i];
            
            int cnt = 0;
            bool collect = false;
            for(int s = startpoint; cnt < 3 && s < products.size(); s++){
                if(i < products[s].size() && products[s][i] == c && products[s].substr(0, max(i-1, 0)) == searchWord.substr(0, max(i-1, 0))){
                    if(!collect){
                        startpoint = s;
                    }
                    collect = true;
                    line.push_back(products[s]);
                    cnt ++;
                }else if(collect){
                    break;
                }
            }

            if(cnt == 0) break;

            ra.push_back(line);            
        }

        while(ra.size() < searchWord.size()){
            ra.push_back({});
        }
        
        return ra;
    }
};