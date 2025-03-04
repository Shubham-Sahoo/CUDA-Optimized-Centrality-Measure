#ifndef UTILS
#define UTILS
#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>

using namespace std;

namespace utils{
class graph
{
 public:
 int n;
 int m;
 int * edges_from;
 int * edges_to;
 int * edges;
 int * scores;

 void print_edges()
 {
  for(int i = 0; i < n; i++)
  {
   std::cout << "Starting " << i;
   /*for(int j = edges_from[i]; j <= edges_to[i]; j++)
   {
    std::cout << edges[j] << std::endl;
   }*/
   if (edges_to[i] == -1)
   {
    std::cout << 0 << std::endl;
   }
   else
   {
    std::cout << (edges_to[i]-edges_from[i] + 1) << std::endl;
   }    
    
  }
 }
 void print_scores_to_file(char * file);
};

graph initialize(std::vector<std::vector<int> > connections)
{
 utils::graph g;
 g.m = connections.size(); // Number of edges
 g.n = 0;
 for(int i = 0; i < g.m; i++)
 {
  if(connections[i][0]>g.n) g.n = connections[i][0];
  if(connections[i][1]>g.n) g.n = connections[i][1];
  
 }
 g.n += 1; // Number of nodes = max_idx + 1

 g.edges_from = new int[g.n]; //edges_from[i] is the index which neighbors of node i start. go up till edges_to[i]
 g.edges_to = new int[g.n]; 
 g.edges = new int[2*g.m];
 g.scores = new int[g.n];

 for(int i = 0; i < g.n; i++)
 {
  g.edges_from[i] = -1;
  g.edges_to[i] = -1;
 }

 int curr_edge_pointer = 0;

 /* Changing here               ------------
 for(int i = 0; i < g.n; i++)
 {
  bool isassigned = 0;
  for(int j = 0; j < g.m; j++)
  {
   if(connections[j][0]==i)
   {
    if(!isassigned)
    {
     g.edges_from[i] = curr_edge_pointer;
     isassigned = 1;
    }
    g.edges[curr_edge_pointer] = connections[j][1];
    curr_edge_pointer += 1; 
   }
   else if(connections[j][1]==i)
   {
    if(!isassigned)
    {
     g.edges_from[i] = curr_edge_pointer;
     isassigned = 1;
    }
    g.edges[curr_edge_pointer] = connections[j][0];
    curr_edge_pointer += 1; 
   }
   if(isassigned)
   {
   g.edges_to[i] = curr_edge_pointer - 1;
   }
  }
 }Till here  -----------------------
*/ 
 //  New -------------------
 for(int i = 0; i < g.n; i++)
 {
  for(int j = 0; j < g.m; j++)
  {
   if(connections[j][0]==i || connections[j][1]==i)
   {
    if (g.edges_from[i] == -1)
    {
     g.edges_from[i] = curr_edge_pointer;
    }
    if(connections[j][0]==i)    g.edges[curr_edge_pointer] = connections[j][1];
    else g.edges[curr_edge_pointer] = connections[j][0];
    curr_edge_pointer += 1;
   }
  }
  if(g.edges_from[i] != -1)
  {
   g.edges_to[i] = curr_edge_pointer-1;
  }
 }
 // New over ----------------------

 std::cout << g.n << " " << g.m << std::endl;
 std::cout << curr_edge_pointer/2 << std::endl;

 return g;
}

}

class Graph {

public:

	int nodeCount, edgeCount;
	int *adjacencyList, *adjacencyListPointers;
	int *edgeList1, *edgeList2;

public:

	int getNodeCount() {
		return nodeCount;
	}

	int getEdgeCount() {
		return edgeCount;
	}

	// Reads the graph and stores in Compressed Sparse Row (CSR) format
	void readGraph() {

		// Reading in CSR format
		cout<<"Enter the nodes and edges count :\n";
		cin >> nodeCount >> edgeCount;

		// Copy into compressed adjacency List
		adjacencyListPointers = new int[nodeCount +1];
		adjacencyList = new int[2 * edgeCount +1];

		cout<<"Enter the row adjacency list:\n";

		for(int i=0; i<=nodeCount; i++) 
			cin >> adjacencyListPointers[i];

		cout<<"Enter the column adjacency list:\n";
		for(int i=0; i<(2 * edgeCount); i++)
			cin >> adjacencyList[i];
	}

	void readGraphfile(char* filename) {

		// Reading in CSR format
		ifstream myfile;
	    myfile.open(filename);

		myfile >> nodeCount >> edgeCount;

		// Copy into compressed adjacency List
		adjacencyListPointers = new int[nodeCount +1];
		adjacencyList = new int[2 * edgeCount +1];

		

		for(int i=0; i<=nodeCount; i++) 
			myfile >> adjacencyListPointers[i];

		
		for(int i=0; i<(2 * edgeCount); i++)
			myfile >> adjacencyList[i];

		myfile.close();
	}

	void convertToCOO() {
		edgeList2 = adjacencyList;
		edgeList1 = new int[2 * edgeCount +1];

		for(int i=0; i <nodeCount; ++i) {
			for(int j=adjacencyListPointers[i]; j<adjacencyListPointers[i+1]; ++j){
				edgeList1[j] = i;
			}
		}
	}

	int *getAdjacencyList() {

		return adjacencyList;
	}

	int *getAdjacencyListPointers() {

		return adjacencyListPointers;
	}
};


#endif
