# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct _CL{
    int val;
    struct _CL* suiv;
};

typedef struct _CL CL;

typedef CL* liste;
