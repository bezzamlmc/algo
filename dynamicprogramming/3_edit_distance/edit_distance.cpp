#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

//C Style matrix , stored by row
typedef vector<int> Row;
typedef vector<Row> Matrix;

int compute_dmatrix(const string& str1, const string& str2) {
//The dmatrix has a size of length of str2 * length of str1, where the columns have the dimension of str2
// Initialize the matrix
	size_t nrows = str2.size() + 1;
	size_t ncolumns = str1.size() + 1;
	Matrix mat(nrows);
	Row firstRow(ncolumns);
	for (size_t j = 0; j < ncolumns; j++)
		firstRow.at(j) = j;
	mat.at(0) = firstRow;
	for (size_t i = 1; i <nrows; i++) {
		Row thisRow(ncolumns);
		thisRow.at(0) = i;
		for (int j = 1; j < ncolumns; j++)
			thisRow.at(j) = 0;
		mat.at(i) = thisRow;
	}
	for (size_t i = 1; i < nrows; i++) {
		for (size_t j = 1; j < ncolumns; j++) {
			int minval = mat[i][j - 1l] + 1;
//			std::cout << "i j-1 " << i << " " << j - 1 << " " << mat[i][j - 1l] << std::endl;
			int val = mat[i - 1l][j] + 1;
//			std::cout << "i-1 j-1 " << i - 1 << " " << j << " " << mat[i-1][j] << std::endl;
			if (val < minval)
				minval = val;
			val = mat[i - 1l][j - 1l];

			if (str2[i-1]!=str1[j-1])
				val += 1;
			if (val < minval)
				minval = val;
//			std::cout << "i-1 j-1 " << i - 1 << " " << j - 1 << " " << mat[i-1l][j - 1l] << " " << str1[i - 1] << " " << str2[j - 1] << std::endl;
			mat[i][j] = minval;
//			std::cout << i << " " << j << " " <<  minval << std::endl;
		}
	}
	return mat[nrows - 1l][ncolumns - 1l];
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  return compute_dmatrix(str1,str2);
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
