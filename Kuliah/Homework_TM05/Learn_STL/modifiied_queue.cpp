#include <iostream>
#include <deque>

int main(){
    std::deque<int> mydeque;
    int t, count, value, rev_status = 0;
    std::cin >> t;
    std::string command;
    while(t--){
        std::cin >> command;
        if(command == "add"){
            std::cin >> value >> count;
            if(rev_status %2 == 0){
                for(int i=0;i<count;i++){;
                    mydeque.push_front(value);
                }
            }
            else{
                for(int i=0;i<count;i++){
                    mydeque.push_back(value);
                }
            }

            std::cout << mydeque.size() << "\n";
        }
        else if(command == "del"){
            std::cin >> count;
            if(rev_status%2 == 0){
                std::cout << mydeque.back() << "\n";
                for(int i=0;i<count;i++){
                    if(mydeque.empty())
                        break;
                    mydeque.pop_back();
                }
            }
            else{
                std::cout << mydeque.front() << "\n";
                for(int i=0;i<count;i++){
                    if(mydeque.empty())
                        break;
                    mydeque.pop_front();
                }
            }
        }
        else if(command == "rev"){
            rev_status++;
        }
    }
}