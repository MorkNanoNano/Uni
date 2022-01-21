#include <iostream>
#include <fstream>
#include <sstream>
#include "funzioni.h"

using namespace std;

struct evento{
    double p1[4];
    double p2[4];
    bool segnale;
    double mass_inv;
};

int main(){

    fstream infile;
    infile.open("eventi.dat", ios :: in);

    if(!infile.good()){
        cout <<"Errore nella lettura del file" << endl;
        return 1;
    }

    int count = 0;
    string tmp;

    for(;;){
        getline(infile,tmp);
        if(infile.eof())
            break;
        count ++;
    }

    infile.clear();
    infile.seekg(0);

    evento *data = new evento[count];

    for(int i = 0; i < count; i++){
        for(int j = 0; j < 4; j++)
            infile >> data[i].p1[j];
        for(int j = 0; j < 4; j++)
              infile >> data[i].p2[j];
        infile >> data[i].segnale;
    }
        
    infile.close();
    
    stringstream ss;

    ss << "Numero di eventi" << "\t" << count << endl;

    int count_sig = 0;

    for(int i = 0; i < count; i++)
        if(data[i].segnale)
            count_sig++;
    
    /*evento *sig = new evento[count_sig];

    int conta = 0;

    for(int i = 0; i < count; i++)
        if(data[i].segnale){
            sig[conta] = data[i];
            conta ++;
        }

    for(int i = 0; i < conta; i++){
        cout << sig[i].segnale << endl;
    }*/

    ss <<"Numero di eventi tipo segnale" << "\t" << count_sig << endl;
    ss <<"Numero di eventi tipo background" << "\t" << (count - count_sig) << endl;
    ss <<"Percentuale eventi segnale" << "\t" << (count_sig/(double)count)*100 << endl;
    ss <<"Percentuale eventi background" << "\t" << ((count - count_sig)/(double)count)*100 << endl;

    cout << ss.str();

    fstream outfile;
    outfile.open("risultati.dat" , ios :: out);

    if(!outfile.good()){
        cout << "Errore nella creazione del file" << endl;
        return 1;
    }

    outfile << ss.str();

    return 0;
}
