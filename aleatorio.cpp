#include <iostream>
#include <random>
#include <deque>
#include <math.h>
#include <map>

using namespace std;

std::random_device rd;
std::mt19937 eng(rd());

int generarNumero(int min, int max){
    uniform_int_distribution distr(min, max);
    return distr(eng);
}

void generarArrayAleatorio(int longitud, int min, int max){

    while(longitud--){
        cout << generarNumero(min, max) << " ";
    }

    cout << "\n";
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

int main(){
    generateRondaDeNoche(50);
}