/********************************************************************
* Written By:-     Jenil Gandhi
* Sem:-            CE 4
* Date:-           25/12/2020
* Roll no:-        CE038
* Subject:-        DAA(Design and Analysis of Algorithm)
* Guidance by:-    Prof Jigar Pandya
* Objective:-      Solve Kruskal's algorithm for minimum spanning tree
				   by greedy strategy.

* Problem description
  -------------------
  * Problem Statement:
     -> The below code solves the problem of minimum spanning tree by the
     	use of greedy strategy.given T testcases , and given N edges connections,
     	In the form of source(S),destination(D),weight(W). 
     ->	the problem will output the edges that would be selected and the minimum 
     	cost of the spanning tree i.e. ∑ Wi is minimum with no loops.
  
  * Data structures used:
  	 -> Maps.
  	 -> Graph
  	 -> Sets.
  	 -> Disjoint Set's union and find 
  
  * Time complexity analysis:
  	 -> O(V*E + ElogE) where V are vertices and E are edges. V*E for finding
  	 	the parent via disjoint sets method for each edge and ElogE for sorting 
  	 	the edges by weight.

  * Space complexity analysis:
  	 -> O(E+V) where E stands for edges and V stands for vertiices.

  * Input format:
  	 -> First line: Input T testcases.
  	 -> First line for each test cases must be no of edges say N
  	 -> Next N lines would be followed by entering Si,Di,Wi. Si is
  	 	source is source for i'th line similarly D is destination and
  	 	W is weight. 

  * Output format:
  	 -> For each testcase the program will output the selected edges
  	 	and the minimum cost of the spanning tree.

  * TestCases:

  	 -> Testcase:1
  	    1
  	    6
	    2 1 1000
	    3 4 299
	    2 4 200 
	    2 4 100
	    3 2 300
	    3 2 6

	    Output:
	    Case #1
		Src:3 Dest:2 Weight:6
		Src:2 Dest:4 Weight:100
		Src:2 Dest:1 Weight:1000
		total cost:1106

	 -> Testcase:2
	 	6
		1 2 5
		1 3 3
		4 1 6
		2 4 7
		3 2 4
		3 4 5

		Output:
		Case #4
		Src:1 Dest:3 Weight:3
		Src:3 Dest:2 Weight:4
		Src:3 Dest:4 Weight:5
		total cost:12

  * Limitations:
  	 -> The limitation of the above problem is it takes O(V*E) for finding
  	    The set, also you cannot assign 0 as any of src or dest because the program
  	    will run in an ∞ loop.

  * How to test?
  	 -> Input all the testcases in the 01_input.txt and then compile and run
********************************************************************/
#include<bits/stdc++.h>
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
class triplet{

public:
	int src,dest,weight;
	triplet(int src,int dest,int weight)
	{
		this->src=src;
		this->dest=dest;
		this->weight=weight;
	}
	void display()
	{
		cout<<"Src:"<<src<<" Dest:"<<dest<<" Weight:"<<weight<<endl;
	}

};
int parents[2];

bool compare(triplet a,triplet b)
{
	return a.weight<b.weight;
}

// function to find the parent from disjoint sets
int get_parent(int a,map<int,int> dsu)
{
	int cur=a;
	while(dsu[cur]!=0)
	{
		cur=dsu[cur];
	}
	return cur;
}

//this function sets the absolute parent of vertices .
void get_abs_parent(int a,int b,map<int,int> dsu)
{
	parents[0]=get_parent(a,dsu);
	parents[1]=get_parent(b,dsu);
}

int main()
{

	c_p_c();
	int t;
	cin>>t;
	int cntr=0;
	cout<<"\n------------------------------------------------------\n";
	while(t--)
	{
		cout<<"Case #"<<++cntr<<endl;
		int n;
		int cnt=0;
		int cost=0;
		vector<triplet> all_cons;
		vector<triplet> final_ans;
		set<int> uniques;
		map<int,int> dsu;
		cin>>n;
		
		//loop for taking input
		for(int i=0;i<n;i++)
		{
			int src,dest,weight;
			cin>>src>>dest>>weight;
			if(src==dest)continue;
			triplet *tp=(triplet*) new triplet(src,dest,weight);
			all_cons.push_back(*tp);
			uniques.insert(src);
			uniques.insert(dest);
		}

		//sorting all edges based on weights.
		sort(all_cons.begin(),all_cons.end(),compare);
		
		
		//loop for selection of minimum cost edges. with no loops.
		for(triplet t:all_cons)
		{
			//condition to stop if we cover N-1 edges where N is vertices.
			if(cnt==uniques.size()-1)
			{
				break;
			}
			
			get_abs_parent(t.src,t.dest,dsu);
			
			//if below condition is true then this will add loop t the graph hence
			//we continue ahead
			if(parents[0]==parents[1])
			{
				continue;
			}
			else
			{
				final_ans.push_back(t);
				//union of two disjoint sets
				dsu[parents[0]]=parents[1];
				cnt++;
				cost+=t.weight;
			}
		}

		//loop for displaying the selected edges.
		for(triplet e:final_ans)
		{
			e.display();
		}
		cout<<"total cost:"<<cost<<endl;
		cout<<"------------------------------------------------------\n";

	}
}
