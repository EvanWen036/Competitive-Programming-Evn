#include <bits/stdc++.h>
using namespace std;


int main(){

	string s;
	string s2;
	cin >> s >> s2;
	int kY = s[1] - 48;
	int kX = s[0] -  96;
	int tY = s2[1] - 48;
	int tX = s2[0] - 96;
	//cout << kX << " " << kY << " " << tX << " " << tY;
	int ans = 1000000000;
	int xDist = tX - kX;
	int yDist = tY - kY;
	cout << max(abs(kY-tY), abs(kX - tX)) << "\n";
	while(kX != tX || kY != tY){
		
		if(kX < tX){
			kX++;
			cout<<"R";
		}
		if(kX > tX){
			kX--;
			cout<<"L";
		}
		if(kY < tY){
			kY++;
			cout<<"U";
		}
		if(kY > tY){
			kY--;
			cout<<"D";
		}
		cout << "\n";
		
	}
	

}