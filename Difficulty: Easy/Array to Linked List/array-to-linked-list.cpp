//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// } Driver Code Ends

// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

 class Solution {
public:
    Node* constructLL(vector<int>& arr) {
        // Function to construct a linked list from an array of integers using an array-based approach
        // Returns a pointer to the head of the constructed linked list
        
        if (arr.empty()) return nullptr;
        // Check if the input array is empty
        // If empty, return nullptr as there's no linked list to create
        
        // Static vector to ensure nodes persist after function returns
        // WARNING: This approach has limitations (thread safety issues, potential problems with multiple calls)
        static vector<Node> nodes;
        // 'static' keyword ensures the vector persists between function calls
        // Without 'static', the vector would be destroyed when the function ends, invalidating any pointers
        
        nodes.clear();
        // Clear any previous data in the static vector
        // This is necessary if the function is called multiple times
        
        nodes.reserve(arr.size());
        // Pre-allocate memory to avoid reallocations that could invalidate pointers
        // This is an optimization to prevent memory addresses from changing during vector resizing
        
        // Populate the vector with Node objects
        for (int value : arr) {
            nodes.emplace_back(value);
            // Create a new Node object directly in the vector with the current array value
            // emplace_back constructs the object in-place rather than copying it
        }
        
        // Connect the nodes to form the linked list
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i].next = &nodes[i + 1];
            // Set each node's 'next' pointer to point to the address of the following node
            // Creates the actual linked list structure by connecting nodes sequentially
        }
        
        // Ensure the last node's next pointer is nullptr (end of list)
        if (!nodes.empty()) {
            nodes.back().next = nullptr;
            // Set the last node's next pointer to nullptr
            // This properly terminates the linked list
        }
        
        // Return a pointer to the first node, which serves as the head of the linked list
        return nodes.empty() ? nullptr : &nodes[0];
        // If nodes vector is empty, return nullptr, otherwise return address of first node
        // This provides access to the entire linked list via the head pointer
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        Node* ans = ob.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends