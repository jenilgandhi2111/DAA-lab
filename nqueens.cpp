#include <bits/stdc++.h>
using namespace std;
bool check_condition(int **arr, int cur_row, int cur_col, int n)
{
    //check above
    int row = cur_row;
    int col = cur_col;

    for (int i = 0; i < cur_row; i++)
    {
        if (arr[i][cur_col] == 1)
        {
            return false;
        }
    }

    //check left diagonal
    row = cur_row;
    col = cur_col;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    //check right diagonal
    row = cur_row;
    col = cur_col;
    while (row >= 0 && col >= 0 && col <= n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool solve_nqueens(int **arr, int cur_row, int n)
{
    //base case for returning
    if (cur_row >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (check_condition(arr, cur_row, i, n))
        {
            arr[cur_row][i] = 1;

            // If we get a correct answer from below calls we return true
            // to the above call
            if (solve_nqueens(arr, cur_row + 1, n))
            {
                return true;
            }
            // Else we reverse our decision of keeping the current cell to 1
            // and try keeping them in different cell
            else
            {
                arr[cur_row][i] = 0;
            }
        }
        
    }

    // If we fail on all the cells we come out of the loop and return false
    // for trying for some other combination
    return false;
}
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cout << "Enter N:";
        cin >> n;
        int **arr;
        arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = 0;
            }
            // cout << endl;
        }
        bool ans = solve_nqueens(arr, 0, n);

        if (!ans)
        {
            cout << "Solution does not exists for " << n << " x " << n << " chessboard" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}