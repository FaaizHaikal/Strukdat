#include <bits/stdc++.h>

struct Data {
    int untung;
    int susah;
	int index;
    bool operator<(const Data& other) const {
        if (untung != other.untung){
            return untung < other.untung;
		}
        if(susah != other.susah){
			return susah < other.susah;
		}
		return index > other.index;
    }
};

int main() {
    std::priority_queue<Data> mypq;
	int n, biaya, gaji, susah, untung, i =0;
	int tSusah = 0, tUntung = 0;
	int banyak;
	scanf("%d", &n);
	char command[11];
	while(n--){
		scanf("%s ", command);
		
		if(command[0] == 'p'){
			scanf("%d%d%d", &susah, &biaya, &gaji);
			untung = gaji - biaya;
			mypq.push({untung, susah, i});
			i++;
		}
		else{
			scanf("%d", &banyak);
			while(banyak--){
				if(mypq.empty()){
					printf("Sabar Woy!\n");
					break;
				}
				Data data = mypq.top();
				mypq.pop();
				if(data.untung < 0){
					printf("Skip pekerjaan %d\n", data.index);
					banyak++;
				}
				else {
					printf("Mengerjakan pekerjaan %d\n", data.index);
					tSusah += data.susah;
					tUntung += data.untung;
				}
			}
		}
	}
	printf("Total Kesusahan: %d\nTotal Keuntungan: %d", tSusah, tUntung);
	return 0;
}


