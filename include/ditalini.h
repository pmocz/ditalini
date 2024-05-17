/** @file ditalini.h
 *  @brief A modern template for your C++ software project
 * 
 * This is the main public header file of your awesome C++ library
 *  @author Philip Mocz (Flatiron Institute)
 **/

#ifndef __DITALINI_H__
#define __DITALINI_H__

namespace ditalini
{
    
  class Simulation {
    public:
      /**
       * Constructor for Simulation.
       * @param val The value to be squared.
       */
      Simulation(double val);
      /**
       * Returns the square of the value.
       * @return The square of the value.
       */
      double square();
    private:
      double value_;
  };

}  // ditalini

#endif  // __DITALINI_H__