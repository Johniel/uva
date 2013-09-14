//fuck string !
#include <iostream>
#include <string>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int M = 20000 + 1;
static const int N = 60 + 1;

class Data{
public:
  char *info[8];
};

Data data[M];

bool cmp(const Data a, const Data b)
{
  int re = strcmp(a.info[2], b.info[2]);
  if(re == -1)return true;
  else if(re == 1)return false;
  REP(i, 8){ 
    if(i == 2)continue;
    re = strcmp(a.info[i], b.info[i]);
    if(re == -1)return true;
    else if(re == 1)return false;
  }
  return true;
}

int main(void)
{
  int ni = 0, di = 0;
  char tmp[N];
  gets(tmp);
  char Depertment[atoi(tmp)][N];
  bool flg = true;
  while(flg){
    gets(Depertment[ni]);
    if(strlen(Depertment[ni]) == 0)
      continue;
    while(true){
      char *in = new char[N*8];
      char *cp;
      if(gets(in) == NULL)flg = false;
      if(strlen(in) == 0 || !flg)break;
      cp = strtok(in, ",");
      REP(i, 7){
	//cp = strtok(NULL,",");
	if (cp != NULL)data[di].info[i] = cp;
	if(i+1 != 7)cp = strtok(NULL,",");
      }
      data[di].info[7] = Depertment[ni];
      di++;
    }
    ni++;
  }
  sort(data, data + di, cmp);
  REP(i, di){
    printf("----------------------------------------\n");
    printf("%s %s %s\n", data[i].info[0], data[i].info[1], data[i].info[2]);
    printf("%s\n", data[i].info[3]);
    printf("Department: %s\n", data[i].info[7]);
    printf("Home Phone: %s\n", data[i].info[4]);
    printf("Work Phone: %s\n", data[i].info[5]);
    printf("Campus Box: %s\n", data[i].info[6]);
  }
  return 0;
}
