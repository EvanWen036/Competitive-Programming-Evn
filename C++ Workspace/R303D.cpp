#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int A[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	sort(A, A+N);
	int count = 0;
	int time = 0;
	for(int  i = 0;i < N;i ++){
		if(A[i] >= time){
			count++;
			time += A[i];
		}
		
	}
	cout << count;


}