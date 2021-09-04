#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char token;
    char buffer[100];
    do{    
    token = get_token(buffer);
        switch (token)
        {        
        case SEP: printf("Separador: ,");
            break;
    
        //imprimo cadena que se encuentra almacenada en el buffer con %s
        case CAD: printf("Cadena: %s\n", buffer);
            break;

        default: printf("Fin de texto: \n");
        }
   }while(token != FDT); 
}