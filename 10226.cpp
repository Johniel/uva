#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define LOOP(i, b, n) for(int i=0; i<(int)n; ++i)

using namespace std;

static const int MAX_TEXT_LEN = 30 * ;
static const int MAX_QUERY = 1000;
static const int MAX_QUERY_LEN = 1000;
static const int MAX_CHAR = CHAR_MAX;

struct Node{
  Node *next[MAX_CHAR];//next[0]=>fail
  vector<int> leaf;
  Node(){
    fill(next, next + MAX_CHAR, (Node*)NULL);
  }
  ~Node(){
    LOOP(i, 1, MAX_CHAR){
      if(next[i] != NULL)
	delete next[i];
    }
  }
};

int main(void)
{
}
