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
                   >> participantes[numero >> participantes[numero_participantes].partidas_perdidas) {
        numero_participantes++;
        if (numero_participantes >= MAX_PARTICIPANTES) {
            break;
        }
    }
    archivo.close();
}
