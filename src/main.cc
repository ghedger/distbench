/* MIT License
 *
 * Copyright (c) 2018 Greg Hedger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <math.h>
#include <iostream>

#include "distbench_log.h"

namespace distbench {
void PrintPreamble()
{
  using namespace std;
  cout << "Distbench" << endl;
  cout << "Copyright (c) 2018 Greg Hedger" << endl;
  cout << "MIT License" << endl;
  cout << endl;
  cout << "Permission is hereby granted, free of charge, to any person obtaining a copy" << endl;
  cout << "of this software and associated documentation files (the \"Software\"), to deal" << endl;
  cout << endl;
  cout << "in the Software without restriction, including without limitation the rights" << endl;
  cout << "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell" << endl;
  cout << "copies of the Software, and to permit persons to whom the Software is" << endl;
  cout << "furnished to do so, subject to the following conditions:" << endl;
  cout << endl;
  cout << "The above copyright notice and this permission notice shall be included in all" << endl;
  cout << "copies or substantial portions of the Software." << endl;
  cout << "Copyright (C) 2019 Gregory P. Hedger" << endl;
  cout << endl;
}

void PrintUsage()
{
  using namespace std;
  PrintPreamble();
  cout << "Usage:" << endl;
  cout << "\tdistbench <lambda> <k>" << endl;
}

double Factorial(double real)
{
  double factorial = 1.0;
  while (real > 1.0) {
    factorial *= real;
    real -= 1.0;
  }
  return factorial;
}

} // namespace distbench
// main
// This is the main entry point and testbed for ternary tree.
int main(int argc, const char *argv[])
{
  static const double kE = 2.718281828;
  using namespace std;
  using namespace distbench;

  if (argc < 3) {
    PrintUsage();
    return -1;
  }

  double lambda = 0.0, k = 0.0;
  sscanf(argv[1], "%lf", &lambda);
  sscanf(argv[2], "%lf", &k);

  // Poisson binomial distribution:
  //
  //                                      lambda^k
  // P(k events in interval) = e^-lambda  --------
  //                                         k!
  double poisson_probability = pow(kE,-lambda) * (pow(lambda,k)
    / Factorial(k));
  cout << "Poisson p = " << poisson_probability << endl;

  return 0;
}
