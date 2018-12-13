/*
ID: Demosthenes
PROG: haybales
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
int q;
vector<int> haybales;
vector<vector<int> > queries;
int powsucks(int base, int exp){
    int temp=1;
    for(int i=0; i<exp; i++){
        temp*=base;
    }
    return temp;
}
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

int main()
{
    ofstream fout ("haybales.out");
    ifstream fin ("haybales.in");
    fin>>n>>q;
    haybales.resize(n);
    queries.resize(q);
    int counter;
    for(int i=0; i<n; i++){
        fin>>haybales[i];
    }
    quicksort(haybales, 0, haybales.size()-1);
    //cout<<n<<" "<<q;
    //cout<<"EWDAS";
   /*for(int i=0; i<haybales.size(); i++){
        cout<<haybales[i]<<" ";
    }*/
    for(int i=0; i<q; i++){

        queries[i].resize(2);
        fin>>queries[i][0]>>queries[i][1];
        //cout<<queries[i][0]<<" "<<queries[i][1]<<" ";
    }
    for(int i=0; i<q; i++){
            counter =0;
            if(queries[i][0]>haybales[haybales.size()-1]){

                fout<<0<<endl;
                continue;
            }
        /*for(int j=0; j<haybales.size(); j++){
            if(haybales[j]>=queries[i][0]&&haybales[j]<=queries[i][1]){
                counter++;
            }
            else if(haybales[j]>queries[i][1]){

                break;

            }

        }*/

        fout<<upper_bound(haybales.begin(), haybales.end(), queries[i][1])-lower_bound(haybales.begin(),haybales.end(), queries[i][0])<<endl;




    }
    return 0;
}
