#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int rightPos = 0;
    int pref = 0;
    int suff = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i] == i+1)rightPos++;        
    }
    int i = 0;
    while(i < n && a[i] == i+1){
        pref++;
        i++;
    }
    i = n-1;
    while(i >= 0 && a[i] == i+1){
        suff++;
        i--;
    }
    if(rightPos == n)cout << 0 << endl; 
    else if(rightPos == pref || rightPos == suff || pref + suff == rightPos)cout << 1 << endl;
    //else if(rightPos == 0)cout << 1 << endl;
    else{cout << 2 << endl;}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}

