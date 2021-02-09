#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int cows = 0;
int control = 0;
void calc(vector<int> gangs){
    priority_queue<pii> pq;
    for(int i = 1; i < gangs.size(); i++){
        pq.push(mp(gangs[i], i));    
    }
    while(!pq.empty()){
        pii big = pq.top();pq.pop();
        if(cows == 0){
            control = big.s;
        }
        if(control == big.s){
            cows++;
        }
        else{
            cows--;
        }
        if(big.f > 1){
            pq.push(mp(big.f-1, big.s));    
        }
    }
    //return cows;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> gangs(M);
    //priority_queue<pii> s;
    for(int i = 0; i < M; i++){
        cin >> gangs[i];
        //s.push(mp(gangs[i],i));
    }
    //sort(gangs.begin() + 1, gangs.end());
    //int cows = 0;
    //int control = 0;
    calc(gangs);
    int ans = gangs[0] - cows;
    //int ans = gangs[0] - cows;
    if(ans <= 0){
        cout << "No" << endl;
        //return 0;
    }
    
    else{
        cout << "Yes\n" << ans << endl;
        cows = 0;
        control = -1;
        for(int i = 0; i < N; i++){
            int prevCow = cows;
            int prevControl = control;
            for(int j = 0; j < M; j++){
                if(gangs[j] == 0)continue;
                //try placing gang j as the i'th cow
                //priority_queue<pii> pq;
                //pq.push(make_pair(gangs[j], ));
                gangs[j]--;
                if(cows == 0){
                    control = j;
                }
                if(j == control){
                    cows++;
                }
                else{
                    cows--;
                }
                calc(gangs);
                if(gangs[0] - cows == ans){
                    cout << j+1 << endl;
                    break;
                }
                gangs[j]++;
                cows = prevCow;
                control = prevControl;
            }
        }
    }



}

