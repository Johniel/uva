#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool d_prime(int a, int b, int c)
{
  return b - a == c - b;
}

int main(void)
{
  const int P = 40000;
  bool prime[P]; 
  int p[P], size = 0;
  fill(prime, prime + P, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<P; ++i){    
    for(int j=2; i*j<P; ++j){
      prime[i * j] = false;
    }
  }
  for(int i=0; i<P; ++i){
    if(prime[i])p[size++] = i;
  }
  
  vector< pair<int, int> > v;
  for(int i=0; i<size; ++i){
    if(!d_prime(p[i], p[i + 1], p[i + 2]))continue;
    for(int j=i+1; j<size; ++j){
      if(!d_prime(p[j], p[j + 1], p[j + 2])){
        v.push_back(make_pair(i, j+1));
        i = j;
        break;
      }
    }
  }

  /*
  for(int i=0; i<v.size(); ++i){
    for(int j=v[i].first; j<=v[i].second; ++j){
      cout << p[j] << ' ';
    }
    cout << endl;
  }
  */

  for(int a, b; ; ){
    cin >> a >> b;
    if(a == 0 && b == 0)break;
    if(a > b)swap(a, b);
    for(int i=0; i<v.size(); ++i){
      if(a <= p[v[i].first] && p[v[i].second] <= b){
        for(int j=v[i].first; j<=v[i].second; ++j){
          if(j - v[i].first)cout << ' ';
          cout << p[j];
        }
        cout << endl;
      }
    }
  }
  return 0;
}
