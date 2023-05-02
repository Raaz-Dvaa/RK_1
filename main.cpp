#include "tasks_rk1.h"
#include <iostream>
#include <string>
#include <vector>



void task_1(){
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_sourceFile_task1.txt");
}


void task_2() {
    writeToFile("result_task2.txt", convertDecToBin(-60));
}


void task_3(){
    writeToFile("result_task3.txt", convertBinToHex("11100100"));
}


void task_4(){
    buildTree(6);
}


void task_5(){
    float* arr = new float[20];
    randFill(arr, 20);
    std::vector<std::pair<int, float>> out = averStr2DArray(arr, 5, 4);
    FILE* pFile = fopen("result_task5.txt", "w");
    for (auto i: out) {
        fprintf(pFile, "%d\t%c\t%f\n", i.first, ':', i.second);
    }
    fclose(pFile);
}

void task6_7(){
    linkedList out;
    for(int i = 0; i < 10; i++){
        out.push_back(i);
    }
    out.writeToFileFromHead();
    out.insert(228, 10);
    out.writeToFileFromTail();
}
void test_egor(){
    linkedList egor;
    egor.insert(228,0);
    egor.insert(33,1);
    egor.writeToFileFromHead();
}

int main() {


    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task6_7();
    test_egor();


    return 0;
}
