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
	double n, k;
    cin >> n >> k;
    vector<int> A(n);
    double sum =0;
    for(int i = 0; i < n;i ++){
        cin >> A[i]; 
        sum += A[i];
    }
    k -= 0.5;
    int count = 0;
    while(sum / n < k){
        count ++;
        sum += (k + 0.5);
        n++;
    }
    cuut << count << endl;




}

