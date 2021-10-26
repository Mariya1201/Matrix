#include "Header.h"



void List::addNode(int n, int index) { // Добавляет элемент в список
    Node* node = new Node;
    node->val = n;
    node->j = index;
    node->next = NULL; // новый узел в конце, поэтому NULL
    if (head == NULL) {
        head = node;
    }
    else {
        Node* current = head;
        while (current->next != NULL) { // ищем в цикле предшествующий последнему узел
            current = current->next;
        }
        current->next = node; // предшествующий указывает на последний
    }
}

void List::print() { // Печатает список на экран
    Node* node = head;
    for (int i = 0; i < size; i++) {

        if (node != NULL && node->j == i) {
            cout << node->val << " ";
            node = node->next;
        }
        else {
            cout << "0 ";
        }

    }
    /*while (node != NULL) {
        if (node->j == i) {
            cout << node->val << "-" << node->j << " ";
            node = node->next;
        }
        else {
            cout << "0 ";
        }
        i++;
    }*/
}

int List::get(int getJ) { // Получает значение элемента с ключом j = getJ
    Node* node = head;
    while (node != NULL) {
        if (node->j == getJ) {
            return node->val;
        }
        node = node->next;
    }
    return 0;
}

void List::set(int setJ, int newVal) { // Меняет значение элемента с ключом j = setJ на newVal
    Node* node = head;
    bool found = false; // Есть ли элемент на данной позиции
    int lastJ = -1; // j последнего элемента, после которого надо вставить новый
    while (node != NULL) {
        if (node->j == setJ) {
            node->val = newVal;
            found = true;
            break;
        }
        if (node->j < setJ) {
            if (node->next == NULL) {
                lastJ = node->j;
                break;
            }
            else if (node->next->j > setJ) {
                lastJ = node->j;
                break;
            }
        }
        node = node->next;
    }

    if (!found) { // Если элемент не был найден, значит там был "0". Создадим этот элемент
        Node* node = head;

        if (lastJ == -1) { // Если элемент вставляется в начало списка

            Node* n = new Node();
            n->val = newVal;
            n->j = setJ;
            n->next = head;

            head = n;

        }
        else {
            while (node != NULL) {
                if (node->j == lastJ) { // Находим позицию, куда надо вставить элемент
                    Node* n = new Node();
                    n->val = newVal;
                    n->j = setJ;
                    n->next = node->next;
                    node->next = n;

                    break;
                }
                else {
                    node = node->next;
                }
            }
        }

    }
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








void Matrix::input() { // Ввод элементов матрицы
    int data;
    for (int i = 0; i < m; i++) {
        cout << "Vvedite elementy stroki nomer " << (i+1) << ":" << endl;
        for (int j = 0; j < n; j++) {
            cin >> data;
            if (data != 0) {
                rows[i].addNode(data, j);
            }
        }
    }
}

void Matrix::print() { // Печать матрицы на экран
    for (int i = 0; i < m; i++) {
        rows[i].print();
        cout << endl;
    }
}

int Matrix::get(int getI, int getJ) { // Получает значение элемента [getI][getJ] матрицы
    return rows[getI].get(getJ);
}
void Matrix::set(int setI, int setJ, int newVal) { // Меняет значение элемента [getI][getJ] матрицы на newVal
    rows[setI].set(setJ, newVal);
}

void Matrix::rowRotate(int row1, int row2) { // Меняет строки местами
    int* q1, * q2;
    q1 = new int[n];
    q2 = new int[n];
    for (int i = 0; i < n; i++) {
        q1[i] = rows[row1].get(i);
        q2[i] = rows[row2].get(i);
    }


    for (int i = 0; i < n; i++) {
        rows[row1].set(i, q2[i]);
    }

    for (int i = 0; i < n; i++) {
        rows[row2].set(i, q1[i]);
    }
}

void Matrix::multiply(int row, int num) { // Умножает строку row матрицы на число num
    for (int i = 0; i < n; i++) {
        rows[row].set(i, rows[row].get(i) * num);
    }
}

List Matrix::getRow(int i) { // Получает строку матрицы
    return rows[i];
}

List Matrix::getColumn(int i) { // Получает столбец матрицы
    List col(m);
    for (int j = 0; j < m; j++) {
        col.addNode(j, rows[j].get(i));
    }
    return col;
}