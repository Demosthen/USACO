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
long int n;
string code;
string full;
int i=0;
int z;
void solve(){

    int b=1;

    while(b<i){
            b++;

        full+=full.substr(full.length()-1)+full.substr(0, full.length()-1);


    }
    z=full.size();
    full=full.substr(full.length()-1)+full.substr(0, full.length()-1);



}
int main()
{
    ifstream fin ("cowcode.in");
    ofstream fout ("cowcode.out");


    fin>>code;
    fin>>n;
    long int y;
    long int x=code.size();

    while(x<n){
            i++;
            y=x;
        x=x*2;
    }


    full=code;
    solve();
    cout<<i<<" ";
    fout<<full[n-z-1]<<endl;
    return 0;
}
