class StockSpanner {
public:
    StockSpanner() = default;
    
    int next(int price) {
        const_s.push(price);
        s = const_s;

        int c{};
        while (s.empty() == false) {
            if (s.top() <= price) {
                s.pop();
                c++;
            }
            else {
                return c;
            }
        }

        return c;
    }

private:
    std::stack<int> s{};
    std::stack<int> const_s{};
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */