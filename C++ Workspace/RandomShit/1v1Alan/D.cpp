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
    int b, g, n;
    cin >> b >> g >> n;
    int blueCards = 0;
    int redCards = 0;
    int ans = 100000000;
    int turns = 0;
    set<pii> s;
    for(int i = 0; i <= b; i++){
        for(int j = 0; j <= g; j++){
            if(i + j == n){
                s.insert(mp(i,j));
            }
        }
    }
    cout << s.size() << "\n";



}

