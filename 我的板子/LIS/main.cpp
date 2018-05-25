#define max(x, y) ((x)>(y))?(x):(y)
/**
*dp[i]表示以ai结尾的最长上升子序列长度
* 以ai结尾的子序列是说 ： 1.只包含 ai的子序列 2.在满足j<iandaj<ai的一上升子序列末尾，加上ai后得到的子序列
*/
int dp[10010];
int mes[10010];
int l;
void solve(){
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < l; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(mes[i] > mes[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(dp[i], res);
	}
	printf("%d\n", res);
}

