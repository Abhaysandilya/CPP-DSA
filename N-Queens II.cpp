#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    bool isCol[10], isPrimary[20], isSecondary[20];

    int solve(int rowNo, int n)
    {
        if (rowNo == n) {
            return 1;
        }
        int ans = 0;
        for (int colNo = 0; colNo < n; colNo++) {
            if (!isCol[colNo] && !isPrimary[rowNo + colNo]
                && !isSecondary[rowNo - colNo + 10]) {
                isCol[colNo] = isPrimary[rowNo + colNo]
                    = isSecondary[rowNo - colNo + 10]
                    = true;

                ans += solve(rowNo + 1, n);

                isCol[colNo] = isPrimary[rowNo + colNo]
                    = isSecondary[rowNo - colNo + 10]
                    = false;
            }
        }
        return ans;
        return ans;
    }

    int totalNQueens(int n)
    {

        if (n == 1)
            return 1;
        if (n <= 3)
            return 0;
        return solve(0, n);
    }
};


int main()
{
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
    return 0;
}
