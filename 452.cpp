#include <iostream>
#include <vector>
using namespace std;

class data{
public:
  char name;
  int cost;
  bool finish;
  vector<char> next;
};

vector<data> task;

void input(void)
{
  //cout << "test1" << endl;
  while(1){
    data tmp;
    string in;
    if(!(cin >> in))
      //if(cin >> in)
      break;

    //cout << "test2" << endl;

    tmp.name = in[0];
    tmp.cost = in[2];
    for(int i=3; i<in.size(); i++){
      tmp.next.push_back(in[i]);
    }
    tmp.finish = false;
    task.push_back(tmp);
  }
}

int day(void)
{
  int sum_day = 0;
  char from,to;
  
  int max=INT_MIN,min=INT_MAX;
  for(int i=0; i<task.size(); i++){
    if(task[i].name < min)
      min = task[i].name;
    if(task[i].name < max)
      max = task[i].name;
  }
  to = max;
  from = min;
  
  cout << to << from << endl;

  return sum_day;
}

void test()
{
  for(int i=0; i<task.size(); i++){
    cout << task[i].name << ' ' << task[i].cost << ' ';
    for(int j=0; j<task[i].next.size(); j++)
      cout << task[i].next[j] << ' ';
    cout << endl;
  }
}

int main(void)
{
  int n;

  cin >> n;
  input();
  test();
  while(n--){
    cout << day() << endl;
    }
 
 return 0;
}
