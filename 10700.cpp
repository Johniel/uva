#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int NUM = 12;

class F{
public:
  int size;
  lli num[NUM];  
  F(){
    size = 0;
    fill(num, num + NUM, -1ll);
  }
  void add(int n){
    num[size++] = n;
  }
  void calc(int i, char o){
    int j;
    for(j=i+1; num[j] == -1ll; ++j);
    for(i; num[i] == -1ll; --i);
    if(o == '+'){
      num[i] = num[i] + num[j];
    }
    if(o == '*'){
      num[i] = num[i] * num[j];
    }
    num[j] = -1;
  }  
  void test() const {
    for(int i=0; i<size; ++i){
      cout << num[i] << ' ' ;
    }
    cout << endl;
  }
};
bool operator < (const F &a, const F &b)
{  
  for(int i=0; i<NUM; ++i){
    if(a.num[i] != b.num[i])return a.num[i] < b.num[i];
  }
  return false;
}

pair<lli, lli> solve(F f, char op[])
{
  const int M = 1 << NUM;
  F mx[M];
  F mn[M];
  mx[0] = mn[0] = f;
  int b = 1 << (f.size - 1);
  for(int i=0; i<(1 << (f.size-1)); ++i){
    for(int j=0; j<f.size-1; ++j){
      if(i & (1 << j))continue;
      int nx = i | (1 << j);
      {
	F tmp = mx[i];
	tmp.calc(j, op[j]);
	if(mx[nx].size == 0)mx[nx] = tmp;
	else mx[nx] = max(mx[nx], tmp);	
      }
      {
	F tmp = mn[i];
	tmp.calc(j, op[j]);
	if(mn[nx].size == 0)mn[nx] = tmp;
	else mn[nx] = min(mn[nx], tmp);	
      }
    }
  }
  pair<lli, lli> re;
  --b;
  for(int i=0; i<f.size; ++i){
    if(mx[b].num[i] != -1ll)re.first = mx[b].num[i];
    if(mn[b].num[i] != -1ll)re.second = mn[b].num[i];
  }
  return re;
}

#include <cstdio>
int main(void)
{
  int tc;
  char buff[10];
  char op[NUM];
  cin >> tc;  
  while(tc--){
    string s;
    int size = 0;
    int b = 0;
    F f;
    cin >> s;
    for(int i=0; i<s.size(); ++i){
      if(isdigit(s[i])){
	buff[b++] = s[i];
      }
      else{
	buff[b] = '\0';
	f.add((lli)atoi(buff));	
	b = 0;
	op[size++] = s[i];
      }
    }
    buff[b] = '\0';
    f.add(atoi(buff));	
    pair<lli, lli> p =solve(f, op);
    cout << "The maximum and minimum are " << p.first 
	 << " and " << p.second << "." << endl;
  }  
  return 0;
}
