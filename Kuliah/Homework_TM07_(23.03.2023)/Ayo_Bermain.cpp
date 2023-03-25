#include <bits/stdc++.h>

typedef struct player{
    std::string nama;
    int posisi;
    bool ketangkep = false;
};

int main(){
    player Player[4];
    for(int i=0;i<4;i++)
        std::cin >> Player[i].nama;
    int langkah;
    std::string Penjaga;
    std::cin >> langkah >> Penjaga;
    int id_player, pindah_ke;
    player *posisi;
    while(langkah--){
        std::cin >> id_player >> pindah_ke;
        Player[id_player].posisi = pindah_ke;
        
}