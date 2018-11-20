// futbol.cpp : Defines the entry point for the console application.
// Roman santana sandoval

#include "stdafx.h"
#include "iostream.h"
#include "string.h"
#include "windows.h"

struct equipo
{
	char nombre[60];
	int puntos;
	int golfavor;
	int golencontra;
	equipo *sigequipo;
	struct partido *primerpartido;
};

equipo *inicio=NULL;
equipo *fin=NULL;

struct partido
{
	char equipo[60];
	int afavor;
	int encontra;
	partido *sigpartido;
};

class cancha
{
public:
	void insertarequipos();
	void mostrarequipos();
	void insertarpartidos();
	void mostrarpartidos();
	void calculargolestotal();
	void puntos();
	void eliminarpartido();
	void eliminarequipo();
	void ganador();
	void equipogoleador();
	void equipogoleado();
};
void cancha::eliminarequipo()
{
	equipo *ant2;
	equipo *aux;
	partido *aux2;
	partido *ant;
	char nombre[60];
	if(inicio==NULL)
	{
		cout<<"no hay equipos en el torneo"<<endl;
	}
	else
	{
		cout<<"Inserta el nombre del equipo que decea eliminar: "<<endl;
		cin>>nombre;
		aux=inicio;
		while(aux!=NULL)
		{
			if(strcmp(aux->nombre,nombre)==0)
			{
				if(aux->primerpartido!=NULL)
				{
					aux2=aux->primerpartido;
					
					while(aux2!=NULL)
					{
						ant=aux2;
						aux2=aux2->sigpartido;
						delete ant;
					}
				}
				if(aux==inicio)
				{
					inicio=aux->sigequipo;
					delete aux;
					aux=NULL;
				}
				else
				{
					if(aux->sigequipo==NULL)
					{
						ant2->sigequipo=NULL;
						delete aux;
						aux=NULL;
					}
					else
					{
						ant2->sigequipo=aux->sigequipo;
						aux->sigequipo=NULL;
						delete aux;
						aux=NULL;
					}
				}
			}
			else
			{
				ant2=aux;
				aux=aux->sigequipo;
			}
		}
	}
}
void cancha::calculargolestotal()
{
	equipo *aux;
	partido *aux2;
	char nombre[60];
	if(inicio==NULL)
	{
		cout<<"no hay equipos en el torneo"<<endl;
	}
	else
	{
		aux=inicio;
		cout<<"escriba el nombre del equipo del cual calcularemos el numero total de goles: "<<endl;
		cin>>nombre;
		
		while(aux!=NULL)
		{
			if(strcmp(aux->nombre,nombre)==0)
			{
				int num;
				num=0;
				aux2=aux->primerpartido;
				aux->golfavor=0;
				aux->golencontra=0;
				while(aux2!=NULL)
				{
					aux->golfavor=aux->golfavor+aux2->afavor;
					aux->golencontra=aux->golencontra+aux2->encontra;
					aux2=aux2->sigpartido;
				}
				if(aux2==NULL)
				{
					aux=NULL;
				}
			}
			else
			{
				aux=aux->sigequipo;
			}
		}
	}
}

void cancha::puntos()
{
	equipo *aux;
	partido *aux2;
	char nombre[60];
	if(inicio==NULL)
	{
		cout<<"no hay equipos en el torneo"<<endl;
	}
	else
	{
		aux=inicio;
		cout<<"calcular los puntos del equipo: "<<endl;
		cin>>nombre;
		
		while(aux!=NULL)
		{
			if(strcmp(aux->nombre,nombre)==0)
			{
				int num;
				num=0;
				aux->puntos=0;
				aux2=aux->primerpartido;
				while(aux2!=NULL)
				{
					if(aux2->afavor>aux2->encontra)
					{
						aux->puntos=aux->puntos+3;
					}
					else
					{
						if(aux2->afavor==aux2->encontra)
						{
							aux->puntos=aux->puntos+0;
						}
					}
					aux2=aux2->sigpartido;
				}
				if(aux2==NULL)
				{
					aux=NULL;
				}
			}
			else
			{
				aux=aux->sigequipo;
			}
		}
	}
}

void cancha::eliminarpartido()
{
	equipo *aux;
	partido *aux2;
	partido *ant;
	char nombre[60];
	if(inicio==NULL)
	{
		cout<<"no hay equipos en el torneo"<<endl;
	}
	else
	{
		aux=inicio;
		cout<<"Equipo en el cual eliminaremos partidos: "<<endl;
		cin>>nombre;
		
		while(aux!=NULL)
		{
			if(strcmp(aux->nombre,nombre)==0)
			{
				int num;
				num=0;
				aux->puntos=0;
				aux2=aux->primerpartido;
				while(aux2!=NULL)
				{
					char nom[60];
					cout<<"escriba el nombre del equipo invitado para eliminar el partido: "<<endl;
					cin>>nom;

					while(aux2!=NULL)
					{
						if(strcmp(aux2->equipo,nom)==0)
						{
							if(aux->primerpartido==aux2)
							{
								aux->primerpartido=aux2->sigpartido;
								delete aux2;
								aux2=NULL;
								aux=NULL;
							}
							else
							{
								if(aux2->sigpartido==NULL)
								{
									ant->sigpartido=NULL;
									delete aux2;
									aux2=NULL;
									aux=NULL;
								}
								else
								{
										ant->sigpartido=aux2->sigpartido;
										aux2->sigpartido=NULL;
										delete aux2;
										aux2=NULL;
										aux=NULL;
								}
							}
						}
						else
						{
							ant=aux2;
							aux2=aux2->sigpartido;
						}
					}
				}
				if(aux2==NULL)
				{
					aux=NULL;
				}
			}
			else
			{
				aux=aux->sigequipo;
			}
		}
	}
}

void cancha::insertarequipos()
{
	equipo *nuevo;
	equipo *aux;
	nuevo=new equipo;
	cout<<"Insertar nombre del equipo: "<<endl;
	cin>>nuevo->nombre;
	nuevo->sigequipo=NULL;
	nuevo->primerpartido=NULL;
	nuevo->golfavor=0;
	nuevo->golencontra=0;
	nuevo->puntos=0;
	int cont=0;
	if(inicio==NULL)
	{
		inicio=nuevo;
		fin=nuevo;
	}
	else
	{	aux=inicio;
		while(aux!=NULL)
		{
			if(strcmp(aux->nombre,nuevo->nombre)==0)
			{
			cout<<"Este equipo ya esta en la lista"<<endl;
			cont=1;
			aux=NULL;
			}
			else
			{
				aux=aux->sigequipo;	
			}
		}

		if(cont==0)
		{
			fin->sigequipo=nuevo;
			fin=nuevo;
		}
	}

}
void cancha::mostrarequipos()
{
	equipo *aux;
	if(inicio!=NULL)
	{
		aux=inicio;
		while(aux!=NULL)
		{
			cout<<"Este es uno de los 4 equipos participantes:"<<endl;
			cout<<aux->nombre<<endl;
			cout<<"tuvo "<<aux->golfavor<<" goles en todos sus partidos"<<endl;
			cout<<"tiene "<<aux->golencontra<<" goles en su contra"<<endl;
			cout<<"los puntos por partidos ganados son: "<<aux->puntos<<endl;
			system("pause");
			system("cls");
			aux=aux->sigequipo;
		}
	}
	else
	{
		cout<<"No hay equipos guardados"<<endl;
	}
}

void cancha::insertarpartidos()
{
	char equi[60];
	equipo *aux;
	cout<<"Inserte el nombre del equipo local: "<<endl;
	cin>>equi;
	
	if(inicio!=NULL)
	{
		aux=inicio;
		while(aux!=NULL)
		{
			if(strcmp(aux->nombre,equi)==0)
			{
				partido *nuevo2;
				partido *aux2;
				nuevo2=new partido;
				cout<<"inserte el nombre del equipo invitado: "<<endl;
				cin>>nuevo2->equipo;
				cout<<"Inserte los goles a favor: "<<endl;
				cin>>nuevo2->afavor;
				cout<<"inserte los goles encontra: "<<endl;
				cin>>nuevo2->encontra;
				nuevo2->sigpartido=NULL;
				
				if(aux->primerpartido==NULL)
				{
					aux->primerpartido=nuevo2;
					aux=NULL;
				}
				else
				{
					aux2=aux->primerpartido;
					while(aux2!=NULL)
					{
						if(aux2->sigpartido==NULL)
						{
							aux2->sigpartido=nuevo2;
							aux=NULL;
							aux2=NULL;
						}
						else
						{
							aux2=aux2->sigpartido;
						}
					}
				}
			}
			else
			{
				aux=aux->sigequipo;
			}
		}
	
	}
	else
	{
	cout<<"no hay equipos en la lista"<<endl;
	}
}

void cancha::mostrarpartidos()
{
	char equi[30];
	equipo *aux;
	partido *aux2;
	aux=inicio;
	if(aux!=NULL)
	{
				cout<<"escriba el equipo del cual decea mostrar sus partidos: "<<endl;
				cin>>equi;
				cout<<endl;
				system("cls");
				while(aux!=NULL)
				{
					if(strcmp(aux->nombre,equi)==0)
					{
						aux2=aux->primerpartido;

						while(aux2!=NULL)
						{
							cout<<"El equipo invitado se llama "<<aux2->equipo<<endl;
							cout<<"los goles del equipo local fueron "<<aux2->afavor<<endl;
							cout<<"los goles del equipo invitado fueron "<<aux2->encontra<<endl;
							system("pause");
							system("cls");
							aux2=aux2->sigpartido;	
						}	
						aux=NULL;
					}
					else
					{
						aux=aux->sigequipo;
					}
				}
		}
	
	else
	{
	cout<<"no hay equipos en la lista"<<endl;
	}
}
void cancha::ganador()
{
	equipo *aux;
	aux=inicio;
	equipo *num;
	num=inicio->sigequipo;
	if(aux!=NULL)
	{
		while(num!=NULL)
		{
			if(aux->puntos<num->puntos)
			{
				aux=num;
				num->sigequipo;
			}
			num=num->sigequipo;
		}
		if(aux->puntos==0)
		{
			cout<<"no hubo ganador es empate"<<endl;
		}
		else
		{
			cout<<"El equipo ganador es: "<<aux->nombre<<endl;
			cout<<"Puntos: "<<aux->puntos<<endl;
		}
	}
	else
	{
	cout<<"no hay equipos en la lista"<<endl;
	}
}

void cancha::equipogoleador()
{
	equipo *aux;
	aux=inicio;
	equipo *num;
	num=inicio->sigequipo;
	if(aux!=NULL)
	{
		while(num!=NULL)
		{
			if(aux->golfavor<num->golfavor)
			{
				aux=num;
				num->sigequipo;
			}
			num=num->sigequipo;
		}
		if(aux->golfavor==0)
		{
			cout<<"no hubo goleador"<<endl;
		}
		else
		{
			cout<<"El equipo goleador es: "<<aux->nombre<<endl;
			cout<<"goles: "<<aux->golfavor<<endl;
		}
	}
	else
	{
	cout<<"no hay equipos en la lista"<<endl;
	}
}
void cancha::equipogoleado()
{
		equipo *aux;
	aux=inicio;
	equipo *num;
	num=inicio->sigequipo;
	if(aux!=NULL)
	{
		while(num!=NULL)
		{
			if(aux->golencontra<num->golencontra)
			{
				aux=num;
				num->sigequipo;
			}
			num=num->sigequipo;
		}
		if(aux->golfavor==0)
		{
			cout<<"no hubo mas goleado"<<endl;
		}
		else
		{
			cout<<"El equipo mas goleado es: "<<aux->nombre<<endl;
			cout<<"goles: "<<aux->golencontra<<endl;
		}
	}
	else
	{
	cout<<"no hay equipos en la lista"<<endl;
	}
}
int main(int argc, char* argv[])
{
	cancha obj;
	int op;
	do
	{
		cout<<"   INGRESA LOS DATOS CORRESPONDIENTES   "<<endl<<endl;	
		cout<<" algunos datos de los equipos deben irse actualizando conforme hay juegos "<<endl;
		cout<<"1. Insertar equipos"<<endl;		
		cout<<"2. Mostrar equipos"<<endl;
		cout<<"3. Insertar Datos del partido"<<endl;
		cout<<"4. Mostrar Partidos"<<endl;
		cout<<"5. Calcular total de goles a favor y encontra por equipo"<<endl;
		cout<<"6. Calcular los puntos por equipo"<<endl;
		cout<<"7. Eliminar partido"<<endl;
		cout<<"8. Eliminar equipo"<<endl;
		cout<<"9. Mostrar Ganador"<<endl;
		cout<<"10.Equipo Goleador"<<endl; 
		cout<<"11.Equipo Mas goleado"<<endl;
		cout<<"0. Salir"<<endl;	
		cout<<"opcion: ";
		cin>>op;
		system("CLS");

		switch (op)
		{	
			case 1: 
				obj.insertarequipos(); 
				system("pause");
				system("cls");
				break;

			case 2: 
				obj.mostrarequipos(); 
				system("pause");
				system("cls");
				break;

			case 3:
				obj.insertarpartidos();
				system("pause");
				system("cls");
				break;
			case 4:
				obj.mostrarpartidos();
				system("pause");
				system("cls");
				break;
			case 5:
				obj.calculargolestotal();
				system("pause");
				system("cls");
				break;
			case 6:
				obj.puntos();
				system("pause");
				system("cls");
				break;
			case 7:
				obj.eliminarpartido();
				system("pause");
				system("cls");
				break;
			case 8:
				obj.eliminarequipo();
				system("pause");
				system("cls");
				break;
			case 9:
				obj.ganador();
				system("pause");
				system("cls");
				break;
			case 10:
				obj.equipogoleador();
				system("pause");
				system("cls");
				break;
			case 11:
				obj.equipogoleado();
				system("pause");
				system("cls");
				break;
		}

	}while (op!=0);
	return 0;
}
