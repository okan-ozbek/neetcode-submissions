class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::tuple<int, int>> temps{};
        std::vector<int> ans(temperatures.size(), 0);

        for(int i{}; i < temperatures.size(); ++i) {
            if (temps.size() > 0) {
                while(temps.size() > 0) {
                    std::tuple<int, int> temp = temps.top();

                    if (std::get<1>(temp) < temperatures[i]) {
                        temps.pop();
                    } else {
                        break;
                    }

                    ans[std::get<0>(temp)] = i - std::get<0>(temp);
                }
            }

            std::cout << "Inserting: " << i << ", " << temperatures[i] << std::endl;

            temps.push(std::make_tuple(i, temperatures[i]));
        }

        return ans;
    }
};
