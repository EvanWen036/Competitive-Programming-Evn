#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
pair<long long, long long> t[800005];
long long lazy[800005];
void build(long long a[], int v, int l, int r){
	if(l == r){
		t[v].first = a[l];
		t[v].second = a[l];
	}
	else{
		int mid = (l+r)/2;
		build(a, v*2, l, mid);
		build(a, v*2+1, mid + 1, r);
		t[v].first = t[v*2].first + t[v*2+1].first;
		t[v].second = min(t[v*2].second, t[v*2+1].second);
	}
}
long long minimum(int v, int lr, int rr, int l, int r){
	if(r < lr || l > rr || lr > rr)return 1000000000;
	if(lazy[v] != 0){
		t[v].first += (rr-lr+1)*lazy[v];
		t[v].second += lazy[v];
		if(lr != rr){
			lazy[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(l <= lr && r >= rr){
		return t[v].second;
	}
	
	int tm = (lr + rr)/2;
	return min(minimum(2*v, lr, tm, l, r), minimum(2*v+1, tm+1, rr, l, r));
}
void updateRange(int v, int lr, int rr, int l, int r, long long val){
	//cout << v << " " << lr << " " << rr << " " << l << " " << r << " " << val << "\n";
	if(lazy[v] != 0){
		t[v].first += (rr -lr+1) * lazy[v];
		t[v].second += lazy[v];
		if (lr != rr) {                                     // update lazy[] for children nodes
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
		lazy[v] = 0;
	}
	if(lr > rr || l > rr || r < lr )return;
	if(l <= lr && r >= rr){
		t[v].first += (rr - lr+1) * val;
		t[v].second += val;
		//t[v].first += val;
		if(lr != rr){
			lazy[2*v] += val;
			lazy[2*v+1] += val;
		}
		return;
	}
	int tm = (lr+rr)/2;
	updateRange(2*v, lr, tm, l, r, val);
	updateRange(2*v+1, tm+1, rr, l ,r, val);
	t[v].first = t[2*v].first + t[2*v+1].first;
	t[v].second = min(t[2*v].second, t[2*v+1].second);
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	ll arr[N];
	for(int i = 0; i < N;i ++){
		cin >> arr[i];
	}
	
	build(arr, 1, 0, N-1);
	string line;
	getline(cin, line);
	getline(cin, line);
	int Q = stoi(line);
	for(int i = 0; i < Q;i ++){
		getline(cin, line);
		//cout << line << '\n';
		int prev = -1;
		vector<int> arg;
		for(int j = 0;j < line.length(); j++){
			if(line[j] == ' '){
				//cout << line.substr(prev+1, j-prev)<< endl;
				arg.pb(stoi(line.substr(prev+1, j-prev)));
				prev = j;
			}
		}
		arg.pb(stoi(line.substr(prev+1, line.length()-prev)));
		if(arg.size() == 2){
			//cout << arg[0] << " " << arg[1] << endl;
			if(arg[1] < arg[0]){
				cout << min(minimum(1,0,N-1,0,arg[1]), minimum(1,0,N-1,arg[0],N-1)) << '\n';
			}
			else{
				cout << minimum(1,0,N-1, arg[0], arg[1]) << '\n';
			}
		}
		else{
			if(arg[1] < arg[0]){
				updateRange(1,0,N-1,0,arg[1],arg[2]);
				updateRange(1,0,N-1,arg[0],N-1,arg[2]);
			}
			else{
				updateRange(1,0,N-1, arg[0],arg[1], arg[2]);
			}
		}
	}

}
