#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afisareAltFisier(char *numeFisierCitire, char *numeFisierScriere) {
    FILE *in, *out;
    in = fopen(numeFisierCitire, "r");
    if (in == NULL) {
        printf("Fisierul nu a putut fi deschis!");
        exit(0);
    }

    out = fopen(numeFisierScriere, "w");
    int c = fgetc(in);
    char linie[500];
    fgets(linie, 500, in);
    while (fgets(linie, 500, in) != NULL) {
        for (int i = 0; i < strlen(linie); i++) {
            if (linie[i] == c) {
                strcpy(linie + i, linie + i + 1);
                i--;
            }
        }
        fputs(linie, out);
    }

    fclose(in);
    fclose(out);
}

void suprascrieAcelasiFisier(char *numeFisier) {
    FILE *fisier = fopen(numeFisier, "a+");
    if (fisier == NULL) {
        printf("Fisierul nu a putut fi deschis!");
        exit(0);
    }

    fseek(fisier, 0, SEEK_END);
    int finalFisier = ftell(fisier);
    rewind(fisier);
    int c = fgetc(fisier);
    char linie[500];
    while (ftell(fisier) < finalFisier) {
        fgets(linie, 500, fisier);
        for (int i = 0; i < strlen(linie); i++) {
            if (linie[i] == c) {
                strcpy(linie + i, linie + i + 1);
                i--;
            }
        }
        int poz = ftell(fisier);
        fseek(fisier, 0, SEEK_END);
        fputs(linie, fisier);
        fseek(fisier, poz, SEEK_SET);
    }

    fclose(fisier);
}


int main() {
    //afisareAltFisier("..//fisierText.txt", "replica.txt");
    suprascrieAcelasiFisier("..//fisierText.txt");
}