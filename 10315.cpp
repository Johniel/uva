#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

typedef long long int lli;

//#define TEST

class Card{
public:
  int n, s;
  void read(void){    
    string t;

    cin >> t;    

    char c = t[(int)t.size() - 1];

    if(c == 'C')s = 0;
    else if(c == 'D')s = 1;
    else if(c == 'H')s = 2;
    else if(c == 'S')s = 3;

    if(isdigit(t[0])){
      n = t[0] - '0';
    }
    else{
      if(t[0] == 'T')n = 10;
      else if(t[0] == 'J')n = 11;
      else if(t[0] == 'Q')n = 12;
      else if(t[0] == 'K')n = 13;	
      else if(t[0] == 'A')n = 14;
    }
    return ;
  }
};
bool operator < (const Card &a, const Card &b)
{
  if(a.n != b.n)return a.n < b.n;
  else return a.s < b.s;
}

lli HighCard(Card c[])
{
  lli sum = 0;
  for(int i=5; i--; ){
    sum += c[i].n;
    sum *= 100;
  }
  return sum;
}

pair<int, lli> solve(Card c[])
{
  int cnt[15][4];
  fill(&cnt[0][0], &cnt[15 - 1][4], false);
  sort(c, c + 5);

  for(int i=0; i<5; ++i){
    ++cnt[c[i].n][c[i].s];
  }

  int p[5], h[5];  
  bool flush = (c[0].s == c[1].s && 
		c[1].s == c[2].s && 
		c[2].s == c[3].s && 
		c[3].s == c[4].s);
  bool straight = (c[0].n + 1 == c[1].n && 
		   c[1].n + 1 == c[2].n && 
		   c[2].n + 1 == c[3].n &&
		   c[3].n + 1 == c[4].n);
  fill(p, p + 5, 0);
  fill(h, h + 5, 0);
  for(int i=0; i<15; ++i){    
    int tmp = cnt[i][0] + cnt[i][1] + cnt[i][2] + cnt[i][3];
    ++p[tmp];        
    h[tmp] = max(h[tmp], i);
  }   
#ifdef TEST
  cout << p[1] << ' ' << p[2] << ' ' << p[3] << ' ' << p[4] << endl;
#endif

  int mx = c[4].n;
  if(flush && straight){
    return make_pair(8, mx);
  }
  if(p[4]){
    return make_pair(7, h[4]);  
  }
  if(p[3] && p[2]){
    return make_pair(6, h[3]);
  }
  if(flush){
    return make_pair(5, HighCard(c));
  }
  if(straight){
    return make_pair(4, mx);
  }
  if(p[3]){
    return make_pair(3, h[3]);
  }
  if(p[2] == 2){
    int sum = h[2];
    for(int i=0; i<h[2]; ++i){
      int tmp = cnt[i][0] + cnt[i][1] + cnt[i][2] + cnt[i][3];
      if(tmp == 2)sum = sum * 100 + i;
    }
    for(int i=0; i<5; ++i){
      if(h[2] == c[i].n || sum % 10 == c[i].n)continue;
      sum = sum * 100 + c[i].n;
      break;
    }
    return make_pair(2, sum);
  }
  if(p[2]){
    int sum = h[2];
    for(int i=0; i<5; ++i){
      if(c[i].n != h[2]){
	sum = sum * 100 + c[i].n;
      }
    }
    return make_pair(1, sum);
  }
  return make_pair(0, HighCard(c));
}

int main(void)
{
  int cnt = 0;
  while(true){
    Card w[5], b[5];
    for(int i=0; i<5; ++i){
      b[i].read();
    }
    for(int i=0; i<5; ++i){
      w[i].read();
    }
    if(cin.eof())break;
#ifndef TEST
    pair<int, lli> x = solve(b);
    pair<int, lli> y = solve(w);
#endif
#ifdef TEST
    cout << "--------------------------------------   " << cnt++ << endl;
    pair<int, lli> x = solve(b);
    pair<int, lli> y = solve(w);
    cout << x.first << ' ' << x.second << endl;
    cout << y.first << ' ' << y.second << endl;

    cout << "W : ";
    for(int i=0; i<5; ++i){
      cout << "(" << w[i].n << ',' << w[i].s << ") " ;
    }
    cout << endl;

    cout << "B : ";
    for(int i=0; i<5; ++i){
      cout << "(" << b[i].n << ',' << b[i].s << ") " ;
    }
    cout << endl;
#endif

    if(x == y)cout << "Tie." << endl;
    else cout << (x < y ? "White wins." : "Black wins.") << endl;
  }
  return 0;
}
