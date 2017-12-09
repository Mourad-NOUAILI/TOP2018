//Le chocolat
/*
 * Constest: TOP2018 - Pre-selection round #2.
 * Subject: Le chocolat (with memoization)
 * Lang: C++11.
* Submission result: Accepted.
* Time complexity:  θ(n)
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = -1e9;

map<int, int> memo;

int x, y, z, r;

int f(int n)  {
 auto it = memo.find(n);
  if (it != memo.end())
      return memo[n];

  if (n == 0) r = 0;
  else if (n < 0) r = INF;
  else r =  max(max(f(n-x), f(n-y)), f(n-z)) + 1;

  memo.insert(pair<int, int>(n, r));

  return r;
}

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

 
  cin >> x >> y >> z;
  
  int ans = f(n);
  

  cout << ans << '\n';

  return 0;
}

