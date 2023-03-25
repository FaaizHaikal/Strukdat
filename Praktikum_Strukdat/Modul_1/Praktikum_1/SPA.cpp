#include <bits/stdc++.h>

std::string solve(std::string input){
    std::stack<std::string> mystack;
    std::string temp;

    int size = input.size();

    for(int i=0;i<size;i++){
        if(input[i] == '/'){
            if(temp == ".."){
                if(!mystack.empty())
                    mystack.pop();
            }
            else if(temp != "" && temp != "."){
                mystack.push(temp);
            }
            temp = "";
        }
        else
            temp += input[i];
    }

    std::string output = "";
    while(!mystack.empty()){
        output = '/' + mystack.top() + output;
        mystack.pop();
    }

    if(output == "")
        output = "/";
    
    return output;
}

int main(){
    std::string input;
    std::cin >> input;
    
    while(input != "stop"){
        input += '/';
        std::cout << solve(input) << std::endl;
        std::cin >> input;
    }
    
}