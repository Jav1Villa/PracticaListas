#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_elemento
{
  char Nombre[200], Password[200];
  struct def_elemento *sig;
} TipoElemento;

void AltaUsuario(TipoElemento **Inicio,char Nombre[200], char Password [200]);
void Buscar(TipoElemento *Inicio);
void BorrarUsuario(TipoElemento **Inicio);
void ImprimirArchivo(TipoElemento *Inicio);
void Imprimir(TipoElemento *Inicio);
void Borrar_Lista(TipoElemento *Inicio);

int main (void)
{
  TipoElemento *Primero=NULL;
  char Name[200], Pass[200];
  int Opcion;
  do {
      system("clear");
      printf("Menú\n\n");
      printf("1.- Agregar Usuario.\n");
      printf("2.- Mostrar Usuarios.\n");
      printf("3.- Buscar Usuario\n");
      printf("4.- Eliminar Usuario\n");
      printf("5.- Imprimir en Archivo\n");
      printf("6.- Salir.\n\n");
      printf("Ingresa la opción a usar\n");
      scanf(" %d", &Opcion);
      switch(Opcion)
      {
        case 1:
        system("clear");
        printf("Ingrese el nombre del usuario\n");
        scanf(" %[^\n]", Name);
        printf("Ingrese la contraseña del usuario\n");
        scanf(" %[^\n]", Pass);
        AltaUsuario(&Primero,Name,Pass);
        printf("\nPresione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 2:
        system("clear");
        printf("Número en lista: \n");
        Imprimir(Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 3:
        system("clear");
        Buscar(Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 4:
        system("clear");
        BorrarUsuario(&Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 5:
        system("clear");
        ImprimirArchivo(Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 6:
        Borrar_Lista(Primero);
        printf("Saliendo del programa...\n");
        break;
        default:
        printf("Opción errónea, inténtelo de nuevo\n");
        break;
      }
  } while(Opcion!=6);
}


void AltaUsuario(TipoElemento **Inicio,char Nombre[200], char Password [200])
{
  TipoElemento *nuevo, *temp;
  nuevo = (TipoElemento *)malloc(sizeof(TipoElemento));
  strcpy (nuevo -> Nombre, Nombre);
  strcpy (nuevo -> Password, Password);
  nuevo -> sig = NULL;
  if (*Inicio!= NULL)
    {
      temp = *Inicio;
      while (temp -> sig != NULL)
	temp = temp -> sig;
      temp -> sig = nuevo;
    }
  else
    *Inicio = nuevo;
}

void Imprimir(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      printf("Nombre:%s\n",temp->Nombre);
      printf("Contraseña:%s\n",temp->Password);
      temp=temp->sig;
    }
}
void Buscar(TipoElemento *Inicio)
{
  TipoElemento *temp;
  int flag=0;
  char Name[200];
  temp=Inicio;
  printf("Que usuario buscas?\n");
  scanf(" %[^\n]", Name);
  while(temp!=NULL)
    {
      if(strcmp(Name,temp->Nombre)==0)
      {
        printf("Nombre:%s\n",temp->Nombre);
        printf("Contraseña:%s\n",temp->Password);
        flag=1;
      }
      temp=temp->sig;
    }
    if(flag==0)
    printf("No existe el usuario, sorry bro\n");
}
void BorrarUsuario(TipoElemento **Inicio)
{
  TipoElemento *temp,*temp2,*temp3;
  char Name[200];
  temp = *Inicio;
  temp2 = *Inicio;
  printf("Que usuario deseas eliminar?\n");
  scanf(" %[^\n]", Name);
  if (*Inicio == NULL ) // Si la lista está vacía
    {
      printf ("La lista está vacía, no existe el usuario\n");
    }
  else
    {
      while (temp != NULL)
	     {
	        if ((strcmp(Name,temp->Nombre))==0)
	         {
	            if (temp != *Inicio)
		            {
                  while (temp2 -> sig != temp)
                    temp2 = temp2 -> sig;
                  temp2->sig = temp-> sig;
                  printf("Otro Elemento\n");
                  free (temp);
                  break;
		            }
	             else
		            {
                   *Inicio = temp-> sig;
                    free (temp);
                    printf("Primer Elemento\n");
                }
	           }
	            temp = temp-> sig;
	      }
    }
}
void ImprimirArchivo(TipoElemento *Inicio)
{
  TipoElemento *temp;
  char NombreArchivo[200];
  FILE *Archivo;
  temp=Inicio;
  printf("Ingrese el archivo a imprimir los datos\n");
  scanf(" %[^\n]", NombreArchivo);
  Archivo = fopen(NombreArchivo,"wt");
  while(temp!=NULL)
    {
      fprintf(Archivo,"%s\n",temp->Nombre);
      fprintf(Archivo,"%s\n",temp->Password);
      temp = temp-> sig;      
    }
    fclose(Archivo);

}

void Borrar_Lista(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}
