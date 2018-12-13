#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ofstream fout("highcard.out");
    ifstream fin("highcard.in");
    int n;
    fin>>n;
    vector<int> elCards;

    elCards.resize(n);
    deque<int> beCards;
    for(int i=0; i<n; i++){
        fin>>elCards[i];
    }
    sort(elCards.begin(),elCards.end());
    int cnt=0;
    for(int i=1; i<=2*n; i++){
        if(cnt<elCards.size()&&i==elCards[cnt]){
            ++cnt;
        }
        else{
            beCards.push_back(i);
        }
    }
    int points=0;
    cout<<"uqwebfiwj"<<endl;
    auto pos=upper_bound(elCards.begin(),elCards.end(),beCards.back());
    for(int i =pos-elCards.begin(); i<elCards.end()-elCards.begin(); i++){
        cout<<beCards.front()<<endl;
        beCards.pop_front();
    }
    cout<<"hey"<<beCards.size()<<endl;
    auto temp=elCards.end();
    while(!beCards.empty()){

        pos=upper_bound(elCards.begin(),temp,beCards.back());
        cout<<pos-elCards.begin()<<" "<<temp-elCards.begin()<<endl;
        if(pos!=elCards.begin()){
            ++points;
            beCards.pop_back();
        }
        else{
            break;
        }
        temp=pos-1;

    }
    cout<<points<<endl;
    /*while(pos!=elCards.end()&&!beCards.empty()){
        ++points;
        auto temp=pos-1;
        pos=upper_bound(elCards.begin(),pos-1,beCards.front());
        for(int i =pos-elCards.begin(); i<temp-elCards.begin(); i++){
            --points;
            beCards.pop_back();
        }
        if(pos==temp){
            if(binary_search(elCards.begin(),temp,beCards.front())){
                --points;
                beCards.pop_back();
            }
        }
        else{
            beCards.pop_front();
        }
        cout<<points<<endl;
    }*/
    fout<<points<<endl;
    return 0;
}
