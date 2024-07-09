char tablero[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

// Función para dibujar el tablero del juego Tic Tac Toe
void dibujarTablero(char tablero[3][3]) {
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
