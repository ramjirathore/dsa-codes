// PROBLEM - 

// Given two sequences, print the longest subsequence present in both of them.

// LINK - https://www.geeksforgeeks.org/printing-longest-common-subsequence/
// SOLUTION - https://www.youtube.com/watch?v=x5hQvnUcjiM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=23

// Approach - O(m*n) time and space
// This problem is just an extension of the find LCS
// We basically retrace path from the last and check if the last character of both strings match
// if yes, then we move back diagonally else to that cell where the value is more 
// Until we reach the first row or first column of matrix

/* Dynamic Programming implementation of LCS problem */
#include<bits/stdc++.h>
using namespace std;

void lcs(string &s1, string &s2, int m, int n)
{
	int t[m+1][n+1];

	// filling the matrix
	for (int i=0; i<m+1; i++)
	{
		for (int j=0; j<n+1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (s1[i-1] == s2[j-1]) // if equal then add 1 to previous answer
				t[i][j] = t[i-1][j-1] + 1; 
			else
				t[i][j] = max(t[i-1][j], t[i][j-1]); // else leave last character of either string and find max
		}
	}


	int i = m, j = n;

	string res = "";

	while(i > 0 && j > 0) {
		if(s1[i-1] == s2[j-1]) {
			res.push_back(s1[i-1]);
			i--;
			j--;
		} else {
			if(t[i][j-1] > t[i-1][j]) {
				j--;
			} else {
				i--;
			}
		}
	}

	reverse(res.begin(), res.end());
	cout<<"LCS: "<<res;
}

int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	int m = X.length();
	int n = Y.length();
	lcs(X, Y, m, n);
	return 0;
}
