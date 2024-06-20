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

void inscribirParticipante() {
    if (numero_participantes >= MAX_PARTICIPANTES) {
        // Verificar si se ha alcanzado el número máximo de participantes
        cout << "No se pueden inscribir mas participantes.\n";
        return;
    }
    
    Participante nuevo;
    // Solicitar el nombre del nuevo participante
    cout << "Ingrese el nombre del participante: ";
    cin >> nuevo.nombre;
    nuevo.partidas_ganadas = 0;
    nuevo.partidas_perdidas = 0;
    // Añadir el nuevo participante al arreglo
    participantes[numero_participantes] = nuevo;
    numero_participantes++;
    cout << "Participante inscrito exitosamente!\n";
}

void listarParticipantes() {
    // Mostrar la lista de participantes inscritos
    cout << "\n--- Lista de Participantes ---\n";
    for (int i = 0; i < numero_participantes; ++i) {
        cout << i + 1 << ". " << participantes[i].nombre << " - Ganadas: " << participantes[i].partidas_ganadas << ", Perdidas: " << participantes[i].partidas_perdidas << "\n";
    }
}

void guardarParticipantesEnArchivo() {
    // Guardar la información de los participantes en un archivo
    ofstream archivo("participantes.txt");
    for (int i = 0; i < numero_participantes; ++i) {
        archivo << participantes[i].nombre << " " << participantes[i].partidas_ganadas << " " << participantes[i].partidas_perdidas << "\n";
    }
    archivo.close();
}

void cargarParticipantesDesdeArchivo() {
    // Cargar la información de los participantes desde un archivo
    ifstream archivo("participantes.txt");
    if (!archivo.is_open()) {
        return; // No hace nada si no existe el archivo
    }
    
    numero_participantes = 0;
    // Leer los datos del archivo y añadirlos al arreglo
    while (archivo >> participantes[numero_participantes].nombre 
                   >> participantes[numero_participantes].partidas_ganadas 
                   >> participantes[numero_participantes].partidas_perdidas) {
        numero_participantes++;
        if (numero_participantes >= MAX_PARTICIPANTES) {
            break;
        }
    }
    archivo.close();
}

void mostrarInstruccionesJuego() {
    // Mostrar las instrucciones del juego Tic Tac Toe
    cout << "\n--- Instrucciones del Juego Tic Tac Toe ---\n";
    cout << "1. El juego es para dos jugadores.\n";
    cout << "2. El tablero es una cuadrícula de 3x3.\n";
    cout << "3. Un jugador usa 'X' y el otro usa 'O'.\n";
    cout << "4. Los jugadores se turnan para colocar sus marcas en una celda vacía.\n";
    cout << "5. El primer jugador en alinear tres de sus marcas gana.\n";
    cout << "6. Si todas las celdas están llenas y ningún jugador ha alineado tres marcas, el juego es un empate.\n";
}
