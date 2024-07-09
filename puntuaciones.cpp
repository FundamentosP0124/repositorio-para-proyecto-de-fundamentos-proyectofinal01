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

