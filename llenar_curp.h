// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: llenar curp
// Fecha: 14 Octubre 2025    Modif: 14 Octubre 2025
// llenar_curp.h
#include "validar_curp.h"

void datos(char ap_pat[], char ap_mat[], char nombre[]);
void posicion_0_3(char curp[], char ap_pat[], char ap_mat[], char nombre[]);
int posicion_4_9(char curp[], int anio, int mes, int dia);
void posicion_10(char curp[]);
void posicion_11_12(char curp[]);
void posicion_13_15(char curp[], char ap_pat[], char ap_mat[], char nombre[]);
void posicion_16(char curp[], int anio);
void posicion_17(char curp[]);

void datos(char ap_pat[], char ap_mat[], char nombre[])
{
    printf("APELLIDO PATERNO: ");
    my_gets_validado(ap_pat, 50);
    mayusculas(ap_pat);

    printf("PRESIONA ENTER PARA OMITIR\nAPELLIDO MATERNO (Opcional): ");
    my_gets_validado(ap_mat, 50);
    mayusculas(ap_mat);

    int i = 0;
    int valido = 0;

    while (ap_mat[i] != '\0')
    {
        if (ap_mat[i] != ' ')
        {
            valido = 1;
        }
        i++;
    }

    if (valido == 0)
    {
        ap_mat[0] = 'X';
        ap_mat[1] = '\0';
    }

    printf("NOMBRE(s): ");
    my_gets_validado(nombre, 50);
    mayusculas(nombre);

    printf("\n");
}

void posicion_0_3(char curp[], char ap_pat[], char ap_mat[], char nombre[])
{
    char primer_nombre[50];
    curp[0] = ap_pat[0];
    curp[1] = primera_vocal_interna(ap_pat);
    if (ap_mat[0] != '\0')
    {
        curp[2] = ap_mat[0];
    }
    else
    {
        curp[2] = 'X';
    }
    curp[3] = nombre[0];

    jose_maria(nombre, primer_nombre);
}

int posicion_4_9(char curp[], int anio, int mes, int dia)
{
    int cant_dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    anio = valida_num(1900, 2025, "ANIO DE NACIMIENTO: ");
    mes = valida_num(1, 12, "MES DE NACIMIENTO: ");

    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        {
            cant_dias[1] = 29;
        }
    }
    
    for (int i = 0; i < 12; i++)
    {
        if (i == mes - 1)
        {
            dia = valida_num(1, cant_dias[i], "DIA DE NACIMIENTO : ");
        }
    }

    char anio_temp[5];
    itoa(anio, anio_temp, 10);

    char mes_temp[3];
    if (mes < 10)
    {
        mes_temp[0] = '0';
        itoa(mes, mes_temp + 1, 10);
    }
    else
    {
        itoa(mes, mes_temp, 10);
    }

    char dia_temp[3];
    if (dia < 10)
    {
        dia_temp[0] = '0';
        itoa(dia, dia_temp + 1, 10);
    }
    else
    {
        itoa(dia, dia_temp, 10);
    }

    curp[4] = anio_temp[2];
    curp[5] = anio_temp[3];
    curp[6] = mes_temp[0];
    curp[7] = mes_temp[1];
    curp[8] = dia_temp[0];
    curp[9] = dia_temp[1];

    return anio;
}

void posicion_10(char curp[])
{
    int sexo;
    sexo = valida_num(1, 2, "1. HOMBRE\n2. MUJER\n\nELIGE UNA OPCION: ");

    if (sexo == 1)
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }
}

void posicion_11_12(char curp[])
{
    int entidad;
    printf(
        "\n1. AGUASCALIENTES"
        "\n2. BAJA CALIFORNIA"
        "\n3. BAJA CALIFORNIA SUR"
        "\n4. CAMPECHE"
        "\n5. COAHUILA"
        "\n6. COLIMA"
        "\n7. CHIAPAS"
        "\n8. CHIHUAHUA"
        "\n9. DISTRITO FEDERAL"
        "\n10. DURANGO"
        "\n11. GUANAJUATO"
        "\n12. GUERRERO"
        "\n13. HIDALGO"
        "\n14. JALISCO"
        "\n15. MEXICO"
        "\n16. MICHOACAN"
        "\n17. MORELOS"
        "\n18. NAYARIT"
        "\n19. NUEVO LEON"
        "\n20. OAXACA"
        "\n21. PUEBLA"
        "\n22. QUERETARO"
        "\n23. QUINTANA ROO"
        "\n24. SAN LUIS POTOSI"
        "\n25. SINALOA"
        "\n26. SONORA"
        "\n27. TABASCO"
        "\n28. TAMAULIPAS"
        "\n29. TLAXCALA"
        "\n30. VERACRUZ"
        "\n31. YUCATAN"
        "\n32. ZACATECAS"
        "\n33. NACIDO EN EL EXTRANJERO");

    entidad = valida_num(1, 33, "\n\nINGRESA LA OPCION DESEADA: ");

    char entidades[33][3] = {
        "AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF",
        "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT",
        "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC",
        "TS", "TL", "VZ", "YN", "ZS", "NE"};

    curp[11] = entidades[entidad - 1][0];
    curp[12] = entidades[entidad - 1][1];
}

void posicion_13_15(char curp[], char appat[], char apmat[], char nombre[])
{
    curp[13] = primera_consonante_interna(appat);
    curp[14] = primera_consonante_interna(apmat);
    curp[15] = primera_consonante_interna(nombre);
}

void posicion_16(char curp[], int anio)
{
    if (anio <= 1999)
    {
        curp[16] = '0';
    }
    else
    {
        curp[16] = 'A';
    }
}

void posicion_17(char curp[]) // LO INTENTE EN VECTOR DE CADENAS Y UN ARREGLO CON LOS VALORES, PERO NO FUNCIONABA
{
    char caracter;
    int valor = 0, suma = 0, digito;

    for (int i = 0; i < 17; i++)
    {
        caracter = curp[i];
        switch (caracter)
        {
        case '0':
            valor = 0;
            break;
        case '1':
            valor = 1;
            break;
        case '2':
            valor = 2;
            break;
        case '3':
            valor = 3;
            break;
        case '4':
            valor = 4;
            break;
        case '5':
            valor = 5;
            break;
        case '6':
            valor = 6;
            break;
        case '7':
            valor = 7;
            break;
        case '8':
            valor = 8;
            break;
        case '9':
            valor = 9;
            break;
        case 'A':
            valor = 10;
            break;
        case 'B':
            valor = 11;
            break;
        case 'C':
            valor = 12;
            break;
        case 'D':
            valor = 13;
            break;
        case 'E':
            valor = 14;
            break;
        case 'F':
            valor = 15;
            break;
        case 'G':
            valor = 16;
            break;
        case 'H':
            valor = 17;
            break;
        case 'I':
            valor = 18;
            break;
        case 'J':
            valor = 19;
            break;
        case 'K':
            valor = 20;
            break;
        case 'L':
            valor = 21;
            break;
        case 'M':
            valor = 22;
            break;
        case 'N':
            valor = 23;
            break;
        case 'O':
            valor = 25;
            break;
        case 'P':
            valor = 26;
            break;
        case 'Q':
            valor = 27;
            break;
        case 'R':
            valor = 28;
            break;
        case 'S':
            valor = 29;
            break;
        case 'T':
            valor = 30;
            break;
        case 'U':
            valor = 31;
            break;
        case 'V':
            valor = 32;
            break;
        case 'W':
            valor = 33;
            break;
        case 'X':
            valor = 34;
            break;
        case 'Y':
            valor = 35;
            break;
        case 'Z':
            valor = 36;
            break;
        }

        suma = suma + (valor * (18 - i));
    }

    digito = suma % 10;
    if (digito != 0)
    {
        digito = 10 - digito;
    }

    curp[17] = digito + '0';
    curp[18] = '\0';
}
