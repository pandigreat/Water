


void ShellSort(int mes[], int l){
	int dx = l/2 & 0x == 1? l / 2: l / 2 + 1;
	for(; dx > 0; dx -= 2){
		for(int i = dx; i < l; i++){
			for(int j = i - dx; j >= 0; j -= dx){
				if(mes[j] > mes[j + dx]){
					int tmp = mes[j + dx];
					mes[j + dx] = mes[j];
					mes[j] = tmp;
				}
			}
		}
	}
	
}