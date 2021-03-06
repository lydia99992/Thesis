/*
 * Copyright (c) 2016 Pierpaolo Necchi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef PROBABILITYDISTRIBUTION_H
#define PROBABILITYDISTRIBUTION_H

#include <armadillo>  /* arma::vec */
#include <memory>     /* std::unique_ptr */

/*!
 * ProbabilityDistribution is a pure abstract class that defines the generic
 * interface for a probability distribution. Probability distribution are used
 * in PGPE policies to simulate the deterministic controller parameters.
 */

class ProbabilityDistribution
{
    public:
        //! Default destructor.
        virtual ~ProbabilityDistribution() = default;

        /*!
         * Virtual clone method for polymorphic copy.
         * \return unique pointer to a copy of the probability distribution
         */
        virtual std::unique_ptr<ProbabilityDistribution> clone() const = 0;

        /*!
         * Get distribution output size.
         * \return output size
         */
        virtual size_t getDimOutput() const = 0;

        /*!
         * Get probability distribution size, i.e. size of the parameter vector
         * \return parameters size
         */
        virtual size_t getDimParameters() const = 0;

        /*!
         * Get method for the distribution parameters.
         * \return parameters stored in an arma::vector
         */
        virtual arma::vec getParameters() const = 0;

        /*!
         * Set method for the distribution parameters.
         * \param parameters_ the new parameters stored in an arma::vector
         */
        virtual void setParameters(arma::vec const &parameters_) = 0;

        /*!
         * Simulate a realization of the probability distribution.
         * \return realization of the probability distribution
         */
        virtual arma::vec simulate() const = 0;

        /*!
         * Evaluate the Likelihood score of a given realization
         * \param output_ distribution realization
         * \return likelihood score evaluated at output_
         */
        virtual arma::vec likelihoodScore(arma::vec const &output_) const = 0;

        /*!
         * Reset distribution to initial conditions.
         */
        virtual void reset() = 0;
};

#endif // PROBABILITYDISTRIBUTION_H
