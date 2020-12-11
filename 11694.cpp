#include <bits/stdc++.h>
using namespace std;
int N;
size_t one_cnt = 0;
bitset<32> xor_sum(0);
string winner;
const string k("koosaga"), c("cubelover");
int main()
{
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    unsigned int pile;
    cin >> pile;
    if(pile == 1)
    {
      ++one_cnt;
    }
    xor_sum ^= pile;
  }
  if(one_cnt > 0)
  {
    if(one_cnt % 2 == 1)
    {
      if(N == one_cnt)
        winner = c;
      else
        winner = xor_sum.any() ? k : c;
    }
    else
    {
      winner = xor_sum.any() ? c : k;
    }
  }
  else
  {
    winner = xor_sum.any() ? k : c;
  }
  cout << winner;
  return 0;
}