#include <bits/stdc++.h>
using namespace std;
pair<int, int> fib_mem[41] = {{1, 0}, {0, 1}, {1, 1}};
pair<int, int> fibonacci(int n) {
  if(fib_mem[n] != make_pair(0, 0))
  {
    return fib_mem[n];
  }
  else
  {
    auto a = fibonacci(n - 1);
    auto b = fibonacci(n - 2);
    return fib_mem[n] = make_pair(a.first + b.first, a.second + b.second);
  } 
  
}
int main()
{
  fibonacci(40);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    cout << fib_mem[n].first << " " << fib_mem[n].second << endl;
  }
  return 0;
}