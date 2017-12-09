#include <bits/stdc++.h>

using namespace std;

/*
int maxProduct(vector<int> v) {
  int curMaxP = v[0];
  int curMinP = v[0];
  int maxP = v[0];

  for(int i = 1; i < v.size(); i++){

    if(v[i] > 0){
      curMaxP = max(curMaxP * v[i], v[i]);
      curMinP = min(curMinP * v[i], v[i]);
    } 
    else{
      int curMaxPNeg = max(curMinP * v[i], v[i]);
      curMinP = min(curMaxP * v[i], v[i]);
      curMaxP = curMaxPNeg;
    }
    maxP = max(maxP, curMaxP);
  }
  return maxP;
}*/

/*
static int product(vector<int> A, int begin, int end)
{
	int i, step, mh, ma;

	step = begin>end?-1:1;

	ma = A[begin]; mh = 1;
	for (i = begin; i != end; i += step) {
		mh *= A[i];
		if (mh > ma)
			ma = mh;
		if (A[i] == 0)
			mh = 1;
	}

	return ma;
}

int max_subarray_product(vector<int> A, int n)
{
	int x, y;
	x = product(A, 0, n-1);
	y = product(A, n-1, 0);
	return x>y?x:y;
}*/


int maxProduct(vector<int> A, int n) {
  if (n==0) return 0;

  int maxi = 1, mini = 1;
  int out = INT_MIN;

  for (int i=0;i<n;i++) {
    int oldmaxi = max(maxi,1);
    if (A[i] > 0) {
      maxi = oldmaxi*A[i];
      mini *= A[i];
      }
    else {
      maxi = mini*A[i];
      mini = oldmaxi*A[i];
    }

    out = max(out,maxi);
  }

  return out;
} 

int main() {

  int n;
  cin >> n;

  vector<int> v;

  for (int i = 0 ; i < n ; ++i) {
    int val;
    cin >> val;
    v.push_back(val);
  }

  cout << maxProduct(v, n) << '\n';

 return 0;
}
