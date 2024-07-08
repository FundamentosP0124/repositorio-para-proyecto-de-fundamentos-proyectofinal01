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
