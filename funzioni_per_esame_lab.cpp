#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "funzioni.h"
using namespace std;

#define N 10000
//i puntini sono in nome della struct che userai, la prima funzione è per leggere i dati e caricarli su un array

... *load_data(string const &filename, int &ntot){   
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }
     
    ... *read = new ...[N];
    for (;;){
        f >> read[ntot]. 
          >> read[ntot]. 
          >> read[ntot]. 
          >> read[ntot]. 
          >> read[ntot].;
          read[ntotal]. = 0;
        if (f.eof())
            break;
        ntot++;
    }

    // resize array
    ... *out = new ...[ntot];
    for (int i = 0; i < ntot; i++){
        out[i] = read[i];
    }
    
    delete[] read;

    return out;
}

// dove c'è solo m[i].  è perchè così metti il membro della struct che ti serve

void print_data(... *m, int ntot, stringstream &sout){
    for (int i = 0; i < ntot; i++){
        
        sout << m[i]. << " "
             << m[i]. << " "
             << m[i]. << " "
             << m[i]. << " "
             << m[i]. << " "
             << m[i]. << endl;
        
    }
}


void print_and_save(stringstream &ss){
    cout << ss.str();
    fstream outfile("risultati.dat", ios::out);
    outfile << ss.str();
    ss.str("");
    ss.clear();
}

void sort_by_(... *m, int ntot){                   //sort_by_(quello che ti serve) es. ordina in base alla massa, o al tempo.
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i]. > m[j].){
                misure dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}


void filtra(... *m, ... *a, ... *b, int ntot){
    
    int conta1 = 0;
    int conta0 = 0;
    for(int i = 0; i < ntot; i++){
        if(m[i]. > ){
            a[conta1] = m[i];
            conta1 ++;
        }else{
            b[conta0] = m[i];
            conta0 ++;

        }
    
    }
}

double media(.... *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].;
    }
    return sum/ntot;
}

double stdev(... *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].;
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i]. - media),2);
    }
    return sqrt(scarti/ntot);
}

double min_value(... *m, int ntot){
    double min = m[0].;
    for (int i = 0; i < ntot; i++){
        if(m[i]. < min)
        min = m[i].;
    } 
    return min;
}

// caricare i dati che ti servono su un nuovo file per fare il plot
void store_(... *m, int ntot){
    fstream out;
    out.open("masses.dat", ios::out);
    if (!out.good()){
        cout << "Problema con il file da creare" << endl;
        return -1;
    }
        
    for (int i = 0; i < ntot; i++){
        out << m[i]. << endl;
    }
    out.close();
}
