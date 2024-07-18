#include "Dense.h"

Dense::Dense (Matrix &weights, Matrix &bias, activation::ActivationFunction
activation)
:weights(weights) ,bias(bias),activation(activation){}

Matrix &Dense::get_weights () const
{
  return this->weights;
}
Matrix &Dense::get_bias () const
{
  return this->bias;
}
activation::ActivationFunction Dense::get_activation () const
{
  return this->activation;
}
Matrix Dense::operator() (const Matrix &m) const
{
  return this->activation((this->weights*m)+ this->bias);
}




