/*
ID: Demosthenes
PROG: square
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int newx2;
int newy2;
int newx1;
int newy1;
void topright(vector<int>x2, vector<int> y2){
    newx2=max(x2[0], x2[1]);
    newy2=max(y2[0], y2[1]);

}
void bottomleft(vector<int>x1, vector<int> y1){
    newx1=min(x1[0], x1[1]);
    newy1=min(y1[0], y1[1]);

}
int area(int x1, int y1, int x2, int y2){
    int x=abs(x1-x2);
    int y=abs(y1-y2);
    int side=max(x,y);
    return side*side;



}
int main()
{
    ofstream fout ("square.out");
    ifstream fin ("square.in");
    vector<int> x1;
    vector<int> x2;
    vector<int> y1;
    vector<int> y2;
    x1.resize(2);
    x2.resize(2);
    y1.resize(2);
    y2.resize(2);
    for(int i=0; i<2; i++){
        fin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    }
    topright(x2,y2);
    bottomleft(x1, y1);
    fout<<area(newx1, newy1, newx2, newy2)<<endl;



    return 0;
}
