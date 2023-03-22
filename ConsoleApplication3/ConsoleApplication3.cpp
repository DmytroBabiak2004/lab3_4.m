#include <iostream>

using namespace std;

double determinant(double matrix[3][3]);
double detX(double matrix[3][3], double b[3]);
double detY(double matrix[3][3], double b[3]);
double detZ(double matrix[3][3], double b[3]);

int main()
{
	double matrix[3][3] = { {0.65, -0.93, 0.45},{1.15, 0.43, -0.72},{0.56, -0.18, 1.03} };
	double b[3] = { -0.72, 1.24, 2.15 };
	double x, y, z;

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			cout << matrix[i][j]<<"\t";
		}
		cout << endl;

	}

	cout << "determinant:" << determinant(matrix) << endl;
	cout << "detX: " << detX(matrix, b)<< endl;
	cout << "detY: " << detY(matrix, b)<< endl;
	cout << "detZ: " << detZ(matrix, b)<< endl;

	x = detX(matrix, b) / determinant(matrix);
	y = detY(matrix, b) / determinant(matrix);
	z = detZ(matrix, b) / determinant(matrix);

	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Z: " << z << endl;

	return 0;
}

double determinant(double matrix[3][3]) 
{
	double det = 0;

	for (int i = 0; i < 3; i++)
	{
		det = det + (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));
	}

	return det;
}

double detX(double matrix[3][3], double b[3])
{
	double matrixX[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixX[i][j] =matrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		matrixX[i][0] = b[i];
	}

	double det = determinant(matrixX);

	return det;
}

double detY(double matrix[3][3], double b[3])
{
	double matrixY[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixY[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		matrixY[i][1] = b[i];
	}
	double det = determinant(matrixY);

	return det;
}

double detZ(double matrix[3][3], double b[3])
{
	double matrixZ[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixZ[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		matrixZ[i][2] = b[i];
	}

	double det = determinant(matrixZ);

	return det;
}