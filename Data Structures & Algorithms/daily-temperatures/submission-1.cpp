class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::tuple<int, int>> temperature_stack{};
        std::vector<int> answers(temperatures.size(), 0);

        for(int i{}; i < temperatures.size(); ++i) {
            while(temperature_stack.size() > 0 && std::get<1>(temperature_stack.top()) < temperatures[i]) {
                auto temperature{temperature_stack.top()}; 
                temperature_stack.pop();

                answers[std::get<0>(temperature)] = i - std::get<0>(temperature);
            }

            temperature_stack.push(std::make_tuple(i, temperatures[i]));
        }

        return answers;
    }
};
