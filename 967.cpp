#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const static int N = 1000000 + 1;

int main(void)
{
  int c[] = {2,
             3,
             5,
             7,
             11,
             13,
             17,
             31,
             37,
             71,
             73,
             79,
             97,
             113,
             131,
             197,
             199,
             311,
             337,
             373,
             719,
             733,
             919,
             971,
             991,
             1193,
             1931,
             3119,
             3779,
             7793,
             7937,
             9311,
             9377,
             11939,
             19391,
             19937,
             37199,
             39119,
             71993,
             91193,
             93719,
             93911,
             99371,
             193939,
             199933,
             319993,
             331999,
             391939,
             393919,
             919393,
             933199,
             939193,
             939391,
             993319,
             999331};
  const int C = sizeof(c) / sizeof(int);
  int sum[N];
  fill(sum, sum + N, 0);
  for(int i=0; i<C; ++i){
    ++sum[ c[i] ];
  }
  for(int i=1; i<N; ++i){
    sum[i] += sum[i-1];
  }
  int a, b;
  while(cin >> a >> b){
    int tmp = sum[b] - sum[a-1];
    if(tmp == 0)cout << "No Circular Primes." << endl;
    else if(tmp == 1)cout << "1 Circular Prime." << endl;
    else cout << tmp << " Circular Primes." << endl;
  }
  return 0;
}


