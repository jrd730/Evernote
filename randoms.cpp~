#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main (int argc, string argv[])
{
  srand(time(NULL));
  ofstream fout("random_ints.txt");
  fout << argv[1];
  for (int i=0; i < argv[1]; i++)
  {
    fout << rand()%argv[2] << endl;
  }
  return 0;
}
