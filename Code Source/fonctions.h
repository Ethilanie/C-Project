struct _CL{    int val;    struct _CL* suiv;	struct _CL* bas;};typedef struct _CL CL;struct _L{	CL *tete;	struct _L* suite;};typedef struct _L L;

L* boucleAjout(L* skipList, int* val_elements,int nbelts, double proba);
L* creerTete();int* tableauAleatoire(int nbelements);