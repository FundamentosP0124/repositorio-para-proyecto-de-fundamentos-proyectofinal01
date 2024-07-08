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
