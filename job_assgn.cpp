/***********************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           13/03/2021
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Solve Job assignment problem using Branch and bound
   
 * Problem description
   -------------------
   -> For given T testcases and N no of jobs for N person solve the
      job assignment problem.
   -> Assign the job to each people present in such a way that the 
      cost of assignment is minimum using branch and bound methodology.
   -> We would be given a SPACE matrix of size NxN (SPACE[N][N])where 
      rows denote jobs and columns denote person.

 * Input format:
   -> First line of the program is T no of testcases.
   -> First line of each testcase in No of jobs N
   -> Ith line of each testcase would contain the cost of assignment of a Jth job
      to Ith person. for ex 2nd line of the testcase would mean cost of assignment 
      of job to 2nd person each column in the testcase would mean cost of Jth job.
7,6,9,4
 * Output format:
   -> Output the minimum cost of assignment for the given testcase

 * example:
   Testcases:       1
   No of jobs:      4
                    ----->Row Means jobs
                    1   2   3   4

Column means | 1    9   2   7   8
Person       | 2    6   4   3   7
             | 3    5   8   1   8
             V 4    7   6   9   4
   
   Answer:          2+3+5+4=14
 
 * How to test:
    -> Put all your testcases in 01_input.txt
    -> Output would be in 01_output.txt
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
int calc_lower_bound(vector<vector<int>> space,int from,vector<int> taken,map<int,bool> assigned)
{
    
    int lb=0;
    for(int i=0;i<from;i++)
    {
        
        lb+=space[i][taken[i]];
    }
    
    for(int i=from;i<taken.size();i++)
    {
        int min=INT_MAX;
        
        for(int j=0;j<taken.size();j++)
        {
            
            if(space[i][j]<min && assigned[j]==false)
            {
                min=space[i][j];
            }
        }
        
        lb+=min;
    }
    
    return lb;

}
void solve_job_assgn(vector<vector<int>> space,vector<int> taken,int level,map<int,bool> jobs_taken)
{
    map<int,bool> copy=jobs_taken;
    if(level==taken.size())
    {
        // return base condition
        	
        int min_cost=0;
        for(int i=0;i<taken.size();i++)
        {
            min_cost+=space[i][taken[i]];
        }
        cout<<"Min:"<<min_cost<<endl;
        return;
    }
    int min=INT_MAX;
    int min_index;
    vector<int> min_vec;
    for(int i=0;i<taken.size();i++)
    {
        if(jobs_taken[i]==false)
        {
            copy[i]=true;
            taken[level]=i;
            int tmp=calc_lower_bound(space,level+1,taken,copy);
            if(tmp<min)
            {
                min=tmp;
                min_index=i;
                min_vec=taken;
            }
            copy[i]=false;
        
        }
    }
    jobs_taken[min_index]=true;
    taken=min_vec;
    
    solve_job_assgn(space,taken,level+1,jobs_taken);
}
int main()
{
    c_p_c();
    int tt;
    cin>>tt;
    int cntr=1;
    cout<<"----------------------------------\n";
    while(tt--)
    {
        cout<<"Case#"<<cntr<<" ";
        cntr++;
        int jobs;
        cin>>jobs;
       vector<vector<int>> v;
       vector<int> taken;
   
       for(int i=0;i<jobs;i++)
       {
           vector<int> tmp;
           taken.push_back(-1);
           for(int j=0;j<jobs;j++)
           {
               int temp;
               cin>>temp;
               tmp.push_back(temp);
           }
           v.push_back(tmp);
       }
       
       map<int,bool> jobs_taken;
       solve_job_assgn(v,taken,0,jobs_taken);
        cout<<"----------------------------------\n";
    }
}
