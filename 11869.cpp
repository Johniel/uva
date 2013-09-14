#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <sstream>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

class Ml{
public:
  lli name;
  map<lli, char*> var;
  map<lli, Ml*> next;
  Ml(){}
  ~Ml(){
    FOR(i, next){
      delete i->second;
    }
  }
  Ml* parse(void);
  char* query(char t[]);
  lli hash(int a, int b, int c);
  lli hash(char t[]);
};

const int S = 1000 + 1;
const int L = 100 + 1;

int size;
int len[S];
char s[S][L];

const lli MOD =  10000007;
const lli PRIME = 43;

inline
lli 
Ml::hash(int a, int b, int c)
{
  lli sum = 0;
  for(int i=b; i<=c; ++i){
    sum += (s[a][i] - 'a' + 1);
    sum *= PRIME;
    sum %= MOD;
  }
  return sum;
}

inline
lli 
Ml::hash(char t[])
{
  int lim = strlen(t);
  lli sum = 0;
  for(int i=0; i<lim; ++i){
    if(t[i] == '.' || t[i] == '\"')break;
    if(t[i] == '[' || t[i] == ']')break;
    sum += (t[i] - 'a' + 1);
    sum *= PRIME;
    sum %= MOD;    
  }
  return sum;
}

int idx;

inline
Ml*
Ml::parse(void)
{
  int i;
  if(s[idx][1] == '/')return (Ml*)NULL;
  for(i=1; i<len[idx]; ++i){
    if(s[idx][i] == ' ' || s[idx][i] == '>'){
      name = hash(idx, 1, i-1);
      ++i;
      break;
    }
  }
  int a = i++;
  while(i < len[idx]){
    for(int f = 1; i<len[idx]; ++i){
      if(s[idx][i] == '='){
	lli h = hash(idx, a, i-1);
	var.insert(make_pair(h, s[idx] + i + 2));    
	for(i+=2; i<len[idx]; ++i){
	  if(s[idx][i] == '\"'){
	    f = 0;
	    s[idx][i] = '\0';
	    break;
	  }
	}
      }
      if(!f)break;
    }    
    a = i + 2;
  }
  ++idx;
  for(Ml *m, *n; idx < size; ++idx){
    m = new Ml();
    n = m->parse();    
    if(n)next.insert(make_pair(m->name, m));
    else {
      delete m;
      break;
    }
  }
  return this;
}

inline
char*
Ml::query(char t[])
{
  map<lli, Ml*>::iterator itr = next.find(hash(t));
  if(itr == next.end()){
    return (char*)NULL;
  }
  int i;
  for(i = 0; ; ++i){
    if(t[i] == '.')break;
    if(t[i] == '[')break;
  }
  if(t[i] == '.')return itr->second->query(t + i + 1);
  else{
    lli h = hash(t + i + 2);
    map<lli, char*>::iterator i = itr->second->var.find(h);
    if(i == itr->second->var.end())return (char*)NULL;
    else return i->second;
  }
  return (char*)NULL;
}

int main(void)
{
  int tc, cnt = 0;
  char p[S * L];
  scanf("%d", &tc);
  while(tc--){
    scanf("%d\n", &size);
    REP(i, size){
      gets(s[i]);
      len[i] = strlen(s[i]);
    }
    idx = 0;
    Ml *root = new Ml(), *src = new Ml();
    src->parse();
    root->next.insert(make_pair(src->name, src));
    int q;
    scanf("%d\n", &q);
    printf("Case %d:\n", ++cnt);
    while(q--){
      gets(p);
      char *m = root->query(p);
      if(m)puts(m);
      else puts("Undefined");
    }    
    delete root;
  }
  return 0;
}
