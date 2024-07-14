#include <iostream>

class S21Matrix {

	private:
		int rows_, cols_;
		double **matrix_;

	public:
		S21Matrix() : rows_(3), cols_(3) {
			matrix_ = new double* [rows_];
			for (int i = 0; i < cols_; i++)
				matrix_[i] = new double [cols_];
		}

		S21Matrix(int row, int col) : rows_(row), cols_(col) {
			matrix_ = new double* [rows_];
			for (int i = 0; i < cols_; i++)
				matrix_[i] = new double [cols_];
		}

		~S21Matrix() {
			if (matrix_) {
				for (int i = 0; i < cols_; i++) {
					delete[] matrix_[i];
				}
				delete[] matrix_;
			}
		}

		void filling_matrix() {
			for(int i = 0; i < rows_; i++) {
				for(int j = 0; j < cols_; j++) {
					matrix_[i][j] = (2.2 + i) * (1.1 + j);
				}
			}
		}

		void print_matrix() {
			for(int i = 0; i < rows_; i++) {
				for(int j = 0; j < cols_; j++) {
					std::cout << matrix_[i][j] << "   ";
				}
				std::cout << std::endl;
			}
		}
	};


int main() {
//	S21Matrix A;
//	A.filling_matrix();
//	A.print_matrix();

//  S21Matrix B(2,2);
//	B.filling_matrix();
//	B.print_matrix();
  
	S21Matrix C(3, 2);
	C.filling_matrix();
  C.print_matrix();

	return 0;
}
