#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

int get_token(char *buffer){
    char c;
    int index = 0;
    
    //Mientras encuentre un espacio
    do{ c = getchar();
    }while(isspace(c)); 
    
    switch (c){
    //Si llego al final devuelve FDT
    case EOF:
        return FDT;
        break;
    //Si encuentra una coma, devuelve SEP
    case ',':
        return SEP;
        break;
    // Si no es el fin del archivo y ademas no lee una coma
    default: 
    while (c != EOF && c != ',' && !isspace(c))
    {
        // guardar el caracter en la primera posicion (0 si es el primer c que lee), 
        //luego incrementarlo en uno, lee un nuevo caracter
        buffer[index++] = c;
        c = getchar();
    }
    // cuando no detecta mas caracteres de cadena, coloca al final un sentinela y ejecuto ungetc, retorno Cad
        buffer[index] = '\0';
        ungetc(c, stdin);
        return CAD;  
    }
}

