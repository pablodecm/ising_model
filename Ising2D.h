

#include <vector>
#include <random>

class Ising2D {
  public:
    Ising2D(unsigned size, double temperature);
    ~Ising2D();
    void initLatticeRandom(); 
    void doTimeStep(); 
    double meanMagnetization(); 
    std::vector<double> simulate(int n_steps);
    std::vector<std::vector<int>> getLattice();
    void setTemperature(double temp);

  private:  
      
      std::vector<std::vector<int>> lattice_; // spin lattice
      double temp_;  // temperature ( T = 1/beta ) 

      unsigned seed_;  // random seed
      std::default_random_engine r_engine_;
      std::uniform_int_distribution<int> bin_rand_;
      std::uniform_int_distribution<int> grid_rand_;
      std::uniform_real_distribution<double> prob_rand_;

};
