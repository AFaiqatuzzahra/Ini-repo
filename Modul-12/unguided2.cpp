#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Struktur Node
struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan node ke tree
Node* insert(Node* root, string data) {
    if (root == nullptr) {
        return new Node(data);
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Fungsi untuk mencari node dalam tree
Node* findNode(Node* root, const string& data) {
    if (!root) return nullptr;
    if (root->data == data) return root;

    Node* leftNode = findNode(root->left, data);
    if (leftNode) return leftNode;

    return findNode(root->right, data);
}

// Fungsi untuk menampilkan child dari node
void displayChildren(Node* node) {
    if (!node) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Child dari node " << node->data << ": ";
    if (node->left) cout << node->left->data << " ";
    if (node->right) cout << node->right->data;
    cout << endl;
}

// Fungsi untuk menampilkan descendant dari node
void displayDescendants(Node* node) {
    if (!node) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    queue<Node*> q;
    q.push(node);
    cout << "Descendant dari node " << node->data << ": ";
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != node) cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice;
    string data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah node ke tree\n";
        cout << "2. Tampilkan child dari node\n";
        cout << "3. Tampilkan descendant dari node\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // Mengabaikan karakter newline

        switch (choice) {
        case 1:
            cout << "Masukkan data node: ";
            getline(cin, data);
            root = insert(root, data);
            break;
        case 2:
            cout << "Masukkan data node yang ingin ditampilkan child-nya: ";
            getline(cin, data);
            displayChildren(findNode(root, data));
            break;
        case 3:
            cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
            getline(cin, data);
            displayDescendants(findNode(root, data));
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}
