//////////////////////////
// Dijkstra's algorithm //
//////////////////////////

// Complexity: O(V^2 + E)
// V - set of vertexes
// E - set of edges

// g++ -std=c++14 dijkstra_algorithm.cpp


#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>
#include <assert.h>
using namespace std;

#define go(i,n) for(int i=0;i<n;i++)
#define rep(i,from,to) for (int i = from; i <= to; i++)
// #define fill(a, size, value) go(i,size) a[i] = value;
#define IS_UNDIRECTED

template<typename t>
inline void fill(t* const a, const size_t &size, const t &value){
	go(i,size) a[i] = value;
}

int main()
{
	freopen("in.txt", "r", stdin);
	// n = the number of edges
	// k = the number of vertexes

	int n, k;
	cin >> n >> k;
#ifdef IS_UNDIRECTED
	n <<= 1;
#endif

	assert(n > 0 and k > 0);
	
	int head[k+1], goals[n+1], nxt[n+1], weights[n+1];
	int marks[k+1];
	bool extracts[k+1];
	
	rep(i,0,k){
		head[i] = 0;
		marks[i] = INT_MAX;
		extracts[i] = false;
	}
	
	goals[0] = nxt[0] = 0;  // fictitious
	// build
	rep(i,1,n){
		int u, v, w;
		cin >> u >> v >> w;
		
		goals[i] = v;
		weights[i] = w;
		nxt[i] = head[u];
		head[u] = i;

#ifdef IS_UNDIRECTED
		i++;
		swap(u, v);
		goals[i] = v;
		weights[i] = w;
		nxt[i] = head[u];
		head[u] = i;
#endif
	}
	int pos = 1;  // 1 - start vertex

	// --------------
	
	
	marks[pos] = 0;

	while (pos != -1){
		// it's also possible: if (pos == aim) break;
		int u = head[pos];
		cout << "from " << pos << endl;
		// check every neighbour
		while (goals[u] != 0){
			assert(marks[pos] < INT_MAX);
			int till_u = marks[pos] + weights[u];
			if (marks[goals[u]] > till_u){
				cout << "visiting " << goals[u] << "; w = " << weights[u] << ";   replace " << marks[goals[u]] << " by " << till_u << endl;
				marks[goals[u]] = till_u;  // mark neighbour
			} else {
				cout << "already visited " << goals[u] << "; w = " << weights[u] << "; total weight = " << marks[goals[u]] << endl;
			}
			u = nxt[u];
		}
		assert(!extracts[pos]);
		extracts[pos] = true;  // remove current vertex
		cout << "remove " << pos << "\n\n";
		
		// find min, save index in pos
		pos = -1;
		int min = INT_MAX;
		rep(i,1,k){
			if (min > marks[i] and !extracts[i]){
				min = marks[i];
				pos = i;
			}
		}
	}
	
	// result
	rep(i,1,k) cout << "u - " << i << "; w - " << marks[i] << endl;
	
	return 0;
}
