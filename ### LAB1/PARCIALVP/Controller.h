int controller_loadFromText(char* path , LinkedList* dominio);
int controller_saveAsText(char* path, LinkedList* dominio);
int controller_loadFromBinary(char* path , LinkedList* dominio);
int controller_addDominio(LinkedList* dominio);
int controller_menuDeOpciones(void);
int controller_findDominioByID(LinkedList* dominio, int id);
int controller_editDominio(LinkedList* dominio);
int controller_removeDominio(LinkedList* dominio);
int controller_ListDominio(LinkedList* dominio);
int controller_sortDominio(LinkedList* dominio);
int controller_saveAsText(char* path , LinkedList* dominio);
int controller_saveAsBinary(char* path , LinkedList* dominio);
