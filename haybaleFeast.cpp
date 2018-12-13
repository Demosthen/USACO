#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n;
int m;
vector<pair<int,int> > hay;
vector<pair<int,int> > maxSpices;//first is left, second is right, inclusive
vector<int> prefixFlav;

int main()
{
    ofstream fout("hayfeast.out");
    ifstream fin("hayfeast.in");
    fin>>n>>m;
    hay.resize(n);
    maxSpices.resize(n);
    prefixFlav.resize(n);
    int sum=0;
    int leftSpice=0;
    for(int i=0; i<n; i++){
        fin>>hay[i].first>>hay[i].second;
        sum+=hay[i].first;
        prefixFlav[i]=sum;
        //leftSpice=max(hay[i].second,leftSpice);
        //maxSpices[i].first=leftSpice;
    }
    /*int rightSpice=0;
    for(int i=n-1; i>=0; i--){
        rightSpice=max(rightSpice,hay[i].second);
        maxSpices[i].second=rightSpice;
        //cout<<maxSpices[i].first<<" "<<maxSpices[i].second<<endl;
    }*/
    int minSpice=pow(10,9)+1;
    for(int i=0; i<n; i++){
        auto pos=lower_bound(prefixFlav.begin(), prefixFlav.end(),prefixFlav[i]+m-hay[i].first);
        int spice=0;

        if(pos!=prefixFlav.end()){
            for(int j=i; j<=pos-prefixFlav.begin(); j++){
                spice=max(spice,hay[j].second);
            }
            //minSpice=min(minSpice,min(maxSpices[i].second,maxSpices[pos].first));
            minSpice=min(minSpice,spice);
        }
    }
    fout<<minSpice<<endl;
    return 0;
}
