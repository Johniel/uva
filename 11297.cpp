//uva 11297
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>

#define LOOP(i, b, e) for(int i=b; i<e; ++i)
#define REP(i, n) LOOP(i, 0, n)

using namespace std;

static const int MAX_SIZE = 500 + 1;

class RMQ{
public:
  int *n, size;
  RMQ(){}
  RMQ(int a[], int s){ build(a, s); }
  void build(int a[], int s){
    int lg = 1;
    size = s;
    for(int i=1; i<s; i*=2)++lg;
    int *tmp = n = new int[s * lg];
    copy(a, a+s, tmp);
    for(int i=1; i<s; i*=2){
      copy(tmp, tmp+s, tmp+s);tmp += s;
      REP(j, s-i)tmp[j] = min(tmp[j], tmp[j+i]);//min(), max()
    }
    /*
    REP(j, lg){
      REP(i, s)cout << n[i + j * s] << ' ' ;cout << endl;
    }cout << endl << endl;
    //REP(i, s*lg)cout << n[i] <<' ' ;cout << endl;
    */
    return ;
  }
  int query(int b, int e){//[b:e]
    if(e < b)swap(e, b);
    int k;
    for(k = 0; (1 << (k+1)) <= (e-b+1); ++k);
    return min(n[b + size * k], n[e + size * k - (1<<k) + 1]);//min(), max()
  }
};

int main(void)
{
  int n, q;
  int tmp[MAX_SIZE][MAX_SIZE];
  RMQ rmq[2][MAX_SIZE];
  while(true){
    if(cin.eof())break;
    if(!(cin >> n >> n))break;
    if(cin.eof())break;
    REP(i, n){
      REP(j, n)cin >> tmp[i][j]; 
      REP(k, 2){
	rmq[k][i] = RMQ(tmp[i], n); 
	REP(l, n)tmp[i][l] *= -1;
      }
    }
    cin >> q;
    const int MAX = 1, MIN = 0;
    char c;
    int i1, j1, i2, j2, d, b, s;
    REP(i, q){
      b = s = INT_MAX;
      cin >> c;
      if(c == 'c'){
	cin >> i1 >> j1 >> d;
	--i1, --j1;
	tmp[i1][j1] = d;
	REP(k, 2){
	  rmq[k][i1] = RMQ(tmp[i1], n); 
	  REP(l, n)tmp[i1][l] *= -1;
	}
      }
      #define CORRECT(a) a=max(a,0);a = min(a,n-1);
      else{
	cin >> i1 >> j1 >> i2 >> j2;
	--i1; --j1; --i2; --j2;
	CORRECT(i1); CORRECT(j1); CORRECT(i2); CORRECT(j2);
	LOOP(k, i1, (i2+1)){
	  s = min(s, rmq[MIN][k].query(j1, j2));
	  b = min(b, rmq[MAX][k].query(j1, j2));
	}
	cout << -b << ' ' << s << endl;
      }
    }
  }
  return 0;
}
