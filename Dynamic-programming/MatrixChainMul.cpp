//Problem statement: Given the dimension of a sequence of matrices in an array arr[], 
//where the dimension of the ith matrix is (arr[i-1] * arr[i]).
//the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

#include <bits/stdc++.h>
using namespace std;

void MatrixChainOrder(int p[], int n)
{

	int m[n][n];

	int i, j, k, L, q;

	for (i = 1; i < n; i++)
		m[i][i] = 0;

	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	cout<< m[1][n - 1]<<endl;;
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	MatrixChainOrder(arr, size);
	return 0;
}

