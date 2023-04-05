#include <bits/stdc++.h>

int main(){
    int n, value;

    std::vector<int> gedung;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> value;
        gedung.push_back(value);
    }

    std::vector<int> stamina;
    for(int i=0; i<n;i++){
        int temp = gedung[i];
        if(gedung[i] < gedung[i+1]){
            int j = i;
            while(gedung[j] < gedung[j+1]){
                temp = temp ^ gedung[j+1];
                j++;
            }

            stamina.push_back(temp);
            continue;
        }
        stamina.push_back(temp);
    }

    // for(int i : stamina)
    //     std::cout << i << std::endl;

    std::cout << *std::max_element(stamina.begin(), stamina.end()) << std::endl;
}