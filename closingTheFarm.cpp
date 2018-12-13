#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int> > graph;
//vector<bool> visited;
vector<bool> active;
/*void traverse(int pos){
    if(active[pos]&&!visited[pos]){
        visited[pos]=true;
        for(int i=0; i<graph[pos].size(); i++){
            traverse(graph[pos][i]);
        }
    }


}*/
int main()
{
    ofstream fout("closing.out");
    ifstream fin("closing.in");
    int n;
    int m;
    fin>>n>>m;
    active.resize(n+1,true);

    graph.resize(n+1,{});
    int minActive=1;
    for(int i=0; i<m; i++){
        int a,b;
        fin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        queue<int> toCheck;
        vector<bool> visited;
        visited.resize(n+1,false);
        toCheck.push(minActive);
        while(!toCheck.empty()){
            int node=toCheck.front();
            //cout<<node<<endl;
            toCheck.pop();
            if(active[node]&&!visited[node]){
                visited[node]=true;
                for(int j=0; j<graph[node].size(); j++){
                    toCheck.push(graph[node][j]);
                }
            }
        }
        bool b=true;
        for(int j=1; j<=n; j++){

            if(!visited[j]&&active[j]){
                b=false;
                fout<<"NO"<<endl;
                break;
            }
        }
        if(b){
            fout<<"YES"<<endl;
        }
        int close;
        fin>>close;
        active[close]=false;
        if(close==minActive){
            for(int j=1; j<=n; j++){
                if(active[j]){
                    minActive=j;
                    break;
                }
            }
        }

    }
    return 0;
}
