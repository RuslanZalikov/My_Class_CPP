#include <iostream>

using namespace std;


void Foo(int *a){
    (*a)++;
}


int main() {
    int a = 5;
    Foo(&a);
    cout << a;
}