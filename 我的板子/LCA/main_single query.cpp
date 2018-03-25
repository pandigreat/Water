
int getPre(int x){
	return x == pre[x]? x: getPre(pre[x]);
}

void union_set(int x, int y){
    x = getPre(x);
    y = getPre(y);
    if(x != y) pre[x] = y;
}

 
#include <cstdio>
#include <cstring>
const int N = 510;
int pre[N];

///已经遍历过一次，完成Pre还有rank的更新
void dfs(){
	
	
	
}


int LCA(int u, int v) {

    while (pre[u] > pre[v]) {
        u = pre[u];
    }

    while (pre[u] < pre[v]) {
        v = pre[v];
    }

    if (u != v) {
        while (pre[u] > pre[v]) {
            u = pre[u];
        }
    }
    return u;
}

int main() {

    return 0;
}


