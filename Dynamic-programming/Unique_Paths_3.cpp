/*

    Basically its Giving the minimum path sum to reach from
    (0 , 0) --> (N , M)

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define SIZE(v) (int)v.size()
#define MOD 1000000007

#define TC(t) while (t--)

void solve()
{

    return;
}

int recurSolve(vvi &grid, int rowLimit, int colLimit, int row, int col)
{
    if (row == rowLimit - 1 && col == colLimit - 1)
    {
        return grid[row][col];
    }

    else if (row >= rowLimit || col >= colLimit)
    {
        // Ok so here Problem was happening because I was returing INT_MAX
        /*
            Now for this Suppose we have 1 + INT_MAX .. it will result in out of range
            logical error,

            hence Be carefull with the limits

        */
        return 100010;
    }

    else
    {
        int down = grid[row][col] + recurSolve(grid, rowLimit, colLimit, row + 1, col);
        int right = grid[row][col] + recurSolve(grid, rowLimit, colLimit, row, col + 1);

        return min(down, right);
    }
}

int memoIzation(vvi &grid, vvi &dp, int rowLimit, int colLimit, int row, int col)
{
    if (row == (rowLimit - 1) && col == (colLimit - 1))
    {
        return grid[row][col];
    }

    else if (row >= rowLimit || col >= colLimit)
    {
        return 1e9;
    }

    else if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    else
    {
        int down = grid[row][col] + memoIzation(grid, dp, rowLimit, colLimit, row + 1, col);
        int right = grid[row][col] + memoIzation(grid, dp, rowLimit, colLimit, row, col + 1);

        return dp[row][col] = min(down, right);
    }
}

int tabulation(vvi &grid)
{
    int N = SIZE(grid);
    int M = SIZE(grid[0]);
    vvi dp(N, vi(M, 0));
    dp[N - 1][M - 1] = grid[N - 1][M - 1];

    for (int row = N - 1; row >= 0; row--)
    {
        for (int col = M - 1; col >= 0; col--)
        {
            if (row == N - 1 && col == M - 1)
            {
                dp[row][col] = grid[N - 1][M - 1];
                continue;
            }

            else
            {
                int left = row < (N - 1) ? grid[row][col] + dp[row + 1][col] : 1e9;
                int up = col < (M - 1) ? grid[row][col] + dp[row][col + 1] : 1e9;

                dp[row][col] = min(left, up);
            }
        }
    }

    return dp[0][0];
}
int solve(vvi &grid)
{
    int N = SIZE(grid);
    int M = SIZE(grid[0]);
    vvi dp(N, vi(M, -1));
    int ans = memoIzation(grid, dp, N, M, 0, 0);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    TC(t)
    {
        solve();
    }
    return 0;
}