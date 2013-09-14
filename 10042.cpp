#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int lli;

//const int N = 20000000;
const int N = 1000000;
//bool prime[N];
int p[N];
int size = 0; 
//vector<int> p;

inline
int digitSum(int n)
{
  int sum = 0;
  while(10 <= n){
    sum += n % 10;
    n /= 10;
  }
  return sum + n;
}

void genPrime(void)
{
  p[size++] = 2;
  p[size++] = 3;
  p[size++] = 5;
  p[size++] = 7; 
  p[size++] = 11; 
  const lli L = 1000000000;
  for(int i=13; size<=sqrt(L); i+=2){
    bool flg = true;
    if(i%2){
      for(int j=3; j<=sqrt(i); j+=2){
	if(i % j == 0){
	  flg = false;
	  break;
	}
      }
    }
    if(flg)p[size++] = i;
  }
  return ;
}

inline
bool isPrime(int n)
{
  for(int i=0; i<size; ++i){
    if(n == p[i])return true;
    if(n % p[i] == 0)return false;
  }
  return true;
}

int main(void)
{
  genPrime();
  int tc;
  for(cin >> tc; tc--; ){
    int n, m, input;
    scanf("%d", &input);
    for(int j = input + 1; ; ++j){
      if(isPrime(j))continue;
      int sum = 0, cnt = 0;
      n = j;
      for(int i=0; i<size; ++i){
	if(n % p[i] == 0){
	  while(n % p[i] == 0){
	    sum += digitSum(p[i]);
	    n /= p[i];
	    ++cnt;
	  }
	  i = -1;
	}
      }
      if(n != 1)sum += digitSum(n);
      //cout << sum << ' ' << digitSum(j) << ' ' << j << endl;
      if(sum == digitSum(j)){
	printf("%d\n", j);
	break;
      }
    }
  }
  return 0;
}
