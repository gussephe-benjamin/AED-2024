#include <iostream>
#include <vector>
#include <list>

class Grafo {
private:
    int V; // Número de vértices
    std::vector<std::list<int>> adj; // Lista de adyacencia

    // Función recursiva para realizar DFS desde un nodo dado
    void DFSUtil(int v, std::vector<bool>& visitado) {
        // Marcar el nodo actual como visitado y mostrarlo
        visitado[v] = true;
        std::cout << v << " ";

        // Recorrer todos los vértices adyacentes al vértice actual
        for (int vecino : adj[v]) {
            if (!visitado[vecino]) {
                DFSUtil(vecino, visitado); // Llamada recursiva para los nodos no visitados
            }
        }
    }

public:
    // Constructor para inicializar el grafo con V vértices
    Grafo(int V) : V(V) {
        adj.resize(V);
    }

    // Función para agregar una arista dirigida entre dos nodos
    void agregarArista(int u, int v) {
        adj[u].push_back(v); // Solo agregar en una dirección (u -> v) para grafo dirigido
    }

    // Función para realizar DFS desde un nodo inicial
    void DFS(int inicio) {
        // Crear un vector para rastrear los nodos visitados
        std::vector<bool> visitado(V, false);

        // Llamar a la función recursiva DFSUtil para el nodo inicial
        std::cout << "DFS a partir del nodo " << inicio << ": ";
        DFSUtil(inicio, visitado);
        std::cout << std::endl;
    }

    // Función para realizar DFS en todo el grafo, útil para encontrar todas las componentes
    void DFSCompleto() {
        std::vector<bool> visitado(V, false);
        std::cout << "DFS completo para todas las componentes alcanzables:" << std::endl;
        for (int i = 0; i < V; ++i) {
            if (!visitado[i]) {
                std::cout << "Componente alcanzable desde " << i << ": ";
                DFSUtil(i, visitado);
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    // Crear un grafo dirigido con 6 nodos
    Grafo grafo(6);

    // Agregar aristas dirigidas
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);
    grafo.agregarArista(4, 5);
    grafo.agregarArista(5, 3); // Ciclo en el grafo

    // Realizar DFS desde un nodo inicial
    grafo.DFS(2);

    // Realizar DFS completo para encontrar todas las componentes alcanzables
    grafo.DFSCompleto();

    return 0;
}
