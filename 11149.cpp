#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 40 + 1;

struct matrix{
  int h, w, m[N][N];
  matrix(int _h, int _w) : h(_h), w(_w) {
    fill(&m[0][0], &m[h-1][w], 0);
  }
};

matrix operator * (const matrix &a, const matrix &b)
{
  matrix m(a.w, b.h);
  for(int i=0; i<a.h; ++i){
    for(int j=0; j<a.w; ++j){
      for(int k=0; k<a.w; ++k){
	m.m[i][j] += a.m[i][k] * b.m[k][j];       
      }
    }
  }
  return m;
}

matrix operator + (const matrix &a, const matrix &b)
{
  matrix m(a.h, a.w);
  for(int i=0; i<a.h; ++i){
    for(int j=0; j<a.w; ++j){
      m.m[i][j] = a.m[i][j] + b.m[i][j];
    }
  }
  return m;
}

void wellform(matrix &a)
{
  for(int i=0; i<a.h; ++i){
    for(int j=0; j<a.w; ++j){ 
      a.m[i][j] %= 10;
    }
  }
}

matrix power(matrix m, int z)
{
  if(z == 1)return m;
  if(z == 2)return m * m;
  matrix n = power(m, z/2);
  wellform(n);
  return z%2? n * n * m : n * n;
}

matrix rec(matrix m, int z)
{
  if(z == 1)return m;
  if(z == 2)return m * m + m;
  matrix sum = rec(m, z/2);
  wellform(sum);
  matrix p = power(m, z/2);
  wellform(p);
  sum = sum + p * sum;
  if(z%2){
    p = p * p * m;
    wellform(p);
    sum = sum + p;
  }
  wellform(sum);    
  return sum;
}

int main(void)
{
  for(int size, p; ; ){
    scanf("%d %d\n", &size, &p);
    if(size == 0)break;
    matrix m(size, size);
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j){
	scanf("%d", &m.m[i][j]);
	m.m[i][j] %= 10;
      }
    }
    matrix sum = rec(m, p);
    wellform(sum);
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j){
	if(j)printf(" ");
	printf("%d", sum.m[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
