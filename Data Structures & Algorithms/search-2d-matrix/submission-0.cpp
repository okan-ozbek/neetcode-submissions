class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ml{0}; int mr = matrix[0].size() - 1;
        int nl{0}; int nr = matrix.size() - 1;

        int nmm{0};

        while(nl <= nr) {
            int nm = ((nl + nr) / 2);

            if (matrix[nm][ml] <= target && matrix[nm][mr] >= target) {
                nmm = nm;
                break;
            } else {
                if (matrix[nm][ml] < target) {
                    nl = nm + 1;
                } else {
                    nr = nm - 1;
                }
            }
        }

        while(ml <= mr) {
            int mm = ((ml + mr) / 2);

            if (matrix[nmm][mm] == target) {
                return true;
            }

            if (matrix[nmm][mm] < target) {
                ml = mm + 1;
            } else {
                mr = mm - 1;
            }
        }
        
        return false;
    }
};
