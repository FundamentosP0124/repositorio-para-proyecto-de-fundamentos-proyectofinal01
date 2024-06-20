#include <iostream>
using namespace std;

// Declaraciones de funciones
void mostrarMenuPrincipal();
void mostrarMenuAdministrador();
void mostrarMenuJugador();
void mostrarInformacionGrupo();

void mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Menu Administrador\n";
        cout << "2. Menu Jugador\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarMenuAdministrador();
                break;
            case 2:
                mostrarMenuJugador();
                break;
            case 3:
                cout << "Gracias por jugar Equis-Cero!\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 3);
}

void mostrarMenuAdministrador() {
    string clave;
    cout << "Ingrese la clave de administrador: ";
    cin >> clave;

    if (clave != "admin123") {
        cout << "Clave incorrecta.\n";
        return;
    }

    int opcion;
    do {
        cout << "\n--- Menu Administrador ---\n";
        cout << "1. Informacion del Grupo\n";
        cout << "2. Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarInformacionGrupo();
                break;
            case 2:
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 2);
}

void mostrarMenuJugador() {
    int opcion;
    do {
        cout << "\n--- Menu Jugador ---\n";
        cout << "1. Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 1);
}

void mostrarInformacionGrupo() {
    cout << "\n--- Informacion del Grupo ---\n";
    cout << "Miembro 1: Nombre1 - Carnet1\n";
    cout << "Miembro 2: Nombre2 - Carnet2\n";
}

// Menu Principal
int main() {
    mostrarMenuPrincipal();
    return 0;
}
