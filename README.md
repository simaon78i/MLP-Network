
# MLP Network Project

## Overview

This project implements a Multi-Layer Perceptron (MLP) neural network in C++ for digit recognition. The MLP consists of four layers, each utilizing different activation functions and dimensions suited for processing images of handwritten digits.

## Files

- **Activation.cpp / Activation.h**: Implement activation functions (ReLU and Softmax) used by the neural network layers.
- **Dense.cpp / Dense.h**: Define the Dense layer, which includes weights, biases, and activation functions for each layer in the network.
- **main.cpp**: The main entry point of the application. It handles input, processes command-line arguments, and executes the MLP network on a given image.
- **Matrix.cpp / Matrix.h**: Provide a Matrix class for handling matrix operations, essential for the neural network's computations.
- **MlpNetwork.cpp / MlpNetwork.h**: Implement the MLP network class, defining its structure and the forward pass through the network.
- **plot_img.py**: A Python script likely used for plotting images, possibly to visualize the digit recognition results.

## Usage

### Compilation

To compile the project, use a C++ compiler. For example, using `g++`:

\`\`\`bash
g++ -o mlpnetwork main.cpp Activation.cpp Dense.cpp Matrix.cpp MlpNetwork.cpp
\`\`\`

### Running the Application

The application expects several arguments specifying the paths to the binary files containing the weights and biases for each layer:

\`\`\`bash
./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
\`\`\`

- `wi` - the i-th layer's weights
- `bi` - the i-th layer's biases

### Example

\`\`\`bash
./mlpnetwork weights1.bin weights2.bin weights3.bin weights4.bin bias1.bin bias2.bin bias3.bin bias4.bin
\`\`\`

### Input Image

Upon running, the application will prompt you to input the path to an image file. The image should be a 28x28 grayscale image of a handwritten digit.

## Error Handling

The application includes several error messages for common issues:

- `Error: invalid Parameters file for layer`: Indicates an issue with the provided weight or bias files.
- `Error: Failed to retrieve input. Exiting..`: General input retrieval failure.
- `Error: invalid image path or size`: The provided image path or size is incorrect.
- `Error: wrong number of arguments`: Incorrect number of command-line arguments.

## Dependencies

- C++ Standard Library

## License

This project is licensed under the MIT License.

## Acknowledgments

Special thanks to contributors and developers who made this project possible.
