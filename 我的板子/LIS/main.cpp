#define max(x, y) ((x)>(y))?(x):(y)
/**
*dp[i]��ʾ��ai��β������������г���
* ��ai��β����������˵ �� 1.ֻ���� ai�������� 2.������j<iandaj<ai��һ����������ĩβ������ai��õ���������
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

