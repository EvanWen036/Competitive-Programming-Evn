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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N;i ++){
        //cin >> A[i];
    }
    vector<pii> s;
    for(int i= 0; i< N; i++){
        int ans = 0;
        cin >> A[i];
        while(!s.empty() && s.back().f >= A[i]){
            //cuut << s.top().f << " " << s.top().s << endl;
            //ans = max(ans, s.top().s+1);
            s.pop_back();
        }
        
        cout << (!s.empty() ? s.back().s + 1: 0) << " ";
        s.pb(mp(A[i],i));
    }


}

