//  Copyright John Maddock 2007.
//  Copyright Paul A. Bristow 2010
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Note that this file contains quickbook mark-up as well as code
// and comments, don't change any of the special comment mark-ups!

#include <iostream>
using std::cout;  using std::endl;
#include <cerrno> // for ::errno

//[policy_eg_5

#include <boost/math/special_functions.hpp>
// using boost::math::tgamma; // Would create an ambiguity between
// 'double boost::math::tgamma<int>(T)' and
// 'double 'anonymous-namespace'::tgamma<int>(RT)'.

namespace
{ // unnamed

using namespace boost::math::policies;

typedef policy<
   domain_error<errno_on_error>,
   pole_error<errno_on_error>,
   overflow_error<errno_on_error>,
   evaluation_error<errno_on_error>
> c_policy;

BOOST_MATH_DECLARE_SPECIAL_FUNCTIONS(c_policy)

/*`
So that when we call `tgamma(z)`, we really end up calling
 `boost::math::tgamma(z, anonymous-namespace::c_policy())`.
*/

} // close unnamed namespace

int main()
{
   errno = 0;
   cout << "Result of tgamma(30000) is: "
#if defined(__QNX__)
   // Pick one of the overloaded tgamma functions to use  
      << tgammaf(30000) << endl;
#else
      << tgamma(30000) << endl;
#endif
      // tgamma in unnamed namespace in this translation unit (file) only.
   cout << "errno = " << errno << endl;
   cout << "Result of tgamma(-10) is: "
#if defined(__QNX__)
   // Pick one of the overloaded tgamma functions to use  
      << tgammaf(-10) << endl;
#else
      << tgamma(-10) << endl;
#endif
   cout << "errno = " << errno << endl;
   // Default tgamma policy would throw an exception, and abort.
}

//] //[/policy_eg_5]

/*
Output:

  Result of tgamma(30000) is: 1.#INF
  errno = 34
  Result of tgamma(-10) is: 1.#QNAN
  errno = 33


*/