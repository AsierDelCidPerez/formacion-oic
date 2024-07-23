#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct member {
    string nombre;
    bool isFemale;
};

const vector<member> nombres = {
    {"ASIER DEL CID PÉREZ", false}
};

const string country = "SP";
const string inst = "UNIVERSIDAD DE CANTABRIA";
const string state_id = "CAN";

const int digitos = 2;

string normalizacion(int a){
    string n = to_string(a);
    while(n.length() < digitos) n = "0" + n;
    return n;
}

int main(){
    cout << "username,name,country_id,state_id,gender,school_name" << "\n";
    for(int i=0;i<nombres.size();i++){
        cout << "usr" << normalizacion(i+1) << "," <<  nombres[i].nombre << "," << country << "," << state_id << "," << 
        (nombres[i].isFemale ? "female" : "male") << "," << inst << "\n";
    }
}