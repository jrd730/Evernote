#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct entry
{
	string s;
	int 	 n;
};

static bool operator < (const entry l, const entry r){
	return l.n < r.n;
}

int main ()
{
	int N;
	cin >> N;
	
	map <string, int> terms;
	map <string, int> :: iterator it;

	vector <entry> term_list;
	
	int i;
	for (i=0; i < N; i++)
	{
		string t;
		cin >> t;
		if (terms.find(t) != terms.end()){
			terms[t]++;
		}
		else{
			terms[t] = 1;
		}
	}

	term_list.resize (terms.size());
	
	i = 0;
	for (it = terms.begin(); it != terms.end(); it++)
	{
		term_list[i].s = it->first;
		term_list[i].n = it->second;
		i++;
	}
		
	stable_sort (term_list.begin(), term_list.end());
	int k;
	cin >> k;
	
	for (i = 0; i < k; i++){
		cout << term_list[i].s << endl;
	}

	return 0;
}
