#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, D;
    cin >> N >> D;
    pair<int, int> cows[N];
    for(int i=  0; i < N; i++){
        int x, h;
        cin >> x >> h;
        cows[i] = make_pair(x,h);
    }
    sort(cows, cows+N);
    multiset<int> set;
    bool left[N];
    memset(left, false, sizeof(left));
    for(int i=0; i < N; i++){
        if(i >= D){
            set.erase(set.find(cows[i-D].second));
        }
        if(set.size() > 0 && *(set.rbegin()) >= 2 * cows[i].second){
            left[i] = true;
        }
        set.insert(cows[i].second);
    }
    /*
    for(int i = 0 ; i < N ;i ++){
        cout << i << " " << left[i] << endl;
    }
    */
    multiset<int> set2;
    bool right[N];
    for(int i = 0; i < N; i++)right[i] = false;
    for(int i = N-1; i >= 0;i --){
        if(i+D < N){
            set2.erase(set2.find(cows[i+D].second));
        }
        if(set2.size()>0 && *(set2.rbegin()) >= 2 * cows[i].second){
            right[i] = true;
        }
        set2.insert(cows[i].second);
    }
    int ans = 0;
    for(int i  = 0; i < N; i++){
        if(left[i] && right[i])ans++;
    }
    cout << ans;
}

