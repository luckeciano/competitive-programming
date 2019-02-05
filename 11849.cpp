#include <cstdio>
#include <cstdlib>

struct Node {
    int key;
    Node * leftNode;
    Node * rightNode;

};

void insertNode (Node &thisNode, int N) {
    if (thisNode.key < N) {
        if (thisNode.rightNode == nullptr) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->key = N;
            node->leftNode = nullptr;
            node->rightNode = nullptr;
            thisNode.rightNode = node;
        }

        else {
           insertNode(*thisNode.rightNode, N);
        }
    } else {
        if (thisNode.leftNode == nullptr) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->key = N;
            node->leftNode = nullptr;
            node->rightNode = nullptr;
            thisNode.leftNode = node;
        }

        else insertNode(*thisNode.leftNode, N);
    }

}

bool searchNumber (Node thisNode, int N) {
    if (thisNode.key == N)
        return true;
    else if (thisNode.key < N) {
        if (thisNode.rightNode == nullptr) return false;
        else return searchNumber(*thisNode.rightNode,N);
    } else {
        if (thisNode.leftNode == nullptr) return false;
        else return searchNumber(*thisNode.leftNode,N);
    }


}

void printNodes(Node &s) {
    printf ("%d ", s.key);
    if (s.leftNode != nullptr)
        printNodes(*s.leftNode);
    if (s.rightNode != nullptr)
        printNodes(*s.rightNode);

}

int main() {
    int N, M;
    scanf ("%d %d", &N, &M);
    while (!(N == 0 && M == 0)) {
        int n; scanf ("%d", &n);
        Node JackCD;
        JackCD.key = n;
        JackCD.rightNode = nullptr;
        JackCD.leftNode = nullptr;
        for (int i = 1; i < N; i++) {
            scanf ("%d", &n);
            insertNode(JackCD, n);
        }
       // printNodes(JackCD);
        int counter = 0;
        for (int i = 0; i < M; i++) {
            scanf ("%d", &n);
            if (searchNumber(JackCD, n)) counter++;
        }

        printf ("%d\n", counter);
        scanf ("%d %d", &N, &M);
    }



}

