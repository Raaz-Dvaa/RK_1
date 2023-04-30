#include "tasks_rk1.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <vector>
#include "string.h"
#include <map>

int Node::countNodes = 0;

void WorkWithFile::readFromFile(const char *filename) {
    FILE *res = fopen(filename, "r");
    if(res) {
        while (fgets(dataOfFile, 2000, res) != NULL){
        }
    }
    fclose(res);
}
void WorkWithFile::prepareTestFile(const char *filename) {
    FILE* res = fopen(filename, "w");
    char vvod[2000] = "ethsrthaetrjwrthnsr6jwrja6j56rytijw5!!!,,,...okkfbrhg";
    fprintf(res, "%s", vvod);
    fclose(res);
}
WorkWithFile::WorkWithFile(const char *fileName) {
    prepareTestFile(fileName);
    readFromFile(fileName);
}

WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
void WorkWithFile::writeStatInfoToFile(const char *outFile) {
    FILE *res = fopen(outFile, "w");
    int count[100];
    for (int i = 0; i<91; i++){
        count[i] = 0;
    }
    for(int i = 0; i < strlen(dataOfFile); i++) {
        count[int(dataOfFile[i])-33]++;
    }
    for(int i = 0; i < 91;i++){
        fprintf(res, "%c\t%i\n", char(i+33), count[i]);
    }
    fclose(res);
}
void buildTree(int height){
    int z = 1;
    while (height != 0){
        int a = height - 1;
        int b = height - 1;
        while (a != 0){
            std::cout << " ";
            a--;
        }
        for (int i = 0; i < z; i++){
            std::cout << "*";
        }
        z += 2;
        while (b != 0) {
            std::cout << " ";
            b--;
        }
        height--;
        std::cout << std::endl;
    }
}
char* convertDecToBin(int number){
    char* out = new char [33];
    for (int i = 0; i < 33; i++) {
        out[i] = '0';
    }
    out[32] = '\0';
    if(number >= 0) {
        for (int i = 31; i >= 0; i--) {
            out[i] = number % 2 + '0';
            number /= 2;
        }
    }
    if(number < 0){
        int number228 = abs(number);
        for (int i = 31; i >= 0; i--) {
            out[i] = number228 % 2 + '0';
            number228 /= 2;
        }
        for (int i = strlen(out); i >= 0; i--) {
            if(out[i] == '0'){
                out[i] = '1';
            }
            else {
                if (out[i] == '1') {
                    out[i] = '0';
                }
            }
        }
        for (int i = strlen(out) - 1; i >= 0; i--) {
            if(out[i] == '1'){
                out[i] = '0';
            }
            else {
                if (out[i] == '0') {
                    out[i] = '1';
                    break;
                }
            }
        }
    }
    return out;
}
char* convertBinToHex(const char* binNum) {

    std::map<std::string, int> nums;
    nums["0000"] = '0';
    nums["0001"] = '1';
    nums["0010"] = '2';
    nums["0011"] = '3';
    nums["0100"] = '4';
    nums["0101"] = '5';
    nums["0110"] = '6';
    nums["0111"] = '7';
    nums["1000"] = '8';
    nums["1001"] = '9';
    nums["1010"] = 'A';
    nums["1011"] = 'B';
    nums["1100"] = 'C';
    nums["1101"] = 'D';
    nums["1110"] = 'E';
    nums["1111"] = 'F';

    std::string strBin;
    for (int i = 0; i < strlen(binNum); i++) {
        strBin = strBin +binNum[i];
    }
    int c = strlen(binNum);
    for (int i = 0; i < (4 - (strlen(binNum) %4) ); i++){
        strBin = '0' + strBin;
        c++;
    }
    std::string strHex;
    int c1 = 0;
    while (c!=c1){
        strHex += nums[strBin.substr(c1, 4)];
        c1+=4;
    }
    char* out = new char[c1];
    strcpy(out, strHex.c_str());
    return out;
}
void writeToFile(const char* filename, const char* strNum){
    FILE* res = fopen(filename, "w");
    fprintf(res, "%s", strNum);
    fclose(res);
}
void randFill(float* a,int size){
    srand(time(NULL));
    for(int i = 0; i<size; i++){
        int x;
        a[i] = std::rand();
    }
}
std::vector<std::pair<int, float>> averStr2DArray(float* ar, int colCount, int rowCount){
    int size = colCount * rowCount;
    randFill(ar, size);
    std::vector<std::pair<int, float>> out;
    for (int i = 0; i < rowCount; i++){
        float sum = 0;
        for (int j = 0; j < colCount; j++){
            sum+= ar[i*colCount + j];
        }
        sum = sum/colCount;
        out.emplace_back(i+1, sum);
    }
    return out;
}
linkedList::linkedList() {
    Head = nullptr;
    Tail = nullptr;
}
linkedList::~linkedList() {
    while(Head != nullptr) {
        Node *k = Head;
        Head = Head->next;
        delete k;
    }
}

void linkedList::push_back(int nameNode) {
    Node* New = new Node;
    if (Head == nullptr){
        New->nameNode = nameNode + 1;
        New->next = nullptr;
        New->prev = nullptr;
        Head = Tail = New;
    }
    else{
        New->nameNode = nameNode + 1;
        Tail->next = New;
        New->prev = Tail;
        New->next = nullptr;
        Tail = New;
    }
    Node::countNodes++;
}

void linkedList::writeToFileFromTail() {
    FILE* res = fopen("task6_Tail.txt", "w");
    Node* Cursor = Tail;
    while (Cursor != nullptr) {
        fprintf(res, "%i\n", Cursor->nameNode);
        Cursor = Cursor->prev;
    }
    fclose(res);
}
void linkedList::writeToFileFromHead() {
    FILE* res = fopen("task6_Head.txt", "w");
    Node* Cursor = Head;
    while (Cursor != nullptr) {
        fprintf(res, "%i\n", Cursor->nameNode);
        Cursor = Cursor->next;
    }
    fclose(res);
}
void linkedList::insert(int nameNode, int position) {
    Node* New = new Node;
    New->nameNode = nameNode;
    if(position == 0){
        Node* Temp = Head;
        New->next = Head;
        Head = New;
        New->prev = Temp;
        Head->prev = nullptr;
        Node* c = Head;
        while (c->next != nullptr){
            c=c->next;
        }
        Tail = c;
    }
    if(position > 0){
        Node* c = Head;
        for (int i = 0; i < position-1; i++){
            c = c->next;
        }
        New->next = c->next;
        New->prev = c;
        c->next = New;
        Node* count=Head;
        while (count->next!= nullptr){
            count=count->next;
        }
        Tail=count;
    }
    Node::countNodes++;
}
