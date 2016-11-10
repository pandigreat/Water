


/**
四行代码，表达出递推的中心思想
其中 mes[i][i] 为0
未考虑回环和负数权重的版本
**/

for(int k = 0; k < n; k++)
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mes[i][j] = min(mes[i][j], mes[i][k] + mes[k][j]);
		

		
		