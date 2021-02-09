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
vector<string> strings;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string curr = "";
	strings.pb("");
	for(int i = 0; i < N;i ++){
		char c;
		cin >> c;
		if(c == 'T'){
			string add; cin >> add;
			curr += add;
			strings.pb(curr);
		}
		else if(c == 'P'){
			int x;
			cin >> x;
			cout << curr[x] << "\n";
		}
		else{
			int moves; cin >> moves;
			curr = strings[strings.size()-moves-1];
			strings.pb(curr);
		}

	}


}
