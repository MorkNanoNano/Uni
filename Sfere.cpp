#include <iostream>
#include <fstream>
#include <sstream>
// #include "funzioni.h"

using namespace std;

struct sfera{
    float diam; 
    char col; 
    float exact; 
    float atoll; 
    float discr; 
};


double sfere_blue(sfera *x, int n);
double sfere_red(sfera *x, int n);

int main(){

    fstream infile_sfera;
    infile_sfera.open("sfere.dat", ios :: in);

    if(!infile_sfera.good()){
        cout << "Errore nellla lettura del file sfera." << endl;
        return 1;
    }

    // fstream infile_toll;
    // infile_toll.open("tolleranze.dat", ios :: in);

    // if(!infile_toll.good()){
    //     cout << "Errore nella lettura del file toll." << endl;
    //     return 1;
    // }

    int count_sfera = 0;
    string tmp;

    for(;;){
        getline(infile_sfera, tmp);
        if(infile_sfera.eof())
            break;
        count_sfera ++;
    }

    infile_sfera.clear();
    infile_sfera.seekg(0);

    sfera *data = new sfera[count_sfera];

    for(int i = 0; i < count_sfera; i++)
        infile_sfera >> data[i].diam >> data[i].col;

    infile_sfera.close();

    stringstream ss;

    ss << "Numero totale di sfere:" << "\t" << count_sfera << endl;
    ss << "Sfere di colore blu:" << "\t" << sfere_blue(data,count_sfera) << endl;
    ss << "Sfere di colore rosso:" << "\t" << sfere_red(data, count_sfera) << endl;
    ss << "Sfere di colore verde:" << "\t" << count_sfera - (sfere_blue(data, count_sfera) + sfere_red(data,count_sfera)) << endl;
    
    for(int i = 0; i < count_sfera; i++)
        ss <<"Colore:" << "\t" << data[i].col << "\t" << "Diametro:" << "\t" << data[i].diam << endl;

    cout << ss.str() << endl;

    int dim = sfere_blue(data,count_sfera);
    sfera *pass = new sfera[dim];

    for(int i = 0; i < count_sfera; i++){
        if(data[i].col == 'b'){
            pass[i] = data[i];
        }
    }
    
    delete [] data;

    return 0;
}

double sfere_blue(sfera *x, int n){
    int count_blue = 0;
    for(int i = 0; i < n; i++){
        if(x[i].col == 'b')
            count_blue ++;
    }
return count_blue;
}
double sfere_red(sfera *x, int n){
    int count_red = 0;
    for(int i = 0; i < n; i++){
        if(x[i].col == 'r')
            count_red ++;
    }
return count_red;
}
