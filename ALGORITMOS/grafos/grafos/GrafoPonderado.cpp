#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility> // Para std::pair
#include <climits> // Para INT_MAX
#include <algorithm> // Para std::sort
#include <tuple>     // Para std::tuple y std::make_tuple

class GrafoPonderado {
private:
    int V; // Número de vértices
    std::vector<std::list<std::pair<int, int>>> adj; // Lista de adyacencia con pesos (nodo, peso)
    std::vector<std::tuple<int, int, int>> aristas; // Lista de aristas para Kruskal (peso, u, v)

public:
    GrafoPonderado(int V) : V(V) {
        adj.resize(V);
    }

    // Agregar una arista ponderada entre dos nodos
    void agregarArista(int u, int v, int peso) {
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso}); // Agregar en ambas direcciones para grafo no dirigido
        aristas.push_back(std::make_tuple(peso, u, v)); // Usar make_tuple en lugar de {peso, u, v}
    }

    // Mostrar el grafo con sus pesos
    void mostrarGrafo() const {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vértice " << i << " -> ";
            for (const auto& vecino : adj[i]) {
                std::cout << "(" << vecino.first << ", peso: " << vecino.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    // Algoritmo de Prim para encontrar el MST
    void primMST() const {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        std::vector<int> clave(V, INT_MAX);
        std::vector<int> padre(V, -1);
        std::vector<bool> enMST(V, false);

        clave[0] = 0;
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();

            enMST[u] = true;

            for (const auto& vecino : adj[u]) {
                int v = vecino.first;
                int peso = vecino.second;

                if (!enMST[v] && peso < clave[v]) {
                    clave[v] = peso;
                    padre[v] = u;
                    minHeap.push({clave[v], v});
                }
            }
        }

        std::cout << "Aristas en el MST (Prim):\n";
        for (int i = 1; i < V; ++i) {
            std::cout << padre[i] << " - " << i << " con peso: " << clave[i] << std::endl;
        }
    }

    // Funciones auxiliares para Kruskal (Union-Find)
    int encontrar(std::vector<int>& padre, int i) {
        if (padre[i] != i)
            padre[i] = encontrar(padre, padre[i]);
        return padre[i];
    }

    void unir(std::vector<int>& padre, std::vector<int>& rango, int u, int v) {
        int raizU = encontrar(padre, u);
        int raizV = encontrar(padre, v);

        if (rango[raizU] < rango[raizV]) {
            padre[raizU] = raizV;
        } else if (rango[raizU] > rango[raizV]) {
            padre[raizV] = raizU;
        } else {
            padre[raizV] = raizU;
            rango[raizU]++;
        }
    }

    // Algoritmo de Kruskal para encontrar el MST
    void kruskalMST() {
        std::sort(aristas.begin(), aristas.end());

        std::vector<int> padre(V);
        std::vector<int> rango(V, 0);
        for (int i = 0; i < V; ++i)
            padre[i] = i;

        std::vector<std::tuple<int, int, int>> resultado;

        for (const auto& arista : aristas) {
            int peso = std::get<0>(arista);
            int u = std::get<1>(arista);
            int v = std::get<2>(arista);

            int raizU = encontrar(padre, u);
            int raizV = encontrar(padre, v);

            if (raizU != raizV) {
                resultado.push_back(std::make_tuple(u, v, peso));
                unir(padre, rango, raizU, raizV);
            }
        }

        std::cout << "Aristas en el MST (Kruskal):\n";
        for (const auto& arista : resultado) {
            int u = std::get<0>(arista);
            int v = std::get<1>(arista);
            int peso = std::get<2>(arista);
            std::cout << u << " - " << v << " con peso: " << peso << std::endl;
        }
    }
};

int main() {
    // Crear un grafo con 6 nodos
    GrafoPonderado grafo(6);

    // Agregar aristas ponderadas que conectan todos los nodos (grafo conexo)
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 3);
    grafo.agregarArista(1, 2, 1);
    grafo.agregarArista(1, 3, 2);
    grafo.agregarArista(2, 3, 4);
    grafo.agregarArista(3, 4, 2);
    grafo.agregarArista(4, 5, 3);
    grafo.agregarArista(3, 5, 5);

    // Mostrar el grafo
    grafo.mostrarGrafo();

    // Ejecutar el Algoritmo de Prim
    std::cout << "\nEjecutando el Algoritmo de Prim para encontrar el MST:\n";
    grafo.primMST();

    // Ejecutar el Algoritmo de Kruskal
    std::cout << "\nEjecutando el Algoritmo de Kruskal para encontrar el MST:\n";
    grafo.kruskalMST();

    return 0;
}
