/*
 knapsack problem on Spoj online judge
 *memoization method
 DP
 http://www.spoj.com/problems/KNAPSACK/
 by : karim mokhtar
*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define EPS 1e-9
int n,s;
int value[2001],size[2001];
int memo[2001][2001];
int dp(int i , int S){
	if(i == n || S <= 0)
		return 0;
	int &ans = memo[i][S];
	if(ans != -1)return ans;
	ans = dp(i+1,S);
	if(S-size[i] >= 0){
		ans = max( dp(i+1,S-size[i])+value[i] , dp(i+1,S) );
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test", "r", stdin);
	freopen("out", "w", stdout);
#endif

	memset(memo,-1,sizeof memo);
	scanf("%d %d",&s,&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d %d",size+i,value+i);
	cout << dp(0,s);
	return 0;
}
