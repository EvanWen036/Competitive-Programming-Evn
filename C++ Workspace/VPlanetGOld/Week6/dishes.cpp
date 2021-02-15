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
stack<int> stacks[100005];
int bottoms[100005];
int main(){
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N;i ++){
		bottoms[i] = 2e9;
	}
	int mxClean = -1;
	for(int i = 0; i < N;i ++){
		int x;
		cin >> x;
		if(mxClean > x){
			cout << i << '\n';
			return 0;
		}
		int pos = lower_bound(bottoms, bottoms+N, x) - bottoms;
		//cout << pos << endl;
		//add to this stack
		if(bottoms[pos] == 2e9){
			bottoms[pos] = x;
			stacks[pos].push(x);
			continue;
		}
		//cout << stacks[pos].size() << endl;
		while(!stacks[pos].empty() && stacks[pos].top() < x){
			mxClean = max(mxClean, stacks[pos].top());
			stacks[pos].pop();
		}
		stacks[pos].push(x);
	}
	cout << N << '\n';


}
