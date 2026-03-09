const int MAXROWS = 10;
const int MAXCOLS = 10;

class Matrix
{
public:
	int matrix[MAXROWS][MAXCOLS];
	int rows;
	int cols;

	Matrix();
	void displayMatrix();
	void setMatrix();
	void operator -();
	void setRandC(int a, int b);
};
