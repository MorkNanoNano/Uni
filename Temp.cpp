#include <iostream>
#define type double // cambia double con nome dello struct
using namespace std;

class Vector {
    public:
        int len=0;
        type *arr = new type[0];

    void append(type el) {
        len++;
        type *arr2 = new type[len];
        for (int i=0; i<len-1; i++) 
            arr2[i] = arr[i];
        arr2[len-1] = el;
        //delete [] arr;
        type *arr = new type[len];
        copy(arr2,arr2 + len, this -> arr);
        //delete [] arr2;
    }

    void prepend(type el) {
        len++;
        type *arr2 = new type[len];
        arr2[0] = el;
        for (int i=1; i<len; i++) 
            arr2[i] = arr[i-1];
        
        //delete [] arr;
        type *arr = new type[len];
        copy(arr2,arr2 + len, this -> arr);
        //delete [] arr2;
    }

    void remove(int index) {
        type *arr2 = new double[len-1];
        int count = 0;
        for (int i=0; i<len; i++) {
            if (i != index) {
            arr2[count] = arr[i];
            //cout << arr2[count] << endl;
            count++;
            }
        }
        //delete [] arr;
        len--;
        type *arr = new type[len];
        copy(arr2,arr2 + len, this -> arr);
    }

    void sort(double (*func)(type), bool inverted=false) {
        for (int i=0; i<len; i++) {
            for (int j=i; j<len; j++) {
                if ((func(arr[i]) > func(arr[j]) and !inverted) or (func(arr[i]) < func(arr[j]) and inverted)) {
                    type t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }
    }
};

double f(double a) {
    return abs(a);
}

int main() {
    Vector v;
    double t = 0.5;
    for (int i=0; i<10; i++)
        v.append(t*i);

    v.remove(5);
    v.append(-0.7);
    v.sort(&f, true);
    v.prepend(25);

    for (int i=0; i<v.len; i++) cout << v.arr[i] << endl;
    //cout << v.len << endl;

    return 0;
}
