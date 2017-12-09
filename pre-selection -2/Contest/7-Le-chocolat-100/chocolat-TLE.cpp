//Le chocolat
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Le chocolat
 * Lang: C++11
* Submission result: TLE (recursion without memoization)
* Time complexity:  θ(2n/3)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 31;
const int INF = -1e9;

map<int, int> memo;

int x, y, z;

int f(int n) {
  if (n == 0) return 0;
  if (n < 0) return INF;
  return max(max(f(n-x), f(n-y)), f(n-z)) + 1;
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

