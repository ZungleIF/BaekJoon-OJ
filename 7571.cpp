#include <bits/stdc++.h>
using namespace std;
vector<int> r_dots;
vector<int> c_dots;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int r, c;
    cin >> r >> c;
    r_dots.push_back(r);
    c_dots.push_back(c);
  }
  sort(r_dots.begin(), r_dots.end());
  sort(c_dots.begin(), c_dots.end());
  pair<int, int> center{r_dots[M/2], c_dots[M/2]};
  int cnt = 0;
  for_each(r_dots.begin(), r_dots.end(),
           [&cnt, center](const int i)
           {
             cnt += abs(center.first - i);
           }
  );
    for_each(c_dots.begin(), c_dots.end(),
           [&cnt, center](const int i)
           {
             cnt += abs(center.second - i);
           }
  );
  cout << cnt << endl;
  return 0;
}