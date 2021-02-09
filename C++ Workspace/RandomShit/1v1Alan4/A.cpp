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
double total = 0;
double ans = 0;
string curr = "";
string s1, s2;
void go(int x){
	//cout << x << " " << curr << endl;
	if(x >= s2.length()){
		int p1=0;
		int p2=0;
		for(int i = 0;i<s1.length();i++){
			if(s1[i]=='+')p1++;
			else{p1--;}
		}
		for(int i=0;i<s2.length();i++){
			if(curr[i]=='+')p2++;
			else{p2--;}
		}
		if(p1==p2)ans++;
		total++;
	}
	else if(s2[x]=='?'){
		
		curr += "+";
		go(x+1);
		curr = curr.substr(0,x);
		curr += "-";
		//cout << "hi\n";
		go(x+1);
	}
	else{
		curr += s2[x];
		go(x+1);
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s1 >> s2;
	go(0);	
	cout << fixed;
	cout << setprecision(9) << ans/total<<'\n';

}
