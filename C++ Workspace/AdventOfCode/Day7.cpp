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
map<string, vector<string>> adj; 
int main(){
	ifstream File("input.in");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 1; i <= 594;i ++){
		string s;
		getline(File, s);
		//cout << s << '\n';
		int pos = s.find("bags");
		string type = s.substr(0, pos-1);
		//cout << type << '\n';
		for(int i = 0; i < s.length(); i++){
			char c = s[i];
			if(isdigit(c)){
				pos = i + 2;
				int end = s.substr(i).find(",");
				cout << end << '\n';
				if(end == string::npos){
					end = s.length()-1;
				}
				string next = s.substr(pos, end-pos-1);
				if(next[next.length()-1] == '.' || next[next.length()-1] == ','){
					next = next.substr(0, next.length()-1);
				}
				cout << next << '\n';
				//adj[]

			}
		}
	}


}
