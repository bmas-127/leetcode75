#include <vector>


class StockSpanner {
    std::vector<int> history_price{};
    std::vector<int> local_max{};
    std::vector<int> local_min{};
    int day = 0;
    bool y_higher = true;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        history_price.push_back(price);

        if(day > 0){
            if(price < history_price[day-1]){
                // cout << "*" << day << "*" << endl;
                if(y_higher){
                    // cout << day - 1 << endl;
                    local_max.push_back(day-1);
                    y_higher = false;
                }
                day ++;
                return 1;
            }else if (price > history_price[day-1]){
                y_higher = true;
            }
            return find_span(price);
        }

        day ++;

        return 1;
    }

    int find_span(int today_price){
        int span = 1;
        int start = day;
        int end = day;

        for(auto price = local_max.rbegin(); price != local_max.rend(); ++ price){
            start = *price;
            if(today_price < history_price[start]){
                break;
            }
            span = span + end - start;
            end = start;
        }

        if(end == start && start != 0){
            start = -1;
        }

        for(int i = end - 1; i > start; i --){
            if(history_price[i] > today_price){
                break;
            }
            span ++;
        }

        day ++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */