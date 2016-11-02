///////////////***DIJKSTRA***//////////////////////
//!!!tips: remind set the V!!! or the <fill()> function badly!
const int MAXV=;//set max_number here
const int INF=INT_MAX;//int32's INF
struct edge{int to,cost;};
typedef pair<int,int> P;

int V;//set vertex number
vector<edge> G[MAXV];
int d[MAXV];

void dijkstra(int s){
        priority_queue<P,vector<P>,greater<P> > que;
        fill(d+1,d+V+1,INF);//index from 1 (if index from 0,there should be fill(d,d+V,INF) )
        d[s]=0;
        que.push(P(0,s));
        while(!que.empty()){
                P p=que.top();que.pop();
                int v=p.second;
                if(d[v]<p.first) continue;
                for(int i=0;i<G[v].size();i++){
                        edge e=G[v][i];
                        if(d[e.to]>d[v]+e.cost){
                                d[e.to]=d[v]+e.cost;
                                que.push(P(d[e.to],e.to));
                        }
                }
        }
}
///////////////***DIJKSTRA***//////////////////////