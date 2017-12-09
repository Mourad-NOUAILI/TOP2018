//Les clips
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Les clips
 * Lang: C++11
 * Submission result: Accepted
 *Time complexity: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  (b <= c  || d <= a ) ? cout << "NO" : cout << "YES";

 return 0;
}

