#include "treeCreation.h"

p_node createEmptyNode() {
    p_node node;
    node = (p_node) malloc(sizeof(t_node));

    node->left = NULL;
    node->right = NULL;
    node->letterCell = NULL;
    node->value = 0;

    return node;
}

p_node_cell createEmptyNodeCell() {
    p_node_cell node;
    node = (p_node_cell) malloc(sizeof(t_node_cell));

    node->node = createEmptyNode();
    node->next = NULL;

    return node;
}

t_std_node_list createEmptyNodeList() {
    t_std_node_list list;
    list.head = NULL;

    return list;
}

t_tree createEmptyTree() {
    t_tree tree;
    tree.root = NULL;

    return tree;
}

t_tree createHuffmanTree(t_std_list *list, t_std_node_list *nodeList) {

    if (list->head == NULL) {

        if (nodeList->head->next != NULL) {

            p_node leftNode, rightNode;
            leftNode = unstackNodeList(nodeList)->node;
            rightNode = unstackNodeList(nodeList)->node;

            p_node_cell newNodeCell;
            newNodeCell = createNewNodeCell(leftNode, rightNode);

            addNodeToList(nodeList, newNodeCell);

            return createHuffmanTree(list, nodeList);
        } else {
            t_tree tree;
            tree = createEmptyTree();

            tree.root = nodeList->head->node;

            return tree;
        }
    }

    if (nodeList->head == NULL) {

        p_cell leftCell, rightCell;

        leftCell = unstackList(list);
        rightCell = unstackList(list);
        
        p_node_cell newNodeCell;
        newNodeCell = createNodeCellWithTwoCell(leftCell, rightCell);

        addNodeToList(nodeList, newNodeCell);

    } else if (nodeList->head->next == NULL) {
        if (list->head->itirence < nodeList->head->node->value &&
        list->head->next->itirence < nodeList->head->node->value) {

            p_cell leftCell, rightCell;
            leftCell = unstackList(list);
            rightCell = unstackList(list);

            p_node_cell newNodeCell;
            newNodeCell = createNodeCellWithTwoCell(leftCell, rightCell);

            addNodeToList(nodeList, newNodeCell);

        } else if ((list->head->itirence < nodeList->head->node->value &&
        nodeList->head->node->value < list->head->next->itirence) || 
        nodeList->head->node->value < list->head->itirence) {

            p_node rightNode;
            rightNode = unstackNodeList(nodeList)->node;

            p_cell leftCell;
            leftCell = unstackList(list);

            p_node_cell newNodeCell;
            newNodeCell = createNodeCellWithOneCell(leftCell, rightNode);

            addNodeToList(nodeList, newNodeCell);

        } else {
            p_node rightNode;
            rightNode = unstackNodeList(nodeList)->node;

            p_cell leftCell;
            leftCell = unstackList(list);

            p_node_cell newNodeCell;
            newNodeCell = createNodeCellWithOneCell(leftCell, rightNode);

            addNodeToList(nodeList, newNodeCell);
        }
    } else {
        if (list->head->itirence < nodeList->head->node->value &&
        list->head->next->itirence < nodeList->head->node->value) {

            p_cell leftCell, rightCell;
            leftCell = unstackList(list);
            rightCell = unstackList(list);

            p_node_cell newNodeCell;
            newNodeCell = createNodeCellWithTwoCell(leftCell, rightCell);

            addNodeToList(nodeList, newNodeCell);

        } else if (nodeList->head->node->value < list->head->itirence &&
        nodeList->head->next->node->value < list->head->itirence) {

            p_node leftNode, rightNode;
            leftNode = unstackNodeList(nodeList)->node;
            rightNode = unstackNodeList(nodeList)->node;

            p_node_cell newNodeCell;
            newNodeCell = createNewNodeCell(leftNode, rightNode);

            addNodeToList(nodeList, newNodeCell);

        } else if ((list->head->itirence < nodeList->head->node->value &&
        nodeList->head->node->value < list->head->next->itirence) ||
        (nodeList->head->node->value < list->head->itirence &&
        list->head->itirence < nodeList->head->next->node->value)) {

            p_cell leftCell;
            leftCell = unstackList(list);

            p_node rightNode;
            rightNode = unstackNodeList(nodeList)->node;

            p_node_cell newNodeCell;
            newNodeCell = createNodeCellWithOneCell(leftCell, rightNode);

            addNodeToList(nodeList, newNodeCell);
        } else {
            
            p_node rightNode;
            rightNode = unstackNodeList(nodeList)->node;

            p_cell leftCell;
            leftCell = unstackList(list);

            p_node_cell newNodeCell;
            newNodeCell = createNodeCellWithOneCell(leftCell, rightNode);

            addNodeToList(nodeList, newNodeCell);

        }
    }

    // Check when their is only one element left in the list

    // When the list is empty : make the nodeList only one element

    return createHuffmanTree(list, nodeList);
}

p_node createNewNode(p_node leftNode, p_node rightNode) {
    p_node newNode;
    newNode = createEmptyNode();
    newNode->left = leftNode;
    newNode->right = rightNode;
    newNode->value = leftNode->value + rightNode->value;

    return newNode;
}

void addNodeToList(t_std_node_list* list, p_node_cell newNodeCell) {

    if (list->head == NULL) {
        list->head = newNodeCell;       

        return;
    }

    p_node_cell temp, prevTemp;
    int incremented = 0;
    temp = list->head;
    prevTemp = NULL;

    while (temp->next != NULL && !incremented) {
        if (temp->node->value > newNodeCell->node->value) {
            newNodeCell->next = temp;
            if (prevTemp == NULL) {
                list->head = newNodeCell;
            } else {
                prevTemp->next = newNodeCell;
            }

            incremented = 1;
        }

        prevTemp = temp;
        temp = temp->next;
    }

    if (temp->node->value > newNodeCell->node->value && !incremented) {
        newNodeCell->next = temp;
        if (prevTemp == NULL) {
            list->head = newNodeCell;
        } else {
            prevTemp->next = newNodeCell;
        }
    }
    if (!incremented) {
        temp->next = newNodeCell;
    }
}

p_cell unstackList(t_std_list* list) {

    // if (list->head == NULL) {
    //     p_cell cell;
    //     cell = (p_cell) malloc(sizeof(t_cell));
    //     cell->itirence = 0;
    //     cell->letter = ' ';
    //     cell->next = NULL;

    //     return cell;
    // }

    p_cell cell;
    cell = createNewCell(list->head->letter);
    cell->itirence = list->head->itirence;
    list->head = list->head->next;

    return cell;
}

p_node_cell unstackNodeList(t_std_node_list* list) {
    p_node_cell cell;
    cell = (p_node_cell) malloc(sizeof(t_node_cell));

    cell->node = list->head->node;
    cell->next = NULL;
    list->head = list->head->next;

    return cell;
}

p_node_cell createNewNodeCell(p_node leftNode, p_node rightNode) {
    
    p_node node;
    node = createNewNode(leftNode, rightNode);

    p_node_cell cell;
    cell = (p_node_cell) malloc(sizeof(t_node_cell));

    cell->node = node;
    cell->next = NULL;

    return cell;
}

p_node_cell createNodeCellWithTwoCell(p_cell leftCell, p_cell rightCell) {
    p_node leftNode, rightNode;
    leftNode = createEmptyNode();
    rightNode = createEmptyNode();

    leftNode->letterCell = copyCell(leftCell);
    leftNode->value = leftCell->itirence;
    rightNode->letterCell = copyCell(rightCell);
    rightNode->value = rightCell->itirence;

    p_node newNode;
    newNode = createNewNode(leftNode, rightNode);

    p_node_cell nodeCell;
    nodeCell = createEmptyNodeCell();
    nodeCell->node = newNode;

    return nodeCell;
}

p_node_cell createNodeCellWithOneCell(p_cell leftCell, p_node rightNode) {
    p_node leftNode;
    leftNode = createEmptyNode();

    leftNode->letterCell = copyCell(leftCell);
    leftNode->value = leftCell->itirence;

    p_node newNode;
    newNode = createNewNode(leftNode, rightNode);

    p_node_cell newNodeCell;
    newNodeCell = createEmptyNodeCell();
    newNodeCell->node = newNode;

    return newNodeCell;
}

p_cell copyCell(p_cell cell) {
    p_cell newCell;
    newCell = (p_cell) malloc(sizeof(t_cell));

    newCell->itirence = cell->itirence;
    newCell->letter = cell->letter;
    newCell->next = NULL;

    return newCell;
}

void displayNodeList(t_std_node_list list) {

    if (list.head == NULL) {
        printf("List Empty\n");
    }

    p_node_cell temp = list.head;

    while (temp != NULL) {
        printf("%d\n", temp->node->value);
        temp = temp->next;
    }

    return;
}

int getTreeHeight(p_node node) {
    if (node->letterCell != NULL) {
        return 0;
    }

    int rightHeight, leftHeight;
    rightHeight =  1 + getTreeHeight(node->right);
    leftHeight = 1 + getTreeHeight(node->left);

    if (rightHeight > leftHeight) {
        return rightHeight;
    } else {
        return leftHeight;
    }
}
