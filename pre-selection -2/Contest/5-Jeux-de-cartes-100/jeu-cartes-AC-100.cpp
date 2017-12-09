//Jeu de cartes
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Jeu de cartes
 * Lang: C++11
* Submission result: Accepted
*Time complexity: O(n)
*/
#include <bits/stdc++.h>

using namespace std;

multiset <int> all, allPositive, allNegative;
set <int> zero;

int main() {

  int n;
  cin >> n;

  for (int i = 0 ; i < n ; ++i) {
    int val;
    cin >> val;
    if (val == 0) zero.insert(val);
    if (val > 0) allPositive.insert(val);
    if (val < 0) allNegative.insert(val);
  }

  all.insert(allPositive.begin(), allPositive.end());
  all.insert(allNegative.begin(), allNegative.end());

  if (n == 1) {
    cout << *all.begin() << '\n';
    return 0;
  }

  if (allNegative.size() == 0 && allPositive.size() == 0 && zero.size() == 1) {
    cout << "0\n";
    return 0;
  }

  if (zero.size() == 1 && allNegative.size() == 1 && allPositive.size() == 0) {
    cout << "0\n";
    return 0;
  }

  if (allNegative.size() == 1 && allPositive.size() == 1) {
    cout << *allPositive.begin() << '\n';
    return 0;
  }
  
  if (allNegative.size() > 1 && allNegative.size() % 2 != 0) {
    int p = 1;
    auto it = allNegative.end();
    --it;
    allNegative.erase(it);
    
    for(auto e: allNegative)
      p *= e;

    for(auto e: allPositive)
      p *= e;

    cout << p << '\n';
    return 0;
  }

  if (allNegative.size() > 1 && allNegative.size() % 2 == 0) {
    int p = 1;
    for(auto e: all)
      p *= e;

    cout << p << '\n';
    return 0;
  }

  if (allNegative.size() == 0 && allPositive.size() >= 1) {
    int p = 1;
    for(auto e: allPositive)
      p *= e;

    cout << p << '\n';

  }

 return 0;
}
