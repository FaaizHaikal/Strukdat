#include <bits/stdc++.h>


int main(){
    int q;
    scanf("%d", &q);
    std::string command;
    std::deque<std::string> mydeq;
    mydeq.push_back("home");
    mydeq.push_back("anton");
    while(q--){
        std::cin >> command;
        if(command == "goto"){
            std::string x;
            std::cin >> x;
            mydeq.push_back(x);
        }
        else if(command == "goback"){
            if(mydeq.empty())
                std::cout << "cannot go back\n";
            else
                mydeq.pop_back();
        }
        else{
            if(mydeq.empty())
                std::cout << "i am nowhere\n";
            else{
                std::deque<std::string>::iterator it;
                it = mydeq.begin();
                std::cout << *it;
                *it++;
                while(it != mydeq.end()){
                    std::cout << "/" + *it;
                    *it++;
                }
                std::cout << "\n";
            }
        }
    }
}