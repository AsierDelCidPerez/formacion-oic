#include <iostream>
#include <random>
#include <deque>
#include <math.h>
#include <map>
#include <string>
#include <set>

using namespace std;

std::random_device rd;
std::mt19937 eng(rd());

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1) {}

    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }

    void join(int i, int j){
        int x = find(i), y = find(j); 
        if(p[x] > p[y]) {
            swap(x, y);
        } // x siempre contiene al arbol mayor
        p[x] += p[y];
        p[y] = x;
        --numSets;
    }

    bool related(int i, int j){
        return find(i) == find(j);
    }

    int size(int i){
        return -p[find(i)];
    }

};


int generarNumero(int min, int max){
    uniform_int_distribution distr(min, max);
    return distr(eng);
}

bool contengase(vector<int> arr, int a){
    for(int i : arr){
        if(a == i) return true;
    }
    return false;
}

pair<int, int> parNoRepetido(int min, int max){
    int a = generarNumero(min, max);
    int b = generarNumero(min, max);
    while(a == b) int b = generarNumero(min, max);
    return {a, b};
}



void generarArrayAleatorio(int longitud, int min, int max){

    while(longitud--){
        cout << generarNumero(min, max) << " ";
    }

    cout << "\n";
}


void aleatorioGrafo(bool ponderado){
    vector<vector<int>> g;
    int n = generarNumero(3, 1000);
    g.assign(n, vector<int>(0, {}));
    vector<int> parents;
    set<int> peres;
    int salida = generarNumero(0, n-1);
    int pasillos = 0;
    parents.push_back(salida);
    peres.insert(salida);
    ufds u(n);
    while(u.numSets != 1){
        int r = parents[generarNumero(0, parents.size()-1)];
        int a = generarNumero(0, n-1);
        while(u.related(r, a) || peres.count(a)) a = generarNumero(0, n-1);
        // while(r == a) a = random(0, n-1);
        g[r].push_back(a);
        peres.insert(a);
        parents.push_back(a);
        u.join(r, a);
        
        ++pasillos;
    }
    
    int fin = generarNumero(0, n-1);
    int alpha = 1.1*n-pasillos;

    while(alpha--){
        int r = generarNumero(0, n-1);
        int a = fin;
        while(contengase(g[a], r) || contengase(g[r], a) || r == a){
            r = generarNumero(0, n-1);
        }
        g[r].push_back(a);
        ++pasillos;
    }

    const int faktor = 100;

    cout << n << " " << pasillos << "\n";
   
    for(int i=0;i<g.size();i++)
        for(auto j : g[i])
            cout << i+1 << " " << j+1 << (ponderado ? (" " + to_string(generarNumero(1,faktor))) : "") << "\n";
    
    cout << generarNumero(1, n) << " " << generarNumero(1, n) << " " << generarNumero(1,10) << "\n";

}


void generarPedroFranqueza(int T){
    while(T--){
        int N = 500000;
        int k = 50000;
        cout << N << " " << k << "\n";
        generarArrayAleatorio(N, 100,100000);
    }
    cout << "0 0\n";
}

const string banco = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

string generateFromBank(string const & bank, int longitud){
    string generado = "";
    for(int i=0;i<longitud;i++){
        int n = generarNumero(0, bank.length()-1);
        generado += bank[n];
    }
    return generado;
}

void generarToro(int T){
    while(T--){
        int nExamenes = 10000;
        cout << nExamenes << "\n";
        int nEstudiantes = 1000;
        vector<string> estudiantes(nEstudiantes, "");
        for(int i=0;i<nEstudiantes;i++){
            estudiantes[i] = generateFromBank(banco, 30);
        }
        for(int i=0;i<nExamenes;i++){
            cout << estudiantes[i % nEstudiantes] << "\n";
            cout << (generarNumero(0, 1) > 0 ? "CORRECTO" : "INCORRECTO") << "\n";
        }
    }
    cout << "0\n";
}

void generarCubifinito(int T){
    while(T--){
        const int MAX = 10000000;
        const int MIN = 1;
        cout << generarNumero(MIN, MAX) << "\n";
    }
    cout << "0\n";
}

void generateSherlock(int T){
    cout << T << "\n";
    while(T--){
        deque<int> camisasCola;
        int camisas = generarNumero(1, 10000); // MAX 10^5
        cout << camisas << "\n";
        int faktor = (100) * camisas;
        // cout << "Mi faktor = " << faktor << "\n";
        for(int i=0;i<camisas;i++){
            int cam = generarNumero(1, faktor);
            cout << cam << " ";
        }
        cout << "\n";
        int acciones = generarNumero(1, 10000); // MAX 10^5
        cout << acciones << "\n";
        for(int i=0;i<acciones;i++){
            int acc = generarNumero(1, 5);
            if(acc == 1){
                cout << "i\n";
            }else if(acc == 2){
                cout << "d\n";
            }else if(acc == 3){
                int cam = generarNumero(1, faktor);
                cout << "I " << cam << "\n";
            }else if(acc == 4){
                int cam = generarNumero(1, faktor);
                cout << "D " << cam << "\n";
            }else if(acc == 5){
                cout << "P\n";
            }
        }
    }
}

void generateJaean(int T){
    while(T--){
        int F=generarNumero(1, 100),C=generarNumero(1, 100);
        cout << C << " " << F << "\n";
        for(int i=0;i<F;i++){
            for(int j=0;j<C;j++){
                int i = generarNumero(0,2);
                cout << (i==0 ? 'x' : '-');
            }
            cout << "\n";
        }
    }
}

void generateBuscaminas(int T){
    while(T--){
        int F=generarNumero(1, 50),C=generarNumero(1, 50);
        cout << F << " " << C << "\n";
        for(int i=0;i<F;i++){
            for(int j=0;j<C;j++){
                int i = generarNumero(0,9);
                cout << (i==0 ? 'x' : '-');
            }
            cout << "\n";
        }
        int K = generarNumero(1, 10);
        cout << K << "\n";
        while(K--){
            int x = generarNumero(1, F);
            int y = generarNumero(1, C);
            cout << x << " " << y << "\n";
        }
    }
}

void generateMatrixAna(){
    int N = 499;
    cout << N << "\n";
    generarArrayAleatorio(N+1, 1, 100);
}

void generateLaLiga(int T){
    while(T--){
        int N = generarNumero(1,20000);
        cout << N << "\n";
        while(N--){
            cout << generarNumero(10000, 19000) << " ";
        }
        cout << "\n";
    }
}

void generateHongos(int T){
    while(T--){
        int N=generarNumero(1,1499),M=generarNumero(N+1,1500),T=generarNumero(0,3000);
        cout << N << " " << M << " " << T << "\n";
    }
}


map<int, char> dnies2 = {{0, 'T'}, {1, 'R'},{2, 'W'},{3, 'A'},{4, 'G'},{5, 'M'},{6, 'Y'},{7, 'F'},{8, 'P'},{9, 'D'},{10, 'X'},{11, 'B'},{12, 'N'},{13, 'J'},{14, 'Z'},{15, 'S'},{16, 'Q'},{17, 'V'},{18, 'H'},{19, 'L'},{20, 'C'},{21, 'K'},{22,'E'}};

void generateDNI(int T){
    cout << T << "\n";
    while(T--){
        int inter = generarNumero(1, 4);
        string dni = "";
        for(int i=0;i<8;i++){
            int number = generarNumero(0, 9);
            if(8 - dni.size() == inter) dni += '?';
            else if(inter > 0) {
                if(generarNumero(0, 1) > 0){
                    dni += (number + '0');
                }else{
                    dni += '?'; inter--;
                }
            }else{
                dni += (number+'0');
            }
        }

        char letra = dnies2[generarNumero(0, 22)];
        dni += letra;
        cout << dni << "\n";

    }
}

void generateCalculadora(int T){
    while(T--){
        cout << generarNumero(0, 9999) << " " << generarNumero(0, 9999) << "\n";
    }
}

void generateAleatorioSerpientes(int T){
    while(T--){
        int N = generarNumero(1,100);
        int K = generarNumero(1,N);
        int S = generarNumero(1, 100);
        int E = generarNumero(1,100);

        cout << N << " " << K << " " << S << " " << E << "\n";

        for(int i=0;i<S+E;i++){
            cout << generarNumero(1,N*N) << " " << generarNumero(1, N*N) << "\n";
        }
    
    }

    cout << "0 0 0 0\n";


}


void generateRondaDeNoche(int T){
    cout << T << "\n";
    while(T--){
        int W=100,H=100;
        cout << W << " " << H << "\n";
        pair<int, int> origen = {generarNumero(1,W),generarNumero(1,H)};
        pair<int, int> destino = {generarNumero(1,W),generarNumero(1,H)};
        
        while(origen.first == destino.first && origen.second == destino.second) destino = {generarNumero(1,W),generarNumero(1,H)};
        
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                if(origen.first == i && origen.second == j){
                    cout << "E";
                }else if(destino.first == i && destino.second == j){
                    cout << "P";
                }else {
                    int aleatorio = generarNumero(1,30);
                    if(aleatorio >= 1 && aleatorio <= 24) cout << ".";
                    else if(aleatorio > 24 && aleatorio <= 29) cout << "#";
                    else {
                        vector<int> nums = {1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,4,4,5,6,7,8,9};
                        int aleatorio = generarNumero(1,nums.size());
                        cout << nums[aleatorio-1];
                    }
                }
            }
            cout << "\n";
        }

    }
}

void generarRatones(int T){
    while(T--){
        aleatorioGrafo(true);
    }
}

void generateSaturno(int T){
    cout << T << "\n";
    while(T--){
        int N = generarNumero(1,3000);
        int K = generarNumero(1,10000);
        cout << N << " " << K << "\n";
        while(K--){
            int a = generarNumero(1,N-1);
            int b = generarNumero(1,359);
            cout << a << " " << b << "\n";
        }
        for(int i=0;i<N;i++){
            cout << generarNumero(1,1000) << " ";
        }
        cout << "\n";


        cout << generarNumero(1,N) << " " << generarNumero(1,359) << " " << generarNumero(1,N)  << " " << generarNumero(1,359) << "\n";

    }
}

void generaSuper(int T){
    while(T--){
        int N = generarNumero(1, 500);
        int C = generarNumero(1, 500);
        cout << N << " " << C << "\n";
        for(int i=0;i<C;i++){
            cout << generarNumero(1,100) << " ";
        }
        cout << "\n";
    }
    cout << "0 0\n";
}

void generarTrieHard(int T){
    cout << T << "\n";
    while(T--){
        int A = generarNumero(1,1000);
        int B = generarNumero(1,A);
        int C = generarNumero(1,A);
        int conseguir = generarNumero(1,A);
        cout << A << " " << B << " " << C << " " << conseguir << "\n";
    }
}

void generateGas(int T){
    while(T--){
        int N=generarNumero(1,1000),M=generarNumero(1,1000);
        cout << N << "\n";
        for(int i=0;i<N;i++){
            cout << generarNumero(1,100) << " ";
        }
        cout << "\n";
        set<int> numeros;
        for(int i=0;i<M;i++){
            auto par = parNoRepetido(1, N);
            numeros.insert(par.first); numeros.erase(par.second);
            cout << par.first << " " << par.second << " " << generarNumero(1,100) << "\n";
        }
        int Q = generarNumero(1,100); cout << Q << "\n";
        while(Q--){
            cout << generarNumero(1,100) << " ";
            auto conf = parNoRepetido(1,N);
            auto it = numeros.begin();
            auto it2 = numeros.begin();
            for(int i=0;i<conf.first;i++) it++;
            for(int i=0;i<conf.second;i++) it2++;
            cout << *it << " " << *it2 << "\n";
        }
    }
}

int main(){
    int T = 200;
    cout << T << "\n";
    while(T--) aleatorioGrafo(true);
}