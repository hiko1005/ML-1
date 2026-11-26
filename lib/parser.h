#ifndef PARSER_H
#define PARSER_H

enum Args {
    ERROR,
    LEARN,
    PREDICT
};

int ParseActionArg(int argc, char *argv[]);

int ParseEpochsArg(int argc, char *argv[]);

int ParseData(Data **data);

int ParseConfig(float *w, float *b, float *L);

int SaveNewConfig(float new_w, float new_b, float L, float old_w, float old_b);

#endif