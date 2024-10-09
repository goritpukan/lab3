#ifndef HANDLEINPUT_H
#define HANDLEINPUT_H
#include "calculations.h"

void handleCoeffInput(const double *coefficientPointer, const char coefficientChar);
void handleOutputType(const char *outputTypePointer, const unsigned char *outputAccuracyPointer);
void handleOutputAccuracy(const unsigned char *outputAccuracyPointer);
void outputResult(XResults xResults, char outputType, unsigned char outputAccuracy);

#endif
