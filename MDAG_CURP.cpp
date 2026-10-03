// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: CURP
// Fecha: 14 Octubre 2025    Modif: 14 Octubre 2025
// MDAG_CURP.cpp

#include "llenar_curp.h"

int main()
{
    srand(time(NULL));

    char CURP[19] = {'\0'};

    char AP_PAT[50], AP_MAT[50], NOMBRE[50];

    int ANIO, MES, DIA;

    // llenar curp
    datos(AP_PAT, AP_MAT, NOMBRE);

    posicion_0_3(CURP, AP_PAT, AP_MAT, NOMBRE);

    ANIO = posicion_4_9(CURP, ANIO, MES, DIA);

    posicion_10(CURP);

    posicion_11_12(CURP);

    posicion_13_15(CURP, AP_PAT, AP_MAT, NOMBRE);

    posicion_16(CURP, ANIO);

    // validar curp
    palabrotas(CURP);

    validar_letras(CURP);

    posicion_17(CURP);

    printf("%s", CURP);

    return 0;
}

