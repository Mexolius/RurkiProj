#include <iostream>
#include "Matrix.h"
#include "Numeric.h"

using namespace std;

int main()
{
	vector<vector<float>> startmatrix{
		{54,234,11},
		{243,-12,23},
		{-23,24,54}
	};
	vector<float> ret(startmatrix.size());
	Matrix mat(startmatrix.size(), startmatrix);
	mat.toString();
	ret = mat.gauss_for({ 34,6,2 });
	mat.toString();
	for (auto a : ret) cout << a << endl;
	cin.ignore();
	cin.get();
}