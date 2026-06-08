#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int>&vec,int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j],vec[j+1]);
            }
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

    bubblesort(vec,n);
    cout << endl;
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}