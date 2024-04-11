// Write your code here
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAX_NODES = 1000005; // Maximum number of nodes + 5
constexpr int PRIME_MODULUS = 1000000007; // A prime number used for modulo operation

int totalNodes, color, nodeValues[MAX_NODES], parentTags[MAX_NODES]; // nodeValues: stores the color of each node, parentTags: stores the number of times the parent node has been visited
ll product = 1; // product: the final answer
vector<int> childrenLists[MAX_NODES]; // childrenLists: stores the list of children for each node

void traverse(int node, int parent) {
    if (nodeValues[node] <= 0) { // If the node has a non-positive color value, the product becomes 0
        product = 0;
        return;
    }
    parentTags[parent]++; // Increment the parent node's tag
    product = (product * nodeValues[node]) % PRIME_MODULUS; // Update the product
    for (int child : childrenLists[node]) { // Traverse through the children of the current node
        if (child != parent) {
            nodeValues[child] -= parentTags[node] + 1; // Decrease the child node's color value by the parent node's tag + 1
            parentTags[child]++; // Increment the child node's tag
            traverse(child, node); // Recursively traverse the child node
        }
    }
}

int main() {
    cin >> totalNodes >> color;
    for (int i = 1; i <= totalNodes; i++) {
        nodeValues[i] = color; // Initialize the color values for all nodes
    }
    for (int i = 1, parent, child; i < totalNodes; i++) {
        scanf("%d%d", &parent, &child);
        childrenLists[parent].push_back(child); // Add the child node to the parent node's children list
        childrenLists[child].push_back(parent); // Add the parent node to the child node's children list
    }
    traverse(1, 0); // Start traversing from the root node (node 1)
    printf("%lld\n", product); // Print the final answer
    return 0;
}