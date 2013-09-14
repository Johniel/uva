#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
  char c;
  Node *next[2];
  Node(){
    next[0] = next[1] = (Node*)NULL;
  }
  Node(char _c){ 
    c = _c; 
    next[0] = next[1] = (Node*)NULL;
  }
  ~Node(){
    if(next[0])delete next[0];
    if(next[1])delete next[1];
  }
  void assign( Node *n ){
    if(next[0]){
      next[1] = n;
    }
    else{
      next[0] = n;
    }
  }
};

void output( Node *r )
{
  queue< Node* > q;
  vector< Node* > v;
  q.push( r );
  while( q.size() ){
    Node *h = q.front();
    q.pop();
    v.push_back( h );
    if( h->next[0] )q.push( h->next[0] );
    if( h->next[1] )q.push( h->next[1] );
  }
  reverse( v.begin(), v.end() );
  for(int i=0; i<v.size(); ++i){
    cout << v[i]->c ;
  }
  cout << endl;
  return ;
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    stack< Node* > s;
    string t;
    cin >> t;
    for(int i=0; i<t.size(); ++i){
      if( islower( t[i] ) ){
        s.push( new Node( t[i] ) );
      }
      else{
        Node *n = new Node( t[i] );
        Node *a = s.top();
        s.pop();
        Node *b = s.top();
        s.pop();
        n->assign( b );
        n->assign( a );
        s.push( n );
      }
    }
    output( s.top() );
    delete s.top();
  }
  return 0;
}
