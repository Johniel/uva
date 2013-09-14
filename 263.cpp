#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int main(void)
{
  char buff[20];
  string s, t;
  while(cin >> s && s != "0"){
    set<int> vis;
    int tmp =  atoi( s.c_str() );
    vis.insert( tmp );
    cout << "Original number was " << tmp << endl;
    sprintf(buff, "%d", tmp);
    s = string(buff);
    while(true){
      sort(s.begin(), s.end());
      t = s;
      reverse(s.begin(), s.end());
      int a = atoi( s.c_str() );
      int b = atoi( t.c_str() );
      int c = a - b;
      cout << a << " - " << b << " = " << c << endl;
      if( vis.count(c) )break;
      else vis.insert(c);
      sprintf(buff, "%d", c);
      s = string(buff);
    }
    cout << "Chain length " << vis.size() << endl;
    cout << endl;
  }
  return 0;
}
