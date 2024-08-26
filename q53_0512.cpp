
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long low = 1;
        long high = (long) n + 1;

        while(1){
            int mid = (int)((low + high) / 2);
            int guessnum = guess(mid);

            if(guessnum == 0){
                return mid;
            }else if(guessnum == 1){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
    }
};