// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: Mi libreria [string.h - my_gets]
// Fecha: 23 Septiembre 2025    Modif: 28 Septiembre 2025
// my_string.h

#include <stdio.h>
#include <stdlib.h>

void mayusculas(char cadena[]);
void minusculas(char cadena[]);
void capital(char cadena[]);
int caracteres(char cadena[]);
void invertir(char cadena[]);
void eliminar_espacios(char cadena[]);
int iguales(char cadena_a[], char cadena_b[]);

void mayusculas(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
}

void minusculas(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                cadena[i] = cadena[i] + 32;
            }
        }
    }
}

void capital(char cadena[])
{
    int capital = 1;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (capital == 1)
        {
            if (cadena[i] >= 'a')
            {
                cadena[i] = cadena[i] - 32;
            }
        }

        capital = 0;

        if (i == 0)
        {
            if (cadena[i] >= 'a')
            {
                cadena[i] = cadena[i] - 32;
            }
        }

        if (cadena[i] == ' ')
        {
            capital = 1;
        }

        else
        {
            capital = 0;
        }
    }
}

int caracteres(char cadena[])
{
    int contador = 0;
    while (cadena[contador] != '\0')
    {
        contador++;
    }
    return contador;
}

void invertir(char cadena[])
{
    int tamano = caracteres(cadena);
    for (int i = 0; i < tamano / 2; i++)
    {
        char temp = cadena[i];
        cadena[i] = cadena[tamano - 1 - i];
        cadena[tamano - 1 - i] = temp;
    }
}

void eliminar_espacios(char cadena[])
{
    int j = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
}

void copiar(char destino[], char origen[])
{
    int i = 0;
    while (origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; 
}

int iguales(char cadena_a[], char cadena_b[], int lon)
{
    for (int i = 0; i < lon; i++)
    {
        if (cadena_a[i] != cadena_b[i])
        {
            return 0;
        }
    }
    return 1;
}