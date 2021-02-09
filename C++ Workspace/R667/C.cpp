#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if(n == 2){
        cout << a << " " << b << endl;
        return;
    }
    int possible = -1;
    for(int i  = n-1; i > 0; i--){
        //cout << i << endl;
        //cout << (b-a) % i << " " << (b-a)/i << endl;
        if((b-a) % i == 0){
            possible = i;
            break;
        }
    }
    if(possible == -1)possible = 1;
    //cout << possible << endl;
    //stuff pussible elements in between
    int d = (b-a)/possible;
    //cout << d << endl;
    //return;
    for(int i = a; i <= b; i += d){
        cout << i << " ";
        n--;
    }
    //return;
    
    int curr = a-d;
    while(n > 0 && curr > 0){
        assert(n > 0 && curr > 0);
        cout << curr << " ";
        n--;
        //cout << n << endl;
        curr -= d;
        
    }
    curr = b+d;
    while(n > 0){
        cout << curr << " ";
        n--;
        curr += d;
    }
    cout << endl;
    
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

