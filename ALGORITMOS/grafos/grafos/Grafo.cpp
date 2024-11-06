#include <iostream>
#include <vector>
#include <list>

class Grafo {
private:
    int V; // Número de vértices
    std::vector<std::list<int>> adj; // Lista de adyacencia

public:
    // Constructor que inicializa el grafo con V vértices
    Grafo(int V) : V(V) {
        adj.resize(V);
    }

    // Método para agregar una arista no dirigida entre dos nodos
    void agregarArista(int u, int v) {
        adj[u].push_back(v); // Agregar v a la lista de u
        adj[v].push_back(u); // Agregar u a la lista de v (para hacerlo no dirigido)
    }

    // Método para mostrar el grafo
    void mostrarGrafo() const {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vértice " << i << " -> ";
            for (const auto& vecino : adj[i]) {
                std::cout << vecino << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Crear un grafo no dirigido con 5 nodos
    Grafo grafo(5);

    // Agregar aristas no dirigidas entre los nodos
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 4);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(1, 4);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);

    // Mostrar el grafo
    grafo.mostrarGrafo();

    return 0;
}
