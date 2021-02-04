/***********************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           31/01/2021
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Solve coin change problem using dynamic programming 
 * Problem description
   -------------------
   * Problem statement: 
      -> The below code solves the coin change problem for n test cases
         for given m denominations available and for c change to make
      -> The program will give the output solving it by dynamic programming
         methodology and if it is possible to make c change using m denominations available
         the program will output the amount of each denomination used and if 
         not possible then the output will be "Not Possible".
      -> The program would output optimal answer to mke a change.
   * TIME COMPLEXITY ANALYSIS
      ->O(m*c) where m denots the denominations and c denotes the change t make.

   * INPUT FORMAT
      -> First line:   The user will specify no of test cases
      -> Second line:  The user will specify the m no of denominations
      -> Third line:   The user will have to provide the array of
                       denominations available
      -> Fourth line:  The user will have to input the required change
                     the user wants
   * HOW TO TEST?
      -> Input all the test cases in the input file 02_input.txt
      -> Output will be in the 02_output.txt
    
   * OUTPUT FORMAT
      -> display the coins that were used to make if possible solving by recursive manner
      -> display the coins that were used to make if possible solving by Iterative manner
      -> else display "Not possible"
***********************************************************/
#include <bits/stdc++.h>
using namespace std;
void c_p_c()
{
    //functions for fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("02_input.txt", "r", stdin);
    freopen("02_output.txt", "w", stdout);
#endif
}
// This function solves coin-change problem recursively 
int coin_change(int change, vector<int> denoms, vector<int> &dp)
{
    //base case handling 
    if (change == 0)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i < denoms.size(); i++)
    {
        int subans = 0;
        //checking if the change is possible to make
        if (change - denoms[i] >= 0)
        {
            // check i the answer is computed
            if (dp[change - denoms[i]] != -1)
            {
                subans = dp[change - denoms[i]];
            }
            // If the change is not computed
            else
            {
                subans = coin_change(change - denoms[i], denoms, dp);
            }

            // checking if the answer we computed is smaller or it was already smaller
            if (subans != INT_MAX && subans + 1 < ans)
            {
                ans = subans + 1;
            }
        }
    }
    dp[change] = ans;

    return ans;
}

// This function solves coin change problem iteratively 
int iter_coins(int change,vector<int> denoms)
{
    // Initializing dp array 
    int dp[denoms.size()+1][change+1];
    
    for(int i=0;i<=denoms.size();i++)
    {
        for(int j=0;j<=change;j++)
        {
            // If it is the first row put every cell as 0
            if(j==0)
            {
                dp[i][j]=0;
            }
            // If it is the first column put every cell as Infinite
            else if(i==0)
            {
                dp[i][j]=99999;
            }
            // If the denomination is greater than the change then copy
            // above cell
            else if(denoms[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            // Else we take min of above cell or the left over amount
            else
            {
                
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-denoms[i-1]]);
                
            }
        }
    }
    
    int final_ans= dp[denoms.size()][change];
    if(final_ans==99999)
    {
        return -1;
    }
    else
    {
        return final_ans;
    }
    
}
int main()
{
    c_p_c();
    int tt;
    cin >> tt;
    cout<<"--------------------------------------------------------\n";
    while (tt--)
    {
        int n_denoms;
        // cout << "Enter denominations:" << endl;
        cin >> n_denoms;

        //recursievely
        vector<int> denoms;
        vector<int> dp;
        for (int i = 0; i < n_denoms; i++)
        {
            int tmp;
            cin >> tmp;
            denoms.push_back(tmp);
        }
        int change;
        // cout << "Change to make" << endl;
        cin >> change;
        for (int j = 0; j <= change; j++)
        {
            dp.push_back(-1);
        }
        dp[0] = 0;
        int ans = coin_change(change, denoms, dp);
        if (ans == INT_MAX || ans==INT_MIN)
        {
            cout << "Not possible to make change!" << endl;
        }
        else
        {
            cout << "Possible to make in:" << ans << " coins" << endl;
        }


        // Iteratively 
        vector<int> denoms1;

        for(auto i:denoms)
        {
            denoms1.push_back(i);
        }
        ans=iter_coins(change,denoms1);
        if (ans == -1)
        {
            cout << "Not possible to make change!" << endl;
        }
        else
        {
            cout << "Possible to make in:" << ans << " coins" << endl;
        }
        cout<<"--------------------------------------------------------\n";
    }
}
