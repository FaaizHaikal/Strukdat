#include <bits/stdc++.h>

struct urutan{
    std::string nama;
    int keparahan;
    int usia;

    bool operator<(const urutan& other) const {
        if(keparahan != other.keparahan)
            return keparahan < other.keparahan;
        return usia < other.usia;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int spesialis, residen, intern, n_pasien;
    std::cin >> spesialis >> residen >> intern >> n_pasien;

    spesialis *= 2;
    residen *= 3;
    intern *= 4;
    int max = spesialis + residen + intern;

    int count_s = 0, count_r = 0, count_i = 0;

    std::string nama_pasien;

    std::priority_queue<urutan> urutan_s;
    std::priority_queue<urutan> urutan_r;
    std::priority_queue<urutan> urutan_i;
    std::priority_queue<urutan> dialihkan;

    int keparahan, usia;
    for(int i=0;i<n_pasien;i++){
        std::cin >> nama_pasien >> keparahan >> usia;
        if(max > 0){
            if(keparahan > 7){
                if(spesialis > 0){
                    urutan_s.push({nama_pasien, keparahan, usia});
                    spesialis--;
                    max--;
                }
                else
                    dialihkan.push({nama_pasien, keparahan, usia});
            }
            else if(4 < keparahan && keparahan < 8){
                if(residen > 0){
                    urutan_r.push({nama_pasien, keparahan, usia});
                    residen--;
                    max--;
                }
                else
                    dialihkan.push({nama_pasien, keparahan, usia});
            }
            else{
                urutan_i.push({nama_pasien, keparahan, usia});
                intern--;
                max--;
            }
        }
        else
            dialihkan.push({nama_pasien, keparahan, usia});
    }

    std::cout << "Treated by Senior Doctor: " << urutan_s.size() << std::endl;
    while(!urutan_s.empty()){
        urutan temp = urutan_s.top();
        std::cout << temp.nama << " " << temp.keparahan << " " << temp.usia << std::endl;
        urutan_s.pop();
    }

    std::cout << std::endl;
    std::cout << "Treated by Resident: " << urutan_r.size() << std::endl;
    while(!urutan_r.empty()){
        urutan temp = urutan_r.top();
        std::cout << temp.nama << " " << temp.keparahan << " " << temp.usia << std::endl;
        urutan_r.pop();
    }

    std::cout << std::endl;
    std::cout << "Treated by Intern: " << urutan_i.size() << std::endl;
    while(!urutan_i.empty()){
        urutan temp = urutan_i.top();
        std::cout << temp.nama << " " << temp.keparahan << " " << temp.usia << std::endl;
        urutan_i.pop();
    }

    std::cout << std::endl;
    std::cout << "Sent to Another Hospital: " << dialihkan.size() << std::endl;
    while(!dialihkan.empty()){
        urutan temp = dialihkan.top();
        std::cout << temp.nama << " " << temp.keparahan << " " << temp.usia << std::endl;
        dialihkan.pop();
    }


    return 0;
}