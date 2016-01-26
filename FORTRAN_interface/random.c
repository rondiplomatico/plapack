/*
   PLAPACK Release 3.0
   
   Copyright (C) 2000
   Robert A. van de Geijn and The University of Texas at Austin

   For GNU-license details see the file GNU_license in the 
   PLAPACK root directory.
*/

#include "PLA.h"

#if MANUFACTURE == PC
#undef PLA_FOR2C
#ifdef UpCase
	#define PLA_FOR2C(name,NAME) NAME
#else
	/* Changed from "__" to "_" by Daniel Wirtz, 28-Jan-2015 */
	#define PLA_FOR2C(name,NAME) name ## _
#endif 
#endif

#if MANUFACTURE == CRAY
int SEED_RANDOM( int *seed )
#else
int PLA_FOR2C(seed_random,SEED_RANDOM) ( int *seed )
#endif
{
  srand48( *seed );
}

#if MANUFACTURE == CRAY
int COMPLEX_RANDOM( double *x )
#else
int PLA_FOR2C(complex_random,COMPLEX_RANDOM)( double *x )
#endif
{
  double drand48();

  x[0] = drand48( ) * 2.0 - 1.0;
  x[1] = drand48( ) * 2.0 - 1.0;
}

#if MANUFACTURE == CRAY
int REAL_RANDOM( double *x )
#else
int PLA_FOR2C(real_random,REAL_RANDOM) ( double *x )
#endif
{
  double drand48();

  *x = drand48( ) * 2.0 - 1.0;
}
