#pragma once
#include"VectorSpace.h"




typedef struct MyStruct
{
	bool up;
	std::string A;
	VectorSpace B;
}re;





class Matrix
{
public:
	Matrix();
	~Matrix();
	Matrix(const Matrix& _matrix);
	Matrix(std::string _name);
	Matrix(std::string _name, int _row, int _column, std::vector<std::vector<long double>>_matrix);
	Matrix(std::string _name, int _row, int _column, std::vector<VectorSpace>_matrix);
	Matrix(int _row, int _column, VectorSpace _vec);
	Matrix(std::string _name, int _row, int _column, VectorSpace _vec);
	Matrix(std::string _name, int _row, int _column);
	Matrix(int _row, int _column);
	Matrix(int _row, int _column,int n);
	void changename(std::string _name);
	friend std::ostream& operator<<(std::ostream& os, const Matrix&);
	void addRow(long double *a,int _size);
	void addRow(std::vector<long double> _tem, int _size);
	void addRow(VectorSpace _tem, int _size);
	void addColumn(long double *a, int _size);
	void addColumn(std::vector<long double> _tem, int _size);
	void addColumn(VectorSpace _tem, int _size);
	void replaceNuminMatrix(int row, int column, long double _num);
	long double getnuminMatrix(int _row, int _column);
	void deleterow(int _row);
	void deletecolumn(int _column);
	int getcolumn();
	int getRow();
	std::string getName();
	Matrix operator +(const Matrix&_matrix);
	Matrix operator -(const Matrix&_matrix);
	Matrix operator *(const Matrix&_matrix);
	Matrix operator *(const long double&_Scalar);
	Matrix operator /(const long double&_Scalar);
	Matrix operator =(const Matrix&_matrix);
	Matrix operator ^(const long double&_Scalar);
	Matrix Transpose();
	long double determinants();
	Matrix adjoint();
	Matrix Inverse();
	long double Rank();
	Matrix eigenMatrix(long double);
	re  linear_system(VectorSpace _vec);
	std::map<long double, re> eigenvalueAndeigenvectorUnder3();
	std::map<long double, re> powerMethod();
	Matrix Guass();
	
	//least square
private:
	bool juge(Matrix b);
	
	std::vector<std::vector<long double>>matrix;
	int row;
	int column;
	std::string name;
};



bool Linear_independent(std::vector<VectorSpace> _vec);
bool Linear_independent(int howmany,VectorSpace *_vec);
std::string leastSquare(std::vector<VectorSpace> _vec);
std::string leastSquare(int howmany, VectorSpace *_vec);