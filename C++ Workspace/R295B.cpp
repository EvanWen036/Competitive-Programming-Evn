#include <bits/stdc++.h>
#define ll long long;
using namespace std;

struct State{
	int pos;
	int clicks;
};
int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	State init;
	init.pos = n;
	init.clicks = 0;
	queue<State> q;
	q.push(init);
	array<bool, 100000> vis;
	for(int i = 0; i < 100000;i++){
		vis[i] = false;
	}
	vis[n] = true;
	while(true){
		State s = q.front();
		q.pop();
		//cout << s.pos << "\n";
		if(s.pos > 100000 || s.pos < 0){
			continue;
		}
		if(s.pos == m){
			cout << s.clicks;
			break;
		}
		State s1;
		s1.pos = s.pos * 2;
		s1.clicks = s.clicks+1;
		if(s1.pos < 100000 && !vis[s1.pos]){
			q.push(s1);
			vis[s1.pos] = true;
		}
		State s2;
		s2.pos = s.pos-1;
		s2.clicks = s.clicks+1;
		if(s2.pos < 100000 && !vis[s2.pos]){
			q.push(s2);
			vis[s2.pos] = true;
		}
	}
	
	


}