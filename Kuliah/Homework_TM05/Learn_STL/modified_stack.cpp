#include <iostream>
#include <stack>
int main(){
    std::stack<int> stack;
    int t, x, y, addition = 0;
    std::cin >> t;
    std::string command;
    while(t--){
        std::cin >> command;
        if(command == "add"){
            std::cin >> x >> y;
            while(y--)
                stack.push(x-addition);
            std::cout << stack.size() << "\n";
        }
        else if(command == "del"){
            std::cin >> y;
            std::cout << stack.top() + addition << "\n";
            while(y--)
                stack.pop();       
        }
        else if(command == "adx"){
            std::cin >> x;
            addition += x;
        }
        else if(command == "dex"){
            std::cin >> x;
            addition -= x;
        }
    }
}