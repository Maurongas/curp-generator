// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: validar curp
// Fecha: 14 Octubre 2025    Modif: 14 Octubre 2025
// validar_curp.h
#include "mauro.h"
#include <string.h>

char primera_vocal_interna(char cadena[]);
char primera_consonante_interna(char cadena[]);
void palabrotas(char curp[]);
void validar_letras(char cadena[]);
int compuesto(char cadena[]);
void jose_maria(char nombre[], char segundo_nombre[]);

char primera_vocal_interna(char cadena[])
{
    char vocales[] = "AEIOUÁÉÍÓÚÀÈÌÒÙÄËÏÖÜaeiouáéíóúàèìòùäëïöü";
    int i, j;
    for (i = 1; cadena[i] != '\0'; i++)
    {
        for (j = 0; vocales[j] != '\0'; j++)
        {
            if (cadena[i] == vocales[j])
            {
                mayusculas(cadena);
                return cadena[i];
            }
        }
    }
    return 'X';
}

char primera_consonante_interna(char cadena[])
{
    char vocales[] = "AEIOUÁÉÍÓÚÀÈÌÒÙÄËÏÖÜaeiouáéíóúàèìòùäëïöü";
    int i, j, es_vocal;
    for (i = 1; cadena[i] != '\0'; i++)
    {
        es_vocal = 0;
        for (j = 0; vocales[j] != '\0'; j++)
        {
            if (cadena[i] == vocales[j])
            {
                es_vocal = 1;
            }
        }
        if (es_vocal == 0)
        {
            if (cadena[i] != ' ')
            {
                if ((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z') || cadena[i] == 0xD1 || cadena[i] == 0xF1) // ULTIMOS DOS SON Ñ Y ñ
                {
                    mayusculas(cadena);
                    return cadena[i];
                }
            }
        }
    }
    return 'X';
}

void palabrotas(char curp[])
{
    char palabras_prohibidas[80][5] = {
        "BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGO", "CAKA", "CAKO", "WUEY",
        "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO",
        "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA",
        "KAKO", "KAGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO",
        "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR",
        "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE",
        "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO",
        "RUIN", "SENO", "TETA", "VACA", "CAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI"};
    int i;
    for (i = 0; i < 80; i++)
    {
        if (iguales(curp, palabras_prohibidas[i], 4) == 1)
        {
            curp[1] = 'X';
        }
    }
}

void validar_letras(char cadena[])
{
    char letras[5][23] = {
        "aáàâãAÁÀÂÃ",
        "eéèêëEÉÈÊË",
        "iíìîïIÍÌÎÏ",
        "oóòôõöOÓÒÔÕÖ",
        "uúùûüUÚÙÛÜ"};
    char resultado[5] = {'A', 'E', 'I', 'O', 'U'};
    int i, j, k, remplazado;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        remplazado = 0;
        for (j = 0; j < 5; j++)
        {
            for (k = 0; letras[j][k] != '\0'; k++)
            {
                if (cadena[i] == letras[j][k])
                {
                    cadena[i] = resultado[j];
                    remplazado = 1;
                }
            }
        }
        if (remplazado == 0)
        {
            if (cadena[i] == '/' || cadena[i] == '-' || cadena[i] == '.' || cadena[i] == '_')
            {
                cadena[i] = 'X';
            }
        }
    }
}

int compuesto(char cadena[])
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] == ' ')
        {
            return 1;
        }
        i++;
    }

    return 0;
}

void jose_maria(char nombre[], char segundo_nombre[])
{
    char nombres_baneados[6][6] = {"MARIA", "MA.", "MA", "JOSE", "J", "J."};
    int nombre_comp = compuesto(nombre);

    char copia[50];
    copiar(copia, nombre);
    mayusculas(copia);

    char *palabra = strtok(copia, " ");

    int ignorar = 0;
    if (palabra != NULL)
    {
        for (int i = 0; i < 6; i++)
        {
            if (iguales(palabra, nombres_baneados[i], caracteres(palabra)))
            {
                ignorar = 1; 
            }
        }
    }

    if (ignorar && nombre_comp == 1)
    {
        palabra = strtok(NULL, " "); 
    }

    if (palabra != NULL)
    {
        segundo_nombre[0] = palabra[0]; 
    }
    else
    {
        segundo_nombre[0] = 'X';
    }

    segundo_nombre[1] = '\0'; 
}
