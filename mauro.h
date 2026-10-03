// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: Mi libreria
// mauro.h

#include "my_string.h"
#include <time.h>

#define TAM 50

char *my_gets_validado(char *cadena, int tamano);
char *my_gets(char *cadena, int tamano);
int valida_num(int li, int lf, const char msge[]);
int es_valido(char c);

char *my_gets(char *cadena, int tamano)
{
  size_t longitud;
  fflush(stdin);
  fgets(cadena, tamano, stdin);
  if (cadena)
  {

    longitud = caracteres(cadena); // FUNCION CARACTERES CUENTA LOS CARACTERES, ES DE LA LIB MY STRING.H
    if (longitud > 0)
    {
      if (cadena[longitud - 1] == '\n')
      {
        cadena[longitud - 1] = '\0';
      }
    }
    return cadena;
  }
  return NULL;
}

char *my_gets_validado(char *cadena, int tamano)
{
  size_t longitud, j;
  char c;

  fflush(stdin);
  fgets(cadena, tamano, stdin);

  if (cadena)
  {
    longitud = caracteres(cadena);
    if (longitud > 0)
    {
      if (cadena[longitud - 1] == '\n')
      {
        cadena[longitud - 1] = '\0';
        longitud--;
      }
      j = 0;
      for (size_t i = 0; i < longitud; i++)
      {
        c = cadena[i];
        if (es_valido(c))
        {
          cadena[j] = c;
          j++;
        }
      }
      cadena[j] = '\0';
    }
    return cadena;
  }
  return NULL;
}

int valida_num(int li, int lf, const char msge[])
{
  char snum[TAM];
  int num;

  do
  {
    printf("%s", msge);
    my_gets(snum, TAM);
    num = atoi(snum);

  } while (num < li || num > lf);

  return num;
}

int es_valido(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;

  if (c == 225 || c == 233 || c == 237 || c == 243 || c == 250 || // áéíóú
      c == 193 || c == 201 || c == 205 || c == 211 || c == 218 || // ÁÉÍÓÚ
      c == 252 || c == 220)                                       // üÜ
    return 1;

  if (c == '\'' || c == '-' || c == '.')
    return 1;

  return 0;
}
