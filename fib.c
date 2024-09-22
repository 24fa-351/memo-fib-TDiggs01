#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fib_recursion_wrapper( unsigned long long int nth_term, unsigned long long saved_terms[] ) {

   /*Recursive Fibonacci*/
   if( nth_term == 0 ) {
      return 0;
   }
   else if( nth_term == 1 ) {
      return 1;
   }
   else if( saved_terms[nth_term] != 0 ) {
      return saved_terms[nth_term];
   }
   else {
      saved_terms[nth_term] = fib_recursion_wrapper( nth_term - 1, saved_terms ) + fib_recursion_wrapper( nth_term - 2, saved_terms );

      return saved_terms[ nth_term ];
   }

}



unsigned long long int fib_iterative_wrapper( unsigned long long int nth_term, unsigned long long saved_terms[] ) {

   /*Iterative Fibonacci*/
   if( nth_term == 0 ) { 
      return 0;
   }
   else if( nth_term == 1 ) {
      return 1;
   }
   else {
      saved_terms[0] = 0;
      saved_terms[1] = 1;
      for( int ix = 1; ix <= nth_term; ix++ ) {
         saved_terms[ix] = saved_terms[ ix - 1 ] + saved_terms[ ix - 2 ];
      }
      return saved_terms[nth_term];
   }
}



int main( int argc, char *argv[] ) {

   unsigned long long int N;

   int _TWO = 2;

   unsigned long long int fib_Number;

   unsigned long long terms[1000];

   /*Adding first argument with integer in file*/
   N = atoi( argv[1] );

   /*Computing Nth Fibonacci*/
   if(strcmp( argv[_TWO], "r" ) == 0) {
      fib_Number = fib_recursion_wrapper( N - 1, terms );
      //fscanf(save_file, "%llu : %llu", &N, &fib_Number);
      printf( "%llu", fib_Number );
   }
   else if( strcmp( argv[_TWO], "i") == 0 ) {
      fib_Number = fib_iterative_wrapper( N, terms );
      //fscanf(save_file, "%llu : %llu", &N, &fib_Number);
      printf( "%llu", fib_Number );
   }

   return 0;
}