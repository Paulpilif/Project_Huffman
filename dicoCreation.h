#ifndef DICOCREATION
#define DICOCREATION

#include <stdio.h>
#include <stdlib.h>

struct s_cell {
    char letter;
    int itirence;
    struct s_cell* next;
};

typedef struct s_cell t_cell, *p_cell;

struct s_std_list {
    p_cell head;
};

typedef struct s_std_list t_std_list;

t_std_list createEmptyList();
p_cell createNewCell(char);
t_std_list createDictionnaryOfOccurence(char*);
void addOccurence(char, t_std_list*);

t_std_list sortByOccurence(t_std_list);
void displayDico(t_std_list);
int lenghtList(p_cell);

#endif