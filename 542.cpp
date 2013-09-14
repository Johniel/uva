#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int N = 16;

struct Node{
  Node *a, *b;
  double win[N];
  Node(){ fill( win, win + N, 0 ); }
};

double g[N][N];

void gen(int depth, int &cnt, Node *n)
{
  if(depth == 4){
    n->win[ cnt++ ] = 1;
    n->a = n->b = (Node*)NULL;
  }
  else{
    n->a = new Node();
    n->b = new Node();
    gen(depth + 1, cnt, n->a);
    gen(depth + 1, cnt, n->b);
  }
  return ;
}

void calc(Node *n)
{
  if( n->a == (Node*)NULL )return ;
  if( n->b == (Node*)NULL )return ;
  calc( n->a );
  calc( n->b );
  for(int i=0; i<N; ++i){
    double sum1 = 0;
    double sum2 = 0;
    for(int j=0; j<N; ++j){
      if( i == j )continue;
      sum1 += n->a->win[i] * n->b->win[j] * (g[i][j] / 100.0);
      sum2 += n->b->win[i] * n->a->win[j] * (g[i][j] / 100.0);
    }
    n->win[i] = sum1 + sum2;
  }
  return ;
}

int main(void)
{
  string name[N];
  for(int i=0; i<N; ++i){
    cin >> name[i];
  }
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      cin >> g[i][j];
    }
  }
  int cnt = 0;
  Node *root = new Node();
  gen(0, cnt, root);
  calc(root);
  for(int i=0; i<N; ++i){
    name[i].resize(10, ' ');
    printf("%s p=%.2lf%%\n", name[i].c_str(), root->win[i] * 100.0);
  }
  return 0;
}
