//uva 11107, 760
//generalized suffix array
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

#define LOOP(i, b, e) for(int i=(int)b; i<(int)e; ++i)
#define REP(i, n) LOOP(i, 0, n)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int SIZE = 2;// num of string
static const int LEN = SIZE * 300 + SIZE;// total length

struct SuffixArray{
  int idx[LEN], size;
  char *S;
};

struct SACmp{
  int h, *g;// h-order, g:group No.
  SACmp(int _h, int *_g) : h(_h), g(_g) {}
  bool operator () (int a, int b){
    return (g[a] != g[b])? g[a] < g[b] : g[a + h] < g[b + h];
  }
};

struct RMQ{
  int *n, size; 
};

struct Str{
  char *s;
  int size;
  Str(char *_s, int _size) : s(_s), size(_size) {}
  bool operator < (const Str &t) const {
    return strncmp(s, t.s, min(size, t.size)) < 0;
  }
};

void buildRMQ(RMQ &rmq, int a[], int s, int l[])
{
  int lg = 1;
  rmq.size = s;
  for(int i=1; i<s; i*=2)++lg;
  int *tmp = rmq.n = l;
  copy(a, a+s, tmp);
  for(int i=1; i<s; i*=2){
    copy(tmp, tmp+s, tmp+s); tmp += s;
    REP(j, s-i)tmp[j] = min(tmp[j], tmp[j+i]);//min(), max()
  }
  return ;
}

int query(const RMQ &rmq, int b, int e)//[b:e]
{
  int k = 0, x = e-b, *n = rmq.n, size = rmq.size;
  for(k = 0; (1 << (k+1)) <= (e-b+1); ++k);
  return min(n[b + size * k], n[e + size * k - (1<<k) + 1]);
}

void buildSA(SuffixArray &sa, char *s)
{
  static int a[LEN], g[LEN], len;// a::skip & range, g::group
  int size = sa.size = strlen(sa.S = s), *v = sa.idx;// value
  REP(i,size)v[i] = i, a[i] = s[i];
  g[0] = g[size-1] = 0;
  sort(v, v+size, SACmp(0, g));// 0-order
  for(int h = 1; g[size-1] != size-1; h *= 2){
    SACmp cmp(h, a);
    sort(v, v + size, cmp);// 2^n-order;
    REP(i, size-1)g[i+1] = g[i] + cmp(v[i], v[i+1]); 
    REP(i, size)a[v[i]] = g[i];
  }
  return ;
}

void buildLCP(SuffixArray sa, RMQ &lcp, int *lca)
{
  static int height[LEN], rev[LEN];
  int h = 0;
  REP(i, sa.size)rev[sa.idx[i]] = i;
  REP(i, sa.size){
    if(rev[i]){
      int j = sa.idx[rev[i]-1];
      while(sa.S[j + h] == sa.S[i + h])++h;
      height[rev[i]-1] = h;
    } 
    else height[rev[i]-1] = -1;
    if(h)--h;
  }
  buildRMQ(lcp, height, sa.size-1, lca);
  return ;
}

inline
bool isSymbol(char c)
{
  return c < 'A';
}

void MCS(SuffixArray sa, int mult, int len, int n)
{
  const int TMP = LEN * 100;//n * log2 n
  static int lca[TMP], sym[SIZE + 1], leaf[LEN], contain[SIZE];
  set<Str> result;
  RMQ lcp;
  int cnt = 0;
  fill(contain, contain + sa.size, 0);
  buildLCP(sa, lcp, lca);
  REP(i, sa.size){
    if(isSymbol(sa.S[i]))
      sym[cnt++] = i;
  }
  REP(i, sa.size)
    leaf[i] = lower_bound(sym, sym + n, sa.idx[i]) - sym;  
  int begin = 0, end = 0, sum = 1, ans = max(len, 1);
  ++contain[leaf[end]];
  while(begin < sa.size && end < sa.size){//
    while(end+1 < sa.size){
      ++end;
      if(contain[leaf[end]] == 0)
	++sum;
      ++contain[leaf[end]];
      if(!(sum < mult && end < sa.size))
	break;
    } 
    while(begin <= end){
      if(contain[leaf[begin]] == 1)
	break;
      --contain[leaf[begin]];
      ++begin;
    }    
    if(sum < mult || !(begin <= end))break;
    int tmp = query(lcp, begin, end-1);
    if(ans < tmp && !isSymbol(sa.S[sa.idx[begin]])){
      ans = tmp;
      result.clear();
    }
    if(ans == tmp && tmp != 0 && !isSymbol(sa.S[sa.idx[begin]])){      
      result.insert(Str(sa.S + sa.idx[begin], ans));
    }
    while(true){
      if(contain[leaf[begin]] == 1)
	--sum;
      --contain[leaf[begin]];
      ++begin;
      if(sum < mult || !(begin < sa.size) || !(begin <= end))
	break;
    }
  }
  if(result.size()){   
    FOR(i, result){
      REP(j, i->size)printf("%c", i->s[j]);
      printf("\n");
    }
  }
  else printf("No common sequence.\n");
  return ;
}

void display(SuffixArray sa)
{  
  REP(i, sa.size)
    printf("%3d : %3d : %s\n", i, sa.S, (char*)(sa.idx[i] + sa.S));
}

int main(void)
{
  SuffixArray sa;
  bool flg = true;
  string a, b;
  while(true){
    getline(cin, a);
    getline(cin, b);
    if(cin.eof())break;
    if(flg)flg = false;
    else cout << endl;
    int l;
    a += '$' + b + '#';
    buildSA(sa, (char*)a.c_str());
    MCS(sa, 2, 0, 2);
    if(cin.eof())break;
    cin.ignore();
  }
  return 0;
}
