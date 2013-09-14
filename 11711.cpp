#include <iostream>
#include <algorithm>

using namespace std;

const int RULE = 1000 + 1, FAIL = - (1 << 30), TAPE = 1000, TLE = 10000;

struct Rule{
  int q, c, mov;
  Rule(){
    q = c = mov = FAIL;
  }
  Rule(int _q, int _c, int m) : q(_q), c(_c), mov(m) {}
};

class Machine{
public:
  Rule rule[RULE][2];
  int tape[TAPE];
  Machine(){
    clear();
  }
  void makeRule(int qp, int cp, int qn, int cn, char c){
    rule[qp][cp] = Rule(qn, cn, ((c == 'R')? +1 : -1));
  }
  void clear(void){
    fill(&rule[0][0], &rule[RULE-1][2], Rule());
  }  
  string run(int in, int out){   
    int head = 0, state = 0;
    for(int i=0; i<TAPE; ++i){      
      tape[i] = i<in? 1 : 0;
    }
    for(int step = 0; ; ++step){    
      if(head < 0 || TAPE-1 < head){
	return "MLE";
      }
      if(TLE <= step){
	return "TLE";
      }
      Rule r = rule[state][tape[head]];
      if(r.q == FAIL || r.c == FAIL || r.mov == FAIL){
	break;
      }
      tape[head] = r.c;
      state = r.q;
      head += r.mov;
    }
    return (count(tape, tape + TAPE, 1) == out? "AC" : "WA");
    int result = count(tape, tape + out, 1);    
    return (result == out? "AC" : "WA");
  }
};

int main(void)
{
  Machine m;
  for(int rule, test; cin >> rule >> test; ){
    char c;
    int in, out, qp, cp, qn, cn;

    if(rule + test == 0)break;
    
    for(int i=0; i<rule; ++i){
      cin >> qp >> cp >> qn >> cn >> c;
      m.makeRule(qp, cp, qn, cn, c);
    }    
    for(int i=0; i<test; ++i){
      cin >> in >> out;
      cout << m.run(in, out) << endl;
    }
    
    m.clear();
  }  
  return 0;
}
