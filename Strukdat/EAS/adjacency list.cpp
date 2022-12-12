#include <bits/stdc++.h>
using namespace std;

// Function to add edges
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Function to print adjacency list
void adjacencylist(vector<int> adj[], int V)
{
	for (int i = 1; i < V; i++) {
		cout << i << "->";
		for (int& x : adj[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

// Function to initialize the adjacency list
// of the given graph
void initGraph(int V, int edges[27][26], int noOfEdges)
{
	// To represent graph as adjacency list
	vector<int> adj[V];

	// Traverse edges array and make edges
	for (int i = 1; i < noOfEdges; i++) {

		// Function call to make an edge
		addEdge(adj, edges[i][1], edges[i][0]);
	}

	// Function Call to print adjacency list
	adjacencylist(adj, V);
}

// Driver Code
int main()
{
	// Given vertices
	int V = 21;

	// Given edges
	int edges[27][26] = { 
	{ 1, 3 }, 
	{ 1, 2 }, 
	{ 3, 4 }, 
	{ 4, 5 }, 
	{ 4, 17 }, 
	{ 5, 6 }, 
	{ 6, 7 },
	{ 6, 18 }, 
	{ 6, 17 }, 
	{ 7, 8 },
	{ 8, 18 }, 
	{ 18, 19 }, 
	{ 19, 20 }, 
	{ 20, 9 }, 
	{ 9, 10 }, 
	{ 9, 8 }, 
	{ 10, 11 }, 
	{ 2, 11 }, 
	{ 13, 12 }, 
	{ 13, 1 },
    { 12, 11},
    { 15, 13},
    { 15, 14},
    { 14, 11},
    { 16, 15},
    { 16, 17} 
	};

	int noOfEdges = 27;

	// Function Call
	initGraph(V, edges, noOfEdges);

	return 0;
}