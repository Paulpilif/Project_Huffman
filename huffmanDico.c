#include "huffmanDico.h"

void createHuffmanDico(t_tree tree) {

    FILE* fptr;
    fptr = fopen("dico.txt", "w");
    fclose(fptr);

    t_letterCode letterCode;
    int treeSize;
    treeSize = getTreeHeight(tree.root);

    letterCode.code = (char*) malloc(treeSize*sizeof(char));
    letterCode.nbElts = 1;

    letterCode.code[letterCode.nbElts-1] = '0';
    setLetterCode(letterCode, tree.root->left);

    letterCode.code[letterCode.nbElts-1] = '1';
    setLetterCode(letterCode, tree.root->right);
}

void setLetterCode(t_letterCode letterCode, p_node node) {
    if (node->letterCell != NULL) {
        writeLetterInDico(letterCode, node->letterCell->letter);

        return;
    }

    letterCode.nbElts ++;

    letterCode.code[letterCode.nbElts-1] = '0';
    setLetterCode(letterCode, node->left);

    letterCode.code[letterCode.nbElts-1] = '1';
    setLetterCode(letterCode, node->right);

    return;
}

void writeLetterInDico(t_letterCode letterCode, char letter) {
    FILE* fptr;

    fptr = fopen("dico.txt", "a");

    if (letter == '\n') {
        fprintf(fptr, "\\n:");
    } else {
        fprintf(fptr, "%c:", letter);
    }

    for (int index = 0; index < letterCode.nbElts; index ++) {
        fprintf(fptr, "%c", letterCode.code[index]);
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return;
}
