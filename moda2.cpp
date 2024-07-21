#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;


set<int> unicos;
map<int, set<int>> values;
deque<int> camisas;

int ita, jota;




int main(){
    int T;
    cin >> T;
    while(T--){
        ita = 0; jota = 0;
        camisas.clear();
        values.clear();
        unicos.clear();
        int N;
        cin >> N;
        for(int i=0;i<N;i++){
            int c;
            cin >> c;
            camisas.push_back(c);
            auto & posi = values[c];

            if(posi.empty()){
                unicos.insert(jota);
            }else{
                unicos.erase(*posi.begin());
            }
            posi.insert(jota);

            jota++;
        }
        int E;
        cin >> E;
        for(int i=0;i<E;i++){
            char act;
            cin >> act;
            if(act == 'P') {
                if(unicos.empty()){
                    cout << "NADA INTERESANTE\n";
                }else{
                    int itara = (*unicos.begin()) - ita +1; // inclusive
                    int jotara = jota - (*unicos.rbegin()); // no inclusive
                    if(itara == jotara){
                        cout << itara << " CUALQUIERA\n";
                    }else if(itara < jotara){
                        cout << itara << " IZQUIERDA\n";
                    }else{
                        cout << jotara << " DERECHA\n";
                    }
                }
            }
            else if(act == 'I'){
                int arg; cin >> arg;
                int pos = --ita;
                camisas.push_front(arg);
                set<int> & uniq = values[arg];
                if(uniq.empty()){
                    unicos.insert(pos);
                }else if(uniq.size() == 1){
                    unicos.erase(*uniq.begin());
                }
                uniq.insert(pos);
            }else if(act == 'D'){
                int arg; cin >> arg;
                int pos = jota++;
                camisas.push_back(arg);
                auto & uniq = values[arg];
                if(uniq.empty()){
                    unicos.insert(pos);
                }else if(uniq.size() == 1){
                    unicos.erase(*uniq.begin());
                }
                uniq.insert(pos);
            }else if(act == 'i'){
                int label = camisas.front(); camisas.pop_front();
                int pos = ita++;
                auto & uniq = values[label];
                uniq.erase(pos);
                if(uniq.empty()){
                    unicos.erase(pos);
                }else if(uniq.size() == 1){
                    unicos.insert(*uniq.begin());
                }
            }else if(act == 'd'){
                int label = camisas.back(); camisas.pop_back();
                int pos = --jota;
                auto & uniq = values[label];
                uniq.erase(pos);
                if(uniq.empty()){
                    unicos.erase(pos);
                }else if(uniq.size() == 1){
                    unicos.insert(*uniq.begin());
                }
            }
        }
        cout << "---\n";
    }
}