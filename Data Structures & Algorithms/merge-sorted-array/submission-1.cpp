class Solution {
public:
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     for (std::size_t i{}; i < n; ++i) {
    //         nums1[m + i] = nums2[i];
    //     }

    //     for (std::size_t i{ 1 }; i < m + n; ++i) {
    //         std::size_t j{ i - 1 };

    //         while (j >= 0 && nums1[j + 1] < nums1[j]) {
    //             std::swap(nums1[j + 1], nums1[j]);
                
    //             if (j == 0) {
    //                 break;
    //             }
            
    //             --j;
    //         }
    //     }
    // }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last{ m + n - 1 };
        int i{ m - 1 }; 
        int j{ n - 1 };

        while (j >= 0) {
            nums1[last--] = (i >= 0 && nums1[i] > nums2[j]) 
                ? nums1[i--]
                : nums2[j--];
        }

    }
};