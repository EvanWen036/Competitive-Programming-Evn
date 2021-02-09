#include <bits/stdc++.h>
using namespace std;


int main(){


	int n;
	cin >> n;
	vector<int> A(n);
	set<int> s;
	for(int &a : A){
		cin >> a;
		//cout << a;
		s.insert(a);
	}
	if(s.size() > 3){
		cout << -1;
		return 0;
	}
	if(s.size() == 3){
		set<int>::iterator it = s.begin();
		set<int>::iterator it2 = s.end();
		it2--;
		int first = *it;
		//cout << *it << *it2;

		int d = (*it2-*it)/2;
		it++;
		//cout << *it;
		if(first + d == *it && *it2 - d == *it){
			cout << d;
			return 0;
		}
		cout << -1;
	}
	else{
		set<int>::iterator it = s.begin();
		set<int>::iterator it2 = s.end();
		it2--;
		int d = (*it2 - *it)/2;
		if(*it + d == *it2 - d){
			cout << d;
		}
		else{
			cout << *it2 - *it;
		}
	}
	
	

}