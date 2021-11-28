//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  computeGradLag.h
//
//  Code generation for function 'computeGradLag'
//


#ifndef COMPUTEGRADLAG_H
#define COMPUTEGRADLAG_H

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
      namespace fminconsqp
      {
        namespace stopping
        {
          void b_computeGradLag(double workspace[910], int nVar, const double
                                grad[26], const double AineqTrans[442], const
                                int finiteLB[26], int mLB, const double lambda
                                [35]);
          void computeGradLag(double workspace[26], int nVar, const double grad
                              [26], const double AineqTrans[442], const int
                              finiteLB[26], int mLB, const double lambda[35]);
        }
      }
    }
  }
}

#endif

// End of code generation (computeGradLag.h)
