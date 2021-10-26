#include "Header.h"





void menu() {
    cout << endl;
    cout << "______________________" << endl;
    cout << endl;
    cout << "1 - print matrix" << endl; // ���������� �������
    cout << "2 - get matrix element by index" << endl; // �������� ������� �������
    cout << "3 - set matrix element by index" << endl; // �������� ������� �������
    cout << "4 - rotate matrix rows" << endl; // �������� ������� ������ �������
    cout << "5 - multiply matrix row on number" << endl; // �������� ������ ������� �� �����
    cout << "6 - linear combination of matrix rows" << endl; // �������� �������� ���������� ����� �������
    cout << "7 - get row or column of matrix" << endl; // �������� ������� ��� ������ �������
    cout << "0 - exit" << endl; // �������� ���������
    cout << "______________________" << endl;
    cout << endl;
}








int main() {

    if (autotest() == 0) {

        int a = -1; // �������, ������� ���� ��������� � ��������
        int m, n;

        cout << "Vvedite chislo strok: m = ";
        cin >> m;

        cout << "Vvedite chislo stolbcov: n = ";
        cin >> n;

        Matrix matrix(m, n); // ������� ������� �� m �����

        matrix.input();

        cout << endl << "Vasha matrica:" << endl;
        matrix.print();
        cout << endl;


        while (a != 0) { // ����� ��������� ���� ������� ���� �� �������� ������� ������ - 0
            menu(); // ������� �� ����� ���������
            cout << "Your choose: ";
            cin >> a;

            if (a == 0) break;
            while (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7) {
                cout << "Incorrect! Your choose: ";
                cin >> a;
            }

            if (a == 1) { // ���������� ������� �� �����
                matrix.print();
            }

            if (a == 2) { // ������� ������� �� �������
                int getI, getJ;

                cout << "Pozicia elementa:" << endl << "i = ";
                cin >> getI;
                cout << "j = ";
                cin >> getJ;
                cout << endl;
                if ((getI-1) >= 0 && (getI-1) <= n && (getJ-1) >= 0 && (getJ-1) <= m) {
                    cout << "elem[" << getI << "][" << getJ << "] = " << matrix.get((getI-1), (getJ-1)) << endl;
                } else {
                    cout << "Incorrect indexes!!!" << endl;
                }
            }

            if (a == 3) { // �������� ������� �������
                int setI, setJ, newVal;

                cout << "Pozicia elementa:" << endl << "i = ";
                cin >> setI;
                cout << "j = ";
                cin >> setJ;
                cout << "Novoe znachenie = ";
                cin >> newVal;
                cout << endl;
                if ((setI-1) >= 0 && (setI-1) <= n && (setJ-1) >= 0 && (setJ-1) <= m) {
                    matrix.set(setI-1, setJ-1, newVal);
                    cout << "New matrix:" << endl;
                    matrix.print();
                }
                else {
                    cout << "Incorrect indexes!!!" << endl;
                }
            }


            if (a == 4) { // �������� ������� ������ �������
                int row1, row2;

                cout << "Stroka 1: ";
                cin >> row1;
                cout << "Stroka 2: ";
                cin >> row2;
                cout << endl;
                if (row1 >= 1 && row1 <= m && row2 >= 1 && row2 <= m) {
                    matrix.rowRotate(row1-1, row2-1);
                    cout << "New matrix:" << endl;
                    matrix.print();
                }
                else {
                    cout << "Incorrect row numbers!!!" << endl;
                }
            }


            if (a == 5) { // ������� ������ ������� �� �����
                int row, num;

                cout << "Stroka: ";
                cin >> row;
                cout << "Chislo: ";
                cin >> num;
                cout << endl;
                if (row >= 1 && row <= m) {
                    matrix.multiply(row-1, num);
                    cout << "New matrix:" << endl;
                    matrix.print();
                }
                else {
                    cout << "Incorrect row number!!!" << endl;
                }
            }


            if (a == 6) { // ������� �������� ���������� ����� �������
                int rowA, rowB, k1, k2;

                cout << "Stroka 1: ";
                cin >> rowA;
                cout << "Koefficient dlya stroki 1: ";
                cin >> k1;
                cout << "Stroka 2: ";
                cin >> rowB;
                cout << "Koefficient dlya stroki 2: ";
                cin >> k2;
                cout << endl;
                if (rowA >= 1 && rowA <= m && rowB >= 1 && rowB <= m) {

                    for (int j = 0; j < n; j++) {
                        cout << (matrix.getRow(rowA-1).get(j) * k1 + matrix.getRow(rowB-1).get(j) * k2) << " ";
                    }


                }
                else {
                    cout << "Incorrect row number!!!" << endl;
                }
            }


            if (a == 7) { // ������� ������� ��� ������ �������
                int type, index;

                cout << "Poluchit stolbec - 1 " << endl << "Poluchit stroku - 2 " << endl << "Vyberite:";
                cin >> type;
                cout << "index = ";
                cin >> index;
                cout << endl;
                if (index >= 0) {

                    if (type == 1 && index <= n) {
                      //  matrix.getColumn(index).print();

                        for (int j = 0; j < m; j++) {
                            cout << matrix.getRow(j).get(index-1) <<"\n";
                        }

                    }

                    if (type == 2 && index <= m) {
                        matrix.getRow(index-1).print();
                    }


                }
                else {
                    cout << "Incorrect row number!!!" << endl;
                }
            }



        }

    }
    else {
        cout << endl << "Something went wrong!" << endl;
    }

    return 0;
}
