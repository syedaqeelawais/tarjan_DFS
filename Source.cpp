#include<iostream>
#include <list>
#include <stack>
#include<algorithm>
#define NIL -1
using namespace std;

// A class that represents an directed graph
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // A dynamic array of adjacency lists

	// A Recursive DFS based function used by SCC()
	void DFS(int u, int num[], int low[],stack<int> *st, bool stackMember[]);
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void SCC();    // prints strongly connected components
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


void Graph::DFS(int u, int num[], int low[], stack<int> *st,bool stackMember[])
{

	static int time = 0;

	// Initialize discovery time and low value
	num[u] = low[u] = ++time;
	st->push(u);
	stackMember[u] = true;

	// Go through all vertices adjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;  // v is current adjacent of 'u'

		// If v is not visited yet, then recur for it
		if (num[v] == -1)
		{
			DFS(v, num, low, st, stackMember);

			low[u] = min(low[u], low[v]);//tree edge as per definition in Tarjan's paper
		}

		else if (stackMember[v] == true)
			low[u] = min(low[u], num[v]);//back edge as per definition in tarjan's paper
	}

	// head node found, pop the stack and print an SCC
	int w = 0;  // To store stack extracted vertices
	if (low[u] == num[u])
	{
		while (st->top() != u)
		{
			w = (int)st->top();
			cout << w << " ";
			stackMember[w] = false;
			st->pop();
		}
		w = (int)st->top();
		cout << w << "\n";
		stackMember[w] = false;
		st->pop();
	}
}

// The function to do DFS traversal. It uses DFS()
void Graph::SCC()
{
	int *num = new int[V];
	int *low = new int[V];
	bool *stackMember = new bool[V];
	stack<int> *st = new stack<int>();

	// Initialize disc and low, and stackMember arrays
	for (int i = 0; i < V; i++)
	{
		num[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

	for (int i = 0; i < V; i++)
	if (num[i] == NIL)
		DFS(i, num, low, st, stackMember);
}


int main()
{
	cout << "The edges in first graph are" << endl<<"(4,0),(3,4),(3,1),(0,3),(1,2)"<<endl;
	cout << "\nStrongly Connected Coomponents in first graph are: \n"<<endl;
	Graph g1(5);
	g1.addEdge(4, 0);
	g1.addEdge(3, 4);
	g1.addEdge(3, 1);
	g1.addEdge(0, 3);
	g1.addEdge(1, 2);
	g1.SCC();

	cout << "The edges in Second graph are" << endl << "(5,3),(3,4),(4,5),(3,0),(0,1),(3,2),(3,6),(2,1)" << endl;
	cout << "\nStrongly Connected Coomponents in second graph are: \n"<<endl;
	Graph g3(7);
	g3.addEdge(5, 3);
	g3.addEdge(3, 4);
	g3.addEdge(4, 5);
	g3.addEdge(3, 0);
	g3.addEdge(0, 1);
	g3.addEdge(3, 2);
	g3.addEdge(3, 6);
	g3.addEdge(2, 1);
	g3.SCC();

	cout << "The edges in Third graph are" << endl << "(0,1),(1,2),(2,0),(1,4),(4,3),(3,4)" << endl;
	cout << "\nStrongly connected components in Third graph \n"<<endl;
	Graph g5(5);
	g5.addEdge(0, 1);
	g5.addEdge(1, 2);
	g5.addEdge(2, 0);
	g5.addEdge(1, 4);
	g5.addEdge(4, 3);
	g5.addEdge(3, 4);
	g5.SCC();
	
	system("pause");
	return 0;
}