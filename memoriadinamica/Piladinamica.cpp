
  #include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Calificaciones {
private:
    int *arr;
    int top;
    int capacity;

public:
    Calificaciones(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Calificaciones() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << "No se pueden agregar más calificaciones. Pila llena.\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "No hay calificaciones para mostrar. Pila vacía.\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    void display() const {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }
};

void pedirNotas(Calificaciones &calificaciones, int numCalif);
void mostrarNotas(Calificaciones &calificaciones);

int main() {
    int numCalif;
    cout << "Digite el número de calificaciones: ";
    cin >> numCalif;

    Calificaciones calificaciones(numCalif);

    pedirNotas(calificaciones, numCalif);
    mostrarNotas(calificaciones);

    getch();
    return 0;
}

void pedirNotas(Calificaciones &calificaciones, int numCalif) {
    for (int i = 0; i < numCalif; i++) {
        int calif;
        cout << "Ingrese la calificación: ";
        cin >> calif;
        calificaciones.push(calif);
    }
}

void mostrarNotas(Calificaciones &calificaciones) {
    cout << "\n\nMostrando calificaciones del usuario:\n";
    while (!calificaciones.isEmpty()) {
        cout << calificaciones.pop() << endl;
    }
}
