#include <iostream>
using namespace std;
//some global variables for height calculation
int totalNodes = 0;
class Student {
public:
	int studentID;
	string dept;
	string name;
	Student* left;
	Student* right;
	int height;

	//PARAMETERIZED CONSTRUCTOR TO INITIALISE NODE
	Student(int value, string name, string dept) //done
	{
		studentID = value;
		this->name = name;
		this->dept = dept;
		left = nullptr;
		right = nullptr;
		height = 0;
	}
};
class StudentEnrollmentSystem{
public:
	Student* root;

	int calculateHeight(Student* root) {
		if (root == nullptr) {
			return -1;
		}
		else {
			int leftHeight = calculateHeight(root->left);
			int rightHeight = calculateHeight(root->right);
			return 1 + max(leftHeight, rightHeight);
		}
	}

	int height(Student* node) //CALLS THE HEIGHT CALCULATION FUNCTION
	{
		node->height = calculateHeight(node);
		return node->height;
	}


	int balanceFactor(Student* node) //CALCULATES THE BALANCE FACTOR FOR THE NODE
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			cout << 0;
			return 0;
		}

		else if (node->left == nullptr && node->right != nullptr)
		{
			cout << -1 - calculateHeight(node->right);
			return -1 - calculateHeight(node->right);
		}

		else if (node->left != nullptr && node->right == nullptr)
		{
			cout << calculateHeight(node->left) - (-1);
			return calculateHeight(node->left) - (-1);
		}

		else
		{
			cout << calculateHeight(node->left) - calculateHeight(node->right);
			return calculateHeight(node->left) - calculateHeight(node->right);
		}
	}

	int Max(int a, int b) //COMPARES TWO INTEGER VALUES TO FIND THE LARGEST
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
	void  rotateLeft(Student*& node) //ROTATES THE TREE TO THE LEFT
	{
		Student* K2;
		K2 = node->right;
		node->right = K2->left;
		K2->left = node;
		//node->height = Max(height(node->left), height(node->right)) + 1;
		//K2->height = Max(height(K2->right), node->height) + 1;
		node = K2;
	}
	void rotateRight(Student*& node) //ROTATES THE TREE TO THE RIGHT
	{
		Student* temp;
		temp = node->left;
		node->left = temp->right;
		temp->right = node;
		//node->height = Max(height(node->left), height(node->right)) + 1;
		//temp->height = Max(height(temp->left), node->height) + 1;
		node = temp;
	}

	void balance(Student*& node) //BALANCES THE TREE IN ACCORDANCE TO THE NEED
	{

		if (balanceFactor(node) < -1 || balanceFactor(node) > 1)
		{
			//rotate left
			if (balanceFactor(node) < 0 && balanceFactor(node->right) < 0)
			{
				rotateLeft(node);

			}

			//rotate right
			else if (balanceFactor(node) > 0 && balanceFactor(node->left) > 0)
			{
				rotateRight(node);

			}

			//double rotate left
			if (balanceFactor(node) < 0 && balanceFactor(node->right) > 0)
			{
				DoubleRotateLeft(node);
			}
			//double rotate right
			if (balanceFactor(node) > 0 && balanceFactor(node->left) < 0)
			{
				DoubleRotateRight(node);
			}
		}



	}
	Student* insertInto(Student*& node, int key, string name, string dept) //INSERTS A NODE INTO THE TREE AND BALANCES IT ALONG
	{
		if (node == nullptr)
		{
			Student* newNode = new Student(key, name, dept);
			node = newNode;
		}

		else
		{
			if (key > node->studentID)
			{
				insertInto(node->right, key, name, dept);
			}

			else if (key < node->studentID)
			{
				insertInto(node->left, key, name, dept);
			}

		}

		balance(node);
		return node;
	}

	Student* insert(Student* node, int key, string name, string dept) //CALLS THE INSERT FUNCTION
	{

		node = insertInto(node, key, name, dept);
		return node;
	}
	//Student* findMin(Student* node) //DUMMY FUNCITON GIVEN BY SIR, IT WAS OPTIONAL TO USE!
	//{
	//	return node;
	//}

	Student* findInOrderPred(Student* root) //FINDS THE INORDER PREDECESSOR TO BE REPLACED BY NODE INTENDED TO BE DELETED
	{
		Student* ptr = root->left;

		while (ptr->right != nullptr)
		{
			ptr = ptr->right;
		}

		return ptr;
	}

	Student* DoubleRotateRight(Student*& K3) //FIRST ROTATES THE TREE LEFT THEN ROTATES RIGHT
	{


		rotateLeft(K3->left);
		rotateRight(K3);
		return K3;

	}

	Student* DoubleRotateLeft(Student*& K1) //FIRST ROTATES THE TREE RIGHT THEN ROTATES LEFT
	{


		rotateRight(K1->right);
		rotateLeft(K1);

		return K1;
	}

	Student* deleteNodeRecursive(Student*& root, int value) //DELETES THE NODE FROM THE TREE
	{

		//if (root == nullptr)
		//{
		//	return root;
		//}

		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr; //important to do this
			return root;
		}

		else if (value > root->studentID)
		{
			deleteNodeRecursive(root->right, value);
		}

		else if (value < root->studentID)
		{
			deleteNodeRecursive(root->left, value);
		}


		else
		{
			if (root->right == nullptr && root->left != nullptr)
			{
				root->studentID = root->left->studentID;
				deleteNodeRecursive(root->left, root->studentID);
			}

			else if (root->left == nullptr && root->right != nullptr)
			{
				root->studentID = root->right->studentID;
				deleteNodeRecursive(root->right, root->studentID);
			}

			else
			{
				Student* iPre;
				iPre = findInOrderPred(root);
				root->studentID = iPre->studentID;
				deleteNodeRecursive(root->left, iPre->studentID);

			}

		}

		balance(root);
		return root;
	}
	Student* remove(Student*& node, int key) //CALLS THE DELETING NODE FUNCTION
	{
		node = deleteNodeRecursive(node, key);

		return node;
	}
	void inorderRecursive(Student* root) //TRAVSERSES THE TREE USING INORDER
	{
		if (root == nullptr)
		{
			return;
		}

		else
		{
			inorderRecursive(root->left);
			cout << root->studentID << "-" << root->dept << "-" << root->name << " ";
			inorderRecursive(root->right);
		}
	}
	void preorderRecursive(Student* root) //TRAVSERSES THE TREE USING PREORDER
	{
		if (root == nullptr)
		{
			return;
		}

		else
		{
			cout << root->studentID << "-" << root->dept << "-" << root->name << " ";
			preorderRecursive(root->left);
			preorderRecursive(root->right);
		}
	}
	void postorderRecursive(Student* root) //TRAVSERSES THE TREE USING POSTORDER
	{

		if (root == nullptr)
		{
			return;
		}

		else
		{

			postorderRecursive(root->left);
			postorderRecursive(root->right);
			cout << root->studentID << "-"<<root->dept<<"-"<<root->name<<" ";
		}
	}
public:
	StudentEnrollmentSystem() //DEFAULT CONSTRUCTOR TO INITIALISE THE TREE
	{
		root = nullptr;
	}
	void insert(int key, string name, string dept) //CALLS THE INSERT FUNCTION TO INSERT VALUE INTO THE TREE
	{
		root = insert(root, key, name, dept);
	}


	void remove(int key) //CALLS THE DELETE FUNCTION TO REMOVE A VALUE FROM THE TREE
	{
		if (searchRecursive(root, key))
			root = deleteNodeRecursive(root, key);
		else
		{
			cout << "VALUE NOT IN THE TREE!";
		}
	}
	void display() //DISPAYS THE BST IN THE DESIRED ORDER
	{
		int option;
		cout << "HOW DO YOU WANT TO DISPLAY THE TREE, ENTER (1) FOR PREORDER, (2) FOR INORDER, (3) FOR POSTORDER: " << endl;
		cin >> option;

		if (option == 1)
		{
			preorderRecursive(root);
		}

		else if (option == 2)
		{
			inorderRecursive(root);
		}

		else if (option == 3)
		{
			postorderRecursive(root);
		}

		else
		{
			cout << "INVALID INPUT!";
		}

	}

	void Traversal() //PRINTS IN ALL THREE TRAVERSAL ORDERS
	{
		inorderRecursive(root);
		preorderRecursive(root);
		postorderRecursive(root);
	}

	bool searchRecursive(Student* root, int value) //SEARCHES THE VALUE INTO THE TREE
	{

		if (root == nullptr)
		{
			return false;
		}
		else if (root->studentID == value)
		{
			return true;
		}

		else
		{
			if (value > root->studentID)
			{
				searchRecursive(root->right, value);
			}

			else
			{
				searchRecursive(root->left, value);
			}
		}

	}

	bool replaceRecursive(Student* root, int value, int newVal) //SEARCHES THE VALUE INTO THE TREE
	{

		if (root == nullptr)
		{
			return false;
		}

		else
		{
		if (root->studentID == value)
		{
			root->studentID = newVal;
		}

		else
		{
			if (value > root->studentID)
			{
				replaceRecursive(root->right, value, newVal);
			}

			else
			{
				replaceRecursive(root->left, value, newVal);
			}
		}
		balance(root);
		}
	}

	bool checkAVL(Student* root) //CHECKS IF TREE IS AN AVL OR NOT
	{
		bool check = true;

		if (root != nullptr)
		{
			checkAVL(root->left);
			cout << getBalanceFactor(root) << " ";
			if (balanceFactor(root) < -1 || balanceFactor(root) > 1)
			{
				check = false;

			}

			checkAVL(root->right);
		}

		return check;
	}

	Student* getRoot() //RETURNS THE ROOT OF TREE
	{
		return root;
	}

	int getBalanceFactor(Student* node) //RETURNS THE BALANCE FACTOR OF THE PROVIDED NODE
	{
		return balanceFactor(node);
	}

	void checkAVL2()
	{
		int val1, val2;
		cout << "ENTER VALUE 1: ";
		cin >> val1;
		cout << "ENTER VALUE 2: ";
		cin >> val2;

		bool a = searchRecursive(root, val1);
		bool b = searchRecursive(root, val2);

		if (a == 0 || b == 0)
			cout << "BOTH VALUES DOES NOT EXIST IN TREE!";


		else
		{
			bool check = checkAVL(lca(root, val1, val2));

			if (check == false)
			{
				cout << "SUBTREE IS NOT AVL!";
			}

			else
			{
				cout << "TREE IS AVL";
			}
		}
	}

	Student* lca(Student* root, int n1, int n2)
	{
		if (root == NULL)
			return NULL;

		if (root->studentID > n1 && root->studentID > n2)
			return lca(root->left, n1, n2);

		if (root->studentID < n1 && root->studentID < n2)
			return lca(root->right, n1, n2);

		return root;
	}

	bool checkSubTreeAVL(Student* root, int val1, int val2)
	{
		if (root != nullptr)
		{
			checkSubTreeAVL(root->left, val1, val2);

			if (root->right != nullptr && root->left != nullptr)
			{
				if (root->right->studentID == val1 && root->left->studentID == val2)
				{
					return checkAVL(root);
				}

				else if (root->right->studentID == val2 && root->left->studentID == val1)
				{
					return checkAVL(root);
				}
			}
			checkSubTreeAVL(root->right, val1, val2);

		}

	}
};
int main()
{
	StudentEnrollmentSystem avl;
	bool end = false;

	while (end != true)
	{

		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT STUDENT \n(2) CHANGE DEPARTMENT \n(3) DISPLAY \n(4) DELETE STUDENT ID \n(5) EXIT MENU" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int studentID;
			string name, dept;
			cout << "ENTER THE STUDENT ID OF THE STUDENT: ";
			cin >> studentID;
			cout << "ENTER THE DEPARTMENT OF THE STUDENT: ";
			cin >> dept;
			cout << "ENTER THE NAME OF THE STUDENT: ";
			cin >> name;
			avl.insert(studentID, name, dept);
		}

		else if (option == 2)
		{
			int studentID;
			cout << "ENTER THE STUDENT ID OF THE STUDENT TO CHANGE ITS DEPARTMENT: ";
			cin >> studentID;

			int start;
			cout << "CHOOSE DEPARTMENT TO SHIFT THE STUDENT TO, 1 FOR CS, 2 FOR SE, 3 FOR EE, 4 FOR S&H, 5 FOR FSM: ";

			cin >> start;

			int num = studentID;
			int mul = 1;
			int count = 0;
			int final = 0;
			int dig;
			while (num > 10)
			{
				dig = num % 10;
				num = num / 10;
				
				mul = 1;
				for (int i = 0; i < count; i++)
				{
					mul = mul * 10;
				}

				count++;
				final += dig * mul;
				cout << final;
				cout << endl;
			}

			num = num / 10;
			int id;
			id = start * 1000 + final;

			avl.replaceRecursive(avl.root, studentID, id);
			cout << "DEPARTMENT CHANGED SUCCESSFULLY!";
			
		}
		else if (option == 3)
		{
			avl.display();
		}
		else if (option == 4)
		{
			int num;
			cout << "ENTER THE STUDENT ID FOR THE STUDENT THAT YOU WANT TO DELETE: ";
			cin >> num;
			avl.remove(num);
		}
		else if (option == 5)
		{
			end = true;

		}

		else
		{
			cout << "INVALID OPTION!" << endl;
		}

		cout << endl;
		system("pause");
		system("cls");


	}
	return 0;
}