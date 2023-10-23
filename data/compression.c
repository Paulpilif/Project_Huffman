#include "compression.h"

t_std_compressedLetter_list getDico() {
    FILE* fptr;

    fptr = fopen("dico.txt", "r");

    if (fptr == NULL) {
        printf("Fail to open fail");

        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int index;
    t_std_compressedLetter_list list;
    list.head = NULL;
    p_compressedLetter temp;

    while ((read = getline(&line, &len, fptr)) != -1) {

        p_compressedLetter compressedLetter;
        compressedLetter = (p_compressedLetter) malloc(sizeof(t_compressedLetter));
        compressedLetter->code = (char*) malloc(read*sizeof(char));
        compressedLetter->next = NULL;

        if (line[1] == ':') {
            compressedLetter->letter = line[0];

            for (index = 2; line[index] != '\n'; index++) {
                compressedLetter->code[index-2] = line[index];
            }

            compressedLetter->code[index-1] = '\0';

            if (list.head == NULL) {
                list.head = compressedLetter;
                temp = list.head;
            } else {
                temp->next = compressedLetter;
                temp = temp->next;
            }
        } else {
            compressedLetter->letter = '\n';

            for (index = 3; line[index] != '\n'; index++) {
                compressedLetter->code[index-3] = line[index];
            }

            compressedLetter->code[index-1] = '\0';

            if (list.head == NULL) {
                list.head = compressedLetter;
                temp = list.head;
            } else {
                temp->next = compressedLetter;
                temp = temp->next;
            }
        }
    }

    fclose(fptr);

    return list;
}

char* getCompressedLetter(char letter, t_std_compressedLetter_list dico) {
    p_compressedLetter temp = dico.head;

    while (temp != NULL) {
        if (temp->letter == letter) {
            return temp->code;
        }

        temp = temp->next;
    }

    return "";
}

void compressFile(char* filename) {
    FILE *rptr, *wptr;

    rptr = fopen(filename, "r");
    wptr = fopen("compression.txt", "w");

    t_std_compressedLetter_list dicoList;
    dicoList = getDico();

    char currentChar;
    char* compressedLetter;

    while ((currentChar = fgetc(rptr)) != EOF) {
        compressedLetter = getCompressedLetter(currentChar, dicoList);

        fprintf(wptr, "%s", compressedLetter);
    }

    fclose(rptr);
    fclose(wptr);
}

void decompressFile() {
    FILE *rptr, *wptr;

    rptr = fopen("compression.txt", "r");
    wptr = fopen("decompression.txt", "w");

    t_tree tree;
    tree = getTreeFromDico();

    p_node temp;
    temp = tree.root;

    char currentChar;

    if (temp->letterCell != NULL) {
        fprintf(wptr, "%c", temp->letterCell->letter);

        temp = tree.root;
    }

    while ((currentChar = fgetc(rptr)) != EOF){

        if (currentChar == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }

        if (temp->letterCell != NULL) {
            fprintf(wptr, "%c", temp->letterCell->letter);

            temp = tree.root;
        }
    }

    fclose(rptr);
    fclose(wptr);
}

t_tree getTreeFromDico() {
    FILE *fptr;

    fptr= fopen("dico.txt", "r");

    t_tree tree;
    tree = createEmptyTree();

    p_node root;
    root = createEmptyNode();
    tree.root = root;

    p_node tempTree;
    tempTree = tree.root;

    t_std_compressedLetter_list dicoList;
    dicoList = getDico();

    p_compressedLetter tempDico;
    tempDico = dicoList.head;

    while (tempDico != NULL) {
        for (int index = 0; tempDico->code[index] != '\0'; index ++) {
            if (tempDico->code[index] == '0') {
                if (tempTree->left == NULL) {
                    p_node newNode;
                    newNode = createEmptyNode();
                    tempTree->left = newNode;
                }

                tempTree = tempTree->left;
            } else {
                if (tempTree->right == NULL) {
                    p_node newNode;
                    newNode = createEmptyNode();
                    tempTree->right = newNode;
                }

                tempTree = tempTree->right;
            }
        }

        p_cell letterCell;
        letterCell = (p_cell) malloc(sizeof(t_cell));
        letterCell->itirence = 0;
        letterCell->letter = tempDico->letter;
        letterCell->next = NULL;

        tempTree->letterCell = letterCell;

        tempDico = tempDico->next;
        tempTree = tree.root;
    }

    fclose(fptr);

    return tree;
}
