#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int mx = 0;
    vector<int> ans(n+1);
    vector<int> p(n+1);
    srand(time(0));
    int s = (rand() % n) + 1;
    //cout << s << endl;
    for(int i = 1; i <= n; i++){
        if(i == s)continue;
        cout << "? " << i << " " << s << "\n";
        cout.flush();
        int x;
        cin >> x;
        ans[i] = x;
        mx = max(x, mx);
    }
    p[s] = mx+1;
    for(int i = 1 ; i <= n; i++){
        if(i == s)continue;
        cout << "? " << s << " " << i << "\n";
        cout.flush();
        int x;
        cin >> x;
        p[i] = max(ans[i], x);
        if(p[i] == p[s]){
            p[i] = ans[i] + x;
        }
    }
    cout << "! ";
    for(int i = 1;i  <= n; i++){
        cout << p[i] << " ";
    }
    cout.flush();
    
 
 
}
