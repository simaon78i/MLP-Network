#include "Matrix.h"
#include <iostream>
#include <cmath>
#define NUMBER_FOR_PRINTING 0.1

Matrix::Matrix (int rows, int cols): rows(rows), cols(cols)
{
  if (rows<=0 || cols<=0)
  {
    throw std::exception();
  }
  this->matrix=new float [rows*cols];
  for (int i=0;i<rows*cols;i++)
  {
    this->matrix[i]=0;
  }
}
Matrix::Matrix (): Matrix (1,1)
{}

Matrix::Matrix (Matrix const &m):rows(m.rows),cols(m.cols)
{
  matrix = new float [rows*cols];
  for (int i=0;i<rows*cols;i++)
  {
    this->matrix[i]=m.matrix[i];
  }
}
Matrix:: ~Matrix()
{

  delete []this->matrix;
}

int Matrix :: get_rows() const
{
  return this->rows;
}

int Matrix::get_cols () const
{
  return this->cols;
}

Matrix Matrix:: transpose()
{
  Matrix tmp(*this);
  for(int i=0;i<cols;i++)
  {
    for(int j=0;j<rows;j++)
    {
      this->matrix[(i*rows)+j]=tmp.matrix[(j*cols)+i];
    }
  }
  int temp=rows;
  rows=cols;
  cols=temp;
  return *this;
}

void Matrix::plain_print()
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(j!=cols-1)
      {
        std::cout << matrix[i * cols + j] << " ";
      }
      else
      {
        std::cout<<matrix[i * cols + j];
      }
    }
    std::cout << std::endl;
  }
  std::cout <<std::endl;

}

Matrix& Matrix::vectorize ()
{
  this->rows= this->rows* this->cols;
  this->cols=1;
  return *this;
}
Matrix Matrix::dot (const Matrix &m)
{
  if(this->rows !=m.rows || this->cols!=m.cols)
  {
    throw std:: exception();
  }
  Matrix new_mat(*this);
  for (int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      new_mat.matrix[(i*cols)+j]= (this->matrix[(i*cols)+j])*(m.matrix[
          (i*cols)+j]);
    }
  }
  return new_mat;
}
float Matrix::norm ()
{
  float sum=0;
  for( int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      sum+= (this->matrix[(i*cols)+j])*(this->matrix[(i*cols)+j]);
    }
  }
  return std::sqrt (sum);
}

Matrix Matrix::rref()
{
  Matrix new_mat(*this);
  int lead = 0;
  for (int r = 0; r < new_mat.rows; ++r)
  {
    if (new_mat.cols <= lead)
    {
      break;
    }
    int i = r;
    while (new_mat(i, lead) == 0)
    {
      ++i;
      if (new_mat.rows == i)
      {
        i = r;
        ++lead;
        if (new_mat.cols == lead)
        {break;}
      }
    }
    if (new_mat.cols == lead)
    {break;}
    for (int j = 0; j < new_mat.cols; ++j)
    {
      float temp = new_mat(r, j);
      new_mat(r, j) = new_mat(i, j);
      new_mat(i, j) = temp;
    }
    float val = new_mat(r, lead);
    for (int j = 0; j < new_mat.cols; ++j)
    {
      new_mat (r, j) /= val;
    }
    for (int k = 0; k < new_mat.rows; ++k)
    {
      if (k != r)
      {
        float val = new_mat(k, lead);
        for (int j = 0; j < new_mat.cols; ++j)
        {
          new_mat (k, j) -= val * new_mat (r, j);
        }
      }
    }
    ++lead;
  }
  return new_mat;
}



int Matrix::argmax () const
{
  float largest= this->matrix[0];
  int largest_idx=0;
  for(int i=1;i<rows*cols;i++)
  {
    if(this->matrix[i]>largest)
    {
      largest= this->matrix[i];
      largest_idx=i;
    }
  }
  return largest_idx;
}
float Matrix::sum () const
{
  float sum=0;
  for(int i=0;i<rows*cols;i++)
  {
    sum+= this->matrix[i];
  }
  return sum;
}

Matrix& Matrix::operator+= (const Matrix &m)
{
  if(this->cols!=m.cols || this->rows!=m.rows)
  {
    throw std::exception();
  }
  for(int i=0;i<rows*cols;i++)
  {
    this->matrix[i]+=m.matrix[i];
  }
  return *this;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
  if(m1.cols!=m2.cols || m1.rows!=m2.rows)
  {
    throw std::exception();
  }
  Matrix new_mat (m1);
  for (int i=0;i<m1.rows*m2.cols;i++)
  {
    new_mat.matrix[i]+=m2.matrix[i];
  }
  return new_mat;
}

Matrix& Matrix::operator = (const Matrix &m)
{
  if(this!= &m)
  {
    delete [] this->matrix;
    this->rows = m.rows;
    this->cols = m.cols;
    this->matrix = new float[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
      this->matrix[i] = m.matrix[i];
    }
  }
  return *this;
}

Matrix operator* (const Matrix &m1,const Matrix &m2)
{
  if (m1.cols != m2.rows)
  {
    throw std::exception();
  }
  Matrix new_mat = Matrix(m1.rows, m2.cols);
  for (int i=0;i<m1.rows;i++)
  {
    for (int j=0;j<new_mat.cols;j++)
    {
      float sum=0;
      for(int k=0;k<m1.cols;k++)
      {
        sum+=m1(i,k)*m2(k,j);
      }
      new_mat(i,j)=sum;
    }
  }
  return new_mat;
}

float &Matrix::operator() (int i, int j) const
{
  if(i<0 || i> this->rows-1 || j<0 || j> this->cols-1)
  {
    throw std::exception();
  }
  return this->matrix[i*cols +j];
}

float& Matrix::operator[] (int k) const
{
  if(k<0 || k > this->cols*rows-1)
  {
    throw std::exception();
  }
  return this->matrix[k];
}

Matrix operator* (const Matrix &m, float scalar)
{
  Matrix new_mat(m);
  for (int i=0;i<new_mat.rows*new_mat.cols;i++)
  {
    new_mat.matrix[i]*=scalar;
  }
  return new_mat;
}

Matrix operator* (float scalar, const Matrix &m)
{
  return m*scalar;
}

std::ostream &operator<< (std::ostream &printed, Matrix &m)
{
  for (int i=0;i<m.rows*m.cols;i++)
  {
    if(m.matrix[i]>NUMBER_FOR_PRINTING)
    {
      std::cout <<"**";
    }
    else
    {
      std::cout<<" ";
    }
    if((i+1) % m.cols==0)
    {
      std::cout<<std::endl;
    }
  }
  return printed;
}

std::istream &operator>> (std::istream &printed, Matrix &m)
{
  for (int i=0;i<m.rows*m.cols;i++)
  {
    float val;
    if(!printed.read (reinterpret_cast<char *>(&val),sizeof (float )))
    {
      throw std::exception();
    }
    m[i]=val;
  }
  return printed;
}



















