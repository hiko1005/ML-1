#include "../lib/model.h"
#include "../lib/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ParseActionArg(int argc, char *argv[]) {
    if (2 <= argc) {
        if (strcmp(argv[1], "-learn") == 0 || strcmp(argv[1], "-l") == 0) {
            return LEARN;
        }
        else if (strcmp(argv[1], "-predict") == 0 || strcmp(argv[1], "-p") == 0) {
            return PREDICT;
        }
        else {
            fprintf(stderr, "[!] Uknown argument. ([-learn count], [-l count], [-predict], [-p] only)\n");
        }
    }
    else return ERROR;
}

int ParseEpochsArg(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "[!] Missing epochs count.\n");
        return ERROR;
    }

    char *end;
    long epochs = strtol(argv[2], &end, 10);

    if (*end != '\0' || epochs <= 0) {
        fprintf(stderr, "[!] Invalid epochs count.\n");
        return ERROR;
    }

    return (int)epochs;
}

int ParseData(Data **data) {
    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "[!] Cannot open data.txt.\n");
        return ERROR;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "[!] Invalid data size.\n");
        fclose(file);
        return ERROR;
    }

    Data *new_data = realloc(*data, n*sizeof(Data));
    if (new_data == NULL) {
        fprintf(stderr, "[!] Cannot allocate memory.\n");
        return ERROR;
    }

    *data = new_data;
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%f, %f", &(*data)[i].X, &(*data)[i].Y) != 2) {
            fprintf(stderr, "[!] Invalid data at row %d.\n", i);
            free(*data);
            *data = NULL;
            fclose(file);
            return ERROR;
        }
    }

    fclose(file);

    return n;
}

int ParseConfig(float *w, float *b, float *L) {
    FILE *file = fopen("config.txt", "r");

    if (file == NULL) {
        perror("[!] Cannot open config.txt");
        return ERROR;
    }

    if (fscanf(file, "w = %f\n", w) != 1 ||
        fscanf(file, "b = %f\n", b) != 1 ||
        fscanf(file, "L = %f", L) != 1) {

    fprintf(stderr, "[!] Invalid config format.\n");
    fclose(file);
    return ERROR;
}

    fclose(file);

    return 1;
}

int SaveNewConfig(float new_w, float new_b, float L, float old_w, float old_b) {
    FILE *file = fopen("config.txt", "w");

    if (file == NULL) {
        perror("[!] Cannot save new weight and bias");
        return ERROR;
    }

    fprintf(file, "w = %f\n", new_w);
    fprintf(file, "b = %f\n", new_b);
    fprintf(file, "L = %f\n", L);

    fprintf(file, "old w = %f\n", old_w);
    fprintf(file, "old b = %f\n", old_b);

    fclose(file);

    return 1;
}