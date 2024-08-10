#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Graph {
private:
    int vertices;
    Node** adjacency_list;

public:
    Graph(int v) {
        vertices = v;
        adjacency_list = new Node*[v];
        for (int i = 0; i < v; ++i) {
            adjacency_list[i] = nullptr;
        }
    }

    void add_edge(int source, int destination) {
        // Buat node baru untuk tujuan
        Node* new_node = new Node(destination);

        // Sisipkan node baru di awal linked list untuk sumber
        new_node->next = adjacency_list[source];
        adjacency_list[source] = new_node;

        // Untuk graph tidak berarah, tambahkan edge yang berlawanan arah
        new_node = new Node(source);
        new_node->next = adjacency_list[destination];
        adjacency_list[destination] = new_node;
    }

    void print_graph() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Vertex " << i << ":";
            Node* temp = adjacency_list[i];
            while (temp) {
                std::cout << " -> " << temp->data;
                temp = temp->next;
            }
            std::cout << " \n";
        }
    }
};

int main() {
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    g.print_graph();

    return 0;
}