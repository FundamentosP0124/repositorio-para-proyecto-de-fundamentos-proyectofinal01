void inicializarPuntuaciones() {
// Inicializar las puntuaciones de los participantes
    for (int i = 0; i < numero_participantes; ++i) {
        participantes[i].partidas_ganadas = 0;
        participantes[i].partidas_perdidas = 0;
    }
    guardarPuntuacionesEnArchivo();
}
