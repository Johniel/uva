#include <iostream>
#include <algorithm>

using namespace std;
/*
 * c: finger 2~4, 7~10
 * d: finger 2~4, 7~9
 * e: finger 2~4, 7, 8
 * f: finger 2~4, 7
 * g: finger 2~4
 * a: finger 2, 3
 * b: finger 2
 * C: finger 3
 * D: finger 1~4, 7~9
 * E: finger 1~4, 7, 8
 * F: finger 1~4, 7
 * G: finger 1~4
 * A: finger 1~3
 * B: finger 1~2 
 */

void B(int cnt[]){ ++cnt[0]; ++cnt[1]; }
void A(int cnt[]){ ++cnt[0]; ++cnt[1]; ++cnt[2]; }
void G(int cnt[]){ ++cnt[0]; ++cnt[1]; ++cnt[2]; ++cnt[3]; }
void F(int cnt[]){ G(cnt); ++cnt[6]; }
void E(int cnt[]){ F(cnt); ++cnt[7]; }
void D(int cnt[]){ E(cnt); ++cnt[8]; }
void C(int cnt[]){ ++cnt[2]; }
void b(int cnt[]){ ++cnt[1]; }
void a(int cnt[]){ C(cnt); b(cnt); }
void g(int cnt[]){ a(cnt); ++cnt[3]; }
void f(int cnt[]){ g(cnt); ++cnt[6]; }
void e(int cnt[]){ f(cnt); ++cnt[7]; }
void d(int cnt[]){ e(cnt); ++cnt[8]; }
void c(int cnt[]){ d(cnt); ++cnt[9]; }

void dif(int cnt[], int prev[], int now[])
{
  for(int i=0; i<10; ++i){
    if(prev[i] == 0 && now[i] == 1)++cnt[i];
    prev[i] = now[i];
  }
}

int main(void)
{
  int tc, cnt[10], prev[10], now[10];
  cin >> tc;
  for(cin.ignore(); tc--; ){
    string s;
    fill(cnt, cnt + 10, 0);
    fill(prev, prev + 10, 0);
    getline(cin, s);
    for(int i=0; i<s.size(); ++i){
      fill(now, now + 10, 0);
      if(s[i] == 'B')B(now);	
      if(s[i] == 'A')A(now);
      if(s[i] == 'G')G(now);
      if(s[i] == 'F')F(now);
      if(s[i] == 'E')E(now);
      if(s[i] == 'D')D(now);
      if(s[i] == 'C')C(now);
      if(s[i] == 'b')b(now);
      if(s[i] == 'a')a(now);
      if(s[i] == 'g')g(now);
      if(s[i] == 'f')f(now);
      if(s[i] == 'e')e(now);
      if(s[i] == 'd')d(now);      
      if(s[i] == 'c')c(now);
      dif(cnt, prev, now);
    }
    for(int i=0; i<10; ++i){
      if(i)cout << ' ';
      cout << cnt[i];
    }
    cout << endl;
  }
  return 0;
}
