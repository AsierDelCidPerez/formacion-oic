#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int miAlgoritmo(vector<int> A){
    int i=1;
    int j=1;
    int m=0;
    int c=0;
    while(i<=A.size()){
        if(A[i]==A[j]) c++;
        j++;
        if(j > A.size()){
            if(c > m) m = c;
            c = 0;
            i++;
            j = i;
        }
    }
    return m;
}

int miAlgoritmo2(vector<int> & A){
    if(A.size() == 0) return 0;
    sort(A.begin(), A.end());

    for(int i : A) cout << i << " ";
    cout << "\n";

    int max = -1;
    int contador = 1;
    int anterior = A[0];
    for(int i=1;i<A.size();i++){
        if(anterior == A[i]) contador++;
        else{
            max = contador > max ? contador : max;
            contador = 1;
            anterior = A[i];
        }
    }
    max = contador > max ? contador : max;
    return max;
}

void imprimirArray(vector<int> & array){
    for(int i : array) cout << i << " ";
    cout << "\n";
}

int main(){
    vector<int> array = {4, 1, -5, 7, 2, 9};
    sort(array.begin(), array.end()); 
    imprimirArray(array); // -5 1 2 4 7 9
    sort(array.rbegin(), array.rend()); // 9 7 4 2 1 -5
    imprimirArray(array);
}