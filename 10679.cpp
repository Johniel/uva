//uva10679
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define LOOP(i, b, n) for(int i=0; i<(int)n; ++i)

using namespace std;

static const int MAX_TEXT_LEN = 100000;
static const int MAX_QUERY = 1000;
static const int MAX_QUERY_LEN = 1000;
static const int MAX_CHAR = CHAR_MAX;

struct PMA {
  PMA* next[MAX_CHAR];//next[0]=>fail
  vector<int> accept;
  PMA() {
    fill(next, next + MAX_CHAR, (PMA*)NULL);
  }
};

PMA* buildAM(char word[MAX_QUERY][MAX_QUERY_LEN], const int size)
{
  // build tree/tri
  PMA *root = new PMA();
  REP (i, size) {
    PMA *node = root;
    for(int j=0; word[i][j] != '\0'; ++j){
      char c = word[i][j];
      if(node->next[c] == NULL) node->next[c] = new PMA();
      node = node->next[c];
    }
    node->accept.push_back(i);
  }
  // make suffix/failure link with BFS
  queue<PMA*> Q;
  for(int c='A'; c<='z'; ++c){
    if(root->next[c] != NULL){
      root->next[c]->next[0] = root;//truism
      Q.push(root->next[c]);
    }
    else root->next[c] = root;
  }
  for (; Q.size(); Q.pop()) {
    PMA *node = Q.front();
    for(int c='A'; c<='z'; ++c){
      if(node->next[c] != NULL){
        Q.push(node->next[c]);
        PMA *linked = node->next[0];
        while(linked->next[c] == NULL) {
          linked = linked->next[0];
        }
        node->next[c]->next[0] = linked->next[c];
      }
    }
  }
  return root;
}

void matching(char *text, PMA *node, int *result)
{
  const int len = strlen(text);
  REP(i, len){
    char c = text[i];
    while(node->next[c] == NULL) node = node->next[0];
    node = node->next[c];
    REP(j, node->accept.size())
      ++result[node->accept[j]];// count frequency
  }
  return ;
}

char text[MAX_TEXT_LEN];
char query[MAX_QUERY][MAX_QUERY_LEN];
int exist[MAX_QUERY];

int main(void)
{
  int tc, n;
  scanf("%d\n", &tc);
  while (tc--) {
    gets(text);
    scanf("%d\n", &n);
    fill(exist, exist + n, 0);
    REP(i, n) {
      scanf("%s\n", query[i]);
    }
    PMA *root = buildAM(query, n);
    matching(text, root, exist);
    REP(i, n) {
      if (exist[i]) puts("y");
      else puts("n");
    }
  }
  return 0;
}
