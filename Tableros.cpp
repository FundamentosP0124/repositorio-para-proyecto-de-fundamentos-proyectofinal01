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
