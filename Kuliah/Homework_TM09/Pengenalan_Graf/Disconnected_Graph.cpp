#include <bits/stdc++.h>

struct Node{
    bool khusus = false;
    std::vector <int> weight;
    Node(size_t weightSize) : weight(weightSize){}
};

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, E, Q, R, count = 0;
        scanf("%d%d%d%d", &N, &E, &Q, &R);
        N++;
        std::vector<Node> Graph(N, Node(N));

        int A, B, edgeVal = 1;
        for(int i=0;i<E;i++){
            scanf("%d%d", &A, &B);
            Graph[A].weight[B] = edgeVal;
            Graph[B].weight[A] = edgeVal;
            edgeVal++;
        }
        for(int i=0;i<Q;i++){
            scanf("%d", &A);
            Graph[A].khusus = true;
        }
        std::vector<int> removedEdge(E+1, 0);
        for(int i=0;i<R;i++){
            scanf("%d", &A);
            removedEdge[A] = A;
        }

        for(int j=1;j<N-1;j++){
            if(Graph[j].khusus){
                for(int k=j+1;k<N;k++){
                    if(Graph[k].khusus){
                        int temp = Graph[j].weight[k];
                        if(temp == 0)
                            count++;
                        else{
                            if(temp == removedEdge[temp])
                                count++;
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}