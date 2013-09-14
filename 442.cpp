#include <iostream>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int M_SIZE  = 'z' + 1;

typedef struct{
  int h, w;
  bool used;
}matrix;

matrix M[M_SIZE];

char name;

string s;

bool multible(matrix a, matrix b)
{
  return (a.w == b.h)? true : false;
}

int pars(void)
{
  int cnt = 0;
  REP(i, s.size()-1){
    //cout << s << endl;
    if( isalpha(s[i]) && isalpha(s[i+1]) ){ 
      if( !multible( M[s[i]], M[s[i+1]] ) )return -1;
      else{
	cnt += M[s[i]].h// * M[s[i]].w
	  * M[s[i+1]].h * M[s[i+1]].w;
	//cout << cnt << endl;
	M[name].h = M[s[i]].h;
	M[name].w = M[s[i+1]].w;
	s[i] = name;
	name++;
	s.erase(i+1, 2);
	s.erase(i-1, 1);
	i = 0;
	continue;
      }
    }
  }
  return cnt;
}

int main(void)
{
  int n;
  cin >> n;
  REP(i, M_SIZE)M[i].used = false;
  REP(i, n){
    char c;
    cin >> c;
    cin >> M[c].h >> M[c].w;
    M[c].used = true;
  }
  cin.ignore();
  while(true){ 
    getline(cin, s);
    if(cin.eof())break;
    name = 'a';
    int re = pars();
    if(re < 0)cout << "error" << endl;
    else cout << re << endl;
  }
  return 0;
}
