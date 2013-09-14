#include <iostream>
#include <cmath>
#include <vector>

#define N 50000+1
//#define N 50000
using namespace std;

int main(void)
{
  int n;
  int m[N][3];
  fill(&m[0][0], &m[N-1][3], -1);
  cin >> n;
  for(int i=0; i<N; i++){
    if( i*i > N )break;
    for(int j=0; j<N; j++){
      if( i*i + j*j > N )break;
      for(int k=0; k<N; k++){
	if(i*i + j*j + k*k > N )break;
	if(m[i*i + j*j + k*k][0] == -1){
	  m[i*i + j*j + k*k][0] = i;
	  m[i*i + j*j + k*k][1] = j;
	  m[i*i + j*j + k*k][2] = k;
	}
      }
    }
  }
  while( n-- ){
    int in;
    cin >> in;
    if( m[in][0] != -1 )
      cout << m[in][0] << ' ' << m[in][1] << ' ' << m[in][2] << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
/*
int main(void)
{
  int n;
  long long int sqare[N/2+1];
  for(int i=0; i<N/2+1; i++)
    sqare[i] = (long long int)i*i;
  cin >> n;
  while( n-- ){
    vector<int> result;
    long long int num, m;
    cin >> m;
    num = m;
    num = (long long int)sqrt(num) - 1;
    for(int i=num; i<=m; i++){
    //if( m == 1 ){
    //cout << "check " << num<< ' '<< m << endl;
    //m = 0;
    //result.push_back(1);
    //break;
    //}
      if( m == 0 )
	break;
      if( sqare[i] > m ){
	cout << "m = " << m << " i = " << i-1 ;
	cout << " sqare[i] = " << sqare[i-1] << endl;
	result.push_back(i-1);
	m -= sqare[i-1];
	num = (long long int)sqrt(m) - 1;
	if( num < 0 )num = 1;
	i = num;
      }
    }
    if( result.size() <= 3 && m == 0){
      int limi = 3-result.size();
      for(int i=0; i<limi; i++){
	result.push_back(0);
      }
      sort(result.begin(), result.end());
      for(int i=0; i<3; i++){
	cout << result[i] ;
	if( i != 2)cout << ' ';
      }
      cout << endl;
    }
    else
      cout << -1 << endl;
  }
}
*/
