#include <bits/stdc++.h>

int main(){
    int n, t, id;
    std::cin >> n >> t;
    int available = n, smallestID = 1;
    std::string command, name;
    std::unordered_map<int, std::string> myMap;
    while(t--){
        std::cin >> command;
        if(command[0] == 'D'){
            std::cin >> name >> id;
            if(available > 0){
                if(myMap.count(id) > 0){
                    while(myMap.count(smallestID) > 0)
                        smallestID++;
                    if(smallestID > n)
                        std::cout << "Penuh\n";
                    else{
                        myMap[smallestID] = name;
                        smallestID++;
                    }
                }
                else
                    myMap[id] = name;
                available--;
            }
            else
                std::cout << "Penuh\n";
        }
        else if(command == "SELESAI"){
            std::cin >> id;
            myMap.erase(id);
            available++;
            if(id < smallestID)
                smallestID = id;
        }
        else if(command == "STATUS"){
            std::cin >> id;
            if(myMap.count(id) > 0)
                std::cout << "Digunakan " << myMap[id] << '\n';
            else
                std::cout << "Kosong\n";
        }
        else if(command == "CARI"){
            std::cin >> name;
            bool found = false;
            int foundId;
            for(auto it : myMap){
                if(it.second == name){
                    found = true;
                    foundId = it.first;
                    break;
                }
            }
            if(found)
                std::cout << "Komputer " << foundId << '\n';
            else
                std::cout << "Tidak Ada\n";
        }
        else{
            std::cout << n - available << '\n';
        }
    }
}