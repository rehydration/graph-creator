#include <iostream>
#include <cstring>

using namespace std;

struct Node {
  int value;
  Node* next;
};

int shortest_path(int** adj, int from, int to) {
  int dist[21];
  int prev[21];
  bool vis[21];
  for (int i = 0; i < 21; ++i) { //initialize
    dist[i] = 1e9;
    prev[i] = -1;
    vis = false;
  }

  Node* head;
  Node* back;
  Node* n = new Node;
  n->value = from;
  head = n;
  back = n;
  dist[back->value] = 0;
  
  while (head != nullptr) {
    for (int i = 0; i < 21; ++i) {
      if (adj[back->value][i] != -1) { //edge from last to i
	int path = adj[back->value][i] + dist[back->value];
	if (path < dist[i]) {
	  dist[i] = path;
	  prev[i] = last;
	}
	if (!vis[i]) {
	  vis[i] = true;
	  Node* newn = new Node;
	  newn->value = i;
	  back->next = newn;
	  back = newn;
	}
      }  
    }
    //head has been visited
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  int curr = to;
  while (curr != from) {
    cout << curr << " ";
    curr = last[curr];
  }
}


int main() {
  char* vertices[21];
  int adj[21][21];

  int count = 0;
  char input[10];
  bool running = true;
  while (running) {
    cout << "Enter a command:\n";
    cin >> input;
    if (strncmp(input, "add", 3)) {
      cout << "Enter V for vertex, E for edge:\n";
      cin >> input;
      if (input == 'V') {
	cout << "Enter the vertex name:\n";
	cin >> input;
	vertices[count] = new char[10]{input};
      }
      else {
	int v1, v2;
	cout << "Enter the name of the first vertex:\n";
	cin >> input;
	for (int i = 0; i < 21; ++i) if (strcmp(vertices[i], input)) v1 = i;

	cout << "Enter the name of the second vertex:\n";
	cout << "Enter the edge weight:\n";
	int w;
	cin >> w;
	adj[v1][v2] = w;
	adj[v2][v1] = w;
      }
    }
    if (strncmp(input, "remove", 6)) {
      cout << "Enter V for vertex, E for edge:\n";

    }
    if (strncmp(input, "path", 4)) {

    }
  }  
}
