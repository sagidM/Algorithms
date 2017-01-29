//////////////////////
// Kahn's algorithm //
//////////////////////

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Pair { int pair[2]; Pair(int u, int v) { pair[0] = u; pair[1] = v; } };

vector<Pair> input;
int *sums;  // consists sum of each head of arrow

int vertexes = 0;  // count of vertex
void add_to_input(int u, int v)
{
	if (u == v) throw logic_error("self-loop");
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
	add_to_input(4, 3);
	add_to_input(4, 5);
	add_to_input(6, 5);
	add_to_input(5, 7);

//	add_to_input(1, 2);
//	add_to_input(1, 3);
//	add_to_input(2, 4);
//	add_to_input(3, 4);
}

int *dest, *nxt, *head;

void init_arrays()
{
	dest = static_cast<int*>(calloc(input.size() + 1, sizeof(*dest)));
	nxt = static_cast<int*>(calloc(input.size() + 1, sizeof(*nxt)));
	head = static_cast<int*>(calloc(vertexes + 1, sizeof(*head)));
	sums = static_cast<int*>(calloc(vertexes + 1, sizeof(*sums)));

	for (size_t i = 0; i < input.size(); i++)
	{
		int u = input[i].pair[0];
		int v = input[i].pair[1];

		int j = i + 1;
		dest[j] = v;
		nxt[j] = head[u];
		head[u] = j;
		sums[v]++;
	}
}

int* topological_sorting()
{
	int* ans = static_cast<int*>(calloc(vertexes, sizeof(*ans)));
	int j = 0;
	bool l;
	do
	{
		l = false;
		for (int i = 1; i <= vertexes; i++)
		{
			if (sums[i] == 0)
			{
				int u = head[i];
				while (u != 0)
				{
					sums[dest[u]]--;
					u = nxt[u];
				}
				sums[i] = -1;
				ans[j++] = i;
				l = true;
			}
		}
	} while (l);  // while (j < vertexes) also work
	return ans;
}

int main()
{
	build_input();
	init_arrays();

	int* ans = topological_sorting();
	for (size_t i = 0; i < vertexes; i++)
	{
		cout << ans[i] << " ";
	}
	free(ans);

	cin.get();
	return 0;
}
