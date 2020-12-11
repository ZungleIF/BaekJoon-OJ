#include <bits/stdc++.h>

//시간초과 wtf
using namespace std;
int N, M, A, B;
map<int, vector<int>> relation;
vector<pair<int, int>> hackable;
queue<int> q;
bool visited[10002];

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  // 해킹 관계를 mapped_type 이 vector 인 map 에 저장, B -> A
  // B 를 해킹하면 A 또한 해킹이 가능하다
  for (int i = 0; i < M; i++)
  {
    cin >> A >> B;
    relation[B].push_back(A);
  }

  int cnt = 0;

  // BFS, 1번 컴퓨터부터 N번 컴퓨터까지 해킹가능한 관계를 나타낸 그래프를
  // BFS 하고 총 개수를 cnt 에 저장한뒤 결과를 hackable 에 넣는다
  for (int i = 1; i <= N; i++)
  {
    q.push(i);
    visited[i] = true;
    while (!q.empty())
    {
      auto cur = q.front(); q.pop();
      ++cnt;
      for (auto pc : relation[cur])
      {
        if (visited[pc])		continue;
        else							  visited[pc] = true;
        q.push(pc);
      }
    }
    hackable.push_back({ cnt, i });
    memset(visited, false, sizeof(visited));
    cnt = 0;
  }

  // 최대값 중에서 중복된 케이스를 검사, 
  // 해당되는 번호들을 vector 인 order 에 넣는다
  // 먼저 hackable pair 은 first 값을 기준으로 내림차순으로 정렬
  sort(hackable.begin(), hackable.end(),
       [](pair<int, int> pa1, pair<int, int> pa2)
       { return pa1.first > pa2.first; });
  auto max_end = hackable.begin();
  auto max_val = hackable.begin()->first;
  while (++max_end != hackable.end() && max_val == max_end->first) {}
  vector<int> order;
  for_each(hackable.begin(), max_end,
           [&order](pair<int ,int> pa)
           { order.push_back((pa.second)); });

  // 오름차순으로 출력하기위한 sort
  sort(order.begin(), order.end());
  copy(order.begin(), order.end(), ostream_iterator<int>(cout," "));
  return 0;
}