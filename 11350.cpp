#include <iostream>

typedef unsigned long long int ulli;

using namespace std;

ulli gcd(ulli a, ulli b)
{
  return b? gcd(b, a%b) : a;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    ulli a, b;
    string s;
    a = b = 1;
    getline(cin, s);
    ulli la, lb, ra, rb;
    la = 0;
    lb = 1;
    ra = 1;
    rb = 0;
    //cout << la << "/" << lb << " : " << a << "/" << b << " : " << ra << "/" << rb << endl;
    for(ulli i=0; i<s.size(); ++i){
      if(s[i] == 'R'){
        la = a;
        lb = b;        
      }
      else{
        ra = a;
        rb = b;
      }

        a = la + ra;
        b = lb + rb;
        if(a && b){
          ulli d = gcd(max(a, b), min(a, b));
          a /= d;
          b /= d;
        }
        //cout << la << "/" << lb << " : " << a << "/" << b << " : " << ra << "/" << rb << endl;
    }
    cout << a << "/" << b << endl;
    //cout << endl;
  }
  return 0;
}
