#include "Activation.h"
Matrix activation::relu (const Matrix &m)
{
  Matrix new_matrix=Matrix(m);
  for(int i=0;i<new_matrix.get_rows()*new_matrix.get_cols();i++)
  {
    if (new_matrix[i]<0)
    {
      new_matrix[i]=0;
    }
  }
  return new_matrix;
}

Matrix activation::softmax (const Matrix &m)
{
  Matrix new_matrix=Matrix(m);
  float sum=0;
  for (int i=0;i<new_matrix.get_rows()*new_matrix.get_cols();i++)
  {
    float exp_num=std::exp (new_matrix[i]);

    new_matrix[i]=exp_num;
    sum+=new_matrix[i];

  }
  return (1/sum)*new_matrix;
}
