#include <bits/stdc++.h>
using namespace std;
int N, M, j, k;
bool A[50][50], B[50][50];
void flip(bool arr[50][50], int a, int b)
{
  for(int j = a; j < a + 3; j++)
    for(int k = b; k < b + 3; k++)
      arr[j][k] = 1 - arr[j][k];
}
void in(bool arr[50][50])
{
  char val;
  for(j = 0; j < N; j++)
  {
    for(k = 0; k < M; k++)
    {
      cin.get(val);
      arr[j][k] = val == '1';
    }
    cin.ignore();
  }
}
int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int j, k, cnt = 0;
  bool match = true;
  cin >> N >> M;
  cin.ignore();
  in(A);
  in(B);
  for(j = 0; j < N - 2; j++)
  {
    for(k = 0; k < M - 2; k++)
    {
      if(A[j][k] != B[j][k])
      {
        flip(A, j, k);
        ++cnt;
      }
    }
    for(;k < M; k++)
    {
      if(A[j][k] != B[j][k])
      {
        match = false;
        break;
      }
    }
  }
  for(; j < N; j++)
  {
    for(k = 0; k < M; k++)
    {
      if(A[j][k] != B[j][k])
      {
        match = false;
        break;
      }
    }
  }
	match ? cout << cnt : cout << -1;
  return 0;
}