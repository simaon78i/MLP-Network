// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cmath>



// You don't have to use the struct. Can help you with MlpNetwork.h
typedef struct matrix_dims {
    int rows, cols;
}matrix_dims;


// Insert Matrix class here...
class Matrix{
 private:
  float *matrix;
  int rows;
  int cols;
 public:
  Matrix(int rows,int cols);
  Matrix();
  Matrix(Matrix const &m);
  ~Matrix();
  int get_rows() const;
  int get_cols() const;
  Matrix transpose();
  void plain_print();
  Matrix& vectorize();
  Matrix dot(Matrix const &m);
  float norm();
  Matrix rref();
  int argmax() const;
  float sum() const;
  Matrix& operator+=(const Matrix& m);
  friend Matrix operator+(const Matrix& m1 ,const Matrix& m2);
  Matrix& operator=(const Matrix &m);
  friend Matrix operator*(const Matrix& m1,const Matrix& m2);
  friend Matrix operator*(const Matrix& m,float scalar);
  friend Matrix operator*(float scalar,const Matrix& m);
  float& operator()(int i,int j) const;
  float& operator [](int k) const;
  friend std::ostream & operator<<(std::ostream& printed,Matrix &m);
  friend std:: istream & operator>>(std::istream& printed, Matrix &m);
};




#endif //MATRIX_H