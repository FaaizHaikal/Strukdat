#include <bits/stdc++.h>

int main(){
  int n_user, n_msg;
  std::map<std::string, std::string> users;
  std::cin >> n_user >> n_msg;
  for(int i=0;i<n_user;i++){
    std::string user, ip;
    std::cin >> ip >> user;
    users[ip] = user;
  }

  std::map<std::string, std::map<std::string, std::vector<std::string>>> messages;
  for(int i=0;i<n_msg;i++){
    std::string sender, receiver, msg;
    std::cin >> sender >> receiver;
    std::getline(std::cin, msg);
    msg = msg.substr(1);
    messages[receiver][sender].push_back(msg);
  }
  for(auto user : users){
    std::cout << "===========\n";
    std::cout << "Mail: " << user.second << "\n";
    std::string ip = user.first;
    for(auto sender : messages[ip]){
      std::cout << "From: " << users[sender.first] << "\n";
      for(auto msg : sender.second){
        std::cout << ">> " << msg << "\n";
      }
    }
  }
}