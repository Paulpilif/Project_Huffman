#ifndef HUFFMANDICO
#define HUFFMANDICO

#include "treeCreation.h"

struct s_letterCode {
    char* code;
    int nbElts;
};
typedef struct s_letterCode t_letterCode, *p_letterCode;

void createHuffmanDico(t_tree);
void setLetterCode(t_letterCode, p_node);
void writeLetterInDico(t_letterCode, char);

#endif