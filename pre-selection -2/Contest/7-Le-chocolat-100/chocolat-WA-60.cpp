//Le chocolat
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 31;

set<int> s;

int getAns(int n, int a) {
  if (n % a == 0) 
    return n / a;
  
  int ans = 0;
  while (n > 0) {
    ans++;
    n -= a;
    if (s.find(n) != s.end()) {
      ans++;
      break;
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int x, y , z;
  cin >> x >> y >> z;

  s.insert(x);
  s.insert(y);
  s.insert(z);

  int ans = 0;
  for (auto a: s)
    ans = max(ans, getAns(n, a));

  cout << ans << '\n';

  return 0;
}

