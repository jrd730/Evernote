#include <iostream>
#include <list>
#include <string>

using namespace std; 

int main ()
{
	int max, n;
	string in;
	cin >> max;
	char cmd('0');
	bool maxed = false;
	list <string> buffer;
	list <string> :: iterator back;
	list <string> :: iterator it;
	back = buffer.end();
	do{
		cin >> cmd;
		switch (cmd){
			case 'A':
				cin >> n;
				for (; n; n--){
					cin >> in;
					//cout << "inserting: " << in << endl;
					
					if (buffer.size() < max){
						//cout << "appending to partially full list\n";
						buffer.push_back (in);
						if (buffer.size() == max){
							back = buffer.begin();
							maxed = true;
						}
					}
					else{
						//cout << "replacing " << *back << " with " << in << endl;
						*back = in;
						back++;
						if (back == buffer.end()){
							//cout << "resetting insertion point to front of list\n";
							back = buffer.begin();
						}
					}
				}
				break;

			case 'R':
				cin >> n;
				for (; n; n--)
				{
					if (!maxed){
						buffer.pop_front();
					}
					else{
						//cout << "erasing: " << *back << endl;
						back = buffer.erase(back);
						if (back == buffer.end()){
							//cout << "resetting insertion point to front of list\n";
							back = buffer.begin();
						}
					}
				}
				break;

			case 'L':
				if (back == buffer.begin()){
					for (it = buffer.begin(); it != buffer.end(); it++){
						cout << *it << endl;
					}
				}
				else{
					for (it = back; it != buffer.end(); it++){
						cout << *it << endl;
					}
					for (it = buffer.begin(); it != back; it++){
						cout << *it << endl;
					}
				}
				break;
		}
	}while (cmd != 'Q');
	return 0;
}
