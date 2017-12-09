//L'extraterrestre
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Jeu de cartes
 * Lang: C++11
 * Submission result: Accepted
 *Time complexity: O(log n)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 31;
const long long MAX_PRESSURE = 2e9;

set<long long> hasChosen;

int main() {
  ios::sync_with_stdio(false);
  
  srand(time(NULL));

  int t = 1;
  long long up = MAX_PRESSURE;
  long long down = 1;
  while (t++ <= 31) {

    long long m = (up + down) / 2;

    cout << m << '\n';

    string ans;
    cin >> ans;

    if (ans.compare("FLOATS") == 0)
      up = m - 1;

    if (ans.compare("SINKS") == 0)
      down = m + 1;

    if (ans.compare("OK") == 0)
      break;
  }

  return 0;
}
