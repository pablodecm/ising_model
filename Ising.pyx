# distutils: language = c++
# distutils: sources = Ising2D.cpp
# distutils: extra_compile_args = -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.7

from libcpp.vector cimport vector

cdef extern from "Ising2D.h":
    cdef cppclass Ising2D:
        Ising2D(unsigned size, double temp) except +
        void initLatticeRandom()
        void doTimeStep()
        double meanMagnetization()
        vector[double] simulate(int n_steps)
        vector[vector[int]] getLattice()
        void setTemperature(double temp)
        
cdef class IsingSimulator:
    cdef Ising2D *thisptr
    def __cinit__(self, unsigned size, double temp):
        self.thisptr = new Ising2D(size, temp)
    def __dealloc__(self):     
        del self.thisptr
    def initLatticeRandom(self):
        self.thisptr.initLatticeRandom()
    def doTimeStep(self):
        self.thisptr.doTimeStep()
    def meanMagnetization(self):
        return self.thisptr.meanMagnetization()
    def simulate(self, int n_steps):
        return self.thisptr.simulate(n_steps)
    def getLattice(self):
        return self.thisptr.getLattice()
    def setTemperature(self, double temp):
        self.thisptr.setTemperature(temp)




