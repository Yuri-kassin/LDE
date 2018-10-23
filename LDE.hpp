#include <iostream>
#include "No.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

template <typename T>
class LDE{
    private:
        int n;
        No<T>* primeiro;

    public:
        LDE(): n(0), primeiro(nullptr){

        }

        bool insere(T valor){
            No<T>* novo = new No<T>(valor);
            if(novo == nullptr)
                return false;

            No<T>* anterior = nullptr;
            No<T>* atual = primeiro;

            while(atual && valor > atual->valor){
                anterior = atual;
                atual = atual->proximo;
            }

            novo->proximo = atual;
            if(anterior!=nullptr){
                anterior->proximo = novo;
            }else{
                primeiro = novo;
            }
            n++;
            return true;
        }

        bool deletar(T valor){
            No<T>* atual = primeiro;
            No<T>* anterior;
            No<T>* proximo;

            while(atual && atual->valor != valor){
                anterior = atual;
                atual = atual->proximo;
            }
            if(atual->valor != valor) return false;
            proximo = atual->proximo;
            anterior->proximo = proximo;
            return true;
        }

    int busca(T valor){
            No<T>* atual = primeiro;
            No<T>* anterior;
            No<T>* proximo;
            while(atual && atual->valor != valor){
                anterior = atual;
                atual = atual->proximo;
            }
            if(atual->valor != valor) return false;

            cout<<"a "<<atual->valor<<endl;
            return atual->valor;
        }

    void imprime(){
        No<T>* atual = primeiro;
        while(atual){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    No<T> inic() {
        return primeiro;
    }

    T interador(T valor){
            No<T> * atual = primeiro;
            for(int i=0; i<valor; i++){
                atual = atual->proximo;
            }
        return atual->valor;
        }

    virtual ~LDE(){
        No<T>* atual = primeiro;
        No<T>* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif