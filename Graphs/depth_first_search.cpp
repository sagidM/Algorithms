#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Pair { int pairs[2]; Pair(int u, int v) { pairs[0] = u; pairs[1] = v; } };

const bool is_directed = false;
vector<Pair> input;
int vertexes = 0;

void add_to_input(int u, int v)
{
	input.push_back(Pair(u, v));
	if (is_directed) input.push_back(Pair(v, u));

	int &m = u > v ? u : v;
	if (vertexes < m)
		vertexes = m;
}

void build_input()
{
	add_to_input(1, 2);
	add_to_input(1, 3);
	add_to_input(2, 3);
	add_to_input(2, 4);
	add_to_input(2, 5);
	add_to_input(3, 4);
	add_to_input(4, 5);
	add_to_input(4, 6);
}

int *dest, *nxt, *head;

void init_arrays()
{
	dest = static_cast<int*>(calloc(input.size() + 1, sizeof(*dest)));
	nxt = static_cast<int*>(calloc(input.size() + 1, sizeof(*nxt)));
	head = static_cast<int*>(calloc(vertexes + 1, sizeof(*head)));

	for (size_t i = 0; i < input.size(); i++)
	{
		int u = input[i].pairs[0];
		int v = input[i].pairs[1];

		int j = i + 1;
		dest[j] = v;
		nxt[j] = head[u];
		head[u] = j;
	}
}

unsigned short* vis;  // 0 - white, 1 - gray, 2 - black
int w = 0;
char* spaces(int count, const char &space = ' ')
{
	char* s = new char[count+1];
	for (size_t i = 0; i < count; i++)
		s[i] = space;
	s[count] = '\0';
	return s;
}

void depth_first_search(int u)
{
	char* sp = spaces(w);
	cout << sp << u << endl;
	w+=2;
	vis[u] = 1;
	int x = head[u];
	while (x != 0)
	{
//		cout << "  " << dest[x] << "; " << vis[dest[x]] << endl;
		if (vis[dest[x]] == 0)
		{
			depth_first_search(dest[x]);
		}
		x = nxt[x];
	}
	vis[u] = 2;
	cout << sp << u << "\n";
	delete[] sp;
	w -= 2;
}

int main()
{
	build_input();
	init_arrays();

	vis = static_cast<unsigned short*>(calloc(vertexes + 1, sizeof(*vis)));
	depth_first_search(1);
	free(vis);

	cin.get();
	return 0;
}
