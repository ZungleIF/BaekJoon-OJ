#include <bits/stdc++.h>
using namespace std;
int N, C, S;
vector<pair<int, int>> bv;
map<int, multiset<int>> m;
int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> C >> S;
    bv.push_back({ C, S });
    m[C].insert(S);
  }

  for (int i = 0; i < N; i++)
  {
    int score = 0;
    int color = bv[i].first;
    int size = bv[i].second;
    // start searching
    for (auto sit = m.begin(); sit != m.end(); sit++)
    {
      if(sit->first == color) continue;
      auto begin = sit->second.begin();
      auto lb = sit->second.lower_bound(size);
      --begin; --lb;
      for (; lb != begin; lb--)
      {
        score += *lb;
      }
    }
    cout << score << '\n';
  }
  return 0;
}