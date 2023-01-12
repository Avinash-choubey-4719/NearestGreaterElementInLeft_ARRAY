#include<bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterElementInLeft(int arr[], int n){
    stack<int> s;
    vector<int> v;
    int a = -1;

    for(int i = 0;i<n;i++){
        if(!s.empty() && s.top() > arr[i]){
            v.push_back(s.top());
            s.push(arr[i]);
        }

        else if(s.empty()){
            v.push_back(a); 
            s.push(arr[i]);
        }

        else if(!s.empty() && s.top() <= arr[i]){
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }

           if(s.empty()){
                v.push_back(a);        
                s.push(arr[i]);
           }

           else{
                v.push_back(s.top());
                s.push(arr[i]);
           }
        }
    }

    return v;
}

int main(){
    int arr[] = {3, 1, 10, 0, 15};
    int n = 5;
    vector<int> result = nearestGreaterElementInLeft(arr, n);
    for(auto itr : result){
        cout<<itr<<endl;
    }

    return 0;
}