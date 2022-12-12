#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<pair<int, string>> adj[100];
public:
Graph(int v){
	V = v;
}

void addVertex(string str, int v1, int v2){
	adj[v1-1].push_back(make_pair(v2-1, str));
}

void bfs(string startVertex, string destination){
	vector<bool> visited;
	visited.resize(V,false);
	queue<pair<int, string>> q;
	q.push(make_pair(0, startVertex));
	visited[0] = true;
	while(!q.empty()){
		for(auto const &i: adj[q.front().first]){
			if(!visited[i.first]){
				visited[i.first] = true;
				q.push(make_pair(i.first, i.second));
			}
		}
		cout << q.front().second << " ";
		const char *c = q.front().second.c_str();
		const char *d = destination.c_str();
		q.pop();
		if(strcmp(c, d) == 0) break;
	}
}

};
int main(){
	Graph g(20);

	g.addVertex("Rumah",1, 1);
    g.addVertex("Tak Jamin",1, 2);
    g.addVertex("Setia Karya",1, 3);
    g.addVertex("Lestari",2, 11);
    g.addVertex("PGRI 1",3, 4);
    g.addVertex("Graha Kuncara",4, 5);
    g.addVertex("Bimbel",5, 6);
    g.addVertex("OYO",6, 17);
    g.addVertex("SparePart",6, 18);
    g.addVertex("Grand Rose",6, 7);
    g.addVertex("GK Eksekutif",7, 8);
    g.addVertex("SparePart",8, 18);
    g.addVertex("PGRI STKIP",18, 19);
	g.addVertex("Cluster",19, 20);
	g.addVertex("GeoTools",20, 9);
	g.addVertex("Grand Rose",9, 7);
	g.addVertex("Natura",9, 10);
	g.addVertex("Lestari",10, 11);
    g.addVertex("Lestari",12, 11);
	g.addVertex("Garasai Bakul",16, 16);
    g.addVertex("OYO",16, 17);
    g.addVertex("Jenggolo Indah",16, 15);
    g.addVertex("Rusunawa",15, 13);
	g.addVertex("Rumah",13, 1);
	g.addVertex("Sekar Laut",13, 12);
    g.addVertex("Lestari",12, 11);
    g.addVertex("Masjid",15, 14);
    g.addVertex("Lestari",14, 11);
    
	cout << "bfs destinations" << endl;
	g.bfs("Rumah", "GeoTools");
}