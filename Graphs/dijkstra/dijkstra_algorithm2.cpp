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

	assert(n > 0 and k > 0);
	
	vector<int> edges[k+1];
	vector<int> weights[k+1];
	
	rep(i,1,n){
		int u, v, w;
		cin >> u >> v >> w;
		
		edges[u].push_back(v);
		weights[u].push_back(w);
		
#ifdef IS_UNDIRECTED
		edges[v].push_back(u);
		weights[v].push_back(w);
#endif
	}
	
	int marks[k+1];
	bool extracts[k+1];
	rep(i,1,k){
		marks[i] = INT_MAX;
		extracts[i] = false;
	}
	int pos = 1;
	
	// ----------------
	
	marks[pos] = 0;

	while (pos != -1){
		cout << "from " << pos << endl;
		go(i,edges[pos].size()){
			assert(marks[pos] < INT_MAX);
			if (marks[edges[pos][i]] > marks[pos] + weights[pos][i]){
				cout << "visiting " << edges[pos][i] << "; w = " << weights[pos][i]
				     << ";   replace " << marks[edges[pos][i]] << " by " << marks[pos] + weights[pos][i] << endl;
				marks[edges[pos][i]] = marks[pos] + weights[pos][i];
			} else {
				cout << "already visited " << edges[pos][i] << "; w = " << weights[pos][i]
				     << "; total weight = " << marks[edges[pos][i]] << endl;
			}
		}
		assert(!extracts[pos]);
		cout << "remove " << pos << "\n\n";  // remove current vertex
		extracts[pos] = true;

		// find min, save index in pos
		pos = -1;
		int min = INT_MAX;
		rep(i,1,k){
			go(j,edges[i].size()){
				if (min > marks[i] and !extracts[edges[i][j]]){
					min = marks[i];
					pos = edges[i][j];
				}
			}
		}
	}
	
	// result
	rep(i,1,k) cout << "u - " << i << "; w - " << marks[i] << endl;
	
	return 0;
}
