#include <bits/stdc++.h>
// each vertex has only one edge can we even call this DFS?
using namespace std;

bool visited[1002];
int perm[1002];
bool new_cycle = true;
int cycle_count = 0;
bool DFS(int n)
{
	if (visited[n])
	{
		return false;
	}
	if (new_cycle)
	{
		new_cycle = false;
		++cycle_count;
	}
		visited[n] = true;
		DFS(perm[n]);
		return true;
}

int main()
{
	int T, n, e;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> e;
			perm[j] = e;
		}
		for (int j = 1; j <= n; j++)
		{
			DFS(j);
			new_cycle = true;
		}
		cout << cycle_count << "\n";
		cycle_count = 0;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}