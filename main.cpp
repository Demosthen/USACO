#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> scores;
vector<int> minScores;
vector<int> prefix;
vector<int> grades;
vector<int> kVals;
double maxScore=0;
int main()
{
    ofstream fout("homework.out");
    ifstream fin("homework.in");
    fin>>n;
    minScores.resize(n);
    scores.resize(n);
    kVals.reserve(n);
    grades.reserve(n);
    prefix.resize(n);
    int sum=0;
    for(int i=0; i<n; i++){
        fin>>scores[i];
        sum+=scores[i];
        prefix[i]=sum;
    }
    int m=9999999999;
    for(int i=n-1; i>=0; i--){
        m=min(m,scores[i]);
        minScores[i]=m;
    }
    for(int i=1; i<=n-2; i++){
        double grade=((double)(prefix[n-1]-prefix[i-1]-minScores[i]))/((double)(n-i-1));
        //cout<<grade<<endl;
        if(grade>=maxScore-0.001){
            maxScore=grade;
            grades.push_back(grade);
            //kVals.push_back(i);
        }
    }
    for(int i=1; i<=n-2; i++){
        double grade=((double)(prefix[n-1]-prefix[i-1]-minScores[i]))/((double)(n-i-1));
        //cout<<grade<<endl;
        if(grade>=maxScore-0.001){

            fout<<i<<endl;
            //kVals.push_back(i);
        }
    }

    return 0;
}
