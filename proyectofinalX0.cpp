#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

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
void iniciarJuegoTicTacToeVsPC();
void dibujarTablero(char tablero[3][3]);
bool verificarGanador(char tablero[3][3], char jugador);
bool tableroLleno(char tablero[3][3]);
void inicializarPuntuaciones();
void actualizarPuntuaciones(const string& ganador, const string& perdedor);
void mostrarPuntuaciones();
void guardarPuntuacionesEnArchivo();
void cargarPuntuacionesDesdeArchivo();
void mostrarInstruccionesSubmenus();

void mostrarInstruccionesSubmenus() {
    // Mostrar las instrucciones de uso de los submenús
    cout << "\n--- Instrucciones de Uso de los Submenus ---\n";
    cout << "1. Menu Administrador:\n";
    cout << "   - Listar Participantes: Muestra la lista de todos los participantes inscritos.\n";
    cout << "   - Generar Archivos con Informacion: Guarda la información de los participantes en un archivo.\n";
    cout << "   - Informacion del Grupo: Muestra información sobre los desarrolladores del programa.\n";
    cout << "   - Regresar al Menu Principal: Vuelve al menú principal.\n";
    cout << "\n";
    cout << "2. Menu Jugador:\n";
    cout << "   - Inscribir Participante: Permite inscribir un nuevo participante en el juego y guardar sus datos.\n";
    cout << "   - Empezar Juego Tic Tac Toe (Jugador vs Jugador): Inicia una partida de Tic Tac Toe entre dos jugadores. Se pedirá el nombre del jugador para buscarlo en los archivos y actualizar la información que se tenga del jugador con ese nombre. De lo contrario, no se actualizará ningún dato.\n";
    cout << "   - Empezar Juego Tic Tac Toe (Jugador vs PC): Inicia una partida de Tic Tac Toe contra la computadora. Se pedirá el nombre del jugador para buscarlo en los archivos y actualizar la información que se tenga del jugador con ese nombre. De lo contrario, no se actualizará ningún dato.\n";
    cout << "   - Instrucciones del Juego: Muestra las reglas y cómo jugar Tic Tac Toe.\n";
    cout << "   - Mostrar Puntuaciones: Muestra las puntuaciones actuales de los participantes.\n";
    cout << "   - Regresar al Menu Principal: Vuelve al menú principal.\n";
}

void mostrarMenuPrincipal() {
    int opcion;
    do {
        // Mostrar las opciones del menú principal
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Menu Administrador\n";
        cout << "2. Menu Jugador\n";
        cout << "3. Instrucciones de uso\n"; // Nueva opción
        cout << "4. Salir\n";
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
                mostrarInstruccionesSubmenus(); // Mostrar instrucciones
                break;
            case 4:
                cout << "Gracias por jugar Equis-Cero!\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 4); // Repetir hasta que el usuario elija salir
}


void mostrarMenuAdministrador() {
    string clave;
    cout << "Ingrese la clave de administrador: ";
    cin >> clave;

    // Verificar la clave de administrador
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
        cout << "2. Empezar Juego Tic Tac Toe (Jugador vs Jugador)\n";
        cout << "3. Empezar Juego Tic Tac Toe (Jugador vs PC)\n";
        cout << "4. Instrucciones del Juego\n";
        cout << "5. Mostrar Puntuaciones\n";
        cout << "6. Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Ejecutar la opción seleccionada por el jugador
        switch(opcion) {
            case 1:
                inscribirParticipante();
                inicializarPuntuaciones();
                break;
            case 2:
                iniciarJuegoTicTacToe();
                break;
            case 3:
                iniciarJuegoTicTacToeVsPC();
                break;
            case 4:
                mostrarInstruccionesJuego();
                break;
            case 5:
                mostrarPuntuaciones();
                break;
            case 6:
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 6); // Repetir hasta que el jugador elija regresar al menú principal
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

void mostrarAyuda() {
    // Mostrar las instrucciones del juego y del menú
    cout << "\n--- Ayuda ---\n";
    cout << "1. Inscribir Participante: Permite agregar un nuevo jugador.\n";
    cout << "2. Listar Participantes: Muestra la lista de jugadores inscritos.\n";
    cout << "3. Ayuda: Muestra este mensaje de ayuda.\n";
    cout << "4. Informacion del Grupo: Muestra los datos de los desarrolladores.\n";
    cout << "5. Salir: Guarda los datos y sale del juego.\n";
}

void mostrarInstruccionesJuego() {
    // Mostrar las instrucciones del juego Tic Tac Toe
    cout << "\n--- Instrucciones del Juego Tic Tac Toe ---\n";
    cout << "1. El juego es para dos jugadores.\n";
    cout << "2. El tablero es una cuadrícula de 3x3.\n";
    cout << "3. Un jugador usa 'X' y el otro usa 'O'.\n";
    cout << "4. Los jugadores se turnan para colocar sus marcas en una celda vacía.\n";
    cout << "5. El primer jugador en alinear tres de sus marcas horizontalmente, verticalmente o diagonalmente gana.\n";
    cout << "6. Si todas las celdas están llenas y ningún jugador ha alineado tres marcas, el juego es un empate.\n";
}

void mostrarInformacionGrupo() {
    // Mostrar la información de los miembros del grupo
    cout << "\n--- Informacion del Grupo ---\n";
    cout << "Yuliana Sarai Argueta Deras - 00209223\n";
    cout << "Nombre - Carnet\n";
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

void iniciarJuegoTicTacToe() {
    // Tablero del juego Tic Tac Toe
    char tablero[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char jugadorActual = 'X'; // El primer jugador usa 'X'
    int movimiento;
    bool juegoTerminado = false;
    string nombreJugador1, nombreJugador2;

    // Solicitar los nombres de los jugadores
    cout << "Ingrese el nombre del Jugador 1 (X): ";
    cin >> nombreJugador1;
    cout << "Ingrese el nombre del Jugador 2 (O): ";
    cin >> nombreJugador2;

    // Loop principal del juego
    while (!juegoTerminado) {
        // Dibujar el tablero
        dibujarTablero(tablero);

        // Pedir al jugador que haga un movimiento
        cout << "Turno del jugador " << jugadorActual << ". Ingrese el numero de la celda: ";
        cin >> movimiento;

        // Verificar si el movimiento es válido
        if (movimiento < 1 || movimiento > 9) {
            cout << "Movimiento invalido. Intente nuevamente.\n";
            continue;
        }

        // Convertir el movimiento en coordenadas del tablero
        int fila = (movimiento - 1) / 3;
        int columna = (movimiento - 1) % 3;

        // Verificar si la celda está vacía
        if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O') {
            // Realizar el movimiento
            tablero[fila][columna] = jugadorActual;

            // Verificar si hay un ganador
            if (verificarGanador(tablero, jugadorActual)) {
                dibujarTablero(tablero);
                cout << "El jugador " << jugadorActual << " ha ganado!\n";
                juegoTerminado = true;
                // Actualizar las puntuaciones
                if (jugadorActual == 'X') {
                    actualizarPuntuaciones(nombreJugador1, nombreJugador2);
                } else {
                    actualizarPuntuaciones(nombreJugador2, nombreJugador1);
                }
            }
            // Verificar si el tablero está lleno
            else if (tableroLleno(tablero)) {
                dibujarTablero(tablero);
                cout << "El juego es un empate!\n";
                juegoTerminado = true;
            } else {
                // Cambiar de jugador
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        } else {
            // Si la celda no está vacía, pedir otro movimiento
            cout << "Celda ocupada. Intente nuevamente.\n";
        }
    }
}
void iniciarJuegoTicTacToeVsPC() {
    // Tablero del juego Tic Tac Toe
    char tablero[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char jugadorActual = 'X'; // El primer jugador usa 'X'
    int movimiento;
    bool juegoTerminado = false;
    string nombreJugador;

  // Solicitar el nombre del jugador
    cout << "Ingrese el nombre del Jugador (X): ";
    cin >> nombreJugador;

    // Loop principal del juego
    while (!juegoTerminado) {
        // Dibujar el tablero
        dibujarTablero(tablero);

        if (jugadorActual == 'X') {
            // Turno del jugador
            cout << "Turno del jugador " << jugadorActual << ". Ingrese el numero de la celda: ";
            cin >> movimiento;
        } else {
            // Turno de la PC
            srand(time(0));
            do {
                movimiento = (rand() % 9) + 1;
            } while (tablero[(movimiento - 1) / 3][(movimiento - 1) % 3] == 'X' || tablero[(movimiento - 1) / 3][(movimiento - 1) % 3] == 'O');
            cout << "Turno de la PC (O). Movimiento: " << movimiento << endl;
        }

        // Verificar si el movimiento es válido
        if (movimiento < 1 || movimiento > 9) {
            if (jugadorActual == 'X') {
                cout << "Movimiento invalido. Intente nuevamente.\n";
            }
            continue;
        }

        // Convertir el movimiento en coordenadas del tablero
        int fila = (movimiento - 1) / 3;
        int columna = (movimiento - 1) % 3;

        // Verificar si la celda está vacía
        if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O') {
            // Realizar el movimiento
            tablero[fila][columna] = jugadorActual;

            // Verificar si hay un ganador
            if (verificarGanador(tablero, jugadorActual)) {
                dibujarTablero(tablero);
                cout << "El jugador " << jugadorActual << " ha ganado!\n";
                juegoTerminado = true;
                // Actualizar las puntuaciones
                if (jugadorActual == 'X') {
                    actualizarPuntuaciones(nombreJugador, "PC");
                } else {
                    actualizarPuntuaciones("PC", nombreJugador);
                }
            }
            // Verificar si el tablero está lleno
            else if (tableroLleno(tablero)) {
                dibujarTablero(tablero);
                cout << "El juego es un empate!\n";
                juegoTerminado = true;
            } else {
                // Cambiar de jugador
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        } else {
            // Si la celda no está vacía, pedir otro movimiento
            if (jugadorActual == 'X') {
                cout << "Celda ocupada. Intente nuevamente.\n";
            }
        }
    }
}

void dibujarTablero(char tablero[3][3]) {
    // Función para dibujar el tablero del juego Tic Tac Toe
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << tablero[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool verificarGanador(char tablero[3][3], char jugador) {
    // Función para verificar si un jugador ha ganado
    for (int i = 0; i < 3; ++i) {
        // Verificar filas
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        // Verificar columnas
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    // Verificar diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;

    return false; // Ningún jugador ha ganado
}

bool tableroLleno(char tablero[3][3]) {
    // Función para verificar si el tablero está lleno
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void inicializarPuntuaciones() {
    // Inicializar las puntuaciones de los participantes
    for (int i = 0; i < numero_participantes; ++i) {
        participantes[i].partidas_ganadas = 0;
        participantes[i].partidas_perdidas = 0;
    }
    guardarPuntuacionesEnArchivo();
}

void actualizarPuntuaciones(const string& ganador, const string& perdedor) {
    // Actualizar las puntuaciones de los participantes
    for (int i = 0; i < numero_participantes; ++i) {
        if (participantes[i].nombre == ganador) {
            participantes[i].partidas_ganadas++;
        } else if (participantes[i].nombre == perdedor) {
            participantes[i].partidas_perdidas++;
        }
    }
    guardarPuntuacionesEnArchivo();
}

void mostrarPuntuaciones() {
    // Mostrar las puntuaciones de los participantes
    cout << "\n--- Puntuaciones ---\n";
    for (int i = 0; i < numero_participantes; ++i) {
        cout << participantes[i].nombre << " - Ganadas: " << participantes[i].partidas_ganadas << ", Perdidas: " << participantes[i].partidas_perdidas << "\n";
    }
}

void guardarPuntuacionesEnArchivo() {
    // Guardar las puntuaciones de los participantes en un archivo
    ofstream archivo("puntuaciones.txt");
    for (int i = 0; i < numero_participantes; ++i) {
        archivo << participantes[i].nombre << " " << participantes[i].partidas_ganadas << " " << participantes[i].partidas_perdidas << "\n";
    }
    archivo.close();
}

void cargarPuntuacionesDesdeArchivo() {
    // Cargar las puntuaciones de los participantes desde un archivo
    ifstream archivo("puntuaciones.txt");
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

int main() {
    // Cargar los datos desde los archivos al iniciar el programa
    cargarParticipantesDesdeArchivo();
    cargarPuntuacionesDesdeArchivo();
    // Mostrar el menú principal
    mostrarMenuPrincipal();
    // Guardar los datos en los archivos al salir del programa
    guardarParticipantesEnArchivo();
    guardarPuntuacionesEnArchivo();
    return 0;
}
