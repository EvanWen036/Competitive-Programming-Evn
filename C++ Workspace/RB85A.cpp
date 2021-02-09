#include <bits/stdc++.h>
using namespace std;

int main(){

	string a;
	string b;
	cin >> a;
	cin >> b;
	transform(a.begin(), a.end(),a.begin(), ::tolower);
	transform(b.begin(),b.end(),b.begin(), ::tolower);
	//cout << a << "\n";
	//cout << b;
	int comp = a.compare(b);
	if(comp < 0)comp = -1;
	if(comp > 0)comp = 1;
	cout << comp;

}