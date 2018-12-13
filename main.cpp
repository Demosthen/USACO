/*
ID: Demosthenes
PROG: cowsignal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ofstream fout("cowsignal.out");
    ifstream fin("cowsignal.in");
    int m,n,k;
    fin>>m>>n>>k;
    vector<string> lines;
    vector<int> numx;
    string temp;
    for(int i=0; i<m; i++){
            fin>>temp;
        lines.push_back(temp);
        //cout<<temp<<endl;
    }
    numx.resize(lines.size());
    for(int i=0; i<lines.size(); i++){
            for(int v=0; v<k; v++){
        for(int j=0; j<lines[i].size(); j++){
            if(lines[i][j]=='X'){
                for(int z=0; z<k; z++){
                    fout<<'X';
                }
            }
            else{
                for(int z=0; z<k; z++){
                    fout<<'.';
                }
            }
        }
        fout<<endl;
            }
    }
    return 0;
}
