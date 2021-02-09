#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	freopen("slowdown.in", "r", stdin);
	freopen("slowdown.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> timeS;
	vector<int> dist;
	for(int i = 0;i < N;i ++){
		char c; 
		int x;
		cin >> c >> x;
		if(c == 'T'){
			timeS.pb(x);
		}
		else{
			dist.pb(x);
		}
	}
	dist.pb(1000);
	sort(timeS.begin(), timeS.end());
	sort(dist.begin(), dist.end());
	double pos = 0;
	double time = 0;
	int ptr = 0;
	//speed represents how many seconds per one meter
	int speed = 1;
	for(int i = 0; i < dist.size(); i++){
		//deal with time slows
		while(ptr < timeS.size() && time + speed * (dist[i] - pos) >= timeS[ptr]){
			//we need to slow this 
			pos += (timeS[ptr] - time)/speed;
			speed++;
			time = timeS[ptr];
			ptr++;
		}
		//go this extra distance
		time += (dist[i] - pos)*speed;
		pos = dist[i];
		speed++;
	}
	int norm = (int)time;
	if(time - norm >= 0.5)norm++;
	cout << norm << '\n';
}
