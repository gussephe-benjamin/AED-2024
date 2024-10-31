#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

class Grafo {
private:
    int V;  // Número de vértices
    bool esDirigido;
    std::vector<std::list<std::pair<int, int>>> adjList;  // Lista de adyacencia (nodo, peso)
    std::vector<std::tuple<int, int, int>> aristas; // Para Kruskal: (peso, u, v)

public:
    // Constructor
    Grafo(int vertices, bool dirigido = false) : V(vertices), esDirigido(dirigido) {
        adjList.resize(V);
    }

    // Agregar arista con peso
    void agregarArista(int origen, int destino, int peso) {
        adjList[origen].push_back({destino, peso});
        aristas.push_back(std::make_tuple(peso, origen, destino));  // Usamos std::make_tuple
        if (!esDirigido) {
            adjList[destino].push_back({origen, peso});
            aristas.push_back(std::make_tuple(peso, destino, origen));  // Usamos std::make_tuple
        }
    }

    // Algoritmo de Prim para el MST
    void prim(int inicio) {
        std::vector<int> costo(V, INT_MAX); // Costos iniciales infinitos
        std::vector<int> parent(V, -1);     // Array para almacenar MST
        std::vector<bool> enMST(V, false);  // Marca los nodos incluidos en MST
        costo[inicio] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({0, inicio});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            enMST[u] = true;

            for (auto &[v, peso] : adjList[u]) {
                if (!enMST[v] && peso < costo[v]) {
                    costo[v] = peso;
                    pq.push({costo[v], v});
                    parent[v] = u;
                }
            }
        }

        // Imprimir el MST
        std::cout << "Aristas en el MST (Prim):\n";
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1) {
                std::cout << parent[i] << " - " << i << " : " << costo[i] << std::endl;
            }
        }
    }

    // Algoritmo de Kruskal para el MST
    void kruskal() {
        // Ordenar aristas por peso
        std::sort(aristas.begin(), aristas.end());

        // Estructura de conjuntos disjuntos (Union-Find)
        std::vector<int> parent(V);
        std::vector<int> rank(V, 0);
        for (int i = 0; i < V; ++i) parent[i] = i;

        auto find = [&](int u) {
            while (u != parent[u]) u = parent[u];
            return u;
        };

        auto unionSet = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else { parent[rootV] = rootU; rank[rootU]++; }
        };

        std::vector<std::tuple<int, int, int>> mst;

        for (auto &[peso, u, v] : aristas) {
            if (find(u) != find(v)) {
                mst.push_back(std::make_tuple(peso, u, v));  // Usamos std::make_tuple
                unionSet(u, v);
            }
        }

        // Imprimir el MST
        std::cout << "Aristas en el MST (Kruskal):\n";
        for (auto &[peso, u, v] : mst) {
            std::cout << u << " - " << v << " : " << peso << std::endl;
        }
    }
};

int main() {
    Grafo grafo(6, false); // Grafo no dirigido con 6 nodos

    // Agregar aristas con peso
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 4);
    grafo.agregarArista(1, 2, 2);
    grafo.agregarArista(1, 3, 6);
    grafo.agregarArista(2, 3, 8);
    grafo.agregarArista(2, 4, 9);
    grafo.agregarArista(3, 4, 5);
    grafo.agregarArista(3, 5, 8);
    grafo.agregarArista(4, 5, 7);

    grafo.prim(0); // MST usando Prim, empezando desde el nodo 0
    grafo.kruskal(); // MST usando Kruskal

    return 0;
}
