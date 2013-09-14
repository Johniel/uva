//uva 10408
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
  (num / den)
  this class can calcurate puls value only.
*/
class Fraction{
public:
  int num, den;
  Fraction(){}
  Fraction(int n, int d) : num(n), den(d) {}
  int gcd(int a, int b){
    return b? gcd(b, a%b) : a;
  }
  void reduction(void){
    int n = gcd(max(num, den), min(num, den));
    num /= n;
    den /= n;    
  }  
};
bool operator < (const Fraction &a, const Fraction &b)
{
  return a.num * b.den < b.num * a.den;  
}

int main(void)
{
  int n, m;
  while(cin >> n >> m){
    set<Fraction> s;
    for(int i=0; i<n; ++i){
      for(int j=i+1; j<n; ++j){
        Fraction f(i+1, j+1);
        f.reduction();
        s.insert(f);
      }
    }
    s.insert(Fraction(1, 1));
    set<Fraction>::iterator itr = s.begin();
    while(--m)++itr;
    cout << itr->num << "/" << itr->den << endl;
    continue;
    for(itr=s.begin(); itr!=s.end(); ++itr){
      cout << itr->num << "/" << itr->den << endl;
    }
    break;
  }
  return 0;
}
