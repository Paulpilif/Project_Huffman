#ifndef TREECREATION
#define TREECREATION

#include "dicoCreation.h"

struct s_node {
    struct s_node *left;
    p_cell letterCell;
    int value;
    struct s_node *right;
};
typedef struct s_node t_node, *p_node;

struct s_tree {
    p_node root;
};
typedef struct s_tree t_tree;

struct s_node_cell {
    p_node node;
    struct s_node_cell* next;
};
typedef struct s_node_cell t_node_cell, *p_node_cell;

struct s_std_node_list {
    p_node_cell head;
};
typedef struct s_std_node_list t_std_node_list;

p_node createEmptyNode();
t_std_node_list createEmptyNodeList();
t_tree createEmptyTree();

t_tree createHuffmanTree(t_std_list*, t_std_node_list*);
p_cell unstackList(t_std_list*);
void addNodeToList(t_std_node_list*, p_node_cell);
p_node_cell unstackNodeList(t_std_node_list*);
p_node createNewNode(p_node, p_node);
p_node_cell createNewNodeCell(p_node, p_node);
p_node_cell createNodeCellWithTwoCell(p_cell, p_cell);
p_node_cell createNodeCellWithOneCell(p_cell, p_node);
p_cell copyCell(p_cell);

void displayNodeList(t_std_node_list);
int getTreeHeight(p_node);

#endif
