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

    // Función para agregar una arista no dirigida entre dos nodos
    void agregarArista(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Para hacerlo no dirigido
    }

    // Función para realizar DFS en todo el grafo, útil para encontrar todas las componentes
    void DFSCompleto() {
        std::vector<bool> visitado(V, false);
        std::cout << "Componentes conexas en el grafo:" << std::endl;
        for (int i = 0; i < V; ++i) {
            if (!visitado[i]) {
                std::cout << "Componente conexa: ";
                DFSUtil(i, visitado);
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    // Crear un grafo no dirigido con 8 nodos
    Grafo grafo(8);

    // Agregar aristas para crear varias componentes conexas
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 2);

    grafo.agregarArista(3, 4);

    grafo.agregarArista(5, 6);
    grafo.agregarArista(5, 7);

    // Realizar DFS completo para encontrar todas las componentes conexas
    grafo.DFSCompleto();

    return 0;
}
