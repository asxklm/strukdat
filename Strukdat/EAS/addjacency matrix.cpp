#include<bits/stdc++.h>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 1; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 1; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
  }

  // Print the martix
  void toString() {
    for (int i = 1; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 1; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 1; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() {
  Graph g(21);

  g.addEdge(1, 3);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(4, 17);
  g.addEdge(5, 6);
  g.addEdge(6, 7);
  g.addEdge(6, 18);
  g.addEdge(6, 17);
  g.addEdge(7, 8);
  g.addEdge(8, 18);
  g.addEdge(18, 19);
  g.addEdge(19, 20);
  g.addEdge(20, 9);
  g.addEdge(9, 10);
  g.addEdge(9, 8);
  g.addEdge(10, 11);
  g.addEdge(2, 12);
  g.addEdge(13, 12);
  g.addEdge(13, 1);
  g.addEdge(12, 11);
  g.addEdge(15, 13);
  g.addEdge(15, 14);
  g.addEdge(14, 11);
  g.addEdge(16, 15);
  g.addEdge(16, 17);

  g.toString();
}