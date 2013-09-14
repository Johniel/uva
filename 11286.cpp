#include <iostream>
#include <map>
#include <vector>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

typedef unsigned long long int ulli;

const int N = 500, S = 10000, M = 5, ID = 1 << M;

bool used[M];
ulli tmp[M], student[S];
int s, id;

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    map<ulli, int> cnt;
    int mx = -1;
    s = 0;
    id = 0;
    for(int i=0; i<n; ++i){
       ulli num = 0;
       for(int j=0; j<M; ++j)
	 cin >> tmp[j];
       sort(tmp, tmp + M);
       for(int j=0; j<M; ++j)
	 num = num * 100 + tmp[j];
       mx = max(++cnt[student[i] = num], mx);
    }
    vector<ulli> v;
    FOR(itr, cnt){
      if(itr->second == mx){
	v.push_back(itr->first);
      }
    }
    int result = 0;
    for(int i=0; i<n; ++i){
      bool flg = false;
      FOR(itr, v){
	if(student[i] == *itr){
	  flg = true;
	  break;
	}
      }
      result += flg;
    }
    cout << result << endl;
  }
  return 0;
}
