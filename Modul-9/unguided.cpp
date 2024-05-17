#include <iostream>
#include <vector> // Use vector for dynamic heap representation
#include <algorithm>

using namespace std;

int parent(int i) {
  return (i - 1) / 2;
}

int leftChild(int i) {
  return ((2 * i) + 1);
}

int rightChild(int i) {
  return ((2 * i) + 2);
}

void shiftUp(vector<int>& H, int i) {
  while (i > 0 && H[parent(i)] < H[i]) {
    swap(H[parent(i)], H[i]);
    i = parent(i);
  }
}

void shiftDown(vector<int>& H, int i) {
  int maxIndex = i;
  int l = leftChild(i);
  if (l <= H.size() - 1 && H[l] > H[maxIndex]) {
    maxIndex = l;
  }
  int r = rightChild(i);
  if (r <= H.size() - 1 && H[r] > H[maxIndex]) {
    maxIndex = r;
  }
  if (i != maxIndex) {
    swap(H[i], H[maxIndex]);
    shiftDown(H, maxIndex);
  }
}

void insert(vector<int>& H, int p) {
  H.push_back(p);
  shiftUp(H, H.size() - 1);
}

int extractMax(vector<int>& H) {
  if (H.empty()) {
    cout << "Heap is empty!" << endl;
    return -1; // Or throw an exception
  }
  int result = H[0];
  H[0] = H.back();
  H.pop_back();
  shiftDown(H, 0);
  return result;
}

void changePriority(vector<int>& H, int i, int p) {
  if (i >= H.size()) {
    cout << "Invalid index!" << endl;
    return;
  }
  int oldp = H[i];
  H[i] = p;
  if (p > oldp) {
    shiftUp(H, i);
  } else {
    shiftDown(H, i);
  }
}

int getMax(const vector<int>& H) {
  if (H.empty()) {
    cout << "Heap is empty!" << endl;
    return -1; // Or throw an exception
  }
  return H[0];
}

void remove(vector<int>& H, int i) {
  if (i >= H.size()) {
    cout << "Invalid index!" << endl;
    return;
  }
  changePriority(H, i, getMax(H) + 1); // Set priority very high
  extractMax(H);
}

int main() {
  vector<int> H; // Dynamic heap representation

  int numElements;
  cout << "Enter the number of elements in the heap: ";
  cin >> numElements;

  cout << "Enter the elements (space-separated): ";
  for (int i = 0; i < numElements; ++i) {
    int value;
    cin >> value;
    insert(H, value);
  }

  cout << "Priority Queue : ";
  for (int i = 0; i < H.size(); ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  cout << "Node with maximum priority :" << extractMax(H) << "\n";

  cout << "Priority queue after extracting maximum :";
  for (int i = 0; i < H.size(); ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  int changeIndex, newPriority;
  cout << "Enter index to change priority: ";
  cin >> changeIndex;
  cout << "Enter new priority: ";
  cin >> newPriority;

  changePriority(H, changeIndex, newPriority);
  cout << "Priority queue after priority change :";
    for (int i = 0; i < H.size(); ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  int removeIndex;
  cout << "Enter index to remove element: ";
  cin >> removeIndex;

  remove(H, removeIndex);
  cout << "Priority queue after removing the element :";
  for (int i = 0; i < H.size(); ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  return 0;
}

