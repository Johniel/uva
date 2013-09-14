#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6;

char line[N] = {"....."};

char S[N][N] = {{"*****"},
		{"*...."},
		{"*****"},
		{"....*"},
		{"*****"}};

char A[N][N] = {{".***."},
		{"*...*"},
		{"*****"},
		{"*...*"},
		{"*...*"}};

char V[N][N] = {{"*...*"},
		{"*...*"},
		{"*...*"},
		{".*.*."},
		{"..*.."}};

char E[N][N] = {{"*****"},
		{"*...."},
		{"***.."},
		{"*...."},
		{"*****"}};

char H[N][N] = {{"*...*"},
		{"*...*"},
		{"*****"},
		{"*...*"},
		{"*...*"}};

char R[N][N] = {{"*****"},
		{"*...*"},
		{"*****"},
		{"*.*.."},
		{"*..**"}};

char I[N][N] = {{"*****"},
		{"..*.."},
		{"..*.."},
		{"..*.."},
		{"*****"}};

char D[N][N] = {{"***.."},
		{"*..*."},
		{"*...*"},
		{"*..*."},
		{"***.."}};

char O[N][N] = {{"*****"},
		{"*...*"},
		{"*...*"},
		{"*...*"},
		{"*****"}};

char Y[N][N] = {{"*...*"},
		{".*.*."},
		{"..*.."},
		{"..*.."},
		{"..*.."}};


void drawBarH(int n)
{
  for(int i=0; i<n; ++i){
    for(int j=0; j<5*n; ++j){
      cout << line[j/n];
    }
    cout << endl;
  }
  return ;
}

void drawCharH(char w[N][N], int n)
{
  for(int i=0; i<5*n; ++i){
    for(int j=0; j<5*n; ++j){
      cout << w[i/n][j/n];
    }
    cout << endl;
  }
  return ;
}

void drawBarV(int n)
{ 
  for(int i=0; i<n; ++i)
    cout << '.';
  return ;
}

void drawCharV(char w[N][N], int n, int i)
{
  for(int j=0; j<5*n; ++j)
    cout << w[i/n][j/n];
  return ;
}


int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    if(n < 0){
      n *= -1;
      drawCharH(S, n); drawBarH(n);
      drawCharH(A, n); drawBarH(n);
      drawCharH(V, n); drawBarH(n);
      drawCharH(E, n); drawBarH(n);
      for(int i=0; i<2; ++i){
	drawBarH(n); 
      }
      drawCharH(H, n); drawBarH(n);
      drawCharH(R, n); drawBarH(n);
      drawCharH(I, n); drawBarH(n);
      drawCharH(D, n); drawBarH(n);
      drawCharH(O, n); drawBarH(n);
      drawCharH(Y, n);
    }
    else{
      for(int i=0; i<5*n; ++i){
	drawCharV(S, n, i); drawBarV(n);     
	drawCharV(A, n, i); drawBarV(n);     
	drawCharV(V, n, i); drawBarV(n);     
	drawCharV(E, n, i); drawBarV(n);   
	for(int j=0; j<2; ++j){
	  drawBarV(n); 
	}
	drawCharV(H, n, i); drawBarV(n);     
	drawCharV(R, n, i); drawBarV(n);     
	drawCharV(I, n, i); drawBarV(n);     
	drawCharV(D, n, i); drawBarV(n);     
	drawCharV(O, n, i); drawBarV(n);     
	drawCharV(Y, n, i);
	cout << endl;
      }      
    }
    cout << endl << endl;
  }
  return 0;
}
