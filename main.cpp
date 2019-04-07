
#include"VectorAndMatrix.h"
int main() {

	
	double a[5] = { 1,2,3,4,5 };
	double b[3] = { 1,2,3 };
	double c[3] = { 2,4,6 };
	double aa[3][3] = { {7,7,9},{8,8,5},{5,78,3} };
	double ab[3][4] = { {1, 2, 3, 3}, { 2,1,0,6 }, { 2,7,4,5 } };
	//{3,0,2,2},{-6,42,24,54},{21,-21,0,-15}
	//{1, 0, 0, 0}, { 0,1,0,0 }, { 0,0,0,1 }
	//{5,2,1},{-3,4,-11},{2,-1,4}
	//{4,5,6},{8,10,12},{9,6,7}
	double x[3] = {1,1,1};
	double y[3] = { 1,2,2 };
	double z[3] = {1,1,0};
	double k[3] = { 0,0,0 };
	VectorSpace x1("nam", 3, x);
	VectorSpace x2("nam", 3, y);
	VectorSpace x3("nam", 3, z);
	VectorSpace x4("nam", 3, k);
	std::vector<VectorSpace>f;
	f.push_back(x1);
	f.push_back(x2);
	f.push_back(x3);
	Matrix m6("d", 3, 3, f);
	//m6.Rank();
	//cout << m6;
	std::vector<std::vector<double>>t;
	t.resize(3);
	for (int i = 0; i < 3; i++)
	{
		t[i].resize(3);
		for (int j = 0; j < 3; j++)
		{
			t[i][j]=aa[i][j];
		}
	}
	std::vector<std::vector<double>>tt;
	tt.resize(3);
	for (int i = 0; i < 3; i++)
	{
		tt[i].resize(4);
		for (int j = 0; j < 4; j++)
		{
			tt[i][j] = ab[i][j];
		}
	}
	std::string name = "d";
	Matrix m1(name,3, 3,t);	
	//cout << m1.Rank() << endl;
	re ans = m1.linear_system(x4);
	if (ans.up) std::cout << ans.A << std::endl;
	else std::cout << ans.B;
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




