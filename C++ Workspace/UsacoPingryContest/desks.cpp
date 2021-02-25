#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> desks;
//checking function
bool ok(int x){
	int placed = 0;
	//prev is the coordinate of the previous desk placed
	int prev = -1;
	for(int i = 0; i < N; i++){
		if(prev == -1 || desks[i] - prev >= x){
			//can place this desk so greedily place it 
			placed++;
			prev = desks[i];
		}
	}
	//if placed over M desks this value of x works
	return placed >= M;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0;i < N;i ++){
		int x;
		cin >> x;
		desks.push_back(x);
	}
	//sort the coordinates of the desks
	sort(desks.begin(), desks.end());
	int lo = 0;
	int hi = 1e9;
	//binary search on the answer
	while(lo < hi){
		//do lo+hi+1 to avoid infinite loop
		int mi = (lo+hi+1)/2;
		//if the middle point works then the answer might be higher
		if(ok(mi)){
			lo = mi;
		}
		//otherwise the answer is definitely lower
		else{
			hi = mi-1;
		}
	}
	cout << lo << '\n';
}
