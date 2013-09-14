#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > triangles, temp;

void display(void)
{
  for(int i=0; i<triangles.size(); i++){
    for(int h=0; h<i*2; h++)
      cout << ' ' ;
    for(int j=0; j<triangles[i].size(); j++){
      cout << triangles[i][j] << ' ';
    }
    cout << endl;
  }
}


void input(int n)
{
  char c;

  triangles.clear();
  triangles.resize(n);
  cin.get(c);
  for(int i=0; i<triangles.size(); i++){
    while(1){
      cin.get(c);
      if(c == '\n')
	break;
      if(c == '#')
	triangles[i].push_back(0);
      else if(c == '-')
	triangles[i].push_back(1);
    }
  }
}

int count(void)
{
  int maxValue1 = 0, maxValue2 = 0;

  temp = triangles;

  for(int i=0; i<triangles.size(); i++){
    if( count(triangles[i].begin(),triangles[i].end(),1) ){
      maxValue1 = 1;
      maxValue2 = 1;
      break;
    }
  }
  if(maxValue1 == 0)return 0;
  //display();

  for(int j=1; j<triangles[0].size()-1; j+=2){
    if(triangles[0][j])
      triangles[0][j] = min(triangles[0][j-1],triangles[0][j+1]);
  }
  for(int i=1; i<triangles.size(); i++){
    for(int j=0; j<triangles[i].size(); j+=2){
      if(triangles[i][j]){
	triangles[i][j] = triangles[i-1][j+1] + 1;
	maxValue1 = max(maxValue1,triangles[i][j] );
      }
    }
    for(int j=1; j<triangles[i].size(); j+=2){
      if(triangles[i][j])
	triangles[i][j] = min(triangles[i][j-1],triangles[i][j+1]);
    }
  }

  //display();
  
  triangles = temp;
  
  for(int i=0; i<triangles.size(); i++){
    triangles[i][0] = 0;
    triangles[i][triangles[i].size()-1] = 0;
  }
  
  //display();

  for(int i=triangles.size()-1; i>=0; i--){
    for(int j=1; j<triangles[i].size(); j+=2){
      if(triangles[i][j]){
	triangles[i][j] = triangles[i+1][j-1] + 1;
	maxValue2 = max(maxValue2,triangles[i][j] );
      }
    }
    for(int j=0; j<triangles[i].size(); j+=2){
      if(triangles[i][j])
	triangles[i][j] = min(triangles[i][j-1],triangles[i][j+1]);
    }  
  }
 
  //display();

  return max(maxValue1*maxValue1, maxValue2*maxValue2);
}

int main(void)
{
  int cnt = 1;
  while(1){
    int n;
    cin >> n;
    if(n == 0)
      break;
    input(n);

    if(triangles[0].size() == 1){
      reverse(triangles.begin(),triangles.end());
    }

    cout << "Triangle #" << cnt << endl;
    cout << "The largest triangle area is " << count() << '.'<< endl << endl;
    cnt++;
  }
  return 0;
}

