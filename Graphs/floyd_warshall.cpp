// vs15
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

const int INF = (int)1E9;

int main() {
	// Prepare Input
	string input = 
"5\
-1 2 -1 8 4 \
2 -1 1 3 -1 \
-1 1 -1 7 -1 \
8 3 7 -1 2 \
4 -1 -1 2 -1";
	stringstream ss(input);


	// Input

	size_t size;
	ss >> size;
	int** w = new int*[size];
	for (size_t i = 0; i < size; i++)
	{
		w[i] = new int[size];
		for (size_t j = 0; j < size; j++) {
			ss >> w[i][j];
			if (w[i][j] == -1) w[i][j] = INF;
		}
	}


	// Algorithm

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == j) continue;
			for (size_t k = 0; k < size; k++)
			{
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}


	// Output

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (w[i][j] == INF)
				cout << "INF";
			else
				cout << w[i][j];
			cout << " ";
		}
		cout << "\n";
	}



#if _DEBUG
	cout << "\n\n";
	system("pause");
#endif
}
