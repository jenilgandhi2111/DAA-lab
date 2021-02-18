/***********************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           18/02/2021
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Solve longest common subsequence problem
                    using Dynamic Programming methodology
   
 * Problem description
   -------------------
      -> Given T no of test-cases solve the longest common subsequence
         using dynamic programming. For each test case provided String
         s1 and s2 find out the longest common subsequence.
 
 * Time and Space Complexity:
      -> O(N*M) N is length of string s1 and M is length of string s2 .
      -> O(N*M) space complexity.
 
 * Input Format:
      -> First line: specify no of test cases (T).
      -> First line in each test case: String s1.
      -> Second line in each test case : String s2.

 * Output Format:
      -> Output the longest common subsequence
   
 * HOW TO TEST?
      -> Input all the test cases in the input file 01_input.txt
      -> Output will be in the 01_output.txt
 
 * Test-case:
     -> Testcase:1
        1
        abaaba
        babbab

        O/P:
        4

        Longest common subsequence:
          -> abba
************************************************************/
#include<bits/stdc++.h>
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
int solve_longest_common_subsequence(string s1,string s2)
{
    int s1_l=s1.length()+1,s2_l=s2.length()+1;
    int dp[s1_l][s2_l];

    for(int i=0;i<s1_l;i++)
    {
        for(int j=0;j<s2_l;j++)
        {
            
            if(i==0||j==0)
            {
                
                dp[i][j]=0;
            }
            else
            {
                
                if(s1[i-1]==s2[j-1])
                {
                      
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    
     
    return dp[s1_l-1][s2_l-1];
}
int main()
{
    c_p_c();
    int tt;
    cin>>tt;
    int cntr=1;
    cout<<"------------------------------------------------------------\n";
    while(tt--)
    {
        cout<<"Case #"<<cntr<<":"<<endl;
        cntr++;
        string s1,s2;
        cin>>s1>>s2;
        cout<<solve_longest_common_subsequence(s1,s2)<<endl;
        cout<<"------------------------------------------------------------\n";
    }
}
