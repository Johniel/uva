#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 50;
const int MOD = 1000;

struct Matrix{
  int num[SIZE][SIZE];
  Matrix(){
    fill(&num[0][0], &num[SIZE-1][SIZE], 0);
  }
};
Matrix operator * (const Matrix &a, const Matrix &b)
{
  Matrix m;
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
      int sum = 0;
      for(int k=0; k<SIZE; ++k){
	sum += a.num[k][j] * b.num[i][k];
	sum %= MOD;
      }
      m.num[i][j] = sum;
    }        
  }
  return m;
}

void output(Matrix m, int size)
{
  cout << "----------------------" << endl;
  for(int i=0; i<size; ++i){
    for(int j=0; j<size; ++j){
      cout << m.num[i][j] << ' ';
    }
    cout << endl;
  }
}

Matrix rec(Matrix m, int p)
{
  if(p == 1)return m;  
  if(p == 2)return m * m;
  Matrix n = rec(m, p/2);
  n = n * n;
  return p%2 ? n * m : n;
}

int main(void)
{
  int tc, a[SIZE];
  for(cin >> tc; tc--; ){
    int n, r;
    Matrix m;
    cin >> n >> r;
    for(int i=0; i<n; ++i){
      cin >> a[i];
    }
    for(int i=0; i<n; ++i){
      int x;
      cin >> x;
      for(int j=0; j<x; ++j){
	int tmp;
	cin >> tmp;
	m.num[i][tmp] = 1;
      }
    }
    m = rec(m, r);    
    //output(m, 2);
    for(int i=0; i<n; ++i){
      int sum = 0;
      for(int j=0; j<n; ++j){
	sum += m.num[i][j] * a[j];
	sum %= MOD;
      }
      if(i)cout << ' ';
      cout << sum ;
    }
    cout << endl;
  }
  return 0;
}
