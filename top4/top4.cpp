#include <iostream>
#include <list>

using namespace std;

int main ()
{
  int c; // number of elements in list
  cin >> c;
  
  int next; // the next int to be read;
  cin >> next;
  
  list <int> t; // list of top 4 ints
  list <int> :: iterator it;
  t.push_front (next);
  
  int i;
  for (i = 1; i < c; i++)
  {
    cin >> next;
    bool inserted = false;
    for (it = t.begin(); it != t.end(); it++)
    {
      if (next > *it)
      {
        t.insert(it, next);
        inserted = true;
        break;
      }
    }
    if (!inserted)
    {
      t.push_back(next);
    }
    while (t.size() > 4){
      t.pop_back();
    } 
  }
  
  for (it = t.begin(); it != t.end(); it++){
    cout << *it << endl;
  }
   
  return 0;
}
