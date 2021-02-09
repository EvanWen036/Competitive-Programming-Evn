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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<string> colors(N);
	map<string, int> prev;
	vector<int> next(N);
	set<int> current;
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		colors[i] = s;
		if(prev.count(s)){
			next[prev[s]] = i;
		}
		//first instance
		else{
			current.insert(i);
			//cout << i << endl;
		}
		prev[s] = i;
	}
	int curr = 0;
	int pos = 0;
	int ans = 0;
	int pre = 0;
  	while(pos < N-1){

		//take the furthest jump/
		ans++;
    	pre = pos;
		pos = *current.rbegin();
		for(int i = pre; i <= pos; i++){
     		 current.erase(i);
     		 current.insert(next[i]);
    	}    
	}
	if(N==1)ans = 1;
	cout << ans << '\n';
}