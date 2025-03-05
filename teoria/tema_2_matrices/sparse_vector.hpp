#include "vector_t.hpp"
#include <cmath>
#include <cassert>

namespace AyED {
    const double eps{1E-4};
    class sparse_vector{
      private:
        size_t n_;
        size_t nz_;
        vector_t<size_t> inx_;
        vector_t<double> val_;
      public:
		// Constructor de la clase sparse_vector
        sparse_vector(const vector_t<double> &v) : n_{v.get_size()}, nz_{0}, inx_(), val_() {
            for (size_t i{0}; i < n; i++) {
                if (fabs(v[i]) > eps) nz_++;
            }
            inx_.resize(nz_);
            val_.resize(nz_);
			nz_ = 0;

			for (size_t i{0}; i < n_; i++) {
				if (fabs(v[i] > eps) {
					inx_[nz_] = i;
					val_[nz_] = v[i];
					nz_++;
				}	
			}
        }
		
		// Método para calcular el poroducto escalar de un vector escaso
		double scal_prod(const vector_t<double> &v) const {
			double prod{0.0};
			assert(v.get_size() == n);
			for (size_t i{0}; i < nz_; i++) {
				prod += v[inx_[i]] * val_[i];
			}
			return prod;
		}
    };
}
]