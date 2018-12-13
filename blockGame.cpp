/*
ID: Demosthenes
PROG: blocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> letters;
const int A=97;
vector<vector<string > > block;
int n;
//vector<<vector<int> > > hasmost;


int main()
{
    ofstream fout ("blocks.out");
    ifstream fin ("blocks.in");
    letters.resize(26);
    int counter[2];
    fin>>n;
    string temp;
    block.resize(n);
    for(int i=0; i<n; i++){

        for(int j=0; j<2; j++){

            fin>>temp;
            block[i].push_back(temp);
        cout<<block[i][j]<<" ";
        }
    }
cout<<n;

    for(int i=0; i<26; i++){
        for(int j=0; j<n; j++){
                for(int k=0; k<2; k++){
                        counter[k]=0;
                        for(int q=0; q<block[j][k].size(); q++){
                            if(block[j][k][q]-A==i){
                                counter[k]++;
                            }
                        }
                }
                    letters[i]+=max(counter[0], counter[1]);

        }

    }
    for(int i=0; i<26; i++){
        fout<<letters[i]<<endl;
    }
    return 0;
}
