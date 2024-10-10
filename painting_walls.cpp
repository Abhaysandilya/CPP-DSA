#include <bits/stdc++.h>
using namespace std;
int helper(int i, int remain, vector<vector<int>> & memo,
           vector<int> &cost, vector<int> &time) {
    if (remain <= 0) return 0;
    if (i == cost.size()) return 1e9;
    if (memo[i][remain] != -1) return memo[i][remain];

    int paint = cost[i] + helper(i + 1, remain - 1
               - time[i], memo, cost, time);
    int dontPaint = helper(i + 1, remain, memo, cost,
                           time);
    memo[i][remain] = min(paint, dontPaint);
    return memo[i][remain];
}
int minCost(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    return helper(0, n, memo, cost, time);
}

int main() {
    vector<int> cost1 = {1, 2, 3, 2};
    vector<int> time1 = {1, 2, 3, 2};
    cout << "Minimum cost: " << minCost(cost1, time1)
         << endl;

    return 0;
}

