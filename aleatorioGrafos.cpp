#include <iostream>
#include <random>
#include <deque>
#include <math.h>

using namespace std;

std::random_device rd;
std::mt19937 eng(rd());

vector<vector<int>> g;
vector<vector<int>> adyacentes;

int generarNumero(int min, int max){
    uniform_int_distribution distr(min, max);
    return distr(eng);
}

void imprimirGrafo(vector<vector<int>> const & grafo, int const & aristas){
    cout << grafo.size() << " " << aristas << "\n";
    for (int i = 0;i<grafo.size();i++){
        for(int j : grafo[i]){
            cout << i << "->" << j << "\n";
        }
    }
}

void generarGrafoAleatorio(){
    int N = 8;
    int max = .5 * N*(N-1); max--;
    int A = generarNumero(N, max);
    cout << N << " " << A << "\n";
    g.assign(N, vector<int>(0, {}));
    adyacentes.assign(N, vector<int>(N, 0));
    for(int i=0;i<A;i++){
        int origen = generarNumero(0, N-1);
        while(g[origen].size() == N) origen = generarNumero(0, N-1);
        int destino = generarNumero(0, N-1);
        while(destino == origen || adyacentes[origen][destino] == 1) destino = generarNumero(0, N-1);
        adyacentes[origen][destino] = 1; adyacentes[destino][origen] = 1;
        g[origen].push_back(destino);
    }

    imprimirGrafo(g, A);


}


void generarGrafoNoConexoAleatorio(){
    int N = generarNumero(1, 10);
    int max = .5 * N*(N-1); max--;
    int A = N-1;
    cout << N << " " << A << "\n";
    g.assign(N, vector<int>(0, {}));
    adyacentes.assign(N, vector<int>(N, 0));
    for(int i=0;i<A;i++){
        int origen = generarNumero(0, N-1);
        while(g[origen].size() == N) origen = generarNumero(0, N-1);
        int destino = generarNumero(0, N-1);
        while(destino == origen || adyacentes[origen][destino] == 1) destino = generarNumero(0, N-1);
        adyacentes[origen][destino] = 1; adyacentes[destino][origen] = 1;
        g[origen].push_back(destino);
    }

    imprimirGrafo(g, A);


}

int main(){
    generarGrafoNoConexoAleatorio();
}