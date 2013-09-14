#include <iostream>

#define N 1001

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    bool flg = true;
    int num, m[N];
    cin >> num;
    fill(&m[0], &m[num], -1);
    for(int i=0; i<num; i++)
      cin >> m[i];
    sort(&m[0], &m[num]);
    reverse(&m[0], &m[num]);

    if( num > 1 && m[0] == 0 )flg = false;

    for(int i=0; i<num; i++){

      if( flg == false )break;
      if( m[i] < 0 ){flg=false;break;}

      for(int j=0+1; j<m[i]+1; j++){

	if( i+j >= num ){flg = false;break;}

	m[i+j]--;
      }
      m[i] = 0;
    }
    if( flg )cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
