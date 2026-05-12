class StockSpanner {
public:
    StockSpanner() = default;
    
    int next(const int& price) noexcept {
        if (monotonic_stack.empty()) {
            monotonic_stack.push({ price, 1 });
            return 1;
        }

        int span{ 1 };
        while (!monotonic_stack.empty() && monotonic_stack.top().first <= price) {
            span += monotonic_stack.top().second;
            monotonic_stack.pop();
        }

        monotonic_stack.push({ price, span });
        return span;
    }

private:
    std::stack<std::pair<int, int>> monotonic_stack{};
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */