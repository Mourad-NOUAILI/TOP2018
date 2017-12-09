//Le chiffre de la chance
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Le chiffre de la chance
 * Lang: C++11
 * Submission result: Accepted
 *Time complexity: O(m*n)
*/
#include <bits/stdc++.h>

using namespace std;


int reduce1(string n) {
  int s = 0;
  int len = n.size();
  for (int i = 0 ; i < len ; ++i) {
    int d = n[i] - '0';
    s += d;
  }

  return s;
}

int reduce2(int n) {
  int s = 0;
   while (n != 0) {
      s += n % 10;
      n /= 10;
    }
   return s;
}

int main() {

  int m;
  cin >> m;
  
  while (m--) {
    string x;
    cin >> x;
    
    int s = reduce1(x);
        
   
    do {
      s = reduce2 (s);
    }while (s >= 10);

   

    cout << s << '\n';

  }
  
 return 0;
}

