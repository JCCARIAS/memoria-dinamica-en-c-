#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Calificaciones {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Calificaciones(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Calificaciones() {
        delete[] arr;
    }

    void add(int x) {
        if (isFull()) {
            cout << "No se pueden agregar más calificaciones. Cola llena.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    int remove() {
        if (isEmpty()) {
            cout << "No hay calificaciones para mostrar. Cola vacía.\n";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity;
        count--;
        return x;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void display() const {
        int f = front;
        for (int i = 0; i < count; i++) {
            cout << arr[f] << endl;
            f = (f + 1) % capacity;
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
        calificaciones.add(calif);
    }
}

void mostrarNotas(Calificaciones &calificaciones) {
    cout << "\n\nMostrando calificaciones del usuario:\n";
    while (!calificaciones.isEmpty()) {
        cout << calificaciones.remove() << endl;
    }
}
