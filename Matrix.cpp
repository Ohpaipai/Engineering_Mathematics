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

Matrix::Matrix(const Matrix & _matrix)
{
	name = _matrix.name;

	row = _matrix.row;
	column = _matrix.column;
	matrix = _matrix.matrix;
}

Matrix::Matrix(std::string _name)
{
	row = 0;
	column = 0;
	name = _name;
	
}


Matrix::Matrix(std::string _name, int _row, int _column, std::vector<std::vector<double>> _matrix)
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

Matrix::Matrix(std::string _name, int _row, int _column, std::vector<VectorSpace> _matrix)
{
	row = _row;
	column = _column;
	name = _name;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
	}

	for (int i = 0; i <row; i++)
	{
		for (int j = 0; j <column; j++) {
			matrix[i][j] = _matrix[j].getNumInSpace(i);
		}
	}
	
}

Matrix::Matrix(int _row, int _column, VectorSpace  _vec)
{
	row = _row;
	column = _column;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++) {
			matrix[i][j] = _vec.getNumInSpace(i);
		}
	}
}

Matrix::Matrix(std::string _name, int _row, int _column, VectorSpace  _vec)
{
	row = _row;
	column = _column;
	name = _name;
	matrix.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(column);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++) {
			matrix[i][j] =_vec.getNumInSpace(i);
		}
	}
}

Matrix::Matrix(std::string _name, int _row, int _column)
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
		std::vector<double>tem;
		for (int i = 0; i <_size; i++)
		{
			tem.push_back(a[i]);
		}
		row += 1;
		matrix.push_back(tem);
	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}
	
	
}

void Matrix::addRow(std::vector<double> _tem, int _size)
{
	try
	{
		if (_size != column)
			throw "column不一樣";
		row += 1;
		matrix.push_back(_tem);
	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}

}
void Matrix::addRow(VectorSpace _tem, int _size)
{
	try
	{
		if (_size != column)
			throw "column不一樣";
		std::vector<double>tem;
		for (int i = 0; i < _size; i++)
		{
			tem.push_back(_tem.getNumInSpace(i));
		}
		row += 1;
		matrix.push_back(tem);
	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
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
		std::cerr << "錯誤: " << str << std::endl;
	}
}
void Matrix::addColumn(std::vector<double> _tem, int _size)
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
		std::cerr << "錯誤: " << str << std::endl;
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
		std::cerr << "錯誤: " << str << std::endl;
	}
}
void Matrix::replaceNuminMatrix(int row, int column, double _num)
{
	matrix[row][column] = _num;
}
double Matrix::getnuminMatrix(int _row, int _column)
{
	return matrix[_row][_column];
}
void Matrix::deleterow(int _row)
{
	std::vector <std::vector<double>>tem;
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
	std::vector <std::vector<double>>tem;
	for (int i = 0; i < row; i++)
	{
		std::vector<double>t;
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
std::string Matrix::getName()
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
		std::cerr << "錯誤: " << str << std::endl;
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
		std::cerr << "錯誤: " << str << std::endl;
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
		std::cerr << "錯誤: " << str << std::endl;
	}
	//return *this ;
}
Matrix Matrix::operator*(const double & _Scalar)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] *= _Scalar;
		}
	}
	return *this;
}
Matrix Matrix::operator/(const double & _Scalar)
{
	try
	{
		if (_Scalar==0)
			throw "分母不能為0";
		for (int i = 0; i <row; i++)
		{
			for (int J= 0; J < column; J++)
			{
				matrix[i][J] /= _Scalar;
			}
		}
		return *this;

	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}
}
Matrix Matrix::operator=(const Matrix & _matrix)
{
	name = _matrix.name;
	row = _matrix.row;
	column = _matrix.column;
	matrix = _matrix.matrix;
	return *this;
}
Matrix Matrix::operator^(const double & _Scalar)
{
	try
	{
		if (column!=row)
			throw "matrix非方陣";
		if (_Scalar == 1)
		{
			Matrix ans(row, column);
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++) {
					if (j == i)ans.matrix[i][j] = 1;
					else matrix[i][j] = 0;
				}
			}
			return ans;
		}
		else {
			Matrix ans(row, column);
			Matrix tem = *this;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++) {
					if (j == i)ans.matrix[i][j] = 1;
					else matrix[i][j] = 0;
				}
			}
			for (int i = 0; i < _Scalar; i++)
			{
				ans=ans*tem;
			}
			return ans;
		}

	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}
}
Matrix Matrix::Transpose()
{
	Matrix ans;
	//cout << *this << endl;
	//cout << "-----------------" << endl;
	for (int i = 0; i < column; i++)
	{
		std::vector<double>tem;
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
			//cout << tem << endl;
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
		std::cerr << "錯誤: " << str << std::endl;
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
					std::vector<double>t;
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
		std::cerr << "錯誤: " << str << std::endl;
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
		if (denomainater == 0) return ans;
		else {
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					ans.matrix[i][j] /= denomainater;
				}
			}
			return ans;
		}
	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}
	//return *this ;
}
double Matrix::Rank()
{

	Matrix tem(*this);
	int nowColumn = 0;
	double mult = 0;
	for (int _row = 0; _row < tem.row; _row++)
	{
		//cout << _row << "   " << endl << tem;
		if (tem.matrix[_row][nowColumn] != 0)
		{
			for (int _column =nowColumn; _column < tem.row; _column++)
			{
				if (_column != _row) {
					mult = tem.matrix[_column][_row] / tem.matrix[_row][nowColumn];
					
					for (int i = nowColumn; i < tem.column; i++)
					{
						tem.matrix[_column][i] -= mult *tem.matrix[_row][i];
						
					}
					//cout << mult << "  " << endl << tem;
				}
			}
			nowColumn++;
		}
		else
		{
			if (_row == tem.row - 1) break;
			bool allzero = true;
			bool istriangle=false;
			for (int _column = _row+1; _column < tem.row; _column++)
			{
				if (_column==tem.row - 1) {
					if (tem.matrix[_column][_row] == 0)
					{
						istriangle = true;
					}
				}
				if (tem.matrix[_column][_row] != 0) { //row->nowcolumn?
					std::vector<double>change = tem.matrix[_column];
					tem.matrix[_column] = tem.matrix[_row];
					tem.matrix[_row] = change;
					allzero = false;
					break;
				}
			}
			if (allzero) {
				if (istriangle == false)
				{
					_row--;
					nowColumn++;
				}
			}
		}
	}

	//std::cout << "rank:"<< std::endl<<tem << endl;

	int rank = std::min(tem.column,tem.row);
	for (int i = 0; i < tem.row; i++)
	{
		bool allzero = true;
		for (int j = 0; j < tem.column; j++)
		{
			if (tem.matrix[i][j] != 0) {
				allzero = false;
				break;
			}
		}
		if (allzero)
		{
			rank--;
		}
	}

	return rank;

}
Matrix Matrix::eigenMatrix(double a)
{
	Matrix ans(*this);
	for (int q = 0; q < row; q++)
	{
		for (int j = 0; j < row; j++)
		{
			ans.matrix[q][j] -= a;
		}
	}
	return ans;
}
re Matrix::linear_system(VectorSpace _vec)
{
	re A;
	try
	{
		if (row !=_vec.getvectorsize())
			throw "線性系統無對應";
	
		Matrix tem(*this);
		std::string *variance = new std::string[tem.column];
		double *variancenum = new double[tem.column];
		for (int i = 0; i < tem.column; i++)
		{
			variancenum[i] = 0;
			std::stringstream ss;
			ss << (i + 1);
			std::string t;
			ss >> t;
			variance[i] = "x"+t;
			//cout << variance[i] << endl;
		}
		tem.column += 1;
		for (int i = 0; i < row; i++)
		{
			tem.matrix[i].push_back(-1 * _vec.getNumInSpace(i));
		}
		int nowColumn = 0;
		double mult = 0;
		for (int _row = 0; _row < tem.row; _row++)
		{
			//std::cout << tem;
			//cout << _row << "   " << endl << tem;
			if (tem.matrix[_row][nowColumn] != 0)
			{
				for (int _column = nowColumn; _column < tem.row; _column++)
				{
					if (_column != _row) {
						mult = tem.matrix[_column][_row] / tem.matrix[_row][nowColumn];

						for (int i = nowColumn; i < tem.column; i++)
						{
							tem.matrix[_column][i] -= mult * tem.matrix[_row][i];

						}
						//cout << mult << "  " << endl << tem;
					}
				}
				nowColumn++;
			}
			else
			{
				if (_row == tem.row - 1) break;
				bool allzero = true;
				bool istriangle = false;
				for (int _column = _row + 1; _column < tem.row; _column++)
				{
					if (_column == tem.row - 1) {
						if (tem.matrix[_column][_row] == 0)
						{
							istriangle = true;
						}
					}
					if (tem.matrix[_column][_row] != 0) { //row->nowcolumn?
						std::vector<double>change = tem.matrix[_column];
						tem.matrix[_column] = tem.matrix[_row];
						tem.matrix[_row] = change;
						allzero = false;
						break;
					}
				}
				if (allzero) {
					if (istriangle == false)
					{
						_row--;
						nowColumn++;
					}
				}
			}
		}






		//////////////////////////////////////////////////////////////////////////////////////////////



		std::cout << tem;
		VectorSpace temvec(row);
		for (int i = 0; i < row; i++)
		{
			//cout << tem.matrix[i][tem.column - 1] << endl;
			temvec.changeNumInSpace(tem.matrix[i][tem.column - 1]*-1,i);
			tem.matrix[i].pop_back();
		}
		tem.column -= 1;
		//std::cout << "tem     " << std::endl<< temvec << std::endl;
		//std::cout << tem << std::endl;
		re ans;
		if (tem.column == tem.row) //是否為方陣
		{
			for (int i = tem.row - 1; i >= 0; i--)
			{
				if (temvec.getNumInSpace(i) != 0 && tem.matrix[i][i] == 0 && ans.up == false) //是否 有全0但是解不是0狀態
				{
					ans.up = true;
					ans.A = "有理解不存在";
					return ans;
				}
				else if (temvec.getNumInSpace(i) != 0 && tem.matrix[i][i] != 0) //正常有解
				{
					ans.up = false;
					for (int j = tem.column-1; j > i; j--)
					{
						temvec.changeNumInSpace(temvec.getNumInSpace(i)-variancenum[j]*tem.matrix[i][j],i);
					}
					variancenum[i] = temvec.getNumInSpace(i) / tem.matrix[i][i];
				}
				else //無限多種可能解
				{
					ans.up = true;

					std::string phrase="";
					std::map<std::string, double> coefficent;
					std::map<std::string, double>::iterator iter;
					std::string text = "";
					for (int j = tem.column - 1; j >i; j--)//處理問題
					{
						//字串分析
						std::stringstream ss;
						
						
			
						for (int k = 0; k <variance[j].size(); k++)
						{
							/*iter = coefficent.find("c");
							if (iter == coefficent.end()) {
								coefficent.insert(std::pair<std::string, double>("c", 0));
							}*/
							if (variance[j][k] == 'x')//遇到x
							{

								ss.clear();
								ss << text;
								double _num=1;
								ss >> _num;
								std::string text_v ="";
								while (variance[j][k]!=' '||variance[j][k]!='\0')
								{
									if (variance[j][k] == ' '|| variance[j][k] == '\0') break;
									text_v += variance[j][k];
									//cout << i << text_v << "|||||" << endl;
									k++;
									if (k == variance[j].size()) break;
								}
								//text_v += '\0';

								/*for (int i = 1; i <text_v.size(); i++)
								{
									if (text_v[i]==32) {
										text_v[i] = '\0';
										break;
									}
								}*/
								/*for (iter = coefficent.begin(); iter != coefficent.end(); iter++)
								{
									cout << iter->first << "|||" << iter->second << endl;
								}*/
							//	cout << i << text_v << "|||||" << endl;
								iter = coefficent.find(text_v);

								if (iter == coefficent.end()) {

									coefficent.insert(std::pair<std::string, double>(text_v,tem.matrix[i][j]*_num));
								}
								else {
									//cout << iter->second << endl;
									double n =iter->second;
									n+= tem.matrix[i][j] * _num;
									iter->second = n;
								}
								
								text.clear();
							}
							else if (variance[j][k] == 'c')//遇到+
							{
								ss << text;
								double _num=1;
								ss >> _num;
								iter = coefficent.find("c");
								if (iter == coefficent.end()) {
									coefficent.insert(std::pair<std::string, double>("c", tem.matrix[i][j] * _num));
								}
								else {
									iter->second += tem.matrix[i][j] * _num;
								}
								text.clear();
							}
							else
							{
								if (variance[j][k] == ' ' || variance[j][k] == '+') {}
								else
								{
									text += variance[j][k];
								}

								
							}
						}
						

					

					}
					///////////////////////////
					//移向
					/*iter = coefficent.find("c");
					if (iter == coefficent.end()) {
						coefficent.insert(std::pair<std::string, double>("c",temvec.getNumInSpace(i)));
					}
					else {
						iter->second += temvec.getNumInSpace(i);
						std::cout << iter->second << std::endl;
					}*/


					if(tem.matrix[i][i]==0)
					{ 
						std::map<std::string, double>::iterator itrs;
						std::string small="z99999999999";
						int smallnum = 0;
						int smllcof = 0;
						std::string deletename = "";
						for (iter = coefficent.begin(); iter != coefficent.end(); iter++)//找出最小的
						{
							if (iter->first != "c")
							{
								if (iter->first < small) {
									small = iter->first;
									deletename = iter->first;
									itrs = iter;
									std::string comp="";
									for (int q = 1; q < iter->first.size(); q++)
									{
										comp += iter->first[q];
									}
									std::stringstream w;
									w << comp;
									w >> smallnum;
									smllcof = iter->second;
								}
							}
						}
					
						iter = coefficent.find("c");
						if (iter == coefficent.end()) {
							coefficent.insert(std::pair<std::string, double>("c", 0));
						}
					

						for (iter = coefficent.begin(); iter != coefficent.end(); iter++)
						{
							if (iter->first != deletename) {
								std::stringstream ss;
								std::string into;
								if (iter->first == "c") {
									//std::cout << temvec.getNumInSpace(i) << std::endl;
									double _num = (temvec.getNumInSpace(i) - iter->second) / smllcof;
									ss << _num;
									ss >> into;
								}
								else
								{
									double _num = iter->second*(-1) / smllcof;
									ss << _num;
									ss >> into;
								}
								phrase += into;
								phrase += iter->first;
								iter++;

								if (iter == coefficent.end())
								{
									phrase += '\0';

								}
								else
								{
									
										
										phrase += " + ";
									
								}
								iter--;
							}
						}

						variance[smallnum-1] = phrase;
						
						/*for (int m = variance[smallnum-1].size(); m >=0; m--)
						{
							if (variance[smallnum - 1][m] == '+')
							{

							}
						}*/
						
					}
					else {

						iter = coefficent.find("c");
						if (iter == coefficent.end()) {
							coefficent.insert(std::pair<std::string, double>("c", 0));
						}

						for (iter = coefficent.begin(); iter != coefficent.end(); iter++)
						{
							std::stringstream ss;
							std::string into;
							if (iter->first == "c") {
								double _num = (temvec.getNumInSpace(i) - iter->second) / tem.matrix[i][i];
								ss << _num;
								ss >> into;
							}
							else
							{
								double _num = iter->second*(-1) / tem.matrix[i][i];
								ss << _num;
								ss >> into;
							}
							phrase += into;
							phrase += iter->first;
							iter++;
							if (iter == coefficent.end())
							{
								phrase += '\0';

							}
							else
								phrase += " + ";
							iter--;
						}

						variance[i] = phrase;
					}
				}
				
			





			}

			if (ans.up)
			{
				for (int i = 0; i < tem.row; i++)
				{
					for (int j = variance[i].size()-1; j >=0 ; j--)
					{
						bool anything = false;
						while (1) {
						//	std::cout << variance[i][j] << std::endl;
							if ((variance[i][j] >= 48 & variance[i][j] <= 57) || variance[i][j] == 'c')
							{
								anything = true;
								//variance[i][j + 1] = '\0';
								for (int v = j+1; v <=variance[i].size() - 1; v++)
								{
									variance[i][v] = '\0';
								}
								break;
							}
							j--;
						}
						if (anything) {
							break;
						}
					}
					if (i == 0)
					{
						ans.A += "{ ";
						ans.A +=variance[i];

					}
					else if (i + 1 == tem.row)
					{
						ans.A += " , ";
						ans.A += variance[i];
						ans.A += " }";
					}
					else
					{
						ans.A += " , ";
						ans.A += variance[i];
					}
				}
			}
			else
			{
				for (int i = 0; i < tem.column; i++)
				{
					ans.B.addNumInSpace(variancenum[i]);
				}
			}


		}
		else
		{

			for (int i = tem.row - 1; i >= 0; i--)
			{
				//check allrow
				bool allzero = true;
				for (int j = 0; j < tem.column; j++)
				{
					if (tem.matrix[i][j] != 0)
					{
						allzero = false;
						break;
					}
				}
				

					if (allzero) {
						ans.up = true;
						ans.A = "有理解不存在";
						return ans; 
					}
					else //無限多種可能解
					{
						ans.up = true;

						std::string phrase = "";
						std::map<std::string, double> coefficent;
						std::map<std::string, double>::iterator iter;
						std::string text = "";
						for (int j = tem.column - 1; j > i; j--)//處理問題
						{
							//字串分析
							std::stringstream ss;

							//std::cout <<j<<" "<<variance[j] << std::endl;

							for (int k = 0; k < variance[j].size(); k++)
							{
								
								iter = coefficent.find("c");
								if (iter == coefficent.end()) {
									coefficent.insert(std::pair<std::string, double>("c", 0));
								}

								if (variance[j][k] == 'x')//遇到x
								{
									ss.clear();
									//ss.str ="";
									//std::cout << text << std::endl;
									ss << text;
									double _num = 1;
									ss >> _num;
									//std::cout << _num << std::endl;
									std::string text_v = "";
									while (variance[j][k] != ' ' || variance[j][k] != '\0')
									{
										if (variance[j][k] == ' ' || variance[j][k] == '\0') break;
										text_v += variance[j][k];
										//cout << i << text_v << "|||||" << endl;
										k++;
										if (k == variance[j].size()) break;
									}
									//text_v += '\0';

									/*for (int i = 1; i <text_v.size(); i++)
									{
										if (text_v[i]==32) {
											text_v[i] = '\0';
											break;
										}
									}*/
									/*for (iter = coefficent.begin(); iter != coefficent.end(); iter++)
									{
										cout << iter->first << "|||" << iter->second << endl;
									}*/
									//	cout << i << text_v << "|||||" << endl;
									iter = coefficent.find(text_v);

									if (iter == coefficent.end()) {

										coefficent.insert(std::pair<std::string, double>(text_v, tem.matrix[i][j] * _num));
									}
									else {
									//	std::cout<<"     "<<iter->first<<"   " <<iter->second<< std::endl;
										//std::cout << j << " " << variance[j] << std::endl;
										double n = iter->second;
									//	std::cout <<  _num <<std::endl;
										n += tem.matrix[i][j] * _num;
										iter->second = n;
										
									}

									text.clear();
								}
								else if (variance[j][k] == 'c')//遇到+
								{
									ss << text;
									double _num = 1;
									ss >> _num;
									iter = coefficent.find("c");
									if (iter == coefficent.end()) {
										coefficent.insert(std::pair<std::string, double>("c", tem.matrix[i][j] * _num));
									}
									else {
										iter->second += tem.matrix[i][j] * _num;
									}
									text.clear();
								}
								else
								{
									if (variance[j][k] == ' ' || variance[j][k] == '+') {}
									else
									{
										text += variance[j][k];
									}


								}
							}




						}
						///////////////////////////
						//移向
						/*iter = coefficent.find("c");
						if (iter == coefficent.end()) {
							coefficent.insert(std::pair<std::string, double>("c",temvec.getNumInSpace(i)));
						}
						else {
							iter->second += temvec.getNumInSpace(i);
							std::cout << iter->second << std::endl;
						}*/


						if (tem.matrix[i][i] == 0)
						{
							std::map<std::string, double>::iterator itrs;
							std::string small = "z99999999999";
							int smallnum = 0;
							int smllcof = 0;
							std::string deletename = "";
							for (iter = coefficent.begin(); iter != coefficent.end(); iter++)//找出最小的
							{
								if (iter->first != "c")
								{
									if (iter->first < small) {
										small = iter->first;
										deletename = iter->first;
										itrs = iter;
										std::string comp = "";
										for (int q = 1; q < iter->first.size(); q++)
										{
											comp += iter->first[q];
										}
										std::stringstream w;
										w << comp;
										w >> smallnum;
										smllcof = iter->second;
									}
								}
							}

							iter = coefficent.find("c");
							if (iter == coefficent.end()) {
								coefficent.insert(std::pair<std::string, double>("c", 0));
							}


							for (iter = coefficent.begin(); iter != coefficent.end(); iter++)
							{
								if (iter->first != deletename) {
									std::stringstream ss;
									std::string into;
									if (iter->first == "c") {
										//std::cout << temvec.getNumInSpace(i) << std::endl;
										double _num = (temvec.getNumInSpace(i) - iter->second) / smllcof;
										ss << _num;
										ss >> into;
									}
									else
									{
										double _num = iter->second*(-1) / smllcof;
										ss << _num;
										ss >> into;
									}
									phrase += into;
									phrase += iter->first;
									iter++;

									if (iter == coefficent.end())
									{
										phrase += '\0';

									}
									else
									{


										phrase += " + ";

									}
									iter--;
								}
							}

							variance[smallnum - 1] = phrase;

							/*for (int m = variance[smallnum-1].size(); m >=0; m--)
							{
								if (variance[smallnum - 1][m] == '+')
								{

								}
							}*/

						}
						else {
							iter = coefficent.find("c");
							if (iter == coefficent.end()) {
								coefficent.insert(std::pair<std::string, double>("c", 0));
							}

							for (iter = coefficent.begin(); iter != coefficent.end(); iter++)
							{
								std::stringstream ss;
								std::string into;
								if (iter->first == "c") {
									double _num = (temvec.getNumInSpace(i) - iter->second) / tem.matrix[i][i];
									ss << _num;
									ss >> into;
								}
								else
								{
									//std::cout<< iter->first << "    :    "<<iter->second<< std::endl;
									//std::cout << iter->first << std::endl;
									double _num = iter->second*(-1) / tem.matrix[i][i];
									ss << _num;
									ss >> into;
								}
								
								phrase += into;
								phrase += iter->first;
								iter++;
								if (iter == coefficent.end())
								{
									phrase += '\0';

								}
								else
									phrase += " + ";
								iter--;
							}

							variance[i] = phrase;
						}
					}
				
			}
			if (ans.up)
			{
				for (int i = 0; i < tem.column; i++)
				{
					for (int j = variance[i].size() - 1; j >= 0; j--)
					{
						bool anything = false;
						while (1) {
							//	std::cout << variance[i][j] << std::endl;
							if ((variance[i][j] >= 48 & variance[i][j] <= 57) || variance[i][j] == 'c')
							{
								anything = true;
								//variance[i][j + 1] = '\0';
								for (int v = j + 1; v <= variance[i].size() - 1; v++)
								{
									variance[i][v] = '\0';
								}
								break;
							}
							j--;
						}
						if (anything) {
							break;
						}
					}
					if (i == 0)
					{
						ans.A += "{ ";
						ans.A += variance[i];

					}
					else if (i + 1 == tem.column)
					{
						ans.A += " , ";
						ans.A += variance[i];
						ans.A += " }";
					}
					else
					{
						ans.A += " , ";
						ans.A += variance[i];
					}
				}
			}
			else
			{
				for (int i = 0; i < tem.column; i++)
				{
					ans.B.addNumInSpace(variancenum[i]);
				}
			}

		}






		//cout << tem;
		return ans;




	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}
	return re();
}
std::map<double, re> Matrix::eigenvalueAndeigenvectorUnder3()
{

	try
	{
		if (row != column)
			throw "matrix非方陣";
		else if (row > 3)
			throw "請選擇powermethod方法";
		if (row == 2) {
			std::map<double, re>ans;
			std::map<double, re>::iterator it;
			VectorSpace vec(2);
			if (((matrix[0][0] + matrix[1][1])*(matrix[0][0] + matrix[1][1]) - 4 * (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0])) < 0)
				throw "暫無複數處理";
			double x1 = ((matrix[0][0] + matrix[1][1]) + sqrt((matrix[0][0] + matrix[1][1])*(matrix[0][0] + matrix[1][1]) - 4 * (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]))) / 2;
			double x2 = ((matrix[0][0] + matrix[1][1]) - sqrt((matrix[0][0] + matrix[1][1])*(matrix[0][0] + matrix[1][1]) - 4 * (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]))) / 2;
			Matrix tem(*this);
			Matrix a;
			a = tem.eigenMatrix(x1);
			re first = a.linear_system(vec);
			it = ans.find(x1);
			if (it == ans.end()) {
				ans.insert(std::pair<double, re>(x1,first));
			}
			a = tem.eigenMatrix(x2);
			re two = a.linear_system(vec);
			it = ans.find(x2);
			if (it == ans.end()) {
				ans.insert(std::pair<double, re>(x2,two));
			}
			return ans; 
		}
		else
		{
			double p1 = 1;
			double p2 = -1*(matrix[0][0] + matrix[1][1] + matrix[2][2]);
			double p3 =  (matrix[0][0]* matrix[2][2]+ matrix[1][1]* matrix[2][2]+ matrix[0][0] * matrix[1][1]- matrix[0][2] * matrix[2][0]- matrix[0][1] * matrix[1][0]- matrix[1][2] * matrix[2][1]);
			double p4 = -1*(matrix[0][0] * matrix[1][1] * matrix[2][2] -
						matrix[0][2] * matrix[1][1] * matrix[2][0] -
						matrix[0][1] * matrix[1][0] * matrix[2][2] -
						matrix[0][0] * matrix[1][2] * matrix[2][1]);
			double A = p2 * p2 - 3 * p1*p3;
			double B = p2 * p3 - 9 * p1*p4;
			double C = p3 * p3 - 3 * p2*p4;
			double judge = B * B - 4 * A*C;
			if(judge>0) throw "暫無複數處理";
			else
			{
				
				double Q = (p2*p2 - 3 * p3) / 9;
				double R = (2 * p2*p2*p2 - 9 * p3*p2 + 27 * p4) / 54;
				double theata = RadtoAng(acos(R/sqrt(Q*Q*Q)));
				double x1 = -2 * sqrt(Q)*cos(AngtoRad(theata / 3)) - p2 / 3;
				double x2= -2 * sqrt(Q)*cos(AngtoRad(theata +360/ 3)) - p2 / 3;
				double x3= -2 * sqrt(Q)*cos(AngtoRad(theata - 360 / 3)) - p2 / 3;
				Matrix tem(*this);
				Matrix a;
				std::map<double, re>ans;
				std::map<double, re>::iterator it;
				VectorSpace vec(3);
				a = tem.eigenMatrix(x1);
				re first = a.linear_system(vec);
				it = ans.find(x1);
				if (it == ans.end()) {
					ans.insert(std::pair<double, re>(x1, first));
				}
				////
				a = tem.eigenMatrix(x2);
				re Two = a.linear_system(vec);
				it = ans.find(x2);
				if (it == ans.end()) {
					ans.insert(std::pair<double, re>(x2, Two));
				}
				////
				a = tem.eigenMatrix(x3);
				re Two2 = a.linear_system(vec);
				it = ans.find(x3);
				if (it == ans.end()) {
					ans.insert(std::pair<double, re>(x3, Two2));
				}
				return ans;
			}


		}
	}
	catch (const char* str) {
		std::cerr << "錯誤: " << str << std::endl;
	}
	return std::map<double, re>();
}
std::ostream & operator<<(std::ostream & os, const Matrix &A)
{
	for (int i = 0; i < A.row; i++)
	{
	
		for (int j = 0; j <A.column; j++) {
			if (j == A.column - 1) os << std::setw(5)<<A.matrix[i][j];
			else os << std::left<< std::setw(5) << A.matrix[i][j] << " , ";
		}
		os << std::endl;
	}
	os << std::endl;
	return os;
}

bool Linear_independent(std::vector<VectorSpace> _vec)
{
	Matrix tem("tem",_vec[0].getvectorsize(),_vec.size(),_vec);
	//cout << tem;
	int nowColumn = 0;
	double mult = 0;
	for (int _row = 0; _row < tem.getRow(); _row++)
	{
		//cout << _row << "   " << endl << tem;
		if (tem.getnuminMatrix(_row,nowColumn) != 0)
		{
			for (int _column = nowColumn; _column < tem.getRow(); _column++)
			{
				if (_column != _row) {
					mult = tem.getnuminMatrix(_column,_row) / tem.getnuminMatrix(_row, nowColumn);

					for (int i = nowColumn; i < tem.getcolumn(); i++)
					{
						
						tem.replaceNuminMatrix(_column, i, tem.getnuminMatrix(_column,i) - mult*tem.getnuminMatrix(_row, i));

					}
					//cout << mult << "  " << endl << tem;
				}
			}
			nowColumn++;
		}
		else
		{
			if (_row == tem.getRow() - 1) break;
			bool allzero = true;
			bool istriangle = false;
			for (int _column = _row + 1; _column < tem.getRow(); _column++)
			{
				if (_column == tem.getRow() - 1) {
					if (tem.getnuminMatrix(_column,_row) == 0)
					{
						istriangle = true;
					}
				}
				if (tem.getnuminMatrix(_column, _row) != 0) { //row->nowcolumn?
					std::vector<double>change;
					for (int i = 0; i <tem.getcolumn(); i++)
					{
						change.push_back(tem.getnuminMatrix(_column, i));
					}
					
					for (int i = 0; i < tem.getcolumn(); i++)
					{
						//change.push_back(tem.getnuminMatrix(_column, i));
						tem.replaceNuminMatrix(_column, i,tem.getnuminMatrix(_row, i));
					}
					for (int i = 0; i < tem.getcolumn(); i++)
					{
						//change.push_back(tem.getnuminMatrix(_column, i));
						tem.replaceNuminMatrix(_row, i, change[i]);
					}
					//tem.matrix[_column] = tem.matrix[_row];
					//tem.matrix[_row] = change;
					allzero = false;
					break;
				}
			}
			if (allzero) {
				if (istriangle == false)
				{
					_row--;
					nowColumn++;
				}
			}
		}
	}

	//cout << tem << endl;
	/*有0列代表可以組合出為ld 否則li*/
	bool ans = true; 
	for (int i = 0; i < tem.getRow(); i++)
	{
		bool allzero = true;
		for (int j = 0; j < tem.getcolumn(); j++)
		{
			if (tem.getnuminMatrix(i,j)!= 0) {
				allzero = false;
				break;
			}
		}
	
		if (allzero == true)
		{
			ans = false;
			break;
		}
		
	}
	//cout << tem;
	return ans;
}

bool Linear_independent(int howmany,VectorSpace *_vec)
{
	std::string nm = "name";
	int m = _vec[0].getvectorsize();
	Matrix tem(m, howmany, *_vec);
	//cout << tem;
	int nowColumn = 0;
	double mult = 0;
	for (int _row = 0; _row < tem.getRow(); _row++)
	{
		//cout << _row << "   " << endl << tem;
		if (tem.getnuminMatrix(_row, nowColumn) != 0)
		{
			for (int _column = nowColumn; _column < tem.getRow(); _column++)
			{
				if (_column != _row) {
					mult = tem.getnuminMatrix(_column, _row) / tem.getnuminMatrix(_row, nowColumn);

					for (int i = nowColumn; i < tem.getcolumn(); i++)
					{

						tem.replaceNuminMatrix(_column, i, tem.getnuminMatrix(_column, i) - mult * tem.getnuminMatrix(_row, i));

					}
					//cout << mult << "  " << endl << tem;
				}
			}
			nowColumn++;
		}
		else
		{
			if (_row == tem.getRow() - 1) break;
			bool allzero = true;
			bool istriangle = false;
			for (int _column = _row + 1; _column < tem.getRow(); _column++)
			{
				if (_column == tem.getRow() - 1) {
					if (tem.getnuminMatrix(_column, _row) == 0)
					{
						istriangle = true;
					}
				}
				if (tem.getnuminMatrix(_column, _row) != 0) { //row->nowcolumn?
					std::vector<double>change;
					for (int i = 0; i < tem.getcolumn(); i++)
					{
						change.push_back(tem.getnuminMatrix(_column, i));
					}

					for (int i = 0; i < tem.getcolumn(); i++)
					{
						//change.push_back(tem.getnuminMatrix(_column, i));
						tem.replaceNuminMatrix(_column, i, tem.getnuminMatrix(_row, i));
					}
					for (int i = 0; i < tem.getcolumn(); i++)
					{
						//change.push_back(tem.getnuminMatrix(_column, i));
						tem.replaceNuminMatrix(_row, i, change[i]);
					}
					//tem.matrix[_column] = tem.matrix[_row];
					//tem.matrix[_row] = change;
					allzero = false;
					break;
				}
			}
			if (allzero) {
				if (istriangle == false)
				{
					_row--;
					nowColumn++;
				}
			}
		}
	}

	//cout << tem << endl;
	/*有0列代表可以組合出為ld 否則li*/
	bool ans = true;
	for (int i = 0; i < tem.getRow(); i++)
	{
		bool allzero = true;
		for (int j = 0; j < tem.getcolumn(); j++)
		{
			if (tem.getnuminMatrix(i, j) != 0) {
				allzero = false;
				break;
			}
		}

		if (allzero == true)
		{
			ans = false;
			break;
		}

	}
	//cout << tem;
	return ans;
}
