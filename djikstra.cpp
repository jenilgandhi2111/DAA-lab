/******************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           21/01/2021
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Solve Djikstra's algorithm 
 * Problem description
   -------------------
   * Problem statement:
      -> The below code solves the problem of single source
         shortest path using Djikstra's algorithm.
      -> The below code uses Disjoint set's to check whether
         we could apply djikstra's algorithm or not.
      -> The below code also prints the path that need to be
         taken in order to reach the destination.If it is not
         possible then the code output graphs are disjoint and
         outputs -1.
   
   * Input format:
      -> First line takes N no of testcases.
      -> First line of each test case takes number of edges E.
      -> Next E lines takes input in the form src,dest,weight.
      -> Last line contains src and destination whose path needs
         to be found out.
   * Output format:
      -> First line prints the path followed.If not possible then
         it prints The graphs are disjoint.
      -> Next line print total distance.If not possible it output's -1.
    
   * Data Structure's used:
      -> Graphs
      -> Disjoint sets and union
   * Time complexity analysis:
      -> O(ElogV) where E are edges and V are vertices.
   * Limitations:
  	  -> The limitation of the below code is that we are unable to work 
         with negetive edges.
      -> Another limitation is that it gives shortest path froma single source
         and if we need it from other source we need to recompute using djikstra 
         algorithm which inturn uncreases the time
  
   * How to test?
  	 -> Input all the testcases in the 01_input.txt and then compile and run
******************************************************/
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
struct node
{
    int value = INT_MAX;
};

class Graph
{

public:
    map<int, int> dsu;
    map<int, list<int>> path;
    map<int, bool> visited;
    map<int, node> distances;
    map<int, vector<pair<int, int>>> graph;
    void print_dsu()
    {
        for (auto x : dsu)
        {
            cout << x.first << " ->" << x.second << endl;
        }
    }
    int find_parent(int cur)
    {
        int nd = cur;
        while (dsu[nd] != 0)
        {
            nd = dsu[nd];
        }
        return nd;
    }
    void dsu_union(int src, int dest)
    {
        int par1 = find_parent(src);
        int par2 = find_parent(dest);
        if (par1 != par2)
        {
            dsu[par1] = par2;
        }
    }
    void print_route(int dest)
    {
        int i = 0;
        for (auto x : path[dest])
        {
            if (i == path[dest].size() - 1)
            {
                cout << x << endl;
                break;
            }
            cout << x << "->";
            i++;
        }
    }
    void add_edge(int src, int dest, int weight)
    {
        graph[src].push_back(make_pair(dest, weight));
        graph[dest].push_back(make_pair(src, weight));
    }
    void print_graph()
    {
        for (auto node : graph)
        {
            cout << "[" << node.first << "]=> ";
            for (auto adj : node.second)
            {
                cout << "( " << adj.first << " , " << adj.second << " )"
                     << "\t";
            }
            cout << endl;
        }
    }
    int solve_djikstras(int src, int dest)
    {

        if (find_parent(src) == find_parent(dest))
        {

            path[src].push_back(src);
            for (auto x : graph)
            {
                distances[x.first].value = INT_MAX;
                visited[x.first] = false;
            }
            distances[src].value = 0;
            for (int i = 0; i < graph.size(); i++)
            {
                //find minimum element which is not visited
                int min_weight = INT_MAX;
                int min_vertex = -1;

                for (auto vertex : distances)
                {
                    if (vertex.second.value < min_weight && !visited[vertex.first])
                    {
                        min_weight = vertex.second.value;
                        min_vertex = vertex.first;
                    }
                }
                visited[min_vertex] = true;
                // now update weights with which it is connected
                auto adj_list = graph[min_vertex];
                for (auto connections : adj_list)
                {
                    if (!visited[connections.first] && (min_weight + connections.second) < distances[connections.first].value)
                    {
                        distances[connections.first].value = (min_weight + connections.second);
                        path[connections.first] = path[min_vertex];
                        path[connections.first].push_back(connections.first);
                    }
                }
            }
            print_route(dest);
        }
        else
        {
            cout << "The graphs are disjoint" << endl;
            return -1;
        }
        return distances[dest].value - distances[src].value;
    }
};

int main()
{
    c_p_c();
    int tt;
    cin >> tt;
    cout << "-----------------------------------------------------\n";
    while (tt--)
    {
        Graph g1;
        int connections;
        cin >> connections;
        while (connections--)
        {
            int src, dest, weight;
            cin >> src >> dest >> weight;
            g1.add_edge(src, dest, weight);
            g1.dsu_union(src, dest);
        }
        int s, d;
        cin >> s >> d;
        cout << g1.solve_djikstras(s, d) << endl;
        cout << "-----------------------------------------------------\n";
    }
}
