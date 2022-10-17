#include "dicoCreation.h"

t_std_list createDictionnaryOfOccurence(char* fileName) {

    t_std_list list;

    list = createEmptyList();

    
    FILE* fptr;

    fptr = fopen(fileName, "r");

    if (fptr == NULL) {
        printf("Error opening the file\n");
    }

    char currentChar;

    while ((currentChar = fgetc(fptr)) != EOF) {
        addOccurence(currentChar, &list);
    }

    fclose(fptr);
    
    return list;
}

t_std_list createEmptyList() {
    t_std_list list;

    list.head = NULL;

    return list;
}

p_cell createNewCell(char c) {
    p_cell cell;

    cell = (p_cell) malloc(sizeof(t_cell));

    cell->letter = c;
    cell->itirence = 1;
    cell->next = NULL;

    return cell;
}

void addOccurence(char c, t_std_list* list) {

    if (list->head == NULL) {
        p_cell newCell;
        newCell = createNewCell(c);
        list->head = newCell;

        return;
    }

    int incremented = 0;

    p_cell temp = list->head;

    while (temp->next != NULL && !incremented) {
        if (temp->letter == c) {
            temp->itirence ++;
            incremented = 1;
        } else {
            temp = temp->next;
        }
    }

    if (temp->letter == c && !incremented) {
        temp->itirence ++;
        incremented = 1;
    }

    if (!incremented) {
        p_cell newCell;
        newCell = createNewCell(c);
        temp->next = newCell;
    }

    return;
}

t_std_list sortByOccurence(t_std_list list) {

    if (list.head == NULL) {
        return createEmptyList();
    }

    t_std_list sortedList;
    sortedList = createEmptyList();

    p_cell sTemp, prevSTemp;
    int incremented = 0;

    p_cell lTemp = list.head;

    while (lTemp->next != NULL) {
        sTemp = sortedList.head;
        prevSTemp = NULL;
        incremented = 0;
        
        if (sTemp == NULL) {
            p_cell newCell;

            newCell = (t_cell*) malloc(sizeof(t_cell));

            newCell->itirence = lTemp->itirence;
            newCell->letter = lTemp->letter;
            newCell->next = NULL;

            sortedList.head = newCell;
            incremented = 1;
        } else {

            while (sTemp->next != NULL && !incremented) {

                if (sTemp->itirence > lTemp->itirence) {
                    p_cell newCell;
                    newCell = (t_cell*) malloc(sizeof(t_cell));

                    newCell->itirence = lTemp->itirence;
                    newCell->letter = lTemp->letter;
                    newCell->next = sTemp;

                    if (prevSTemp == NULL) {
                        sortedList.head = newCell;
                    } else {
                        prevSTemp->next = newCell;
                    }

                    incremented = 1;
                } else {
                    prevSTemp = sTemp;
                    sTemp = sTemp->next;
                }
            }
            
            if (!incremented) {

                if (sTemp->itirence > lTemp->itirence) {
                    p_cell newCell;
                    newCell = (t_cell*) malloc(sizeof(t_cell));

                    newCell->itirence = lTemp->itirence;
                    newCell->letter = lTemp->letter;
                    newCell->next = sTemp;

                    if (prevSTemp == NULL) {
                        sortedList.head = newCell;
                    } else {
                        prevSTemp->next = newCell;
                    }

                    incremented = 1;
                } else {
                    p_cell newCell;
                    newCell = (t_cell*) malloc(sizeof(t_cell));

                    newCell->itirence = lTemp->itirence;
                    newCell->letter = lTemp->letter;
                    newCell->next = NULL;

                    sTemp->next = newCell;
                }
            }
        }

        lTemp = lTemp->next;
    }

    sTemp = sortedList.head;
    prevSTemp = NULL;
    incremented = 0;
    
    if (sTemp == NULL) {
        p_cell newCell;

        newCell = (t_cell*) malloc(sizeof(t_cell));

        newCell->itirence = lTemp->itirence;
        newCell->letter = lTemp->letter;
        newCell->next = NULL;

        sortedList.head = newCell;
        incremented = 1;
    } else {

        while (sTemp->next != NULL && !incremented) {

            if (sTemp->itirence > lTemp->itirence) {
                p_cell newCell;
                newCell = (t_cell*) malloc(sizeof(t_cell));

                newCell->itirence = lTemp->itirence;
                newCell->letter = lTemp->letter;
                newCell->next = sTemp;

                if (prevSTemp == NULL) {
                    sortedList.head = newCell;
                } else {
                    prevSTemp->next = newCell;
                }

                incremented = 1;
            } else {
                prevSTemp = sTemp;
                sTemp = sTemp->next;
            }
        }
        
        if (!incremented) {

            if (sTemp->itirence > lTemp->itirence) {
                p_cell newCell;
                newCell = (t_cell*) malloc(sizeof(t_cell));

                newCell->itirence = lTemp->itirence;
                newCell->letter = lTemp->letter;
                newCell->next = sTemp;

                if (prevSTemp == NULL) {
                    sortedList.head = newCell;
                } else {
                    prevSTemp->next = newCell;
                }

                incremented = 1;
            } else {
                p_cell newCell;
                newCell = (t_cell*) malloc(sizeof(t_cell));

                newCell->itirence = lTemp->itirence;
                newCell->letter = lTemp->letter;
                newCell->next = NULL;

                sTemp->next = newCell;
            }
        }
    }

    return sortedList;
}

void displayDico(t_std_list list) {

    if (list.head == NULL) {
        printf("List Empty\n");
    }

    p_cell temp = list.head;

    while (temp != NULL) {
        if (temp->letter == '\n') {
            printf("\\n, %d\n", temp->itirence);
        } else {
            printf("%c, %d\n", temp->letter, temp->itirence);
        }
        temp = temp->next;
    }

    return;
}

int lenghtList(p_cell cell) {
    if (cell == NULL) {
        return 0;
    }

    return (1+lenghtList(cell->next));
}
