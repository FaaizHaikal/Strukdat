// Given a set of arrays of size N and an integer K, you have to find the maximum integer for each 
// and every contiguous subarray of size K for each of the given arrays.

// INPUT
// First line of input will contain the number of test cases T. 
// For each test case, you will be given the size of array N and the size of subarray to be used K. 
// This will be followed by the elements of the array Ai.

// OUTPUT
// For each of the contiguous subarrays of size K of each array, you have to print the maximum integer.

#include <bits/stdc++.h>

void solve(int *ar, int n, int k){
    std::deque<int> mydeque;
    for(int i=0;i+k-1<n;i++){
        int z = i;
        for(int j=0;j<k;j++){
            if((!mydeque.empty()) && (ar[z] > mydeque.front()))
                mydeque.push_front(ar[z]);
            else
                mydeque.push_back(ar[z]);
            z++;
        }
        std::cout << mydeque.front() << " ";
        
        mydeque.clear();
    }
}
int main(){
    int T, n, k;
    std::cin >> T;
    while(T--){
        std::cin >> n >> k;
        int ar[n];
        for(int i=0;i<n;i++)
            std::cin >> ar[i];
        solve(ar, n, k);

        printf("\n");
    }

    return 0;

}