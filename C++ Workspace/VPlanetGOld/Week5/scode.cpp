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
map<string ,int> dp;
string s;
int go(string curr){
	if(dp.count(curr))return dp[curr];
	if(curr.length() < 2)return 0;
	if(curr.length() == 2)return 1;
	//cout << "AT " << curr << '\n';
	//try a prefix 
	int ways = (curr == s ? 0:1);
	int mid = (curr.length()-1) / 2;
	for(int i = 0; i < mid; i++){
		string sub = curr.substr(0, i+1);
		//cout << "SUB:" << sub << "\n";
		if(sub == curr.substr(i+1, i+1)){
			//cout << curr.substr(i+1) << '\n';
			ways += go(curr.substr(i+1));
			ways %= 2014;
		}
		if(sub == curr.substr(curr.length() - i-1, i+1)){
			//cout << curr.substr(i+1) << '\n';
			ways += go(curr.substr(i+1));
			ways %= 2014;
		}
	}
	string temp = curr;
	reverse(temp.begin(), temp.end());
	//try a suffix
	for(int i = 0; i < mid; i++){

		string sub = temp.substr(0, i+1);
		reverse(sub.begin(), sub.end());
		//cout << "SUB: " << sub << '\n';
		if(sub == curr.substr(0, i+1)){
			//cout << curr.substr(0, curr.length()-i-1) << '\n';
			ways += go(curr.substr(0, curr.length()-i-1));
			ways %= 2014;
		}
		reverse(sub.begin(), sub.end());
		if(sub == temp.substr(i+1, i+1)){
			//cout << "BRUH\n";
			//cout << curr.substr(0, curr.length()-i-1) << '\n';
			ways += go(curr.substr(0, curr.length()-i-1));
			ways %= 2014;
		}
		
	}
	return dp[curr] = ways;

}
int main(){
	freopen("scode.in", "r", stdin);
	freopen("scode.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	cout << go(s) << '\n';

}
