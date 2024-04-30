#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void traversal(Node* root){
	if (root == NULL){
		return;
	}
	else {
		cout <<root->data<<" ";
		traversal(root->left);
		traversal(root->right);
	}	
}

Node* insert(Node* &root,int x){
	if (root == NULL)
	{
		root = new Node(x);
	}
	else if (x >= root->data){
		root->right = insert(root->right,x);
	}
	else if (x < root->data){
		root->left = insert(root->left,x);
	}
	return root;
}

int height(Node* root){
	if (root == NULL){
		return 0;
	}
	int ls = 1+height(root->left);
	int rs = 1+height(root->right);
	return max(ls,rs);
}

int minimum(Node* root){
	if (root->left == NULL){
		return root->data;
	}
	return min(minimum(root->left),root->data);
}

void search(Node* root,int key,bool &present){
	if (root == NULL){
		return;
	}
	if (root->data == key){
		present = true;
	}
	else if (key < root->data){
		search(root->left,key,present);
	}
	else if (key > root->data){
		search(root->right,key,present);
	}
}

void mirror(Node* &root){
	if (root == NULL){
		return;
	}
	mirror(root->left);
	mirror(root->right);
	swap(root->left,root->right);	
}

int main(){
	Node* root = NULL;
	int n,ch;
	while (1){
		cout << "/n*************MENU***************"<<endl;
		cout << "1.Insert"<<endl;
		cout << "2.Height of BST"<<endl;
		cout << "3.Minimum in BST"<<endl;
		cout << "4.Mirror of BST"<<endl;
		cout << "5.Search"<<endl;
		cout << "6.Traversal"<<endl;
		cout << "7.Exit"<<endl;
		cout << "\nEnter your choice : ";
		cin >> ch;
		if (ch == 1){
			cout <<"Enter the number of nodes : ";
			cin >> n;
			for (int i=0;i<n;i++){
				int ele;
				cout << "Enter the node "<<i+1<<" : ";
				cin >> ele;
				insert(root,ele);
			}
		}
		else if (ch == 2){
			cout << "Height of BST : "<<height(root)<<endl;
		}
		else if (ch == 3){
			cout << "Minimum in BST : "<<minimum(root)<<endl;
		}
		else if (ch == 4){
			mirror(root);
			cout << "Traversal of mirrored BST : ";
			traversal(root);
		}
		else if (ch == 5){
			int key;
			bool present;
			present = false;
			cout << "Enter the key to search : ";
			cin >> key;
			search(root,key,present);
			if (present == true){
				cout << "Key Found"<<endl;
			}
			else if (present == false){
				cout << "Key not found"<<endl;
			}
		}
		else if (ch == 6){
			cout << "Traversal : ";
			traversal(root);
		}
		else if (ch == 7){
			exit(1);
		}
		else{
			cout << "Invalid choice"<<endl;
		}	
	}
	return 0;
}