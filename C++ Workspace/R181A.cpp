#include <bits/stdc++.h>
using namespace std;


int main(){

	int n;
	cin >> n;
	vector<int> s1;
	vector<int> s2;
	vector<int> s3;
	int s1Neg = 0;
	int s2Neg = 0;
	
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a == 0){
			s3.push_back(a);		
		}
		if(a < 0){
			s1.push_back(a);	
		}
		if(a > 0){
			s2.push_back(a);
		}
	}
	if(s2.size() == 0){
		
		s2.push_back(s1.back());
		s1.pop_back();
		s2.push_back(s1.back());
		s1.pop_back();
	}
	if(s1.size() % 2 == 0){
		s3.push_back(s1.back());
		s1.pop_back();
	}
	
	cout << s1.size() << " ";
	for(vector<int>::iterator i = s1.begin(); i != s1.end(); i++){
		cout << *i << " ";
	}
	cout << "\n" << s2.size() << " ";
	for(vector<int>::iterator i = s2.begin(); i != s2.end(); i++){
		cout << *i << " ";
	}
	cout << "\n" << s3.size()  << " ";
	
	for(vector<int>::iterator i = s3.begin(); i != s3.end(); i++){
		cout << *i << " ";
	}


}