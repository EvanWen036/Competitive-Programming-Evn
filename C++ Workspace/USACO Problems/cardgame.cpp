#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int elsie[N];
    bool elsieHas[2*N+5];
    memset(elsieHas,false,sizeof(elsieHas));
    for(int i = 0; i < N; i++){
        cin >> elsie[i];
        elsieHas[elsie[i]] = true;
    }
    set<int> bessie;
    set<int> bessie2;
    for(int i = 1; i<= 2* N; i++){
        if(!elsieHas[i]){
            bessie.insert(i);
            bessie2.insert(i);
        }
    }
    //
    int prefix[N];
    
    for(int i = 0; i < N; i++){
        if(bessie.upper_bound(elsie[i]) != bessie.end()){
            bessie.erase(bessie.upper_bound(elsie[i]));
            if(i == 0)prefix[i] = 1;
            else{
                prefix[i] = 1+prefix[i-1];
            }
        }
        else{
            prefix[i] = (i == 0 ? 0:prefix[i-1]);
        }
        //cout << prefix[i] << endl;
    }
    int suffix[N+1];
    suffix[N] = 0;
    //cout << bessie2.size() << endl;
    for(int i = N-1; i >= 0; i--){
        if(bessie2.lower_bound(elsie[i]) != bessie2.begin()){
            //cout << "HI" << endl;
            bessie2.erase(--bessie2.lower_bound(elsie[i]));
            suffix[i] = 1 + suffix[i+1];
        }
        else{
            suffix[i] = suffix[i+1];
        }
        //cout << suffix[i]  << endl;
    }
    int ans = 0;
    for(int i = 0; i < N-1; i++){
        ans = max(ans, prefix[i] + suffix[i+1]);
    }
    ans = max(ans, suffix[0]);
    ans = max(ans, prefix[N-1]);
    cout << ans << endl;
}

