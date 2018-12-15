#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
vector<bool> taken;
priority_queue<pair<int,int> > pq; //weight, index
vector<vector<int> > adj;
int mst = 0;
int n;
inline int distance(int x1, int y1,int x2, int y2){ //gives X, not sqrt X
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void process(int vtx){
    for(int i=0; i<n; i++){
        if(!taken[i]){
            pq.push(make_pair(-adj[vtx][i], -i)); //negate so sorted in increasing order
        }
    }
}
int main()
{
    ofstream fout ("moocast.out");
    ifstream fin ("moocast.in");

    fin>>n;
    int maxim=0;
    vector<int> x;
    vector<int> y;
    x.resize(n);
    y.resize(n);
    adj.resize(n);
    taken.resize(n,false);
    int temp;
    for(int i=0; i<n; i++){
        fin>>x[i]>>y[i];
        adj[i].resize(n);
    }
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            adj[i][j] = distance(x[i],y[i],x[j],y[j]);
        }
    }
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        pair<int,int> v = pq.top();
        pq.pop();
        if(!taken[-v.second]){
            mst-=v.first;
            process(-v.second);
            maxim = max(-v.first, maxim);
            taken[-v.second] = true;
        }
    }
    fout<<maxim<<endl;
    return 0;
}
