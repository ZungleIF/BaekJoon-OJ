#include <bits/stdc++.h>
using namespace std;
int main()
{
  int arr[11], temp_arr[11];
  int N;
  cin >> N;
  fill(begin(arr), end(arr), 1);
  fill(begin(temp_arr), end(temp_arr), 0);
  for(int i = 1; i < N; i++)
  {
    for(int j = 1; j <= 10; j++)
    {
      for(int k = 1; k <= j; k++)
        temp_arr[j] += arr[k];
      temp_arr[j] %= 10007;
    }
    for(int j = 1; j <= 10; j++)
      arr[j] = temp_arr[j];
    fill(begin(temp_arr), end(temp_arr), 0);
  }
  int sum = 0;
  for(int i = 1; i <= 10; i++)
    sum += arr[i];
  sum %= 10007;
  cout << sum;
  return 0;
}