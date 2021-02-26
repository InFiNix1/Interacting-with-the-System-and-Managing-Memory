#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
    char* outName=malloc((strlen(inputName)+4)*sizeof(*outName));
    strcpy(outName, inputName);
    outName=realloc(outName, (strlen(inputName)+11)*sizeof(*outName));
    strcat(outName, ".counts");
    return outName;
}
