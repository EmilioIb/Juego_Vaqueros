#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Clase pistola
class Pistola{
	private:
		int vida, balas;
	public:
		Pistola();
		void setPistola(int, int);
		int getBalas();
		int getVida();
};

//Variables
Pistola jugador, maquina;
int dificultad, accion, opc, enemigo;

//Constructor
Pistola::Pistola(){
}

//Setter
void Pistola::setPistola(int _vida, int _balas){
	vida = _vida;
	balas = _balas;
}

//Getter
int Pistola::getBalas(){
	return balas;
}

int Pistola::getVida(){
	return vida;
}

void imprimir(){
	cout<<"  __________           __________ "<<endl;
	cout<<" |          |         |          |"<<endl;    
	cout<<" |  |    |  |         |  |    |  |"<<endl;  
	cout<<" |          |         |          |"<<endl;  
	cout<<" |  ______  |         |  ______  |"<<endl;
	cout<<" |__________|         |__________|"<<endl;
	cout<<"    Jugador              Maquina  "<<endl;
	cout<<"      "<<jugador.getVida()<<"ps\t\t  "<<maquina.getVida()<<"ps\n"; 
	cout<<"    "<<jugador.getBalas()<<" balas\t\t "<<maquina.getBalas()<<" balas\n\n"; 
}

void turno(){
	int balasjug, vidajug, balasene, vidaene;	
	balasjug = jugador.getBalas();
	vidajug = jugador.getVida();
	balasene = maquina.getBalas();
	vidaene = maquina.getVida();
	
	while((vidajug > 0) && (vidaene > 0)){
		imprimir();
		
		do{
			cout<<"Acciones: "<<endl;
			cout<<"1.- Disparar"<<endl;
			cout<<"2.- Recargar"<<endl;
			cout<<"3.- Cubrirse"<<endl;
			cout<<"Opcion: ";
			cin>>opc;
			
			if(balasjug == 0 && opc == 1){
				cout<<"No tienes balas en el cargador"<<endl;
				opc = 5;
			}
		}while(opc > 3 || opc < 0);
			
		srand(time(NULL));
		enemigo =1+rand()%(4-1);
			
		if(balasene == 0 && enemigo == 1){
			enemigo = 2;
		}
		
		if(balasene == 3 && enemigo == 2){
			int num=1+rand()%(3-1);
			if(num == 1){
				enemigo = 1;
			}
			else{
				enemigo = 3;
			}
		}
			
		switch(opc){
			case 1:
				switch(enemigo){
					case 1:
						cout<<"Ambos disparan, las balas se cruzan y no ocurre nada"<<endl;
						maquina.setPistola(vidaene, balasene-1);
						jugador.setPistola(vidajug, balasjug-1);
						break;
					case 2:
						cout<<"Tu oponente recarga, pero tu disparas, le diste"<<endl;
						maquina.setPistola(vidaene-1, 3);
						jugador.setPistola(vidajug, balasjug-1);
						break;
					case 3:
						cout<<"Tu disparas, pero tu oponente se cubre"<<endl;
						jugador.setPistola(vidajug, balasjug-1);
						break;
				}
				break;
			case 2:
				switch(enemigo){
					case 1:
						cout<<"Recargas, pero tu enemigo dispara, te dieron"<<endl;
						jugador.setPistola(vidajug-1, 3);
						maquina.setPistola(vidaene, balasene-1);
						break;
					case 2:
						cout<<"Ambos recargan"<<endl;
						maquina.setPistola(vidaene, 3);
						jugador.setPistola(vidajug, 3);
						break;
					case 3:
						cout<<"Tu oponente se cubre, y tu aprovechas para recargar"<<endl;
						jugador.setPistola(vidajug, 3);
						break;
				}
				break;
			case 3:
				switch(enemigo){
					case 1:
						cout<<"Tu oponente dispara, pero tu te proteges"<<endl;
						maquina.setPistola(vidaene, balasene-1);
						break;
					case 2:
						cout<<"Mientras tu te cubres, tu oponente recarga"<<endl;
						maquina.setPistola(vidaene, 3);
						break;
					case 3:
						cout<<"Ambos se cubren, panda de cobardes"<<endl;
						break;
				}
				break;
			}
			
			balasjug = jugador.getBalas();
			vidajug = jugador.getVida();
			balasene = maquina.getBalas();
			vidaene = maquina.getVida();
			
			system("pause");
			system("cls");
	}

	if(vidajug == 0){
		system("color 04");
		cout<<"            PERDISTE :(           "<<endl;
		cout<<"  __________           __________ "<<endl;
		cout<<" |          |         |          |"<<endl;    
		cout<<" |  X    X  |         |  |    |  |"<<endl;  
		cout<<" |          |         |          |"<<endl;  
		cout<<" |  XXXXXX  |         |  ______  |"<<endl;
		cout<<" |__________|         |__________|"<<endl;
		cout<<"   PERDEDOR              GANADOR  "<<endl;
	}	
	if(vidaene == 0){
		system("color 0A");
		cout<<"             GANASTE :D           "<<endl;
		cout<<"  __________           __________ "<<endl;
		cout<<" |          |         |          |"<<endl;    
		cout<<" |  |    |  |         |  X    X  |"<<endl;  
		cout<<" |          |         |          |"<<endl;  
		cout<<" |  ______  |         |  XXXXXX  |"<<endl;
		cout<<" |__________|         |__________|"<<endl;
		cout<<"   GANADOR              PERDEDOR  "<<endl;
	}
	
}

int main(){
	char jd;
	
	cout<<"\t\t\t\t--------- BIENVENIDO ---------"<<endl;
	cout<<"El programa es un pequeño juego de vaqueros, tienes 3 opciones: disparar, recargar, y cubrise. Por cada \nrecarga recuperas 3 balas. Al inicio del juego podras elegir la dificultad. Mucha Suerte"<<endl<<endl;
	
	cout<<"\t\t\t\t            CLASES        "<<endl;
	cout<<"\t\t\t\t     EMILIO IBARRA VALDEZ "<<endl;
	cout<<"\t\t\t\t    ESTRUCTURAS DE DATOS "<<endl;
	cout<<"\t\t\t\t       4B 14/04/2021     "<<endl<<endl;
	

	do{
		system("color 07");
		system("pause");
		system("cls");
		
		do{
		cout<<"\t Seleciona la dificultad \n";
		cout<<"\t----   1.- FACIL     ----\n";
		cout<<"\t----   2.- MEDIO     ----\n";
		cout<<"\t----   3.- DIFICIL   ----\n";
		cout<<"\t       Opcion: ";
		cin>>dificultad;
		
		if(dificultad > 3 || dificultad < 1){
			cout<<"Opcion Incorrecta"<<endl;
		}
		system("pause");
		system("cls");
		
	}while(dificultad > 3 || dificultad < 1);
	
	switch(dificultad){
		case 1: 
			jugador.setPistola(3,0);
			maquina.setPistola(1,0);
			break;
		case 2:
			jugador.setPistola(2,0);
			maquina.setPistola(2,0);
			break;
		case 3:
			jugador.setPistola(1,0);
			maquina.setPistola(3,0);
			break;	
	}
	
	turno();
	
	cout<<"\nQuieres jugar de otra vez? (S/N)\nOpc:";
	cin>>jd;
	system("cls");
	}while(jd == 's' || jd == 'S');
	
	
	
	system("pause");
	return 0;
}
	
