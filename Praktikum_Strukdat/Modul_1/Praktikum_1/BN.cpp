#include <bits/stdc++.h>
#include <algorithm>

int main(){
        int n;
        scanf("%d", &n);
        std::deque<long long> mydeq;
        long long value;
        for(int i=0;i<n;i++){
            std::cin >> value;
            mydeq.push_back(value);
        }
        long long count = 0;
        std::sort(mydeq.begin(), mydeq.end());
        for(auto i = 0; i < mydeq.size(); i++){
            if(mydeq[i] == mydeq[i+1])
                mydeq.pop_front();
            else
                count++;
        }

        std::cout << count << std::endl;
}