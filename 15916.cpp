#include <bits/stdc++.h>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  bool cross = false;
  long long int n, k;
  long long int arr[100001];
  arr[0] = 0;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i + 1];
  }
  cin >> k;
  for(long long int i = 1; i <= n; i++)
  {
    if(arr[i] == k * i) 
    {
      cross = true;
      break;
    }
    if(arr[i - 1] > k * (i - 1) && arr[i] < k * i ||
       arr[i - 1] < k * (i - 1) && arr[i] > k * i   )
    {
      cross = true;
      break;  
    }
  }
  cout << (cross ? "T" : "F") << endl;
  return 0;
}