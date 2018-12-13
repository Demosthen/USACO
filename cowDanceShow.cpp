/*
ID: Demosthenes
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;
int n;
double tmax;
vector<int> cowtimes;
int estimat;
int small=329898;
double sum(vector<int> x){
    double ans=0;
    for(int i=0; i<x.size(); i++){
        ans+=x[i];
    }
    return ans;
}
int solve(int estimate){
    int num[estimate];
    int j=0;
    int time=0;
    int h=0;
    for(int i=0; i<estimate; i++){
        num[i]=cowtimes[j];
        j++;
    }
    while(j<cowtimes.size()){
            h=*min_element(num, num+estimate);
        for(int i=0; i<estimate; i++){
               // cout<<*min_element(num, num+estimate)<<" ";

            num[i]-=h;

            if(num[i]==0){
                num[i]=cowtimes[j];
                j++;
            }

        }
        time+=h;
        if(time>tmax){
            return solve(estimate+1);
            break;

        }

    }
    if(time<tmax){

            return estimate;
        }
}
int main()
{
    ofstream fout ("cowdance.out");
    ifstream fin ("cowdance.in");
    int a;
    fin>>n>>tmax;
    cowtimes.resize(n);
    for(int i=0; i<n; i++){
        fin>>cowtimes[i];
    }
    estimat=ceil(sum(cowtimes)/tmax);
    a=solve(estimat);
    while(a<small){
        small=a;
        a=solve(a-1);
    }
    fout<<small+1<<endl;
    return 0;
}
