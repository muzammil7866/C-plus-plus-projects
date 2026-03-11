
//CODE FOR AN ONLINE STORE USING THE CONCEPTS OF AVL TREES TO ORGANISE PRODUCTS

#include <iostream>
using namespace std;
//GLOBAL VARIABLE FOR THE CALCULATION OF TOTAL PRODUCTS
int totalProducts = 0;
class Product {
public:
	int productID;
	Product* left;
	Product* right;

	//PARAMETERIZED CONSTRUCTOR TO INITIALISE PRODUCT
	Product(int value) //done
	{
		productID = value;
		left = nullptr;
		right = nullptr;
	}
};
class OnlineStore{
public:
	Product* inventory;

	int calculateHeight(Product* inventory) //CALCULATES THE HEIGHT OF PRODUCT PASSED
	{
		if (inventory == nullptr) {
			return -1;
		}
		else {
			int leftHeight = calculateHeight(inventory->left);
			int rightHeight = calculateHeight(inventory->right);
			return 1 + Max(leftHeight, rightHeight);
		}
	}


	int balanceFactor(Product* product) //CALCULATES THE BALANCE FACTOR FOR THE PRODUCT
	{
		if (product->left == nullptr && product->right == nullptr)
		{
			
			return 0;
		}

		else if (product->left == nullptr && product->right != nullptr)
		{
			
			return -1 - calculateHeight(product->right);
		}

		else if (product->left != nullptr && product->right == nullptr)
		{
			
			return calculateHeight(product->left) - (-1);
		}

		else
		{
			return calculateHeight(product->left) - calculateHeight(product->right);
		}
	}

	int Max(int a, int b) //COMPARES TWO ID VALUES TO FIND THE LARGEST
	{
		if (a >= b)
		{
			return a;
		}

		else
		{
			return b;
		}
	}
	void  rotateLeft(Product*& product) //ROTATES THE INVENTORY TO THE LEFT
	{
		Product* K2;
		K2 = product->right;
		product->right = K2->left;
		K2->left = product;
		product = K2;
	}
	void rotateRight(Product*& product) //ROTATES THE INVENTORY TO THE RIGHT
	{
		Product* temp;
		temp = product->left;
		product->left = temp->right;
		temp->right = product;
		product = temp;
	}

	void balance(Product*& product) //BALANCES THE INVENTORY IN ACCORDANCE WITH THE NEED
	{

		if (balanceFactor(product) < -1 || balanceFactor(product) > 1)
		{
			//rotate left
			if (balanceFactor(product) < 0 && balanceFactor(product->right) < 0)
			{
				rotateLeft(product);

			}

			//rotate right
			else if (balanceFactor(product) > 0 && balanceFactor(product->left) > 0)
			{
				rotateRight(product);

			}

			//double rotate left
			if (balanceFactor(product) < 0 && balanceFactor(product->right) > 0)
			{
				DoubleRotateLeft(product);
			}
			//double rotate right
			if (balanceFactor(product) > 0 && balanceFactor(product->left) < 0)
			{
				DoubleRotateRight(product);
			}
		}



	}
	Product* insertInto(Product*& product, int key) //INSERTS A PRODUCT INTO THE INVENTORY AND BALANCES IT ALONG
	{
		if (product == nullptr)
		{
			Product* newNode = new Product(key);
			product = newNode;
		}

		else
		{
			if (key > product->productID)
			{
				insertInto(product->right, key);
			}

			else if (key < product->productID)
			{
				insertInto(product->left, key);
			}

		}

		balance(product);
		return product;
	}

	Product* insert(Product* product, int key) //CALLS THE INSERT PRODUCT FUNCTION
	{

		product = insertInto(product, key);
		return product;
	}

	Product* findInOrderPred(Product* inventory) //FINDS THE INORDER PREDECESSOR TO BE REPLACED BY PRODUCT INTENDED TO BE DELETED
	{
		Product* ptr = inventory->left;

		while (ptr->right != nullptr)
		{
			ptr = ptr->right;
		}

		return ptr;
	}

	Product* DoubleRotateRight(Product*& K3) //FIRST ROTATES THE INVENTORY LEFT THEN ROTATES RIGHT
	{


		rotateLeft(K3->left);
		rotateRight(K3);
		return K3;

	}

	Product* DoubleRotateLeft(Product*& K1) //FIRST ROTATES THE INVENTORY RIGHT THEN ROTATES LEFT
	{


		rotateRight(K1->right);
		rotateLeft(K1);

		return K1;
	}

	Product* deleteProductRecursive(Product*& inventory, int value) //DELETES THE PRODUCT FROM THE INVENTORY
	{

		if (inventory->left == nullptr && inventory->right == nullptr)
		{
			delete inventory;
			inventory = nullptr; 
			return inventory;
		}

		else if (value > inventory->productID)
		{
			deleteProductRecursive(inventory->right, value);
		}

		else if (value < inventory->productID)
		{
			deleteProductRecursive(inventory->left, value);
		}


		else
		{
			if (inventory->right == nullptr && inventory->left != nullptr)
			{
				inventory->productID = inventory->left->productID;
				deleteProductRecursive(inventory->left, inventory->productID);
			}

			else if (inventory->left == nullptr && inventory->right != nullptr)
			{
				inventory->productID = inventory->right->productID;
				deleteProductRecursive(inventory->right, inventory->productID);
			}

			else
			{
				Product* iPre;
				iPre = findInOrderPred(inventory);
				inventory->productID = iPre->productID;
				deleteProductRecursive(inventory->left, iPre->productID);

			}

		}

		balance(inventory);
		return inventory;
	}
	Product* remove(Product*& product, int key) //CALLS THE DELETING PRODUCT FUNCTION
	{
		product = deleteProductRecursive(product, key);

		return product;
	}
	void inorderRecursive(Product* inventory) //TRAVSERSES THE INVENTORY USING INORDER
	{
		if (inventory == nullptr)
		{
			return;
		}

		else
		{
			inorderRecursive(inventory->left);
			cout << inventory->productID << " ";
			inorderRecursive(inventory->right);
		}
	}
	void preorderRecursive(Product* inventory) //TRAVSERSES THE INVENTORY USING PREORDER
	{
		if (inventory == nullptr)
		{
			return;
		}

		else
		{
			cout << inventory->productID << " ";
			preorderRecursive(inventory->left);
			preorderRecursive(inventory->right);
		}
	}
	void postorderRecursive(Product* inventory) //TRAVSERSES THE INVENTORY USING POSTORDER
	{

		if (inventory == nullptr)
		{
			return;
		}

		else
		{

			postorderRecursive(inventory->left);
			postorderRecursive(inventory->right);
			cout << inventory->productID << " ";
		}
	}
public:
	OnlineStore() //DEFAULT CONSTRUCTOR TO INITIALISE THE STORE
	{
		inventory = nullptr;
	}
	void insert(int key) //CALLS THE INSERT FUNCTION TO INSERT PRODUCT INTO THE INVENTORY
	{
		inventory = insert(inventory, key);
	}


	void remove(int key) //CALLS THE DELETE FUNCTION TO REMOVE A PRODUCT FROM THE INVENTORY
	{
		if (searchRecursive(inventory, key))
			inventory = deleteProductRecursive(inventory, key);
		else
		{
			cout << "ID NOT IN THE INVENTORY!";
		}
	}
	void display() //DISPAYS THE INVENTORY IN DESIRED ORDER
	{
		int option;
		cout << "HOW DO YOU WANT TO DISPLAY THE INVENTORY, ENTER (1) FOR PREORDER, (2) FOR INORDER, (3) FOR POSTORDER: " << endl;
		cin >> option;

		if (option == 1)
		{
			preorderRecursive(inventory);
		}

		else if (option == 2)
		{
			inorderRecursive(inventory);
		}

		else if (option == 3)
		{
			postorderRecursive(inventory);
		}

		else
		{
			cout << "INVALID INPUT!";
		}

	}

	bool searchRecursive(Product* inventory, int value) //SEARCHES THE PRODUCT IN THE INVENTORY
	{

		if (inventory == nullptr)
		{
			return false;
		}
		else if (inventory->productID == value)
		{
			return true;
		}

		else
		{
			if (value > inventory->productID)
			{
				searchRecursive(inventory->right, value);
			}

			else
			{
				searchRecursive(inventory->left, value);
			}
		}

	}

	bool checkAVL(Product* inventory) //CHECKS IF INVENTORY IS AVL OR NOT
	{
		bool check = true;

		if (inventory != nullptr)
		{
			checkAVL(inventory->left);
			if (balanceFactor(inventory) < -1 || balanceFactor(inventory) > 1)
			{
				check = false;

			}

			checkAVL(inventory->right);
		}

		return check;
	}

	Product* getInventory() //RETURNS THE ROOT INVENTORY
	{
		return inventory;
	}

	int getBalanceFactor(Product* product) //RETURNS THE BALANCE FACTOR OF THE PASSED PRODUCT
	{
		return balanceFactor(product);
	}

	void checkAVL2() //CHECKS IF THE INVENTORY ROOTED BETWEEN TWO PRODUCT IS AVL
	{
		int val1, val2;
		cout << "ENTER ID 1: ";
		cin >> val1;
		cout << "ENTER ID 2: ";
		cin >> val2;

		bool a = searchRecursive(inventory, val1);
		bool b = searchRecursive(inventory, val2);

		if (a == 0 || b == 0)
			cout << "BOTH PRODUCT ID'S DOES NOT EXIST IN INVENTORY!";


		else
		{
			bool check = checkAVL(lca(inventory, val1, val2));

			if (check == false)
			{
				cout << "INVENTORY IS NOT AVL!";
			}

			else
			{
				cout << "INVENTORY IS AVL";
			}
		}
	}

	Product* lca(Product* inventory, int n1, int n2) //FINDS THE LEAST COMMON ANCESTOR
	{
		if (inventory == NULL)
			return NULL;

		if (inventory->productID > n1 && inventory->productID > n2)
			return lca(inventory->left, n1, n2);

		if (inventory->productID < n1 && inventory->productID < n2)
			return lca(inventory->right, n1, n2);

		return inventory;
	}

};
int main()
{
	OnlineStore onlineStore;
	bool end = false;

	while (end != true)
	{

		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT PRODUCT \n(2) SEARCH AND RETRIEVE INFORMATION \n(3) DISPLAY INVENTORY \n(4) DELETE PRODUCT \n(5) EXIT MENU" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int productID;
			cout << "ENTER PRODUCT ID OF THE PRODUCT TO ADD: ";
			cin >> productID;
			onlineStore.insert(productID);
		}

		else if (option == 2)
		{
			if (onlineStore.getInventory() == nullptr)
			{
				cout << "INVENTORY IS EMPTY!";
			}

			else
			{
				int temp;
				cout << "ENTER THE PRODUCT ID FOR THE PRODUCT TO RETRIEVE ITS INFORMATION: ";
				cin >> temp;
				bool temp2 = onlineStore.searchRecursive(onlineStore.getInventory(), temp);
				cout << endl;
				if (temp2 == false)
				{
					cout << "NOT FOUND!";
				}
				else
				{
					cout << "PRODUCT FOUND IN INVENTORY!";
				}
			}
		}
		else if (option == 3)
		{
			onlineStore.display();
		}
		else if (option == 4)
		{
			int num;
			cout << "ENTER THE PRODUCT ID FOR THE PRODUCT THAT YOU WANT TO DELETE: ";
			cin >> num;
			onlineStore.remove(num);
		}
		else if (option == 5)
		{
			end = true;

		}

		else
		{
			cout << "sINVALID OPTION!" << endl;
		}

		cout << endl;
		system("pause");
		system("cls");


	}
	return 0;
}