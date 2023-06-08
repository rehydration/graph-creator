/*

Nathan Zhou
6/7/23

Weighted edge directed graph creator that adds and removes vertices/edges
and finds the shortest path between two vertices

*/

#include <iostream>
#include <cstring>

using namespace std;

struct Node {
  int value;
  Node* next;
};

//Dijkstra's Algorithm using a linked list for BFS
void shortest_path(int (*adj)[21], char (*nodes)[10], int from, int to) {
  int dist[21];
  int prev[21];
  bool vis[21];
  for (int i = 0; i < 21; ++i) { //initialize
    dist[i] = 1e9;
    prev[i] = -1;
    vis[i] = false;
  }

  Node* head;
  Node* back;
  Node* n = new Node; //starting node
  n->value = from;
  n->next = nullptr;
  head = n;
  back = n;
  dist[back->value] = 0;
  
  while (head != nullptr) {
    for (int i = 0; i < 21; ++i) {
      if (adj[head->value][i] != -1) { //edge from last to i
        int path = adj[head->value][i] + dist[head->value];
        if (path < dist[i]) { //compare new path length vs previous
          dist[i] = path;
          prev[i] = head->value;
        }
        if (!vis[i]) { //add node to end of list if unvisited
          vis[i] = true;
          Node* newn = new Node;
          newn->value = i;
          newn->next = nullptr;
          back->next = newn;
          back = newn;
        }
      } 
    }
    //head has been visited, go to next
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  if (!vis[to]) { //target not visited
    cout << "No path exists.\n";
    return;
  }

  cout << "Path of length " << dist[to] << " from " << nodes[from] << " to " << nodes[to] << ":\n";
  //print path
  int curr = to;
  while (curr != from) {
    cout << nodes[curr] << " <- ";
    curr = prev[curr];
  }
  cout << nodes[curr] << "\n";

}


int main() {
  char vertices[21][10];
  int adj[21][21];
  bool exists[21];

  for (int i = 0; i < 21; ++i) {
    exists[i] = false;
    for (int j = 0; j < 21; ++j) adj[i][j] = -1;
  }
  

  char input[10];
  bool running = true;
  while (running) {
    cout << "Enter a command:\n";
    cin >> input;
    if (!strncmp(input, "add", 3)) {
      cout << "Enter V for vertex, E for edge:\n";
      cin >> input;
      if (input[0] == 'V') { //add a vertex
        cout << "Enter the vertex name:\n";
        cin >> input;
        int ind = 0;
        while (exists[ind]) ++ind; //first empty
        strcpy(vertices[ind], input);
        exists[ind] = true;
      }
      else { //add an edge of weight w between two vertices
        int v1, v2;
        cout << "Enter the name of the first vertex:\n";
        cin >> input;
        for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) v1 = i;
        cout << "Enter the name of the second vertex:\n";
        cin >> input;
        for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) v2 = i;
        cout << "Enter the edge weight:\n";
        int w;
        cin >> w;
        adj[v1][v2] = w;
      }
    }
    if (!strncmp(input, "remove", 6)) {
      cout << "Enter V for vertex, E for edge:\n";
      cin >> input;
      if (input[0] == 'V') { //remove a vertex and all of its paths
        cout << "Enter the vertex name:\n";
        cin >> input;
        int ind;
        for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) ind = i; //find vertex position
        for (int i = 0; i < 21; ++i) {
          for (int j = 0; j < 21; ++j) {
            if (i == ind || j == ind) adj[i][j] = -1; //delete path
          }
        }
        exists[ind] = false;
      }
      else { //remove edge between two vertices
        int v1, v2;
        cout << "Enter the name of the first vertex:\n";
        cin >> input;
        for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) v1 = i;
        cout << "Enter the name of the second vertex:\n";
        cin >> input;
        for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) v2 = i;
        adj[v1][v2] = -1;
      }
    }
    if (!strncmp(input, "path", 4)) {
      int v1, v2;
      cout << "Enter the name of the first vertex:\n";
      cin >> input;
      for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) v1 = i;
      cout << "Enter the name of the second vertex:\n";
      cin >> input;
      for (int i = 0; i < 21; ++i) if (!strcmp(vertices[i], input)) v2 = i;
      shortest_path(adj, vertices, v1, v2);
    }
    if (!strncmp(input, "print", 5)) {
      for (int i = 0; i < 21; ++i) {
        if (!exists[i]) continue;
        cout << vertices[i] << ": ";
        for (int j = 0; j < 21; ++j) {
          if (adj[i][j] != -1) cout << vertices[j] << " (" << adj[i][j] << ") ";
        }
        cout << "\n";
      }
    }
    if (!strncmp(input, "quit", 4)) running = false;
  }
}
