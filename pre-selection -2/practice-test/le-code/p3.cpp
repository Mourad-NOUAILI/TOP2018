#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 16;

bool found[MAX_N] = {false};

set<int> hasChosen;

int main() {
  
  srand(time(NULL));

  int pos = 1;
  while (!found[pos]) {
    assert(pos <= MAX_N);
    int r =  (rand() % 3) + 1;

    auto it = hasChosen.find(r);
    if (it == hasChosen.end()) {
      hasChosen.insert(r);
      cout << r << '\n';

      string ans;
      cin >> ans;

      if (ans.compare("DONE") == 0)
        break;

      if (ans.compare("YES") == 0) {
        found[pos] = true;
         hasChosen.clear();
         pos++;
      }
    }
    else
      r =  (rand() % 3) + 1;  

  }

  return 0;
}
