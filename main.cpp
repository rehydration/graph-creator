#include <iostream>
#include <cstring>

using namespace std;

int shortest_path() {

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
	cout << "Enter the name of the first vertex:\n";
	cout << "Enter the name of the second vertex:\n";
	cout << "Enter the edge weight:\n";
      }
    }
    if (strncmp(input, "remove", 6)) {
      cout << "Enter V for vertex, E for edge:\n";

    }
    if (strncmp(input, "path", 4)) {

    }
  }  
}
