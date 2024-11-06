#include <iostream>
#include <vector>
#include <list>
#include <utility> // Para std::pair

class GrafoDirigido {
private:
    int V; // Número de vértices
    std::vector<std::list<std::pair<int, int>>> adj; // Lista de adyacencia con pesos (destino, peso)

public:
    // Constructor que inicializa el grafo con V vértices
    GrafoDirigido(int V) : V(V) {
        adj.resize(V);
    }

    // Método para agregar una arista dirigida con peso entre dos nodos
    void agregarArista(int u, int v, int peso) {
        adj[u].push_back({v, peso}); // Solo se agrega una dirección (u -> v)
    }

    // Método para mostrar el grafo
    void mostrarGrafo() const {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vértice " << i << " -> ";
            for (const auto& vecino : adj[i]) {
                std::cout << "(" << vecino.first << ", peso: " << vecino.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Crear un grafo dirigido con 5 nodos
    GrafoDirigido grafo(5);

    // Agregar aristas dirigidas con peso
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 3);
    grafo.agregarArista(1, 2, 1);
    grafo.agregarArista(1, 3, 2);
    grafo.agregarArista(2, 3, 4);
    grafo.agregarArista(3, 4, 2);
    grafo.agregarArista(4, 0, 5); // Ejemplo de una arista que regresa al inicio (ciclo)

    // Mostrar el grafo
    grafo.mostrarGrafo();

    return 0;
}
