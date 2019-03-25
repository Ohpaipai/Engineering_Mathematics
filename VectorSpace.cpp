#include "VectorSpace.h"



VectorSpace::VectorSpace()
{
	Vectorsize = 0;
	vec.clear();
	name.clear();
}


VectorSpace::~VectorSpace()
{
	Vectorsize = 0;
	vec.clear();
	name.clear();
}

VectorSpace::VectorSpace(string _name, int _size, double * a)
{
	//use try catch
	name = _name;
	Vectorsize = _size;
	for (int i = 0; i < _size; i++)
	{
		vec.push_back(a[i]);
	}
	
}

VectorSpace::VectorSpace(string _name, int _size, vector<double> _vec)
{
	//use try catch
	name = _name;
	Vectorsize = _size;
	vec = _vec;
}

VectorSpace::VectorSpace(string _name)
{
	name = _name;
}

VectorSpace::VectorSpace(string _name, int _size)
{
	//use try catch
	name = _name;
	Vectorsize = _size;
}

void VectorSpace::addNumInSpace(double _num)
{
	vec.push_back(_num);
	Vectorsize += 1;
}

void VectorSpace::changeNumInSpace(double _num, int place)
{
	vec[place] = _num;
}

VectorSpace::VectorSpace(const VectorSpace & _vec)
{
	vec =_vec.vec;
	Vectorsize = _vec.Vectorsize;
}

int VectorSpace::getvectorsize()
{
	return Vectorsize;
}

void VectorSpace::deleteNumplace(int place)
{
	vector<double>newone;
	for (int i = 0; i <Vectorsize; i++)
	{
		if(i==place){}
		else newone.push_back(vec[i]);
	}
	vec.clear();
	vec = newone;
	Vectorsize -= 1;
}

double VectorSpace::getNumInSpace(int place)
{
	return vec[place];
}

string VectorSpace::getName()
{
	return name;
}

VectorSpace VectorSpace::operator+(const VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		VectorSpace ans;
		ans.Vectorsize = Vectorsize;
		for (int i = 0; i <Vectorsize; i++)
		{
			ans.vec.push_back((vec[i] + _vec.vec[i]));
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return VectorSpace();
}

VectorSpace VectorSpace::operator=(const VectorSpace & _vec)
{
	vec = _vec.vec;
	Vectorsize = _vec.Vectorsize;
	return *this;
}

VectorSpace VectorSpace::operator-(const VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		VectorSpace ans;
		ans.Vectorsize = Vectorsize;
		for (int i = 0; i < Vectorsize; i++)
		{
			ans.vec.push_back((vec[i] - _vec.vec[i]));
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return VectorSpace();
}

double VectorSpace::operator*(const VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		double ans=0;
		
		for (int i = 0; i < Vectorsize; i++)
		{
			ans+=vec[i]*_vec.vec[i];
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return 0.0;
}

VectorSpace VectorSpace::operator/(const double & _Scalar)
{
	for (int i = 0; i < Vectorsize; i++)
	{
		vec[i] /= _Scalar;
	}
	return *this;
}

VectorSpace VectorSpace::operator*(const double & _Scalar)
{
	for (int i = 0; i < Vectorsize; i++)
	{
		vec[i] *= _Scalar;
	}
	return *this;
}

VectorSpace VectorSpace::operator^(const VectorSpace & _vec)
{
	try
	{
		if (Vectorsize!=3&&_vec.Vectorsize!=3)
			throw "超過三維空間";
		VectorSpace ans;
		ans.Vectorsize = Vectorsize;
		ans.vec.push_back(vec[1] * _vec.vec[2] - vec[2] * _vec.vec[1]);
		ans.vec.push_back(vec[0] * _vec.vec[2] - vec[2] * _vec.vec[0]);
		ans.vec.push_back(vec[0] * _vec.vec[1] - vec[1] * _vec.vec[0]);
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return VectorSpace();
}

double VectorSpace::Norm()
{
	double ans = 0;
	for (int i = 0; i < Vectorsize; i++)
	{
		ans += vec[i] * vec[i];
	}
	ans = sqrt(ans);
	return ans;
}

VectorSpace VectorSpace::Normalization()
{
	double denomainater = this->Norm();
	VectorSpace ans;
	ans.Vectorsize = Vectorsize;
	for (int i = 0; i < Vectorsize; i++)
	{
		ans.vec.push_back(vec[i] / denomainater);
	}
	return ans;
}

double VectorSpace::AngleBetween(VectorSpace & _vec)
{

	try
	{
		if (Vectorsize > 3 && _vec.Vectorsize > 3)
			throw "超過三維空間";
		return RadtoAng(acos((*this*_vec) / (_vec.Norm()*this->Norm())));
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return 0;
	
}

double VectorSpace::TriangleArea(VectorSpace & _vec)
{
	try
	{
		if (Vectorsize !=2 && _vec.Vectorsize !=2)
			throw "不是二維空間";
		return 0.5*this->Norm()*_vec.Norm()*RadtoAng(sin(this->AngleBetween(_vec)));
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return 0;
	
}

VectorSpace VectorSpace::Component(VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		VectorSpace ans;
		ans.Vectorsize = Vectorsize;
		for (int i = 0; i < Vectorsize; i++)
		{
			ans.vec.push_back((_vec.vec[i]-vec[i]));
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return VectorSpace();
}

VectorSpace VectorSpace::Projection(VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		VectorSpace ans;
		ans.Vectorsize = Vectorsize;
		double denominator = ((*this*_vec) / _vec.Norm());
		for (int i = 0; i < Vectorsize; i++)
		{
			ans.vec.push_back(_vec.vec[i]*denominator);
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return VectorSpace();
}

bool VectorSpace::Parallel(VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		bool ans = true;
		for (int i = 1; i < Vectorsize; i++)
		{
			if (vec[i - 1] / _vec.vec[i - 1] != vec[i] / _vec.vec[i])
			{
				ans = false;
				break;
			}
		}
		return ans;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return false;
}

bool VectorSpace::Orthohonal(VectorSpace & _vec)
{
	try
	{
		if (Vectorsize != _vec.Vectorsize)
			throw "size不一樣";
		
		double ans = *this*_vec;
		if (ans == 0)return true;
		else return false;
	}
	catch (const char* str) {
		cerr << "錯誤: " << str << endl;
	}
	return false;
}



ostream & operator<<(ostream & os, const VectorSpace & _vec)
{
	os << "{";
	for (int i = 0; i <_vec.Vectorsize; i++)
	{
		if(i==0)
			os << " " << _vec.vec[i]  ;
		else
			os << "," << _vec.vec[i];
			
	}
	os << " }" << endl;
	return os;
}
