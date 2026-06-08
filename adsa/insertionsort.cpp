#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>&vec,int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && vec[j] < vec[j-1]){
            swap(vec[j],vec[j-1]);
            j--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    insertionsort(vec,n);
    cout << endl;
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}