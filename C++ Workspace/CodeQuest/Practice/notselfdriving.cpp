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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string l1;
	getline(cin, l1);
	int n = stoi(l1);
	
	for(int i = 0; i < n;i ++){
		string li;
		getline(cin,li);
		//cout << li << endl;
		int po = li.find(":");

		string s1 = li.substr(0, po+1);
		string s2 = li.substr(po+1);
		double d1 = stod(s1);
		double d2 = stod(s2);
		//cout << d1 << " " << d2 << '\n';
		double time = d2/d1; 
		if(time <= 1.0)cout << "SWERVE\n";
		else if(time <= 5.0)cout << "BRAKE\n";
		else{
			cout << "SAFE\n";
		}
	}


}
