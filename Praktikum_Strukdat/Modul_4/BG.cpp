#include <bits/stdc++.h>

void solve(std::vector<std::vector<char>> &arr, char x, int n, int m){
    switch(x){
        case 'w':
            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    if(arr[i][j] == '*'){
                        if(arr[i-1][j] == '.'){
                            arr[i-1][j] = '*';
                            arr[i][j] = '.';
                        } else if(arr[i-1][j] == '*'){
                            arr[i-1][j] = '.';
                            arr[i][j] = '.';
                        }
                    }
                }
            }
            break;
        case 'a':
            for(int i=0;i<n;i++){ 
                for(int j=1;j<m;j++){
                    if(arr[i][j] == '*'){
                        if( arr[i][j-1] == '.'){
                            arr[i][j-1] = '*';
                            arr[i][j] = '.';
                        } else if( arr[i][j-1] == '*'){
                            arr[i][j-1] = '.';
                            arr[i][j] = '.';
                        }
                    }
                }
            }
            break;
        case 's':
            for(int i=n-2;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(arr[i][j] == '*'){
                        if(arr[i+1][j] == '.'){
                            arr[i+1][j] = '*';
                            arr[i][j] = '.';
                        } else if(arr[i+1][j] == '*'){
                            arr[i+1][j] = '.';
                            arr[i][j] = '.';
                            
                        }
                    }
                }
            }
            break;
        default:
            for(int i=n-1;i>=0;i--){
                for(int j=m-2;j>=0;j--){
                    if(arr[i][j] == '*'){
                        if(arr[i][j+1] == '.'){
                            arr[i][j+1] = '*';
                            arr[i][j] = '.';
                        } else if(arr[i][j+1] == '*'){
                            arr[i][j+1] = '.';
                            arr[i][j] = '.';
                        }
                    }
                }
            }
            break;
    }
}

int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> arr(n, std::vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>arr[i][j];
        }
    }
    std::string controller;
    std::cin >> controller;
    for(char x : controller){
        solve(arr, x, n, m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cout << arr[i][j];
        }
        std::cout << "\n";
    }
}