#include <bits/stdc++.h>
#define ll long long
ll fibonacci(ll h){
    return (pow((1+sqrt(5))/2, h) - pow((1-sqrt(5))/2, h))/(sqrt(5));
}

ll lucas(ll h){
    return pow((1+sqrt(5))/2, h) + pow((1-sqrt(5))/2, h);
}

ll solve(ll h){
    return 2*fibonacci(h) + lucas(h) - 1;
}

int main(){
    std::string type;
    ll h;
    std::cin >> type >> h;
    ll max = pow(2, h+1) - 1;
    if(type[0] == 'B'){
        std::cout << max << " " << h + 1;
    }
    else
        std::cout << max << " " << solve(h);
}