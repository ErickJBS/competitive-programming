/*
* Bytelandian gold coins
* from: https://www.codechef.com/problems/COINS
*/

#include <iostream>
#include <map>
typedef long long int big;

using namespace std;

map<big, big> dp;

big exchange(big n) {
  if (n == 0) return 0;
  if (dp.find(n) != dp.end())
    return dp[n];

  big trade = exchange(n/4) + exchange(n/3) + exchange(n/2);
  big result = (trade > n)? trade : n;
  dp.insert(pair<big, big>(n, result));
  return result;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  big N;
  while(cin >> N) {
    cout << exchange(N) << endl;
  }

  return 0;
}
