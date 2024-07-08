void iniciarJuegoTicTacToe() {
    // Tablero del juego Tic Tac Toe
    char tablero[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char jugadorActual = 'X'; // El primer jugador usa 'X'
    int movimiento;
    bool juegoTerminado = false;
    string nombreJugador1, nombreJugador2;
