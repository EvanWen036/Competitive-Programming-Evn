#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int n;
void solve(){
    cin >> n;
    vector<string> strings(n);
    for(int i = 0; i < n; i++){
        cin >> strings[i];
    }
    for(int i = 0; i < 26; i++){
        //int cnt = -1;
        int curr = 0;
        for(int j = 0; j < n; j ++){
            for(int x = 0; x < strings[j].length(); x++){
                if(strings[j][x] == i + 97)curr++;
            }
            //cout << i << " " << curr << endl;
            //if(cnt == - 1)cnt = curr;
            /**
            if(curr != cnt){
                cout << "No" << endl;
                return;
            }
            **/
        }
        if(curr % n != 0){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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

