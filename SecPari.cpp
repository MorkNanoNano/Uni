#include <iostream>

using namespace std;

bool sec_pari(int *x, int dimx, int p);

int main(){

    int dimX = 4;
    int x[dimX] = {3,6,8,5,};
    int p = 2;

    if(sec_pari(x,dimX,p))
        cout << "BOB" << endl;

    return 0;
}

bool sec_pari(int *x, int dimX, int p){
    bool condition = false;
    int count = 0;
    for(int i = 0; i < dimX; i++){
        if(x[i] % 2 == 0)
            count ++;
        else if(x[i] % 2 != 0)
            count = 0;
        if(count == p){
            condition = true;
            break;
            }
        }
    return condition;
}
