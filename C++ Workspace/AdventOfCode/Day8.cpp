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

	freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<string,int>> vt;
	bool exec[1005];
	memset(exec, false, sizeof(exec));
	for(int i = 0; i < 622; i++){
		string s;
		int y;
		cin >> s >> y;
		vt.pb({s,y});
	}
	int ac = 0;
	int id = 0;
	for(int i = 0; i < 622;i++){
		string original = vt[i].f;
		if(vt[i].f == "nop")vt[i].f = "jmp";
		else if(vt[i].f == "jmp")vt[i].f = "nop";
		id = 0;
		ac = 0;
		cout << "----" << '\n';
		memset(exec, false, sizeof(exec));
		while(true){
			//cout << vt[id].f << " " << vt[id].s << '\n';
			cout << id << '\n';
			if(id == 622){
				cout << ac << '\n';
				return 0;
			}
			if(exec[id])break;
			exec[id] = true;
			if(vt[id].f == "acc"){
				ac += vt[id].s;
				id++;
			}
			if(vt[id].f == "nop")id++;
			if(vt[id].f == "jmp"){
				id += vt[id].s;
			}
		}	
		vt[i].f = original;
	}
	//cout << ac << '\n';

}
