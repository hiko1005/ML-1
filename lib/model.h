#ifndef MODEL_H
#define MODEL_H


typedef struct {
    float X;
    float Y;
} Data;

double Predict(float w, float b, float time);

float Learn(int epochs, int n, float *w, float *b, Data *data, float L);

static double Fit(int n, float *w, float *b, Data *data, float L);

#endif