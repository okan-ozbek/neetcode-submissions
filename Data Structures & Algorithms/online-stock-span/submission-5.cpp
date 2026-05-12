class StockSpanner {
public:
    StockSpanner() = default;
    
    int next(int price) {
        if (s.empty()) {
            s.push({price, 1});
            return 1;
        }

        int val{1};
        while (s.empty() == false && s.top().first <= price) {
            auto p = s.top();
            val += p.second;
            s.pop();
        }

        s.push({price, val});
        return val;
        // const_s.push(price);
        // s = const_s;

        // int c{};
        // while (s.empty() == false) {
        //     if (s.top() <= price) {
        //         s.pop();
        //         c++;
        //     }
        //     else {
        //         return c;
        //     }
        // }

        // return c;
    }

private:
    std::stack<std::pair<int, int>> s{};

    // std::stack<int> s{};
    // std::stack<int> const_s{};
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */