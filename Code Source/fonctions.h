struct _CL{    int val;    struct _CL* suiv;	struct _CL* bas;};typedef struct _CL CL;typedef CL* SkipListestruct _L{	CL *tete;	struct _L* suite;};typedef struct _L L;
