#include "../lib/model.h"
#include <math.h>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double Predict(double w, double b, double time) {
    return sigmoid(w * time + b);
}

float Learn(int epochs, int n, float *w, float *b, Data *data, float L) {
    for (int i = 0; i < epochs-1; i++) {
        Fit(n, w, b, data, L);
    }
    float loss = Fit(n, w, b, data, L);
    return loss;
}

static double Fit(int n, float *w, float *b, Data *data, float L) {
    double w_gradient = 0;
    double b_gradient = 0;
    double loss = 0;

    for (int i = 0; i < n; i++) {
        double z = (*w) * data[i].X + (*b);
        double p_i = sigmoid(z);
        double y_i = data[i].Y;

        if (p_i < 1e-15) p_i = 1e-15;
        if (p_i > 1.0 - 1e-15) p_i = 1.0 - 1e-15;
        
        loss += y_i * log(p_i) + (1 - y_i) * log(1 - p_i);
        double error = p_i - y_i;

        w_gradient += error * data[i].X;
        b_gradient += error;
    }
    loss *= -1./n;

    *w -= w_gradient * L / n;
    *b -= b_gradient * L / n;

    return loss;
}
