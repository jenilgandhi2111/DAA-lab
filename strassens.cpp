/************************************************************
* Written By:-     Jenil Gandhi
* Sem:-            CE 4
* Date:-           13/01/2021
* Roll no:-        CE038
* Subject:-        DAA(Design and Analysis of Algorithm)
* Guidance by:-    Prof Jigar Pandya
* Objective:-      Solve Matrix multiplication problem by using 
				   Strassens method.
* Problem description
  -------------------
  * Problem Statement:
     -> Given 2 N*N matrices multiply them using the strassen's 
	 	method , given log(N) is an integer.
  * Time complexity analysis
     -> O(N^2.8)
  * Space complexity analysis
     -> O(N^2)
  * Input format:
     -> First line provide no of testcases.
	 -> For each testcase provide N.
	 -> For each testcase provide 2 matrices of N*N.
  * Output format:
     -> A N*N matrix 
  * Limitations:
  	 -> The limitation of the above problem is that it only works when log(N)
	    is an integer otherwise it fails.
  * How to test?
  	 -> Input all the testcases in the 01_input.txt and then compile and run
	    outputs would be in 01_output.txt.
  * Testcases:
     -> Testcase-1
	 	1
		4
		1 1 1 1
		1 1 1 1
		1 1 1 1
		1 1 1 1
		2 2 2 2
		2 2 2 2
		2 2 2 2
		2 2 2 2 

		Output:
		8 8 8 8
		8 8 8 8
		8 8 8 8 
		8 8 8 8
	 
	 -> Testcase-2
		1
		8
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1 
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1
		1 1 1 1 1 1 1 1

		Output:
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 
		8 8 8 8 8 8 8 8 

************************************************************/

#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
	//functions for fast I/O
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("01_input.txt", "r", stdin);
    	freopen("01_output.txt", "w", stdout);
	#endif
}

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B)
{
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}
vector<vector<int>> sub(vector<vector<int>> A, vector<vector<int>> B)
{
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}

vector<vector<int>> clone(vector<vector<int>> A, int row_st, int col_st, int col_end)
{
	int size = col_end - col_st;
	vector<vector<int>> C(size, vector<int>(size, 0));
	for (int i = row_st; i < size + row_st; i++)
	{
		for (int j = col_st; j < col_end; j++)
		{
			C[i - row_st][j - col_st] = A[i][j];
		}
	}
	return C;
}
vector<vector<int>> assa(vector<vector<int>> c11, vector<vector<int>> c12, vector<vector<int>> c21, vector<vector<int>> c22, int n)
{
	vector<vector<int>> res(n, vector<int>(n, 0));
	int st = n / 2;
	for (int i = 0; i < st; i++)
	{
		for (int j = 0; j < st; j++)
		{
			res[i][j] = c11[i][j];
		}
	}
	for (int i = 0; i < st; i++)
	{
		for (int j = 0; j < st; j++)
		{
			res[i][st + j] = c12[i][j];
		}
	}
	for (int i = 0; i < st; i++)
	{
		for (int j = 0; j < st; j++)
		{
			res[i + st][j] = c21[i][j];
		}
	}
	for (int i = 0; i < st; i++)
	{
		for (int j = 0; j < st; j++)
		{
			res[i + st][j + st] = c22[i][j];
		}
	}
	return res;
}
vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b)
{
	int n = a.size();

	if (n <= 1)
	{
		vector<vector<int>> result(n, vector<int>(n));
		result[0][0] = a[0][0] * b[0][0];
		return result;
	}
	vector<vector<int>> result(n, vector<int>(n, 0));
	vector<vector<int>> a11(n / 2, vector<int>(n / 2, 0)), a12(n / 2, vector<int>(n / 2, 0)), a21(n / 2, vector<int>(n / 2, 0)), a22(n / 2, vector<int>(n / 2, 0));
	vector<vector<int>> b11(n / 2, vector<int>(n / 2, 0)), b12(n / 2, vector<int>(n / 2, 0)), b21(n / 2, vector<int>(n / 2, 0)), b22(n / 2, vector<int>(n / 2, 0));
	vector<vector<int>> d1, d2, d3, d4, d5, d6, d7, c1, c2, c3, c4;
	a11 = clone(a, 0, 0, n / 2);
	a12 = clone(a, 0, n / 2, n);
	a21 = clone(a, n / 2, 0, n / 2);
	a22 = clone(a, n / 2, n / 2, n);
	b11 = clone(b, 0, 0, n / 2);
	b12 = clone(b, 0, n / 2, n);
	b21 = clone(b, n / 2, 0, n / 2);
	b22 = clone(b, n / 2, n / 2, n);
	d1 = strassen(add(a11, a22), add(b11, b22));
	d2 = strassen(add(a21, a22), b11);
	d3 = strassen(a11, sub(b12, b22));
	d4 = strassen(a22, sub(b21, b11));
	d5 = strassen(add(a11, a12), b22);
	d6 = strassen(sub(a21, a11), add(b11, b12));
	d7 = strassen(sub(a12, a22), add(b21, b22));
	c1 = add(sub(add(d1, d4), d5), d7);
	c2 = add(d3, d5);
	c3 = add(d2, d4);
	c4 = add(d1, d3);
	c4 = sub(c4, d2);
	c4 = add(c4, d6);
	result = assa(c1, c2, c3, c4, n);
	return result;
}
int main()
{

	c_p_c();
	int tc;
	cin >> tc;
	cout<<"---------------------------------------------------------\n";
	while (tc--)
	{
		int n;
		cin >> n;
		int pw = log2(n);
		if (pow(2, pw) != n)
		{
			cout << "this algorithm only use for matrix multiplicatopn whose degree is power of  2 and it should be sqaure matrix ";
			continue;
		}
		vector<vector<int>> A(n, vector<int>(n, 0)), B(n, vector<int>(n, 0)), result(n, vector<int>(n)), temp;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> A[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> B[i][j];

		temp = strassen(A, B);
		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				cout << temp[i][j] << " ";
			}

			cout << endl;
		}
		cout<<"---------------------------------------------------------\n";
	}
}