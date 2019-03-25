#include "Matrix.h"



Matrix::Matrix()
{
	row = 0;
	column = 0;
	name.clear();
	matrix.clear();
}


Matrix::~Matrix()
{
	row=0;
	column = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].clear();
	}
	matrix.clear();
	name.clear();
}

Matrix::Matrix(Matrix & _matrix)
{
	row = _matrix.row;
	column = _matrix.column;
	matrix = _matrix.matrix;
}

Matrix::Matrix(string _name)
{
	row = 0;
	column = 0;
	name = _name;
	
}


Matrix::Matrix(string _name, int _row, int _column, vector<vector<double>> _matrix)
{
	row = _row;
	column = _column;
	name = _name;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = _matrix[i][j];
		}
	}
}

Matrix::Matrix(string _name, int _row, int _column, vector<VectorSpace> _matrix)
{
	row = _row;
	column = _column;
	name = _name;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = _matrix[i].getNumInSpace(j);
		}
	}
}

Matrix::Matrix(string _name, int _row, int _column)
{
	row = _row;
	column = _column;
	name = _name;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] =0;
		}
	}
}

Matrix::Matrix(int _row, int _column)
{
	row = _row;
	column = _column;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Matrix::addRow(double * a, int _size)
{
	try
	{
		if (_size != column)
			throw "column不一樣";
		vector<double>tem;
		for (int i = 0; i <_size; i++)
		{
			tem.push_back(a[i]);
		}
		row += 1;
		matrix.push_back(tem);
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	
	
}

void Matrix::addRow(vector<double> _tem, int _size)
{
	try
	{
		if (_size != column)
			throw "column不一樣";
		row += 1;
		matrix.push_back(_tem);
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}

}
void Matrix::addRow(VectorSpace _tem, int _size)
{
	try
	{
		if (_size != column)
			throw "column不一樣";
		vector<double>tem;
		for (int i = 0; i < _size; i++)
		{
			tem.push_back(_tem.getNumInSpace(i));
		}
		row += 1;
		matrix.push_back(tem);
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}

}
void Matrix::addColumn(double * a, int _size)
{
	try
	{
		if (_size != row)
			throw "row不一樣";
		for (int i = 0; i < _size; i++)
		{
			matrix[i].push_back(a[i]);
		}
		column += 1;
		
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
}
void Matrix::addColumn(vector<double> _tem, int _size)
{
	try
	{
		if (_size != row)
			throw "row不一樣";
		for (int i = 0; i < _size; i++)
		{
			matrix[i].push_back(_tem[i]);
		}
		column += 1;

	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
}
void Matrix::addColumn(VectorSpace _tem, int _size)
{
	try
	{
		if (_size != row)
			throw "row不一樣";
		for (int i = 0; i < _size; i++)
		{
			matrix[i].push_back(_tem.getNumInSpace(i));
		}
		column += 1;

	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
}
void Matrix::replaceNuminMatrix(int row, int column, double _num)
{
	matrix[row][column] = _num;
}
void Matrix::deleterow(int _row)
{
	vector <vector<double>>tem;
	for (int i = 0; i < row; i++)
	{
		if (i == _row) {}
		else tem.push_back(matrix[i]);
	}
	row -= 1;
	matrix = tem;
}
void Matrix::deletecolumn(int _column)
{
	vector <vector<double>>tem;
	for (int i = 0; i < row; i++)
	{
		vector<double>t;
		for (int j = 0; j < column; j++)
		{
			if (j == _column) {}
			else t.push_back(matrix[i][j]);
		}
		tem.push_back(t);
	}
	column += 1;
	matrix = tem;
}
int Matrix::getcolumn()
{
	return column;
}
int Matrix::getRow()
{
	return row;
}
string Matrix::getName()
{
	return name;
}
Matrix Matrix::operator+(const Matrix & _matrix)
{
	try
	{
		if (row != _matrix.row || column != _matrix.column)
			throw "matrix不一樣";
		Matrix ans(row, column);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++) {
				ans.matrix[i][j] = matrix[i][j] + _matrix.matrix[i][j];
			}
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	//return *this ;
	
}
Matrix Matrix::operator-(const Matrix & _matrix)
{
	try
	{
		if (row != _matrix.row || column != _matrix.column)
			throw "matrix不一樣";
		Matrix ans(row, column);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++) {
				ans.matrix[i][j] = matrix[i][j] - _matrix.matrix[i][j];
			}
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	//return *this ;
}
Matrix Matrix::operator*(const Matrix & _matrix)
{
	try
	{
		if (column!= _matrix.row)
			throw "matrix不一樣";
		Matrix ans(row, _matrix.column);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j <_matrix.column; j++) {
				for (int k = 0; k < column; k++)
				{
					ans.matrix[i][j] += matrix[i][k] * _matrix.matrix[k][i];
				}
			}
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	//return *this ;
}
Matrix Matrix::operator=(const Matrix & _matrix)
{
	row = _matrix.row;
	column = _matrix.column;
	matrix = _matrix.matrix;
	return *this;
}
Matrix Matrix::Transpose()
{
	Matrix ans;
	//cout << *this << endl;
	//cout << "-----------------" << endl;
	for (int i = 0; i < column; i++)
	{
		vector<double>tem;
		for (int j = 0; j < row; j++)
		{
			tem.push_back(this->matrix[j][i]);
		}
		ans.matrix.push_back(tem);
	}
	//cout << ans << endl;
	//cout << "-----------------" << endl;
	int tem = column;
	ans.column = row;
	ans.row = tem;
	return  ans;

}
double Matrix::determinants()
{
	try
	{
		if (row !=  column  )
			throw "matrix非方陣";
		Matrix tem(*this);
		if (tem.column == tem.row) {
			if (row == 1) return matrix[0][0];
			if (row == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
			double Max_row, Max_column;//maxrow為最大數字的column值 column為最大排
			double tmp;     //交換用
			double sw;   //存中間值
			int sign = 0;//看變號
			int i = 0, j = 0, k = 0;

			for (i = 0; i < tem.column - 1; i++) {
				Max_column = i;
				Max_row = tem.matrix[i][i];
				for (j = i + 1; j < tem.column; j++) {
					//cout << abs(Max_row) << "   " << abs(tem.mt[j].a[i]) << endl;
					if (abs(Max_row) < abs(tem.matrix[j][i])) {
						Max_row = tem.matrix[j][i];

						Max_column = j;
					}
				}
				if (abs(Max_row) < 0.000001) {
					return NULL;
				}
				if (Max_column != i)
				{
					sign++;
					for (j = i; j < tem.column; j++) {

						tmp = tem.matrix[i][j];

						tem.matrix[i][j] = tem.matrix[Max_column][j];

						tem.matrix[Max_column][j] = tmp;
					}
					//cout << tem << endl;
				}
				for (j = i + 1; j < tem.column; j++) {
					sw = tem.matrix[j][i] / tem.matrix[i][i];
					for (k = i; k < tem.column; k++)
						tem.matrix[j][k] = tem.matrix[j][k] - tem.matrix[i][k] * sw;
				}
				//cout << tem << endl;
				//cout<<"next"<<endl;
			}

			double ans = 1;

			for (i = 0; i < this->column; i++)

				ans *= tem.matrix[i][i];

			if (sign % 2 == 0)
				return ans;
			else
				return ans * (-1);
		}
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	//return *this ;
}
Matrix Matrix::adjoint()
{
	try
	{
		if (row != column )
			throw "matrix非方陣";
		Matrix ans(row, column);
		int NegatineOrPositive = 1;
		for (int i = 0; i < this->column; i++)
		{
			for (int j = 0; j < this->column; j++)
			{
				Matrix tempmt;
				for (int y = 0; y < row; y++)
				{
					vector<double>t;
					for (int x = 0; x < column; x++)
					{
						if (y == i || x == j) {
						}
						else
						{
							t.push_back(matrix[y][x]);
						}
						
					}
					if (t.size() != 0) {
						tempmt.matrix.push_back(t);
					}
					
						
				
				}
				tempmt.column = column - 1;
				tempmt.row = row - 1;
				//cout << tempmt << endl;
				//cout << "--------" << endl;
				if (NegatineOrPositive % 2 == 0)
					ans.matrix[i][j] = tempmt.determinants()*(-1);
				else
					ans.matrix[i][j] = tempmt.determinants()*(1);

				NegatineOrPositive++;
				
				//cout << ans << endl;
			}

		}
		ans = ans.Transpose();
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	//return *this ;
}
Matrix Matrix::Inverse()
{
	
	try
	{
		if (row != column)
			throw "matrix非方陣";
		else if(this->determinants()==0)
			throw "matrix無可逆矩陣";
		Matrix ans;
		ans = this->adjoint();
		double denomainater = this->determinants();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				ans.matrix[i][j] /= denomainater;
			}
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	//return *this ;
}
ostream & operator<<(ostream & os, const Matrix &A)
{
	for (int i = 0; i < A.row; i++)
	{
	
		for (int j = 0; j <A.column; j++) {
			if (j == A.column - 1) os <<setw(5)<<A.matrix[i][j];
			else os <<left<<setw(5) << A.matrix[i][j] << " , ";
		}
		os << endl;
	}
	os << endl;
	return os;
}
