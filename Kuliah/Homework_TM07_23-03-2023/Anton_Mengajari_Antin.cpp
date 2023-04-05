#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

 

    int n, q, value;
    std::cin >> n >> q;

    std::vector<std::vector<int>> myvector;
    std::vector<int> kolom;
    int m;
    for(int i=0;i<n;i++){
        std::cin >> m;
        for(int j=0;j<m;j++){
            std::cin >> value;
            kolom.push_back(value);
        }
        myvector.push_back(kolom);
        kolom.clear();
    }
    
    std::string command;
    int x, y;
    while(q--){
        std::cin >> command;
        std::cin >> x;
        x--;
        if(command == "tambah"){
            std::cin >> y;
            y--;
            x++;
            myvector[y].push_back(x);
        }
        else if(command == "hilang"){
            std::cin >> y;
            y--;
            myvector[y].erase(myvector[y].begin()+x);
        }
        else if(command == "tukar"){
            std::cin >> y;
            y--;
            myvector[x].swap(myvector[y]);
        }
        else if(command == "b_atas"){
            std::cin >> y;
            y--;
            std::vector<int> temp = myvector[y];
            sort(temp.begin(), temp.end());
            for(int i=0;i<temp.size(); i++){
                if(temp[i] > temp[x]){
                    std::cout << i << std::endl;
                    break;
                }
            }
        }
        else if(command == "b_bawah"){
            std::cin >> y;
            y--;
            std::vector<int> temp = myvector[y];
            sort(temp.begin(), temp.end());
            
            for(int i=0;i<temp.size(); i++){
                if(temp[i] == temp[x]){
                    std::cout << i << std::endl;
                    break;
                }
            }
        }
        else if(command == "banyak"){
            int count = 0;
            for(int i : myvector[x]){
                count++;
            }
            std::cout << count << std::endl;
        }
        else if(command == "mean"){
            float sum = 0;
            int count = 0;
            for(int i=0; i<myvector[x].size();i++){
                sum += myvector[x][i];
                count++;
            }
            std::cout << sum/count << std::endl;
        }
        else if(command == "median"){
            std::vector<int> temp = myvector[x];
            sort(temp.begin(), temp.end());

            int size = temp.size();
            if(size % 2 == 0)
                std::cout << (temp[size/2 - 1] + temp[size/2 + 1])/2.0 << std::endl;
            else
                std::cout << temp[size/2] << std::endl;
        }
        else if(command == "modus"){
            int max = *std::max_element(myvector[x].begin(), myvector[x].end());
            std::vector<int> counter(max+1);
            for(int i : myvector[x]){
                counter[i]++;
            }

            int modus = 0, max_count = 0;
            for (int i = 1; i <= max; i++) {
                if (counter[i] > max_count) {
                    max_count = counter[i];
                    modus = i;
                }
            }

            std::cout << modus << std::endl;

        }
        else if(command == "urut"){
            std::vector<int> temp = myvector[x];
            sort(temp.begin(), temp.end());

            for(int i : temp){
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        else{
            std::cout << "Query not found" << std::endl;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < myvector[i].size(); j++)
        //     {
        //         std::cout << myvector[i][j] << " ";
        //     }
        //     std::cout <<  std::endl;
        // }
    }

}