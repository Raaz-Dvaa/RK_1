#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "string.h"
#include <map>

#ifndef RK_1_TASKS_RK1_H
#define RK_1_TASKS_RK1_H

class WorkWithFile {
private:
    char *dataOfFile = new char[2000];

    void readFromFile(const char *filename);

    void prepareTestFile(const char *filename);

public:
    WorkWithFile();

    ~WorkWithFile();

    void writeStatInfoToFile(const char *outFile);
};
void buildTree(int height);
char* convertDecToBin(int number);
char* convertBinToHex(const char* binNum);
void writeToFile(const char* filename, const char* strNum);
void randFill(float* a,int size);
std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount);
struct Node{
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};
class linkedList {
private :
    Node *Head;
    Node *Tail;
public :
    linkedList();

    ~linkedList();

    void push_back(int nameNode);

    void writeToFileFromTail();

    void writeToFileFromHead();

    void insert(int nameNode, int position);
};

#endif //RK_1_TASKS_RK1_H
