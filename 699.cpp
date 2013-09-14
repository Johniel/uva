#include <iostream>
#include <algorithm>
using namespace std;

#define N 80

int sum[N+1];

void result(void)
{
  static int cnt = 1;
  cout << "Case " << cnt++ << ':' << endl;
  for(int i=0; i<N+1; i++){
    if( sum[i] ){
      cout << sum[i] ;
    if(sum[i+1] != 0)
      cout << ' ';
    }
  }
  cout << endl << endl;
  return ;
}

void compute(int p, int key)
{
  if( key < 0 )
    return ;
  sum[p] += key;
  cin >> key;
  compute(p-1,key);
  cin >> key;
  compute(p+1,key);
}

int main(void)
{
  while(true){
    fill(&sum[0], &sum[N+1], 0);
    int root;
    cin >> root;
    if( root < 0 )
      break;
    compute( N/2 ,root );
    result();
  }
  return 0;
}
