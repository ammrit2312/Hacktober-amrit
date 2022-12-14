//Problem statement: There are N houses built in a line, each of which contains some value in it. 
//A thief is going to steal the maximal value of these houses, but he can’t steal in two adjacent houses because the owner of 
//the stolen houses will tell his two neighbors left and right sides. The task is to find what is the maximum stolen value.

#include <iostream>
using namespace std;
 
int maxLoot(int* hval, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return hval[0];
    if (n == 2)
        return max(hval[0], hval[1]);

    int dp[n];
 
    dp[0] = hval[0];
    dp[1] = max(hval[0], hval[1]);
 
    for (int i = 2; i < n; i++)
        dp[i] = max(hval[i] + dp[i - 2], dp[i - 1]);
 
    return dp[n - 1];
}
 
int main()
{
    int hval[] = { 6, 7, 1, 3, 8, 2, 4 };
    int n = sizeof(hval) / sizeof(hval[0]);
    cout << "Maximum loot possible : " << maxLoot(hval, n);
    return 0;
}
 
