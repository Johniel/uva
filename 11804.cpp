#include <iostream>
#include <algorithm>

using namespace std;

struct Player{
  int a, d;
  string name;  
};

bool cmp_a(Player a, Player b)
{
  return a.a < b.a;
}
bool cmp_d(Player a, Player b)
{
  return a.d > b.d;
}
bool cmp_n(Player a, Player b)
{
  return a.name < b.name;
}
bool not_cmp_n(Player a, Player b)
{
  return a.name > b.name;
}
bool cmp(Player a, Player b)
{
  if(a.a != b.a)return a.a < b.a;
  if(a.d != b.d)return a.d > b.d;
  return a.name > b.name;
}

void output(Player p[])
{
  cout << "(";
  for(int i=0; i<5; ++i){
    if(i)cout << ", ";
    cout << p[i].name;
  }
  cout << ")" << endl;
  return ;
}

Player p[10];

void test(void)
{
  for(int i=0; i<10; ++i){
    cout << p[i].name << ' ' << p[i].a << ' ' << p[i].d << endl;
  }
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    for(int i=0; i<10; ++i){
      cin >> p[i].name >> p[i].a >> p[i].d;
    }
    stable_sort(p, p + 10, not_cmp_n);
    stable_sort(p, p + 10, cmp_d);
    stable_sort(p, p + 10, cmp_a);

    //test();    
    
    //sort(p, p + 10, cmp);

    sort(p, p + 5, cmp_n);
    sort(p + 5, p + 10, cmp_n);
    
    cout << "Case " << ++cnt << ":" << endl;
    output(p + 5);
    output(p);
  }
  return 0;
}
