#include<bits/stdc++.h>
using namespace std;
 
int partitionlastpivot (vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
    
}

int anyatpivot(vector<int>&arr,int low,int high,int ind){
    swap(arr[ind],arr[high]);
    return partitionlastpivot(arr,low,high);

}

int partitionfirstpivot(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
   while(i < j){
     while(i <= high-1 && arr[i] <=pivot){
        i++;
    }
    while(j >= low+1 && arr[j] > pivot){
        j--;
    }
    if(i <j ){
        swap(arr[i],arr[j]);
    }
   }
   swap(arr[j],arr[low]);
   return j;
}


void quicksort(vector<int>&arr,int low,int high,int ind){
    if(low < high){
        int partition=anyatpivot(arr,low,high,ind);
        quicksort(arr,low,partition-1,ind);
        quicksort(arr,partition+1,high,ind);
    }
}

int main(){
    int n;
    cin >> n;
    int ind;
    cin >> ind;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
    quicksort(vec,0,n-1,ind);
    cout << endl;
    for(auto i: vec){
        cout << i << " ";
    }
    return 0;
}