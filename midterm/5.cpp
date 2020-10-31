#include<bits/stdc++.h> 
using namespace std; 
  

struct Interval 
{ 
    int low, high; 
}; 
  

bool compareInterval(Interval a, Interval b) 
{ 
    return (a.low < b.low); 
} 
  
void mergeIntervals(Interval arr[], int l) 
{ 
  
    if (l <= 0) 
        return; 

    stack<Interval> temp; 
    sort(arr, arr+l, compareInterval); //c++ sort, passing compareInterval function
    temp.push(arr[0]); //init

    for (int i = 1 ; i < l; i++) 
    { 
  
        Interval top = temp.top(); 
        //no overlap, push to stack
        if (top.high < arr[i].low) 
            temp.push(arr[i]); 
        //overlap, merge interval
        else if (top.high < arr[i].high) 
        { 
            top.high = arr[i].high; 
            temp.pop(); 
            temp.push(top); 
        } 
    } 
  

    //Use below to print
    /*
    std::cout << "Merged Interval Set: \n "; 
    while (!temp.empty()) 
    { 
        Interval t = temp.top(); 
        cout << "[" << t.low << "," << t.high << "] "; 
        temp.pop(); 
    } 
    */
    return; 
} 
  

int main() 
{ 
    Interval arr[] =  { {9,10}, {18,20}, {4,5}, {2,3} } ; 
    int l = sizeof(arr)/sizeof(arr[0]); 
    mergeIntervals(arr, l); 
    return 0; 
} 