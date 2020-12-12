#include <bits/stdc++.h>
using namespace std;
size_t N, K, W, V, max = 0;
size_t val[100][2], in[100][2];

size_t knapsack(size_t n, size_t v, size_t w, bool fill)
{
  if(fill)
  {
    w += in[n][1];
    if(w > K) return v;
    v += in[n][0];
  }
  if(n + 1 > N) return v;
  auto a = knapsack(n + 1, v, w, true);
  auto b = knapsack(n + 1, v, w, false);
  a = std::max(a, b);
  return a;
}
int main()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    cin >> in[i][0] >> in[i][1];
  }
  auto a = knapsack(0, 0, 0, true);
  auto b = knapsack(0, 0, 0, false);
  a = std::max(a, b);
  cout << a << endl;
  return 0;
}