#ifndef COMPRESSION
#define COMPRESSION

#include <stdlib.h>
#include <stdio.h>
#include "treeCreation.h"

struct s_compressedLetter {
    char* code;
    char letter;
    struct s_compressedLetter *next;
};
typedef struct s_compressedLetter t_compressedLetter, *p_compressedLetter;

struct s_std_compressedLetter_list {
    p_compressedLetter head;
};
typedef struct s_std_compressedLetter_list t_std_compressedLetter_list;

t_std_compressedLetter_list getDico();
char* getCompressedLetter(char, t_std_compressedLetter_list);
t_tree getTreeFromDico();
void compressFile(char*);
void decompressFile();

#endif