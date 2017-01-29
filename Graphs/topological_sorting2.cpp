//////////////////////
// Topological sorting through
// depth-first search (by Robert Tarjan)
//////////////////////

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Pair { int pair[2]; Pair(int u, int v) { pair[0] = u; pair[1] = v; } };

vector<Pair> input;

int vertexes = 0;  // count of vertex
void add_to_input(int u, int v)
{
	input.push_back(Pair(u, v));

	int m = u > v ? u : v;  //by max vertex
	if (vertexes < m) vertexes = m;
}

void build_input()
{
	add_to_input(1, 2);
	add_to_input(1, 3);
	add_to_input(2, 4);
	add_to_input(3, 6);
	add_to_input(6, 5);
//	add_to_input(6, 4);  // cycle edge
	add_to_input(5, 7);
	add_to_input(4, 3);
	add_to_input(4, 5);

//	add_to_input(1, 2);
//	add_to_input(1, 3);
//	add_to_input(2, 4);
//	add_to_input(3, 4);
}

int *dest, *nxt, *head;
short *vis;

void init_arrays()
{
	dest = static_cast<int*>(calloc(input.size() + 1, sizeof(*dest)));
	nxt = static_cast<int*>(calloc(input.size() + 1, sizeof(*nxt)));
	head = static_cast<int*>(calloc(vertexes + 1, sizeof(*head)));
	vis = static_cast<short*>(calloc(vertexes + 1, sizeof(*head)));

	for (size_t i = 0; i < input.size(); i++)
	{
		int u = input[i].pair[0];
		int v = input[i].pair[1];

		int j = i + 1;
		dest[j] = v;
		nxt[j] = head[u];
		head[u] = j;
	}
}

void dfs(int u, vector<int> &path, bool &found)
{
	vis[u] = 1;
	int i = head[u];
	while (i != 0 && !found)
	{
		if (vis[dest[i]] == 1)
		{
			found = true;
			cout << "here: " << dest[i] << endl;
		}
		else if (vis[dest[i]] == 0)
			dfs(dest[i], path, found);
		i = nxt[i];
	}
	vis[u] = 2;
	path.push_back(u);
}

void ts_by_dfs()
{
	int m = 1-1;
	vector<int> v;
	for (int i = 0; i < vertexes; i++)
	{
		int j = (i+m) % vertexes + 1;
		bool cycleFound = false;
		if (vis[j] == 0)
			dfs(j, v, cycleFound);
		if (cycleFound)
		{
			cout << "Cycle is found!\n";
			break;
		}
	}
	cout << "path:";
	for (int i = v.size() - 1; i >= 0; --i)
	{
		cout << " " << v[i];
	}
}


int main()
{
	build_input();
	init_arrays();

	ts_by_dfs();

	cin.get();
	return 0;
}
