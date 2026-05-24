#include<bits/stdc++.h>
using namespace std;

bool isEmpty(int top){
    return top == -1;
}

bool isFull(int top, int n){
    return top == n - 1;
}

void push(vector<int>& st, int &top, int val, int n){

    if(isFull(top, n)){
        cout << "Stack Overflow" << endl;
        return;
    }

    top++;
    st[top] = val;
}

void pop(vector<int>& st, int &top){

    if(isEmpty(top)){
        cout << "Stack Underflow" << endl;
        return;
    }

    cout << "Popped element: " << st[top] << endl;
    top--;
}

void peek(vector<int>& st, int top){

    if(isEmpty(top)){
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << "Top element: " << st[top] << endl;
}

int main(){

    int n;
    cin >> n;

    vector<int> st(n);

    int top = -1;

    int k = 5;

    while(k--){

        int choice;
        cin >> choice;

        switch(choice){

            case 1:{

                int val;
                cin >> val;

                push(st, top, val, n);

                break;
            }

            case 2:

                pop(st, top);
                break;

            case 3:

                if(isEmpty(top))
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is Not Empty" << endl;

                break;

            case 4:

                if(isFull(top, n))
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is Not Full" << endl;

                break;

            case 5:

                peek(st, top);
                break;

            default:

                cout << "Invalid Choice" << endl;
        }
    }
}