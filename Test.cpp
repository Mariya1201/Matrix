#include"Header.h"

int autotest1() {
    bool boolean = false;
    int m = 2, n = 2;
    List* rows;
    rows = new List[m];
    for (int i = 0; i < m; i++) {
        List l(n);
        for (int j = 0; j < n; j++) {
            l.addNode(i, j);
        }
        rows[i] = l;
    }
    Matrix matrix(m, n, rows);
    
    if (matrix.get(0, 1) != 0) {
        boolean = true;
    }

    matrix.set(0, 1, 2);
    if (matrix.get(0, 1) != 2) {
        boolean = true;
    }


    matrix.rowRotate(0, 1);
    if (matrix.get(0, 0) != 1 || matrix.get(0, 1) != 1 || 
        matrix.get(1, 0) != 0 || matrix.get(1, 1) != 2) {
        boolean = true;
    }


    matrix.multiply(1, 2);
    if (matrix.get(1, 0) != 0 || matrix.get(1, 1) != 4) {
        boolean = true;
    }

    

    return boolean;
}

int autotest2() {
    bool boolean = false;
    int m = 2, n = 3;
    List* rows;
    rows = new List[m];
    for (int i = 0; i < m; i++) {
        List l(n);
        for (int j = 0; j < n; j++) {
            l.addNode(j+1, j);
        }
        rows[i] = l;
    }
    Matrix matrix(m, n, rows);
    //matrix.print();

    if (matrix.get(1, 2) != 3) {
        boolean = true;
    }

    matrix.set(1, 2, 7);
    if (matrix.get(1, 2) != 7) {
        boolean = true;
    }


    matrix.rowRotate(0, 1);
    if (matrix.get(0, 0) != 1 || matrix.get(0, 1) != 2 || matrix.get(0, 2) != 7 ||
        matrix.get(1, 0) != 1 || matrix.get(1, 1) != 2 || matrix.get(1, 2) != 3) {
        boolean = true;
    }


    matrix.multiply(0, 0);
    if (matrix.get(0, 0) != 0 || matrix.get(0, 1) != 0 || matrix.get(0, 2) != 0) {
        boolean = true;
    }

    
    return boolean;
}

int autotest3() {
    bool boolean = false;
    int m = 2, n = 2;
    List* rows;
    rows = new List[m];
    for (int i = 0; i < m; i++) {
        List l(n);
        for (int j = 0; j < n; j++) {
            l.addNode(28, j);
        }
        rows[i] = l;
    }
    Matrix matrix(m, n, rows);
    //matrix.print();

    if (matrix.get(0, 1) != 28) {
        boolean = true;
    }

    matrix.set(0, 1, 33);
    if (matrix.get(0, 1) != 33) {
        boolean = true;
    }


    matrix.rowRotate(0, 1);
    if (matrix.get(0, 0) != 28 || matrix.get(0, 1) != 28 ||
        matrix.get(1, 0) != 28 || matrix.get(1, 1) != 33) {
        boolean = true;
    }


    matrix.multiply(1, 33);
    if (matrix.get(1, 0) != 924 || matrix.get(1, 1) != 1089) {
        boolean = true;
    }

   

    return boolean;
}

int autotest() {
    if (autotest1() == 0 && autotest2() == 0 && autotest3() == 0) {
        printf("Autotests passed!\n\n");
        return 0;
    }
    else {
        printf("Autotests is not passed!\n\n");
        return 1;
    }
}