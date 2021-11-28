//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  linearForm_.h
//
//  Code generation for function 'linearForm_'
//


#ifndef LINEARFORM__H
#define LINEARFORM__H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder
{
  namespace optim
  {
    namespace coder
    {
      namespace qpactiveset
      {
        namespace Objective
        {
          void linearForm_(boolean_T obj_hasLinear, int obj_nvar, double
                           workspace[910], const double H[64], const double f[26],
                           const double x[26]);
        }
      }
    }
  }
}

#endif

// End of code generation (linearForm_.h)
