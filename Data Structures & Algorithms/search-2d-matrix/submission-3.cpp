class Solution {
public:
    //
    // My attempt: This was log(n) + log(m)
    //
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int ml{ 0 }; int mr = matrix[0].size() - 1;
    //     int nl{ 0 }; int nr = matrix.size() - 1;

    //     int nmm{ 0 };

    //     while(nl <= nr) {
    //         int nm{ (nl + nr) / 2 };

    //         if (matrix[nm][ml] == target || matrix[nm][mr] == target) {
    //             return true;
    //         }

    //         if (matrix[nm][ml] <= target && matrix[nm][mr] >= target) {
    //             nmm = nm;
    //             break;
    //         } else {
    //             if (matrix[nm][ml] < target) {
    //                 nl = nm + 1;
    //             } else {
    //                 nr = nm - 1;
    //             }
    //         }
    //     }

    //     while(ml <= mr) {
    //         int mm{ (ml + mr) / 2 };

    //         if (matrix[nmm][mm] == target) {
    //             return true;
    //         }

    //         if (matrix[nmm][mm] < target) {
    //             ml = mm + 1;
    //         } else {
    //             mr = mm - 1;
    //         }
    //     }
        
    //     return false;
    // }

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left{ 0 };
        int right{ m * n - 1 }; 

        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }

            else if (matrix[row][col] > target) {
                right = mid - 1;
            }
            
            else {
                left = mid + 1;
            }
        }

        return false;
    }
};
