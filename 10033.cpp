#include <iostream>

using namespace std;

int ram[1000 + 1], reg[10 + 1];  

#define op0 ram[i] / 100
#define op1 ((ram[i] % 100) - (ram[i] % 10)) / 10
#define op2 ram[i] % 10

//#define TEST

int run(int lim)
{
  int cnt = 0;
  for(int i = 0; i < 1001; ++cnt, ++i){
#ifdef TEST
    cout << i << ' ' << cnt << endl;
    cout << op0 << op1 << op2 << endl;
    for(int j=0; j<=10; ++j)cout << reg[j] << ' '; cout << endl;
#endif
    if(op0 == 1 && op1 == 0 && op2 == 0){
      return cnt + 1;
    }
    else if(op0 == 2){
      reg[op1] = op2;
    }
    else if(op0 == 3){
      reg[op1] += op2;
      reg[op1] %= 1000;
    }
    else if(op0 == 4){
      reg[op1] *= op2;
      reg[op1] %= 1000;
    }
    else if(op0 == 5){
      reg[op1] = reg[op2];
    }
    else if(op0 == 6){
      reg[op1] += reg[op2];
      reg[op1] %= 1000;
    }
    else if(op0 == 7){
      reg[op1] *= reg[op2];
      reg[op1] %= 1000;
    }
    else if(op0 == 8){
      reg[op1] = ram[reg[op2]]; 
      //ram[op2] = reg[op1]; 
    }
    else if(op0 == 9){
      ram[reg[op2]] = reg[op1];
      //ram[reg[s]] = reg[d];
      //ram[op2] = reg[op1]; 
      //reg[op1] = ram[reg[op2]]; 
    }
    else if(op0 == 0){
      if(reg[op2])i = reg[op1] - 1;
    }
    //else --cnt;
  }
  return cnt;
}

int main(void)
{
  int tc, n;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  for(; tc--; ){
    fill(reg, reg + 10 + 1, 0);
    fill(ram, ram + 1000 + 1, 0);
    int i;
    for(i=0; ; ++i){
      string s;
      getline(cin, s);
      if(s.size() == 0){
	ram[i] = -1;
	break;
      }
      ram[i] = atoi(s.c_str());
    }
    cout << run(i) << endl;
    if(tc)cout << endl;
  }
  return 0;
}
