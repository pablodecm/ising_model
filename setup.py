
from distutils.core import setup
from Cython.Build import cythonize
 
# Use "python setup.py build ---build-dir ." to compile

setup(
    name = "ising_simulator",
    ext_modules = cythonize( "Ising.pyx")
)
