#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
bitset<100001> checked;
bitset<100001> inCycle;
vector<int> shuffle1;
int n;
vector<bool> stationary;
int numStat=0;
void traverse(int pos, int startPos, bool firstRun,vector<int> &cycle){
    if(!inCycle[pos]&&!stationary[pos]){
        inCycle[pos]=true;
        cycle.push_back(pos);
        //checked[pos]=true;
        traverse(shuffle1[pos],startPos,false,cycle);
    }
    else if(inCycle[pos]&&!firstRun&&pos==startPos){
        for(int i=0; i<cycle.size(); i++){
            if(!stationary[cycle[i]]){
                stationary[cycle[i]]=true;
                ++numStat;
            }
        }
    }
}
int main()
{
    ofstream fout ("shuffle.out");
    ifstream fin ("shuffle.in");

    fin>>n;
    shuffle1.resize(n);
    //checked.resize(n,false);
    stationary.resize(n,false);
    for(int i=0; i<shuffle1.size(); i++){
        fin>>shuffle1[i];
        --shuffle1[i];
    }
    for(int i=0; i<n; i++){
        if(!stationary[i]){
                vector<int> c;
            traverse(i,i,true,c);
            inCycle.reset();
        }
    }
    fout<<numStat<<endl;
    return 0;
}
