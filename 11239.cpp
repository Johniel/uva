#include <iostream>
#include <map>
#include <set>

#define N 100+1

using namespace std;

int main(void)
{
  while(true){
    int p = -1;
    set<string> project[N];
    map<string, int> student;
    while(true){
      string s;
      getline(cin, s);
      if( s[0] == '0')
	return 0;
      else if( s[0] == '1' )
	break;
      else if( 'A'<= s[0] && s[0] <= 'Z' ){
	p++;
	project[p].insert(s);
      }
      else{
	if(project[p].count(s) == 0){
	  project[p].insert(s);
	  if(student.count(s) == 0)
	    student.insert(make_pair(s, 1));
	  else
	    student[s]++;
	}
      }
    }
    map<string, int> :: iterator itr;
    for(itr = student.begin(); itr != student.end(); itr++){
      if( (*itr).second == 1 )continue;
      for(int i=0; project[i].size() != 0; i++){
	if(project[i].count((*itr).first) == 0)
	  continue;
	else
	  project[i].erase((*itr).first);
      }
    }
    map<string ,int> sorting;
    for(int i=0; project[i].size() != 0; i++){
      set<string>::iterator it = project[i].begin();
      sorting.insert( make_pair( (*it), project[i].size()-1) );
    }
    multimap<int, string> output;
    for(itr = sorting.begin(); itr != sorting.end(); itr++){
      output.insert( make_pair(-1*((*itr).second), (*itr).first) );
    }
    multimap<int, string> :: iterator outi;
    for(outi = output.begin(); outi != output.end(); outi++)
      
      cout << ((*outi).second) << ' ' << -1*(*outi).first<< endl;
  }
  return 0;
}
