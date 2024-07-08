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
