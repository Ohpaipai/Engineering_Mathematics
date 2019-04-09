#pragma once
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<fstream>
#define pi 3.14159265359
#define RadtoAng(N) N*180/pi
#define AngtoRad(N) N*pi/180
	
class VectorSpace
{
public:
	VectorSpace();
	~VectorSpace();
	VectorSpace(std::string _name, int _size, long double *a);
	VectorSpace(std::string _name, int _size, std::vector<long double>_vec);
	VectorSpace(std::string _name);
	VectorSpace(std::string _name, long double a); 
	void changename(std::string _name);
	VectorSpace(std::string _name,int _size);
	VectorSpace(int _size);
	void addNumInSpace(long double _num);
	void changeNumInSpace(long double _num, int place);
	VectorSpace(const VectorSpace& _vec);
	friend std::ostream& operator<<(std::ostream& os, const VectorSpace&);
	int getvectorsize();
	void deleteNumplace(int place);
	long double getNumInSpace(int place);
	std::string getName();
	VectorSpace operator +(const VectorSpace& _vec);
	VectorSpace operator =(const VectorSpace& _vec);
	VectorSpace operator -(const VectorSpace& _vec);
long double operator *(const VectorSpace& _vec); //¤º¿n
	VectorSpace operator /(const long double& _Scalar);
	VectorSpace operator *(const long double& _Scalar);
	VectorSpace operator ^(VectorSpace& _vec);
long double Norm();
	VectorSpace Normalization();
	long double AngleBetween(VectorSpace& _vec);
	long double TriangleArea(VectorSpace& _vec);
	long double Component(VectorSpace& _vec);
	VectorSpace Projection(VectorSpace& _vec);
	bool Parallel(VectorSpace &_vec);
	bool Orthohonal(VectorSpace&_vec);
	
	//Linear_independent judgement
private:
	std::vector<long double>vec;
	std::string name;
	int Vectorsize;
};

std::vector<VectorSpace> Orthonormalbasis(std::vector<VectorSpace> _vec);