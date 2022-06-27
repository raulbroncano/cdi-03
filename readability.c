#include <stdio.h>

#include <ctype.h>

#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("no se a encontrado el archivo\n");
        return 1;
    }

    int i = 0;
    int cantidaddeletras = 0;
    int cantidaddepalabras = 1;
    int cantidaddeoraciones = 0;

    while (text [i]>0) {
        
        if (text [i] == '.') {
            cantidaddeoraciones++;
        }
        
        if (text [i] == ' ') {
            cantidaddepalabras++;
        }
        if (isalpha(text [i])) {
            cantidaddeletras++;
        }
        if (text [i] == '?'){
            cantidaddeoraciones++;
        }
        if (text[i] == '!'){
            cantidaddeoraciones++;
        }
        i++;
    }

    float L = 0;
    float S =  0;
    float grado;

    S = 100.0 * cantidaddeoraciones / cantidaddepalabras;
    L = 100.0 * cantidaddeletras / cantidaddepalabras;

    grado = 0.0588 * L - 0.296 * S - 15.8;
    grado = round(grado);

    if(grado<1) {
        printf("Before Grado 1");
    }
    else if (grado>16){
        printf("grado +16");
    }
    else {
        printf ("Grado %d", (int)grado);
    }

    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    
    do {
        c = getc(fp);
        *text = c;
        text++;
    } while (c != EOF);
    
    text--;
    *text = '\0';
    return 0;
}
