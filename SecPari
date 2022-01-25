#include <iostream>

using namespace std;

bool sec_pari(int *x, int dimx, int p);

int main(){

    int dim = 10;
    int x[dim] = {10,3,6,4,8,5,7,2,5,7};
    int n = 3;

    if(sec_pari(x,dim,n))
        cout << "BOB" << endl;

    return 0;
}

bool sec_pari(int *x, int dimx, int p){
    bool condition = false;
    int count = 0;
    for(int i = 0; i < dimx; i++){
        while(x[i] % 2 == 0){
            count ++;
        }
    if(count == p)
        condition = true;

    else if(count != p)
        count = 0;
    }
return condition;
}
