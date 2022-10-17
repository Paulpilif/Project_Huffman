#include <time.h>
#include "fileConverter.h"
#include "huffmanDico.h"
#include "compression.h"

int main(int argc, char* argv[]) {
    double timeSpent = 0.0;
    clock_t begin = clock();

    printf("Number of characters in 'ChapterI.txt' : %d\n", numberCharacterInFile("ChapterI.txt"));
    printf("Number of characters in 'Output.txt' : %d\n", numberCharacterInFile("Output.txt"));

    t_std_list list;
    list = createDictionnaryOfOccurence("ChapterI.txt");
    list = sortByOccurence(list);

    t_tree tree;
    t_std_node_list nodeList;
    nodeList = createEmptyNodeList();
    tree = createHuffmanTree(&list, &nodeList);

    createHuffmanDico(tree);

    compressFile("ChapterI.txt");
    decompressFile();

    printf("Number of characters in 'compression.txt' : %d\n", numberCharacterInFile("compression.txt"));
    printf("Number of characters in 'decompression.txt' : %d\n", numberCharacterInFile("decompression.txt"));

    timeSpent += (double)(clock() - begin) / CLOCKS_PER_SEC;
    printf("The time spent of the programm is : %f\n", timeSpent);
    return 0;
}
