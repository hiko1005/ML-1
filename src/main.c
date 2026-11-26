#include "../lib/model.h"
#include "../lib/parser.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int arg = ParseActionArg(argc, argv);
    if (arg == ERROR) {
        fprintf(stderr, "[!] Unknown error.");
        return 1;
    }

    float w, b, L;
    if (ParseConfig(&w, &b, &L) == ERROR) {
        return 1;
    }

    Data *data = NULL;
    int n = ParseData(&data);

    if (n == ERROR) {
        return 1;
    }

    if (arg == PREDICT) {
        printf("-----------Prediction Mode-----------\n");
        for (int i = 0; i < n; i++) {
            float X = data[i].X;
            printf("[%d] X = %f\t | Predict = %f\t\n", i+1, X, Predict(w, b, X));
        }
    }
    else if (arg == LEARN) {
        printf("-----------Learning Mode-----------\n");
        float old_w = w;
        float old_b = b;

        int epochs = ParseEpochsArg(argc, argv);
        if (epochs == ERROR) return 1;
        
        double loss = Learn(epochs, n, &w, &b, data, L);
        printf("Current loss is %f.", loss);
        SaveNewConfig(w, b, L, old_w, old_b);
    }

    free(data);

    return 0;
}