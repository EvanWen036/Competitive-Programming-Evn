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
        cin >> A[i];
    }
    ll B, D;
    B = 0;
    D = 0;
    for(int i = N-1; i >= 0;i --){
        if(D + A[i] >= B){
            D += A[i];
            swap(D,B);
        }
    }
    cout << B << " " << D << endl;

}

