#include <bits/stdc++.h>
using namespace std;
int N, M, a, b;
// if A is hacked, it can lead to hacking hackable[A]
bool visited[10002];
int hackable[10002];
int cnt = 0;

bool DFS(vector<int>* g, int e)
{
	if(visited[e])
  {
		return false;
  }
  else
  {
    visited[e] = true;
    ++cnt;
  }
  for(auto i: g[e])
  {
    DFS(g, i);
  }
	
}

int main()
{
  vector<int> graph[10002];
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}
  for(int i = 1; i <= N; i++)
  {
    DFS(graph, i);
    hackable[i] = cnt;
    cnt = 0;
    memset(visited, false, sizeof visited);
  }
  int max = 0;
  for(auto i: hackable)
  {
    if(max < i)
    {
      max = i;
    }
  }
  vector<int> max_group;
  for(int i = 1; i <=N; i++)
  {
    if(hackable[i] == max)
    {
      max_group.push_back(i);
    }  
  }
  sort(max_group.begin(), max_group.end());
  copy(max_group.begin(), max_group.end(), ostream_iterator<int>(cout, " "));
  return 0;
}