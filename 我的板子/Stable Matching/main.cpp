#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
#include<vector>

int ManLike[10010][10010];
int WomanLike[10010][10010];
queue<int> q;
int res[10010];
int wres[10010];
bool v[10010];
int pos[10010];
int l;

void Solve(){
	memset(ManLike, 0, sizeof(ManLike));
	memset(WomanLike, 0, sizeof(WomanLike));
	memset(v, 0, sizeof(v));
	for(int i = 1; i <= l; i++){
		int m = ManLike[i][1];
		if(!v[m])
			res[i] = m, v[m] = true, wres[m] = i;
		else{
			int p1, p2;
			for(int j = 1; j <= l; j++){
				if(WomanLike[m][j] == wres[m]) p1 = j;
				if(WomanLike[m][j] == i) p2 = j;
			}
			if(p1 < p2) q.push(i), pos[i] = 2;
			else{
				q.push(wres[m]);
				pos[wres[m]] = 2;
				res[wres[m]] = 0;
				wres[m] = p2;
				res[i] = m;	
			}
		}
	}
	while(!q.empty()){
		int man = q.top(); q.pop();
		for(int i = pos[man]; i <= l; i++){
			int m = ManLike[man][i];
			if(!v[m])
				res[tmp.first] = m, v[m] = true, wres[m] = tmp.first, break;
			else{
				int p1, p2;
				for(int j = 1; j <= l; j++){
					if(WomanLike[m][j] == wres[m]) p1 = j;
					if(WomanLike[m][j] == tmp.first) p2 = j;
				}
				if(p1 < p2) q.push(tmp);
				else{
					q.push(PII(wres[m], 2));
					res[wres[m]] = 0;
					wres[m] = p2;
					res[i] = m;	
				}
			}
		}		
	}
	
}


int main(){
	fopen("1.txt", "r");
	fscanf("%d", &l);
	for(int i = 1; i <= l; i++)
		for(int j = 1; j <= l; j++)
			fscanf("%d", (*(ManLike + i)) + j);
	for(int i = 1; i <= l; i++)
		for(int j = 1; j <= l; j++)
			fscanf("%d", (*(WomanLike + i)) + j);
	solve();
	
	return 0;
}


