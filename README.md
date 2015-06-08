# Ising Model

The IPython Notebook with the results can be [viewed directly
](https://github.com/pablodecm/ising_model/blob/master/IsingModel.ipynb) on GitHub.

## Requisites
In order to build and execute the simulator and interactively explore the results
these tools are required:

 - C++11 compatible compiler
 - Python 2.7
 - IPython
 - Cython
 - numpy
 - matplotlib

## Cloning the repository 

    git clone https://github.com/pablodecm/ising_model.git

## Compiling and linking the simulator

The Ising 2D simulator is implemented in C++ and linked using Cython, a C+11 compatible compiler is required. To compile the extension as a shared library in the same folder use:

    python setup.py --build-dir .

Check the *Ising.pyx* file to see the functions implemented on the Python interface.

## Exporting to Latex PDF

Execute in the root of the repository:

    ipython nbconvert

