//Carrelage
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Carrelage
 * Lang: C++11
 * Submission result: Accepted
 *Time complexity: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

  int h, w;
  cin >> h >> w;
  
  int side;
  cin >> side;
  
  cout << (h / side) * (w / side) << '\n';

 return 0;
}

