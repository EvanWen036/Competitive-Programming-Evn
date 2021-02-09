#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
bool skip[200005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    pair<int, pii> operation;
    for(int i = 0; i < q; i++){
        cin >> operation.f >> operation.s.f >> operation.s.s;    
    }
    int max2 = -1;
    

}

