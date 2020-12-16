#include <bits/stdc++.h>
using namespace std;
int N, R, C, cnt = 0;
void solve(int n, int u, int d, int l, int r)
{
  if(n == 0)
  {
    return;
  }
  int size = pow(2, 2 * (n - 1));
  int rmid = (u + d) / 2, cmid = (l + r) / 2;
  if(d >= R && R > rmid && l <= C && C <= cmid)
  {
    solve(n - 1, rmid + 1, d, l, cmid);
    cnt += size * 2;
  }
  else if(d >= R && R > rmid && cmid < C && C <= r)
  {
    solve(n - 1, rmid + 1, d, cmid + 1, r);
    cnt += size * 3;
  }
  else if(rmid >= R && R >= u && l <= C && C <= cmid)
  {
    solve(n - 1, u, rmid, l, cmid);
  } 
  else if(rmid >= R && R >= u && cmid < C && C <= r)
  {
    solve(n - 1, u, rmid, cmid + 1, r);
    cnt += size * 1;
  }
}
int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> R >> C;
  solve(N, 0, pow(2, N) - 1, 0, pow(2, N) - 1);
  cout << cnt << endl; 
  return 0;
}