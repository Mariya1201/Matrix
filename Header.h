#pragma once
#include <iostream>
#include <math.h>

using namespace std;




struct Node {
    int val;
    int j; // Индекс положения элемента в строке массива
    Node* next;
};



class List {
private:
    Node* head;
    int size;
public:
    List() {
        head = NULL;
        size = 0;
    }
    List(int s) {
        head = NULL;
        size = s;
    }
    ~List() {
       // delete[] head;
        head = nullptr;
    }
    void addNode(int n, int j);
    void print();
    int get(int getJ);
    void set(int setJ, int newVal);
};



class Matrix {
private:
    List* rows; // Массив строк
    int m; // Количество строк в матрице
    int n; // Количество столбцов в матрице
public:
    Matrix(int ms, int ns) {
        m = ms;
        n = ns;
        rows = new List[m];
        for (int i = 0; i < m; i++) {
            List l(n);
            rows[i] = l;
        }
    }
    Matrix(int ms, int ns, List* mtrx) {
        m = ms;
        n = ns;
        rows = mtrx;
    }
    ~Matrix() {
        delete[] rows;
    }
    void input();
    void print();
    int get(int getI, int getJ);
    void set(int setI, int setJ, int newVal);
    void rowRotate(int row1, int row2);
    void multiply(int row, int num);
    List getRow(int i);
    List getColumn(int i);
};



int autotest();