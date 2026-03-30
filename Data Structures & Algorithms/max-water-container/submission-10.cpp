class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left{0};
        int right{heights.size() - 1};

        int result{0};

        while (left < right) {
        
            result = std::max(
                result, 
                ((right - left) * std::min(heights[left], heights[right]))
            );

            if (heights[left] > heights[right]) {
                --right;
            } else {
                ++left;
            }
        }

        return result;
    }

    
};
