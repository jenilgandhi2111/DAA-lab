/****************************************************************
* Written By:-     Jenil Gandhi
* Sem:-            CE 4
* Date:-           31/12/2020
* Roll no:-        CE038
* Subject:-        DAA(Design and Analysis of Algorithm)
* Guidance by:-    Prof Jigar Pandya
* Objective:-      Solve 0/1 knapsack problem with dynamic programming
                   methodology

* Description
  -----------
 * PROBLEM STATEMENT
    -> Below code solves the 0/1 knapsack problem by dynamic programming
       methedology.Here the user need to provide the number of items
       N and weight of knapsack W. In the next N lines two space seperated
       integers for profit and weight.
    -> The program will output the maximum profit possible from the 
       input items.
 
 * TIME COMPLEXITY ANALYSIS
    -> O(W*N) where W stands for weight and N stands for no of items.
 
 * HOW TO TEST?
    -> Input all the test cases in the input file 01_input.txt
    -> Output will be in the 01_output.txt
 
 * INPUT FORMAT
    -> First line:The user will specify T tescases.
    -> Second line: The user will specify N items and W weight of knapsack.
    -> Next N lines will have profit and weight(space seperated). 
 
 * OUTPUT FORMAT
    -> The problem will output the maximum profit possible from input.
****************************************************************/
#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
    //functions for fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("01_input.txt", "r", stdin);
    freopen("01_output.txt", "w", stdout);
#endif
}

// This function solves 0/1 knapsack problem and return maximum profit possible
int solve_knapsack(int capacity, vector<int> weights, vector<int> profits)
{
    int w_size = weights.size() + 1;
    int cap_size = capacity + 1;
    int dp[w_size][cap_size];

    for (int i = 0; i < w_size; i++)
    {
        for (int j = 0; j < cap_size; j++)
        {
            // If it is the first row or column then the cell would be 0
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                // If weights of item is above the capacity of knapsack then copy above cell down
                if (weights[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                // Else we take the max out of above cell and current item plus remaining weight
                else
                {
                    dp[i][j] = max(dp[i - 1][j], profits[i - 1] + dp[i - 1][j - weights[i - 1]]);
                }
            }
        }
    }
    return dp[w_size - 1][cap_size - 1];
}
int main()
{
    c_p_c();
    int tt;
    cin >> tt;
    cout<<"--------------------------------------------------------\n";
    while (tt--)
    {
        vector<int> wt, prof;
        int items;
        // cout << "Enter number of items:[Enter in weight profit]" << endl;
        cin >> items;
        for (int i = 0; i < items; i++)
        {
            int profit, weight;
            cin >> weight >> profit;
            wt.push_back(weight);
            prof.push_back(profit);
        }
        // cout << "Enter capacity\n";
        int capacity;
        cin >> capacity;
        cout << "Max profit:" << solve_knapsack(capacity, wt, prof)<<endl;
        cout<<"--------------------------------------------------------\n";
    }
}