#pragma once
#include"VectorSpace.h"
class Matrix
{
public:
	Matrix();
	~Matrix();
	Matrix(Matrix& _matrix);
	Matrix(string _name);
	Matrix(string _name, int _row, int _column, vector<vector<double>>_matrix);
	Matrix(string _name, int _row, int _column, vector<VectorSpace>_matrix);
	Matrix(string _name, int _row, int _column);
	Matrix(int _row, int _column);
	friend ostream& operator<<(ostream& os, const Matrix&);
	void addRow(double *a,int _size);
	void addRow(vector<double> _tem, int _size);
	void addRow(VectorSpace _tem, int _size);
	void addColumn(double *a, int _size);
	void addColumn(vector<double> _tem, int _size);
	void addColumn(VectorSpace _tem, int _size);
	void replaceNuminMatrix(int row, int column, double _num);
	double getnuminMatrix(int _row, int _column);
	void deleterow(int _row);
	void deletecolumn(int _column);
	int getcolumn();
	int getRow();
	string getName();
	Matrix operator +(const Matrix&_matrix);
	Matrix operator -(const Matrix&_matrix);
	Matrix operator *(const Matrix&_matrix);
	Matrix operator *(const double&_Scalar);
	Matrix operator /(const double&_Scalar);
	Matrix operator =(const Matrix&_matrix);
	Matrix operator ^(const double&_Scalar);
	Matrix Transpose();
	double determinants();
	Matrix adjoint();
	Matrix Inverse();
	double Rank();

	//linear system
	//eigenvaule
	//power method of eigen value
	//least square
private:
	vector<vector<double>>matrix;
	int row;
	int column;
	string name;
};

