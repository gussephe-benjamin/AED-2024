#include <iostream>
#include <vector>
#include <list>

class GrafoDirigido {
private:
    int V; // Número de vértices
    std::vector<std::list<int>> adj; // Lista de adyacencia (solo destino)

public:
    // Constructor que inicializa el grafo con V vértices
    GrafoDirigido(int V) : V(V) {
        adj.resize(V);
    }

    // Método para agregar una arista dirigida entre dos nodos
    void agregarArista(int u, int v) {
        adj[u].push_back(v); // Solo se agrega una dirección (u -> v)
    }

    // Método para mostrar el grafo
    void mostrarGrafo() const {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertice " << i << " -> ";
            for (const auto& vecino : adj[i]) {
                std::cout << vecino << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Crear un grafo dirigido con 5 nodos
    GrafoDirigido grafo(5);

    // Agregar aristas dirigidas
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);
    grafo.agregarArista(4, 0); // Ejemplo de una arista que regresa al inicio (ciclo)

    // Mostrar el grafo
    grafo.mostrarGrafo();

    return 0;
}
