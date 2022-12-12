#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;

	int adjM[20][20] ={
          {0, 0},
          {0, 0}
    };
	string place[20];
	
public:
Graph(int v){
	V = v;
}

void addVertex(string str, int v1, int v2){
	adjM[v1-1][v2-1] = 1;
	place[v2-1] = str;
}

void bfs(string startVertex, string destination){
	bool visited[20] = {false};
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int flag = 0;
		for(int i = 0; i<= 20; i++){
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
		const char *d = destination.c_str();
		const char *c = place[q.front()].c_str();
		cout << place[q.front()] << " ";
		q.pop();
		if(strcmp(d, c)==0) break;
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
	g.bfs("Rumah", "OYO");

}