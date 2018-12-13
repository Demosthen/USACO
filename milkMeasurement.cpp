#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n;
int g;
vector<pair<int,pair<int,int> > > msrmnts;
//vector<int> cows;
unordered_map<int,int> cows;
bool inline compare(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    return a.first<b.first;
}
int main()
{
    ofstream fout("measurement.out");
    ifstream fin("measurement.in");
    fin>>n>>g;
    msrmnts.resize(n);
    int cnt=0;
    int maxMilk=0;//value
    vector<int> maxMilks;//indices
    //cows.resize(,0);
    for(int i=0; i<n; i++){
        fin>>msrmnts[i].first>>msrmnts[i].second.first>>msrmnts[i].second.second;
    }
    sort(msrmnts.begin(),msrmnts.end(), compare);
    int currentDay=0;
    bool shouldChange=false;
    bool firstRun=true;

    vector<int> maxMilks2;
    for(int i=0; i<msrmnts.size(); i++){
        if(msrmnts[i].first!=currentDay){

            if(maxMilks!=maxMilks2){

                ++cnt;
            }

            firstRun=false;
            maxMilks2=maxMilks;
            shouldChange=false;
            currentDay=msrmnts[i].first;
        }
        if(maxMilk!=0&&cows[msrmnts[i].second.first]==maxMilk&&msrmnts[i].second.second<0){//if pic on wall and gonna go down
            //++cnt;
            //shouldChange=true;
            //cout<<msrmnts[i].first<<endl;
            cows[msrmnts[i].second.first]+=msrmnts[i].second.second;
            if(maxMilks.size()==1){//only 1 pic on wall
                maxMilks.clear();
                int maxAmt=0;
                for(auto j=cows.begin(); j!=cows.end(); ++j){
                    maxAmt=max(j->second,maxAmt);
                }
                maxAmt=max(maxAmt,0);
                maxMilk=maxAmt;
                for(auto j=cows.begin(); j!=cows.end(); ++j){
                    if(j->second==maxAmt){
                        maxMilks.push_back(j->first);
                    }
                }
            }
            else{//more than 1 pic on wll
                remove(maxMilks.begin(),maxMilks.end(),msrmnts[i].second.first);
            }
        }
        else{
            cows[msrmnts[i].second.first]+=msrmnts[i].second.second;
            if(cows[msrmnts[i].second.first]==maxMilk){
                //++cnt;
                //shouldChange=true;

            //cout<<msrmnts[i].first<<endl;
                maxMilks.push_back(msrmnts[i].second.first);

            }
            else if(cows[msrmnts[i].second.first]>maxMilk){
                //++cnt;
                //shouldChange=true;

            //cout<<msrmnts[i].first<<endl;
                maxMilks.clear();
                int maxAmt=max(0,cows[msrmnts[i].second.first]);

                maxMilk=maxAmt;
                for(auto j=cows.begin(); j!=cows.end(); ++j){
                    if(j->second==maxAmt){
                        maxMilks.push_back(j->first);
                    }
                }
            }
        }

    }
    if(maxMilks!=maxMilks2){
        ++cnt;
    }
    if(msrmnts[0].second.second<0){
        ++cnt;
    }
    fout<<cnt<<endl;
    return 0;
}
