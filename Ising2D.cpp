#include "Ising2D.h"
#include <chrono>


Ising2D::Ising2D(unsigned size, double temp) :
   lattice_(size, std::vector<int>(size)),
   temp_(temp),
   seed_(std::chrono::system_clock::now().time_since_epoch().count()),
   r_engine_(seed_),
   bin_rand_(0,1),
   grid_rand_(0, size-1),
   prob_rand_(0.0, 1.0)
{
    // init all lattice spins randomly (1 or -1)
    initLatticeRandom();
    
}


Ising2D::~Ising2D()
{
}

void Ising2D::initLatticeRandom()
{
  for (int i=0; i< lattice_.size(); i++) {
    for (int j=0; j < lattice_[0].size(); j++) {
      lattice_[i][j] = -1 + 2 * bin_rand_(r_engine_);
    }
  }
}

void Ising2D::doTimeStep()
{
  int size = lattice_.size(); 
  int nSpins = size * size;
  for (int s = 0; s < nSpins; s++ ) {
    // get random spin within the lattice
    int i = grid_rand_(r_engine_); 
    int j = grid_rand_(r_engine_); 

    // get hamiltonian for that point
    double ho = -lattice_[i][j]*(lattice_[(i-1+size)%size][j] +
                                 lattice_[(i+1+size)%size][j] +
                                 lattice_[i][(j-1+size)%size] +
                                 lattice_[i][(j+1+size)%size] ); 
    // hamiltonian if flipped
    double hf = -ho;

    // if less energy flip with prob exp(-(hf-ho)/T)
    if ( (hf<ho) || (prob_rand_(r_engine_) < exp(-(hf-ho)/temp_)))
      lattice_[i][j] = - lattice_[i][j];
  }
} 

double Ising2D::meanMagnetization()
{
  double sum = 0;
  for (int i=0; i< lattice_.size(); i++) {
    for (int j=0; j < lattice_[0].size(); j++) {
      sum += lattice_[i][j];
    }
  }
  return sum/(lattice_.size()^2);
}

std::vector<double> Ising2D::simulate( int n_steps ) 
{
  // vector to save mean magnetization
  std::vector<double> mag_vector(n_steps);
  // perform simulation steps and get magmetization
  for (int i = 0; i < n_steps; i++)
  {
    doTimeStep();
    mag_vector[i] = meanMagnetization();
  }
  return mag_vector;
}

std::vector<std::vector<int>> Ising2D::getLattice()
{
  return lattice_;
}

void Ising2D::setTemperature(double temp) 
{
  temp_ = temp;
}



