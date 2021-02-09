/*
ID:evan.h.1
TASK:milk
LANG:C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
    cin >> n >> m;
    vector<pii> v;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    int curr = 0;
    int gal = 0;
    int index = 0;
    while(gal < n){
        if(gal + v[index].second < n){
            curr += v[index].first * v[index].second;
            gal += v[index].second;
            index++;
        }
        else{
            curr += (n-gal) * v[index].first;
            break;
        }
    }
    cout << curr << endl;


}

