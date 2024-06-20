#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definir el número máximo de participantes
const int MAX_PARTICIPANTES = 100;

// Clave de administrador
const string CLAVE_ADMIN = "admin123";

// Estructura para almacenar la información de cada participante
struct Participante {
    string nombre;
    int partidas_ganadas;
    int partidas_perdidas;
};

// Declarar un arreglo estático para almacenar los participantes
Participante participantes[MAX_PARTICIPANTES];

// Contador para llevar el número actual de participantes
int numero_participantes = 0;

// Declaraciones de funciones
void mostrarMenuPrincipal();
void mostrarMenuAdministrador();
void mostrarMenuJugador();
void inscribirParticipante();
void listarParticipantes();
void mostrarAyuda();
void mostrarInstruccionesJuego();
void mostrarInformacionGrupo();
void guardarParticipantesEnArchivo();
void cargarParticipantesDesdeArchivo();
void iniciarJuegoTicTacToe();

void mostrarMenuPrincipal() {
    int opcion;
    do {
        // Mostrar las opciones del menú principal
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Menu Administrador\n";
        cout << "2. Menu Jugador\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Ejecutar la opción seleccionada por el usuario
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
    } while(opcion != 3); // Repetir hasta que el usuario elija salir
}
void mostrarMenuAdministrador() {
    string clave;
    cout << "Ingrese la clave de administrador: ";
    cin >> clave;

    if (clave != CLAVE_ADMIN) {
        cout << "Clave incorrecta.\n";
        return;
    }

    int opcion;
    do {
        // Mostrar las opciones del menú de administrador
        cout << "\n--- Menu Administrador ---\n";
        cout << "1. Listar Participantes\n";
        cout << "2. Generar Archivos con Informacion\n";
        cout << "3. Informacion del Grupo\n";
        cout << "4. Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Ejecutar la opción seleccionada por el administrador
        switch(opcion) {
            case 1:
                listarParticipantes();
                break;
            case 2:
                guardarParticipantesEnArchivo();
                cout << "Archivos generados exitosamente!\n";
                break;
            case 3:
                mostrarInformacionGrupo();
                break;
            case 4:
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 4); // Repetir hasta que el administrador elija regresar al menú principal
}
void mostrarMenuJugador() {
    int opcion;
    do {
        // Mostrar las opciones del menú de jugador
        cout << "\n--- Menu Jugador ---\n";
        cout << "1. Inscribir Participante\n";
        cout << "2. Empezar Juego Tic Tac Toe\n";
        cout << "3. Instrucciones del Juego\n";
        cout << "4. Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Ejecutar la opción seleccionada por el jugador
        switch(opcion) {
            case 1:
                inscribirParticipante();
                break;
            case 2:
                iniciarJuegoTicTacToe();
                break;
            case 3:
                mostrarInstruccionesJuego();
                break;
            case 4:
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 4); // Repetir hasta que el jugador elija regresar al menú principal
}
