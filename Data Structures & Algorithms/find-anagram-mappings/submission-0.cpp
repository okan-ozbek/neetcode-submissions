class Solution {
public:
    using value_t = int;
    using index_t = int;

    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<value_t, index_t> table(nums1.size());
        std::vector<int> mapping(nums1.size());

        for (size_t i{}; i < nums2.size(); ++i) {
            table[nums2[i]] = i;
        }

        for (size_t i{}; i < nums1.size(); ++i) {
            mapping[i] = (table[nums1[i]]); 
        }

        return mapping;
    }
};
