#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        bool frontEmpty = true;
        bool presentEmpty = (flowerbed[0] == 0);

        for(int i = 0; i < flowerbed.size() - 1 && n > 0; i ++){
            bool backEmpty = (flowerbed[i + 1] == 0);

            if(frontEmpty && presentEmpty && backEmpty){
                n --;
                frontEmpty = false;
            }else{
                frontEmpty = presentEmpty;
            }

            presentEmpty = backEmpty;
        }

        return (n == 0) || (n == 1) && frontEmpty && presentEmpty;
    }
};