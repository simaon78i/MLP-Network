#include "Dense.h"
#include "MlpNetwork.h"

 MlpNetwork::MlpNetwork (Matrix *weights, Matrix *bias): layer_first
(weights[0],bias[0],activation::relu),
layer_second (weights[1],bias[1],activation::relu),
layer_third (weights[2],bias[2],activation::relu),
layer_firth (weights[3],bias[3],activation::softmax)
{}

digit MlpNetwork::operator() (Matrix &input) const
{
Matrix new_mat=layer_firth(layer_third(layer_second(layer_first(input))));
  digit new_digit=(digit){(unsigned int)new_mat.argmax(),new_mat[new_mat
  .argmax()]};
  return new_digit;
}

