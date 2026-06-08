#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int>&vec,int n){
    for(int i=0;i<n-1;i++){
        // last ele sort by itself
        int min=i;
        for(int j=i+1;j<n;j++){
               if(vec[j] < vec[min]){
                min=j;
            }
        }
        swap(vec[i],vec[min]);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    selectionsort(vec,n);
    cout << endl;
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}