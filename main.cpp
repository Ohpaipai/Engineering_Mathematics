
#include"VectorAndMatrix.h"

int main() {
	/*long double a[2] = {1,1};
	long double a1[2] = { 2,3 };
	long double a2[2] = { 3,4 };
	long double a3[2] = { 4,6 };
	long double a4[2] = { 5,5 };
	VectorSpace v0("nam", 2, a);
	VectorSpace v1("nam", 2, a1);
	VectorSpace v2("nam", 2, a2);
	VectorSpace v3("nam", 2, a3);
	VectorSpace v4("nam", 2, a4);
	std::vector<VectorSpace>vv;
	vv.push_back(v0);
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	vv.push_back(v4);
	
	std::cout << leastSquare(vv) << std::endl;*/
	int aq =3 ;
	
	std::fstream file1;
	file1.open("v1.txt", std::ios::in);
	std::fstream file2;
	file2.open("v2.txt", std::ios::in);
	long double *a=new long double[aq];
	long double *b = new long double[aq];
	for (int i = 0; i < aq; i++)
	{
		file1 >> a[i];
		file2>> b[i];
		//std::cout << a[i] << "  " << b[i] << std::endl;
	}
	VectorSpace v0("nam", aq, a);
	VectorSpace v1("nam", aq, b);
	//std::cout << v0 << v1;
	//VectorSpace ans = v0 ^ v1;
	//std::cout << v0.AngleBetween(v1)<< std::endl;
	//std::cout << v0.Parallel(v1) << std::endl;
	//std::cout <<ans;
	std::fstream file3;
	file3.open("m1.txt", std::ios::in);
	
	Matrix ma(aq, aq);
	for (int i = 0; i < aq; i++)
	{
		for (int j = 0 ; j < aq; j++)
		{
			long double l;
			file3 >> l;
			//std::cout << l << std::endl;
			ma.replaceNuminMatrix(i, j, l);
		}
	}
	//std::cout << ma;
	//std::cout << ma;
	std::cout << ma.Rank() << std::endl;
	//file4 << ma.Rank();
	ma = ma.Guass();
	//for (int i = 0; i < aq; i++)
	//{
	//	for (int j = 0; j < aq; j++)
	//	{
	//		file4 << ma<< "    ";
	//	}
	//	file4 << "\n";
	//}

	//file4 << ma << "    ";



//	long double a[5] = { 1,2,3,4,5 };
//	long double b[3] = { 1,2,3 };
//	long double c[3] = { 2,4,6 };
//	long double aa[2][2] = { {4,2},{3,-1} };
//	long double ab[3][4] = { {1, 2, 3, 3}, { 2,1,0,6 }, { 2,7,4,5 } };
//	//{3,0,2,2},{-6,42,24,54},{21,-21,0,-15}
//	//{1, 0, 0, 0}, { 0,1,0,0 }, { 0,0,0,1 }
//	//{5,2,1},{-3,4,-11},{2,-1,4}
//	//{4,5,6},{8,10,12},{9,6,7}
//	long double x[3] = {1,1,1};
//	long double y[3] = { 1,2,2 };
//	long double z[3] = {1,1,0};
//	long double k[3] = { 0,0,0 };
//	VectorSpace x1("nam", 3, x);
//	VectorSpace x2("nam", 3, y);
//	VectorSpace x3("nam", 3, z);
//	VectorSpace x4("nam", 3, k);
//	std::vector<VectorSpace>f;
//	f.push_back(x1);
//	f.push_back(x2);
//	
//	Matrix m6("d", 3, 2, f);
////	std::cout << m6;
//	//m6.Rank();
//	//cout << m6;
//	std::vector<std::vector<long double>>t;
//	t.resize(2);
//	for (int i = 0; i < 2; i++)
//	{
//		t[i].resize(2);
//		for (int j = 0; j < 2; j++)
//		{
//			t[i][j]=aa[i][j];
//		}
//	}
//	std::vector<std::vector<long double>>tt;
//	tt.resize(3);
//	for (int i = 0; i < 3; i++)
//	{
//		tt[i].resize(4);
//		for (int j = 0; j < 4; j++)
//		{
//			tt[i][j] = ab[i][j];
//		}
//	}
//	std::string name = "d";
//	Matrix m1(name,2, 2,t);	
//	//cout << m1.Rank() << endl;
//	std::map<long double, re>an;
//	std::map<long double, re>::iterator it;
//	an = m1.powerMethod();
//	for (it=an.begin();it!=an.end();it++)
//	{
//		std::cout << it->first << std::endl;
//		if (it->second.up) std::cout << it->second.A << std::endl;
//		else std::cout << it->second.B;
//	}
//	
//	Matrix m2(name, 3, 4, tt);
	//cout << Linear_independent(f) << endl;
	//cout << m1.Inverse() << endl;
	//cout << m1.Rank() << endl;
	//cout << m2.Rank() << endl;
	//cout << m2.Rank() << endl;
	//vector<VectorSpace>ans = Orthonormalbasis(f);
	//cout << "----------------------------------" << endl;
	/*for (int i = 0; i < ans.size(); i++)
	{
		//cout << f[i];
		cout << ans[i];
	}*/
	system("pause");
	return 0;
}




