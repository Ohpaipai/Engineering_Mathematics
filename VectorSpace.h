#pragma once
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#define pi 3.14159265359
#define RadtoAng(N) N*180/pi
#define AngtoRad(N) N*pi/180
	using namespace std;
class VectorSpace
{
public:
	VectorSpace();
	~VectorSpace();
	VectorSpace(string _name, int _size, double *a);
	VectorSpace(string _name, int _size, vector<double>_vec);
	VectorSpace(string _name);
	VectorSpace(string _name,int _size);
	VectorSpace(int _size);
	void addNumInSpace(double _num);
	void changeNumInSpace(double _num, int place);
	VectorSpace(const VectorSpace& _vec);
	friend ostream& operator<<(ostream& os, const VectorSpace&);
	int getvectorsize();
	void deleteNumplace(int place);
	double getNumInSpace(int place);
	string getName();
	VectorSpace operator +(const VectorSpace& _vec);
	VectorSpace operator =(const VectorSpace& _vec);
	VectorSpace operator -(const VectorSpace& _vec);
	double operator *(const VectorSpace& _vec);
	VectorSpace operator /(const double& _Scalar);
	VectorSpace operator *(const double& _Scalar);
	VectorSpace operator ^(const VectorSpace& _vec);
	double Norm();
	VectorSpace Normalization();
	double AngleBetween(VectorSpace& _vec);
	double TriangleArea(VectorSpace& _vec);
	VectorSpace Component(VectorSpace& _vec);
	VectorSpace Projection(VectorSpace& _vec);
	bool Parallel(VectorSpace &_vec);
	bool Orthohonal(VectorSpace&_vec);
	
	//Linear_independent judgement
	//Orthonormal basis
private:
	vector<double>vec;
	string name;
	int Vectorsize;
};

vector<VectorSpace> Orthonormalbasis(vector<VectorSpace> _vec);