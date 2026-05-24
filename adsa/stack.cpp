#include<bits/stdc++.h>
using namespace std;

bool isEmpty(vector<int>&st,int top){
    return top==-1;

}
bool isfull(vector<int>&st,int top,int n){
    return top==n-1;
}

void push(vector<int>&st,int &top,int val,int n){
    if(!isfull(st,top,n)){
        top++;
        // st.push_back(val);
        st[top]=val;
        // return;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
   
}
int topele(vector<int>&st,int top){
    if(!isEmpty(st,top)){
        return st[top];
    }
    else{
        cout<<"Stack is empty"<<endl;
        return -1;
    }
}
void pop(vector<int>&st,int &top){
    if(!isEmpty(st,top)){
            
            st.pop_back();
            top--;
    }
    else{
        cout<<"Stack underflow"<<endl;
    }
}


int main(){
    int n;
    
    // size of stack
    cin >> n;
    vector<int>st(n);
    int top=-1;
    int k=5;
    while(k--){
         int choice;
         cin >> choice;
         switch(choice){
        case 1:
            int val;
            cin >> val;
            push(st,top,val,n);
            cout << st[top] << endl;
            break;
        case 2:
            pop(st,top);
            break;
        case 3:
            if(isEmpty(st,top)){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"Stack is not empty"<<endl;
            }
            break;
        case 4:
            if(isfull(st,top,n)){
                cout<<"Stack is full"<<endl;
            }
            else{
                cout<<"Stack is not full"<<endl;
            }
        default:
            cout<<"Invalid choice"<<endl;
    }
    }
   


}