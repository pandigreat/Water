


/**
���д��룬�������Ƶ�����˼��
**/

for(int k = 0; k < n; k++)
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mes[i][j] = min(mes[i][j], mes[i][k] + mes[k][j]);
		
		