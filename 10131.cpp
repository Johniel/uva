#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int INF = INT_MAX;

struct data{
  int w, s, i;
  data(){};
  data(int _w, int _s, int _i)
    : w(_w), s(_s), i(_i) {};
};

bool operator < (const data &a, const data &b)
{
  if(a.w != b.w)return a.w < b.w;
  return a.s < b.s;
}

void LIS(const int num[], const int size, const vector<data> &input)
{
  int t[size];
  int ind[size];
  int len = INT_MIN;
  fill(t, t + size, INF);
  REP(i, size){
    ind[i] = distance(t, lower_bound(t, t + size, num[i]));
    t[ ind[i] ] = num[i];
  }
  len = *max_element(ind, ind + size);
  /*
  REP(i, size)cout << num[i] << ' ';cout << endl;
  REP(i, size)cout << t[i] << ' '; cout << endl;
  REP(i, size)cout << ind[i] << ' ';cout << endl;
  cout << len << endl;
  */
  int tmp = len;
  int result[len+1];
  REP(i, size){
    if(ind[size-1-i] == len)
      result[len--] = size-1-i;  
  }
  printf("%d\n", tmp + 1);
  REP(i, tmp+1){
    printf("%d\n", input[result[i]].i + 1);
  }
  return ;
}

int main(void)
{
  vector<data> input;
  data tmp;
  int cnt = 0;
  while(cin >> tmp.w >> tmp.s){
    tmp.i = cnt++;
    input.push_back(tmp);
  }
  sort(input.begin(), input.end());
  int num[input.size()];
  for(int i = 0; i < input.size(); ++i){    
    //cout << input[i].w << ' ' << input[i].s << endl;
    num[i] = -input[i].s;
  }
  LIS(num, input.size(), input);
  return 0;
}
