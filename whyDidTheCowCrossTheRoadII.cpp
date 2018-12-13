/*
ID: Demosthenes
PROG: helpcross
LANG: C++
*/
#include <iostream>
#include <fstream>
//#include <string>
#include <algorithm>
#include <vector>
//#include <cmath>
//#include <iterator>
#include <numeric>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    a = b;
    b = temp;
}
int split_array(vector<int>& array, int pivot, int start_index, int end_index)
{
    int left_boundary = start_index;
    int right_boundary = end_index;
    while (left_boundary < right_boundary) {
	    while (pivot < array[right_boundary] && right_boundary > left_boundary) {
		    right_boundary--;
	    }
	    swap(array[left_boundary], array[right_boundary]);
	    while (pivot >= array[left_boundary] && left_boundary < right_boundary) {
		    left_boundary++;
	    }
	    swap(array[right_boundary], array[left_boundary]);
    }
    return left_boundary;
}
void quicksort(vector<int>& array, int start_index, int end_index)
{
    int pivot = array[start_index];
    int split_point;
    if (end_index > start_index) {
	    split_point = split_array(array, pivot, start_index, end_index);
	    array[split_point] = pivot;
	    quicksort(array, start_index, split_point-1);
	    quicksort(array, split_point+1, end_index);
    }
}

int n;
int k;
int b;
vector<int> signals;
vector<int> blocks;// blocks of contiguous street lights
vector<int> starts;//starting iterator of each block
vector<int> endsi;//starts+blocks[i]
int sum=1000000;
void getblocks(){
    if(!binary_search(signals.begin(), signals.end(), 1)){
        blocks.push_back(signals[0]-1);
        starts.push_back(1);
        endsi.push_back(1+signals[0]-1);
    }
    for(int i=0; i<b-1; i++){
        if(signals[i]+1!=signals[i+1]){
            blocks.push_back(signals[i+1]-signals[i]-1);
            starts.push_back(signals[i]+1);
            endsi.push_back(signals[i]+1+signals[i+1]-signals[i]-1);
        }
    }
    if(n-signals[b-1]!=0){
        blocks.push_back(n-signals[b-1]);
        starts.push_back(signals[b-1]+1);
        endsi.push_back(signals[b-1]+1+n-signals[b-1]);
    }
}
int addemup(vector<int> x, int startiter, int enditer){
    int temp=0;
    for(int i=startiter; i<=enditer; i++){
        temp+=x[i];
    }
    return temp;
}
void solve(){

    int temp=0;
    int e=0;
    int y=0;
    for(int j=0; j<blocks.size(); j++){
        for(int i=0; i<blocks.size()-j; i++){
            y=addemup(blocks, i, i+j);
            e=endsi[i+j]-starts[i]-y;
            if(y>=k-e&&e<sum){
                sum=e;
            }
        }
    }



}
int main()
{
    ofstream fout("maxcross.out");
    ifstream fin ("maxcross.in");
    fin>>n>>k>>b;
    signals.resize(b);
    for(int i=0; i<b ;i++){
        fin>>signals[i];
    }
    quicksort(signals, 0, signals.size()-1);
    getblocks();
    solve();
    fout<<sum<<endl;
    return 0;
}
