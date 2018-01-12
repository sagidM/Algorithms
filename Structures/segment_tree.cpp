// VS15
#include <iostream>
#include <vector>
using namespace std;


template <typename collection>
void print(const collection& c) {
	for (auto t : c) {
		cout << t << " ";
	}
	cout << "\n";
}

void print_n_times(char c, size_t count) {
	for (size_t i = 0; i < count; i++)
		cout << c;
}

void print_tree(const vector<int>& t, size_t p = 0, int level = 0) {
	if (p >= t.size()) return;
	print_n_times('.', level);
	cout << "" << t[p] << "\n";
	print_tree(t, p * 2 + 1, level + 3);
	print_tree(t, p * 2 + 2, level + 3);
}

// O(N)
void build(vector<int> &t, vector<int> &v, int p, int vl, int vr) {
	if (vl == vr)
		t[p] = v[vl];
	else {
		int m = (vr - vl) / 2 + vl;
		build(t, v, p * 2 + 1, vl, m);
		build(t, v, p * 2 + 2, m + 1, vr);
		t[p] = t[p * 2 + 1] + t[p * 2 + 2];
	}
}

// O(log N)
int sum(vector<int> &t, int p, int tl, int tr, int l, int r) {
	if (l <= tl && tr <= r)
		return t[p];
	if (l > tr || tl > r)
		return 0;

	int m = (tl + tr) / 2;
	return sum(t, p * 2 + 1, tl, m, l, r) +
	       sum(t, p * 2 + 2, m + 1, tr, l, r);
}

// O(r-l + log N)
void update(vector<int> &t, vector<int> &a, int p, int tl, int tr, int l, int r) {
	if (l > tr || tl > r)
		return;
	if (l <= tl && tr <= r) {
		build(t, a, p, tl, tr);
		return;
	}

	int m = (tl + tr) / 2;
	update(t, a, p * 2 + 1, tl, m, l, r);
	update(t, a, p * 2 + 2, m + 1, tr, l, r);
	t[p] = t[p * 2 + 1] + t[p * 2 + 2];
}

// O(log N)
void updateOne(vector<int> &t, vector<int> &a, int p, int tl, int tr, int idx, int newVal) {
	if (tl == tr && idx == tl) {
		a[idx] = newVal;
		t[p] = newVal;
		return;
	}
	if (tl >= tr)
		return;

	int m = (tl + tr) / 2;
	updateOne(t, a, p * 2 + 1, tl, m, idx, newVal);
	updateOne(t, a, p * 2 + 2, m + 1, tr, idx, newVal);
	t[p] = t[p * 2 + 1] + t[p * 2 + 2];
}

// t - tree
// p - tree's index
// a - original array
// tl/tr - left/right bounds of tree
// l/r - left/right bounds of original array
// idx - index of original array
// newVal - new value to set

int main() {
	vector<int> v = { 1, 20, 300, 4000, 50000, 600000, 7000000 };
	cout << "original array: ";	print(v);
	const int n = v.size();
	vector<int> tree(n * 4);
	build(tree, v, 0, 0, n - 1);
	cout << "Sum(3..6) = " << sum(tree, 0, 0, n - 1, 3, 6) << "\n";
	for (size_t i = 3; i <= 6; i++)
		v[i] += 2;
	cout << "[3..6] += 2:\n";
	update(tree, v, 0, 0, n - 1, 3, 6);
	cout << "Sum(3..6) = " << sum(tree, 0, 0, n - 1, 3, 6) << "\n\n";

	cout << "Update: [4] = -1:\n";
	updateOne(tree, v, 0, 0, n - 1, 4, -1);
	cout << "original array: ";	print(v);
	print_tree(tree);

	cout << "\n\n\n";
	system("pause");
	return 0;
}
