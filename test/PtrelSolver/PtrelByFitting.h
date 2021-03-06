
#ifndef PtrelByFitting_h
#define PtrelByFitting_h

#include "PtrelSolver.h"
#include "PtrelUtils.h"

class PtrelByFitting : public PtrelSolver
{

public:

    //! Default constructor.
    explicit PtrelByFitting(char const * filename, Fit::Type fittype) : PtrelSolver(filename, fittype)
    {
        // Computing error kernel
        Double_t matrix[] =
        {
            1., 1.,
            0., 1.
        };

        kernel_.transformation(2, matrix);
    }

    //! Measure efficiency
    virtual void solve(char const *, char const *);

private:

    //! Error propagation kernel
    ErrorPropagator kernel_;

    //! Compute the efficiency
    bool compute(
        TH1 *,
        Flavor::Type dependency,
        ValueVector const &,
        ValueVector const &,
        ValueVector const &,
        ValueVector const &
    );

public:

    ClassDef(PtrelByFitting, 1)

};

#endif
