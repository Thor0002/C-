#include <iostream>
#include <exception>
#include <vector>
using namespace std;

class Matrix{
  public:
  Matrix(){M = {{}};}
  Matrix(const int& num_rows, const int& num_cols){
	  if(num_rows < 0 or num_cols){throw out_of_range("");}
	  else {
	  vector<int> v(num_cols);
	  vector<vector<int>> new_M(num_rows, v);
	  M = new_M;
	  }
  }
void Reset(const int& new_num_rows, const int& new_num_cols){
	if (new_num_rows < 0 or new_num_cols < 0)
	{throw out_of_range("");}
	else{
	vector<int> v(new_num_cols,0);
    vector<vector<int>> new_M(new_num_rows, v);
    M = new_M;
	}
}
int At(const int& rows, const int& cols) const{
	if(rows < 0 or cols < 0 or rows >= M.size() or cols >= M[0].size())
	{throw out_of_range("");}
	else {
		return M[rows][cols];
	}
}

int& At(const int& rows, const int& cols){
	if(rows < 0 or cols < 0 or rows >= M.size() or cols >= M[0].size())
	{throw out_of_range("");}
	else {
		return M[rows][cols];
	}
}

int GetNumRows() {
	if (M[0].size()) {return 0;}
	else {return M.size();}
}

int GetNumColumns(){
	return M[0];
}
  private:
  vector<vector<int>> M;
};

istream& operator>>(istream& stream, Matrix& M){
	int num_rows, num_cols, m;
	stream >> num_rows >> num_cols;
	Matrix new_M(num_rows, num_cols);
    if(num_rows < 0 or num_cols){throw out_of_range("");}
    else {
	for(int i = 0; i < num_rows; i++){
		for (int j = 0; j < num_cols; j++){
			cin >> m;
			new_M [i][j] = m;
		}
	}
	}
	M = new_M;
	return stream;
}



int main() {
	return 0;
}
