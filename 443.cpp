#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <complex>
#include <cstdlib>
#include <climits>
#include <utility>
#include <sstream>

#define REP(i, n) for(long long i=0; i<(long long)n; i++)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const long long N = 5842 + 1;

long long num[N];

const long long m[4] = {2, 3, 5, 7};
const string s[4] = {"st", "nd", "rd", "th"};

int main(void)
{                                               
  priority_queue<long long, vector<long long>, greater<long long> > que;
  que.push(1);
  REP(i, N){
    long long tmp = que.top();
    que.pop();
    if(que.size() > 1)if(tmp == que.top()){i--;continue;}
    REP(j, 4)
      que.push(tmp*m[j]);
    num[i] = tmp;
  }
  while(true){
    long long n;
    cin >> n;
    if(n == 0)break;
    long long c;
    if(n%10){
      if(n % 10 == 1 && n % 100 != 11)
	c = 0;
      else if(n%10 == 2 && n%100 != 12)
	c = 1;
      else if(n%10 == 3 && n%100 != 13)
	c = 2;
      else c = 3;
    }
    else c = 3;
    cout << "The " << n << s[c] << " humble number is " << num[n-1] << "." << endl;
  }
  return 0;
}
