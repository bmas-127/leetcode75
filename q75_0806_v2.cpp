#include <vector>


class StockSpanner {
    std::vector<int> history_price{};
    std::vector<int> cont{};
    int day = 0;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        history_price.push_back(price);

        if(day > 0){       
            bool up = (cont[day - 1] >= 0);     
            if(price >= history_price[day - 1]){
                int up_time = (up) ? cont[day - 1] : 0;
                cont.push_back(up_time + 1);
                span = find_span(price);
            }else{
                int down_time = (up) ? 0 : cont[day - 1];
                cont.push_back(down_time - 1);
            }

        }else{
            cont.push_back(0);
        }

        day ++;
        return span;
    }

    int find_span(int today_price){
        int span = 1;
        int end = day;
        int start = day;


        while(true){
            span += cont[end];
            end -= cont[end];

            if(end <= 0){
                break;
            }

            start = end + cont[end];
            
            if(today_price >= history_price[start]){
                span -= cont[end];
                end = start;
            }else{
                break;
            }
        }

        for(int i = end-1; i > start; i --){
            if(history_price[i] > today_price){
                break;
            }
            span ++;
        }

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */