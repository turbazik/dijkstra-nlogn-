#include<iostream>
#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

const long long INF = 10000000000000;

int main(){
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);
    int num;
    scanf("%d\n",&num);
    for(int i=1;i<=num;i++){
        int n,m,s;
        scanf("%d %d\n",&n,&m);
        vector<vector<pair<int,int> > > g(n+10);
        vector<long long> d (n+10, INF),  p (n+10);
        set < pair<int,int> > q;
        for(int j=1;j<=m;j++){
            int x,y,z;
            scanf("%d %d %d\n",&x,&y,&z);
            g[x].push_back(make_pair(y,z));
            g[y].push_back(make_pair(x,z));
        }
        scanf("%d\n",&s);
        d[s] = 0;
        q.insert (make_pair (d[s], s));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase (q.begin());
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    q.erase (make_pair (d[to], to));
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.insert (make_pair (d[to], to));
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<d[i]<<" ";
        cout<<endl;

    }
    return 0;
}
