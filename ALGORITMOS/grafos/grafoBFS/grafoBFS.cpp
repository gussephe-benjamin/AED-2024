#include <iostream>
#include <vector>
#include <queue>

class Grafo {
private:
    int V; // Número de vértices
    std::vector<std::vector<int>> adj; // Lista de adyacencia

public:
    // Constructor para inicializar el grafo con V vértices
    Grafo(int V) : V(V) {
        adj.resize(V);
    }

    // Método para agregar una arista no dirigida entre dos nodos
    void agregarArista(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Para hacer la conexión no dirigida
    }

    // Método para realizar BFS desde un nodo inicial
    void BFS(int inicio) {
        // Crear un vector para rastrear los nodos visitados
        std::vector<bool> visitado(V, false);
        std::queue<int> cola;

        // Marcar el nodo de inicio como visitado y encolar
        visitado[inicio] = true;
        cola.push(inicio);

        std::cout << "Recorrido BFS desde el nodo " << inicio << ": ";

        while (!cola.empty()) {
            // Extraer el siguiente nodo de la cola
            int nodo = cola.front();
            cola.pop();
            std::cout << nodo << " ";

            // Obtener todos los nodos adyacentes
            for (int vecino : adj[nodo]) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    cola.push(vecino); // Encolar los vecinos no visitados
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    // Crear un grafo con 7 nodos
    Grafo grafo(7);

    // Agregar aristas para formar el grafo
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 3);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 4);
    grafo.agregarArista(2, 5);
    grafo.agregarArista(3, 4);
    grafo.agregarArista(4, 5);
    grafo.agregarArista(4, 6);

    // Realizar BFS desde el nodo 0
    grafo.BFS(0);

    return 0;
}
