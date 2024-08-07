#include <iostream> 
#include "ll_node.h"
using namespace std;

// Node<int>::Node(int data) { 
// 	this->data = data; 
// 	this->next = NULL; 
// } 
 
class Linkedlist { 
	Node<int>* head; // head variable stores the memory location of the Node class `Object`
	public:  

	Linkedlist() { 
		head = NULL; 
	} 

	void insertNode(int data) { 
		Node<int>* newNode = new Node<int>(data); 
		if (head == NULL) { 
			head = newNode; 
			return; 
		} 
		// Traverse till end of list 
		Node<int>* temp = head; 
		while (temp->next != NULL) { 
			temp = temp->next; 
		} 
		temp->next = newNode; 
	} 

	void printList() { 
		Node<int>* temp = head;  
		if (head == NULL) { 
			cout << "List is empty" << endl; 
			return; 
		}  
		while (temp != NULL) { 
			cout << temp->data << " "; 
			temp = temp->next; 
		} 
	} 

	void deleteNode(int node) {
		if (head == NULL) { 
			cout << "List is empty, nothing to delete" << endl; 
			return; 
		}  

		Node<int>* temp = head;

		while(temp->next != NULL){
			if(temp->next->data == node) {
				cout << "Found the node to be deleted !!" << temp->next->data << endl;
				if(temp->next->next == NULL) {
					temp->next = NULL;
					break;
				}
				Node<int>* t = temp->next->next;
				delete temp->next;
				temp->next = t;
			}
			temp = temp->next;
		}
		cout << "TRIED TO DELETE A NODE !" << endl;
	}
}; 

int main() { 
	Linkedlist list; 

	for(int i = 1; i < 100 ; i++ ){
		list.insertNode(i);
	}	

	cout << "Elements of the list are: "; 
	list.printList(); 
	cout << endl; 

	list.deleteNode(8);
	list.deleteNode(19);
	list.deleteNode(98);
	list.deleteNode(7);
	list.deleteNode(1);
	list.deleteNode(5);
	list.deleteNode(44);

	cout << "Elements of the list are: "; 
	list.printList(); 
	cout << endl; 
	return 0; 
}
