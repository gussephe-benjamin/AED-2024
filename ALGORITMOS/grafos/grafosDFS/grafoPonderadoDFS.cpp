#include <iostream>
#include <vector>
#include <list>
#include <utility> // Para std::pair

class GrafoPonderado {
private:
    int V; // Número de vértices
    std::vector<std::list<std::pair<int, int>>> adj; // Lista de adyacencia con pesos (destino, peso)

    // Función recursiva para realizar DFS desde un nodo dado
    void DFSUtil(int v, std::vector<bool>& visitado) {
        // Marcar el nodo actual como visitado y mostrarlo
        visitado[v] = true;
        std::cout << v << " ";

        // Recorrer todos los vértices adyacentes al vértice actual
        for (const auto& vecino : adj[v]) {
            int nodo = vecino.first;
            int peso = vecino.second;
            if (!visitado[nodo]) {
                std::cout << "(peso: " << peso << ") "; // Mostrar el peso de la arista
                DFSUtil(nodo, visitado); // Llamada recursiva para los nodos no visitados
            }
        }
    }

public:
    // Constructor para inicializar el grafo con V vértices
    GrafoPonderado(int V) : V(V) {
        adj.resize(V);
    }

    // Función para agregar una arista ponderada no dirigida entre dos nodos
    void agregarArista(int u, int v, int peso) {
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso}); // Para hacerlo no dirigido
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
};

int main() {
    // Crear un grafo ponderado no dirigido con 5 nodos
    GrafoPonderado grafo(5);

    // Agregar aristas con pesos
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 3);
    grafo.agregarArista(1, 2, 1);
    grafo.agregarArista(1, 3, 2);
    grafo.agregarArista(2, 3, 4);
    grafo.agregarArista(3, 4, 5);

    // Realizar DFS desde un nodo inicial
    grafo.DFS(2);

    return 0;
}
