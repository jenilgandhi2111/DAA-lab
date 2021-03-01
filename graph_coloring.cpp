/***********************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           24/02/2021
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Solve graph coloring problem using Backtracking
   
 * Problem description
   -------------------
   -> Given a graph G with E edges and V vertices we need to color_graph
      in such a way that no adjacent vertices must be colored with same color_graph
      and this process must be completed with minimum no of colors.
 
 * Input format:
   -> First line is no of testcases T
   -> First line of each test case is no of Edges E
   -> E lines would have source and destination vertices
 
 * Output format:
   -> The program will output color of each vertices.
   
 * Time complexity:
   ->O(V^2+E) Worst case
   
 * How to test?
   -> put all the test case in 01_input.txt
   -> Compile and run the file a.out 
   -> Output would be reflected in 01_output.txt
   
***********************************************************/

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
class graph{
    map<int,vector<int>> graph;
    vector<int> graph_answers;
    map<int,int> visited;
    map<int,int> colors;
    public:
    void add_edge(int src,int dest,bool is_bidir=true)
    {
        graph[src].push_back(dest);
        if(is_bidir)
        {
            graph[dest].push_back(src);
        }
    }
    void print_graph()
    {
        for(auto e:graph)
        {
            cout<<e.first<<": ";
            for(auto v:e.second)
            {
                cout<<v<<",";
            }
            cout<<endl;
        }
    }
    bool check_condn(int vertex,int color)
    {
        // check adj list
        for(auto e:graph[vertex])
        {
           
            if(visited[e]==1 && colors[e]==color)
            {
                
                return false;
            }
        }
        return true;
    }
    bool color_graph(int vertex_cur)
    {
        if(vertex_cur==graph.size()+1)
        {
            for(auto x:colors)
            {
                cout<<x.second<<" ";
            }
            cout<<endl;
            return true;
        }
        visited[vertex_cur]=1;
        for(int i=0;i<INT_MAX;i++)
        {
            
            if(check_condn(vertex_cur,i))
            {
                graph_answers.push_back(i);
                colors[vertex_cur]=i;
                
                if(color_graph(vertex_cur+1))
                {
                    return true;
                }
                
            }
        }
        return true;
    }
};
int main()
{
    c_p_c();
    int tt;
    cin>>tt;
    while(tt--)
    {
        int  connections,src,dest;
        cin>>connections;
        graph g;
        for(int i=0;i<connections;i++)
        {
            int src,dest;
            cin>>src>>dest;
            g.add_edge(src,dest);
        }
        //g.print_graph();
        g.color_graph(1);
    }
}







