#include <iostream>
#include <random>
#include <deque>
#include <math.h>

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

int main(){
    generateBuscaminas(1000);
}