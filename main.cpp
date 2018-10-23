#include <iostream>
#include "LDE.hpp"
#include "No.hpp"

using namespace std;
int main(int argc, char *argv[]) {
    LDE<int> l;

    for(int i=100;i>=1;i--)
        l.insere(i);
    l.deletar(2);
    int a =l.busca(3);
    l.imprime();
    cout<<endl;
    cout<<a<<endl;
    cout<<l.interador(2)<<endl;
    return 0;
}