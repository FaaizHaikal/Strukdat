#include <iostream>
#include <deque>

int main(){
    std::deque<int> mydeque;

    int t, value;
    std::cin >> t;
    std::string command;
    while(t--){
        std::cin >> command;
        if(command == "push_back"){
            std::cin >> value;
            mydeque.push_back(value);
        }
        else if(command == "push_front"){
            std::cin >> value;
            mydeque.push_front(value);
        }
        else if(command == "pop_back"){
            mydeque.pop_back();
        }
        else if(command == "pop_front"){
            mydeque.pop_front();
        }
    }

    std::deque<int>::iterator it;
    it = mydeque.begin();
    while(it != mydeque.end()){
        std::cout << *it << "\n";
        *it++;
    }
}