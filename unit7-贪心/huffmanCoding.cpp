#include <bits/stdc++.h> // use g++ 
using namespace std; 


struct MinHeapNode { 
	char data; 
	unsigned freq; 
	MinHeapNode *left, *right; 
	MinHeapNode(char data, unsigned freq) { // struct class
		left = right = NULL; 
		this->data = data; 
		this->freq = freq; 
	} 
}; 

struct compare { 
	bool operator()(MinHeapNode* l, MinHeapNode* r) { // operator overloading
		return (l->freq > r->freq); 
	} 
}; 


void printCodes(struct MinHeapNode* root, string str) { // call itself
	if (!root) {
		return; 
	}
	if (root->data != '$') { // hack
		cout << root->data << ": " << str << "\n"; // print string: left is zero and right is one
	}
	printCodes(root->left, str + "0"); // recursion
	printCodes(root->right, str + "1"); // recursion
} 

void HuffmanCodes(char data[], int freq[], int size) { 
	struct MinHeapNode *left, *right, *top; 
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;  // type, container, compare function

	for (int i = 0; i < size; ++i) {
		minHeap.push(new MinHeapNode(data[i], freq[i])); 
	}

	while (minHeap.size() != 1) {
		left = minHeap.top(); 
		minHeap.pop(); 
		right = minHeap.top(); 
		minHeap.pop(); 
		top = new MinHeapNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		minHeap.push(top); 
	} 
	printCodes(minHeap.top(), ""); 
} 

int main() { 

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'}; 
	int freq[] = { 45, 13, 12, 16, 9, 5}; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	HuffmanCodes(arr, freq, size); 

	return 0; 
} 


//  ~  g++-8 /Users/qianqian/Desktop/hfmc.cpp -o main     Mon May  6 23:08:22 2019
//  ~  ./main                                    1205ms  Mon May  6 23:10:42 2019
// a: 0
// c: 100
// b: 101
// f: 1100
// e: 1101
// d: 111