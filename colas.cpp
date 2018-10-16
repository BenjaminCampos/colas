#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;//es lo que tendra la cola el valor
	Nodo *siguiente;
};
//protos de funciones
void insertarCola(Nodo *&,Nodo *&,int);
bool cola_vacia(Nodo *);
void eliminarCola(Nodo *& , Nodo*&,int &);

int main(){
	//se crean los apuntadores de tipo nodo para poder señalar en donde se encuentran
	Nodo *frente=NULL;
	Nodo *fin=NULL;
	int dato;
	cout<<"inserte un dato a la cola\n";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	cout<<"inserte un dato a la cola\n";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	cout<<"inserte un dato a la cola\n";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	cout<<"\n";
	cout<<"se quitara los eleemntos de la cola\n";
	while(frente !=NULL){
		eliminarCola(frente,fin,dato);
		if(frente !=NULL){
			cout<<dato<<" , ";
		}else
		{
			cout<<dato<<" . ";
		}
	}
	
	return 0;
}

void insertarCola(Nodo *&frente,Nodo *&fin,int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n,
	nuevo_nodo->siguiente=NULL;	
	
	if(cola_vacia(frente)){
		frente=nuevo_nodo;
	}else{
		fin->siguiente=nuevo_nodo;
	}
	fin=nuevo_nodo;
	
	cout<<"\t se inserto el elemneto "<<n<<" en la cola correctamente \n";
}

//para saber si la cola tiene valor o apunta a NULL
bool cola_vacia(Nodo *frente){
	return(frente == NULL)?  true:false;
}

//funcion para eliminar elementos en la cola
void eliminarCola(Nodo *&frente , Nodo *&fin ,int &n){
	n=frente->dato;
	Nodo *aux=frente;
	if(frente==fin){
		frente=NULL;
		fin=NULL;
	}else{
		frente=frente->siguiente;
	}
	
	delete aux;
}
