#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>vec;
    int left=low, right=mid+1;
    while(left<=mid && right <= high){
        if(arr[left] <= arr[right]){
            vec.push_back(arr[left]);
            left++;
        }
        else{
            vec.push_back(arr[right]);
                right++;
            
        }

    }
    while(left <= mid){
        vec.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        vec.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=vec[i-low];
    }
}

void mergesort(vector<int>&arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
    
}
int main(){
    int n;
    cin >> n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    mergesort(vec,0,n-1);
    cout << endl;
    for(auto i: vec){
        cout << i << " ";
    }
    return 0;
}