
#include"Matrix.h"
int main() {

	double a[5] = { 1,2,3,4,5 };
	double b[3] = { 1,2,3 };
	double c[3] = { 2,4,6 };
	double aa[3][3] = { {1,4,-2},{0,2,3},{4,-1,1} };
	double ab[3][4] = { {3,0,2,2},{-6,42,24,54},{21,-21,0,-15} };
	vector<vector<double>>t;
	t.resize(3);
	for (int i = 0; i < 3; i++)
	{
		t[i].resize(3);
		for (int j = 0; j < 3; j++)
		{
			t[i][j]=aa[i][j];
		}
	}
	vector<vector<double>>tt;
	tt.resize(3);
	for (int i = 0; i < 3; i++)
	{
		tt[i].resize(4);
		for (int j = 0; j < 4; j++)
		{
			tt[i][j] = aa[i][j];
		}
	}
	string name = "d";
	Matrix m1(name,3, 3,t);	
	Matrix m2(name, 3, 4, tt);
	cout << m1.Inverse() << endl;
	//cout << m1.Rank() << endl;
	cout << m2.Rank() << endl;
	system("pause");
	return 0;
}