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
	int N, M;
    cin >> N >> M;
    vector<int> gangs(M);
    priority_queue<pii> pq;
    for(int i = 0; i < M; i++){
        cin >> gangs[i];    
    }
    int cows = 0;
    int contr = 0;
    vector<int> ans(M);
    //vector<string> seq(M);
    for(int i = 1; i < M; i++){
        cows = 1;
        contr = i;
        //gang i is the first to go
        //add all the gangs to the priority queue
        //pq = priority_queue<pii>();
        pq.push(mp(gangs[i]-1, i));
        for(int j = 1; j < M; j++){
            if(j == i)continue;
            pq.push(mp(gangs[j], j));
        }
        while(!pq.empty()){
            //bring cow in
            pii top = pq.top(); pq.pop();
            seq[i] += to_string(top.s + 1);
            if(cows == 0){
                contr = top.s;
            }
            if(contr ==  top.s){
                cows++;
            }
            else{
                cows--;
            }
            //no cows left in this gang
            if(top.f == 1)continue;
            pq.push(mp(top.f-1, top.s));
        }
        ans[i] = gangs[0] - cows;
    }
    int max = -100000000;
    int cow = 0;
    for(int i =1; i < N; i++){
        if(ans[i] > max){
            max = ans[i];
            cow = i;
        }
    }
    if(max < 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << max << endl;
    for(int i = 0; i < seq[cow].length(); i++){
        cout<<seq[cow][i]<<endl;
    }
    

}

