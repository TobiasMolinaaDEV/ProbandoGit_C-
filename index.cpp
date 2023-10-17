#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

void pausa();
int menu (void);
void generar (FILE *punent);  
void mostrar (FILE *punent);
void ordenar(FILE *punent);
void agregar(FILE *punent);

main(){
    FILE *ente;
    srand(time(0));
	int opcion,N,pos;

	do
	{
		opcion=menu();
		switch(opcion)
		{
			case 1:
					printf("\n\nSe va a generar nros para el archivo: ");
					pausa();
					generar(ente);
					break;
			case 2:
					mostrar(ente);
					break;
			case 3:
					//consulta(ente);
					break;
			case 4: 
					//rango(ente);
					break;
			case 5:
					agregar(ente);
					break;
			case 6:
					ordenar(ente);
					break;
			case 7:
					printf("\nUd esta por salir del sistema.");
					break;
			default:
					printf("\nNo es una opcion correcta...");
					break;
		}
		printf("\n\n");
		system("pause");
	}while(opcion!=7);
}

void generar(FILE *punent)
{
	int nro;
	punent=fopen("k6entero.dat","w+b");
	nro=1+rand()%100;
	for(int i=0;i<277;i++)
	{
		fwrite(&nro,sizeof(int),1,punent);
		nro=1+rand()%100;
	}
	fclose(punent);
}

void mostrar(FILE *punent)
{
int valor,cant=0;
	punent=fopen("k6entero.dat","r+b");
	fread(&valor,sizeof(int),1,punent);
	
	while (!feof(punent)) 
	 { 
	 	printf("\nNro %d: %d",cant+1,valor);
	 	cant++;
	 	fread(&valor,sizeof(int),1,punent);
	 }  
	 fclose(punent);


}

void agregar(FILE *punent)
{
	int nro;
	punent=fopen("k6entero.dat","a+b");
	printf("\nIngrese nros y 0 para Salir");
	printf("\nNro: ");
	scanf("%d",&nro);
	while(nro!=0)
	{
		fwrite(&nro,sizeof(int),1,punent);
		printf("\nIngrese nros y 0 para Salir");
		printf("\nNro: ");
		scanf("%d",&nro);
	}
	fclose(punent);


}

int menu(void)
{
	system("cls");
	int opc;
	printf("\nMenu General de Alumnos");
	printf("\n\n1. Crear Archivo de enteros");
	printf("\n2. Listado General");
	printf("\n3. Consulta de Nro.");
	printf("\n4. Listado de Rango pedido");
	printf("\n5. Agregar Numeros indeterminado");
	printf("\n6. Ordenar el archivo");
	printf("\n7. Salir");
	printf("\n\nIngrese su opcion: ");
	scanf("%d",&opc);
	return(opc);
}

void ordenar(FILE *punent)
{

}

void pausa()
{
	printf("\n\n");
	system("pause");
}
