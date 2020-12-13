// TODO : not finished
#include <bits/stdc++.h>
using namespace std;
int M, N, L;
vector<int> points{0, L};
priority_queue<int> dist;
int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> M >> L;
  for(int i = 0; i < N; i++)
  {
    int val;
    cin >> val;
    points.push_back(val);
  }
  sort(points.begin(), points.end());
  for(int i = 0; i <= N; i++)
    dist.push(points[i + 1] - points[i]);

  int l = 0, r = L, t, m, mid;
  while(l <= r)
  {
    m = M;
    // mid: target cut value
    priority_queue<int> _dist = dist;
    mid = (l + r) / 2;
    while(m > 0)
    {
      t = _dist.top();
      // cut value bigger than or equal to the current top value (cannot cut)
      if(t <= mid)
        break;
      _dist.pop();
      while(t >= mid)
      {
        t -= mid;
        _dist.push(mid);
        if((--m) == 0)
          break;
      }
    }

    t = _dist.top();
    if(m > 0 || t > mid)
    {
      r = mid - 1;
    }
    else if (t < mid)
    {
      l = mid + 1;
    }
    else if ( m == 0 && t == mid)
    {
      break;
    }
  }
  cout << t;
  return 0;
}