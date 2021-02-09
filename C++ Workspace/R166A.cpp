#include <bits/stdc++.h>
using namespace std;

bool isDistinct(int n){
	set<int> set;
	while(n > 0){
		if(set.count(n%10) != 0){
			return false;
		}
		set.insert(n%10);
		n/=10;
	}
	return true;

}
int main(){

	int n;
	cin >> n;
	n++;
	while(!isDistinct(n)){
		//cout << n;
		n++;
	}
	cout << n;

}