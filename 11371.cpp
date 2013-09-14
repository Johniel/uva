#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

static const int L = 11;
static char s[L], t[L];

typedef long long int lli;

inline 
lli mx()
{
  lli l = strlen(s), r = 0;
  priority_queue<int> Q;
  for(int i=0; i<l; ++i)
    Q.push(s[i] - '0');
  while(true){
    //cout << r << endl;
    r += Q.top();
    Q.pop();
    if(Q.empty())break;
    r *= 10;
  }
  return r;
}

inline 
lli mn()
{  
  int l = strlen(s), i, cnt = 0;
  sort(s, s + l);
  for(i=0; i<l; ++i){
    if(s[i]-'0'){
      t[cnt] = s[i];
      break;
    }
  }
  // cout << t << ' ' << s << endl;
  for(int j=0; j<l && j != i && s[j] == '0'; ++j)
    t[++cnt] = s[j];
  //cout << t << endl;
  for(int j=i+1; j<l && j != i; ++j)
    t[++cnt] = s[j];
  //cout << t << endl;
  return atoi(t);
}

int main(void)
{
  int n;
  fill(s, s + L, '\0');
  fill(t, t + L, '\0');
  while(scanf("%s\n", s) != EOF){
    int tmp = atoi(s);
    fill(s, s + L, '\0');
    sprintf(s, "%d", tmp);
    //cout << "s = " << s << endl;
    lli x = mx();
    lli n = mn();
    cout << x << " - " << n << " = " << x-n 
	 << " = 9 * " <<  (x-n)/9 << endl;
    fill(s, s + L, '\0');
    fill(t, t + L, '\0');
  }
  return 0;
}
