/******************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           21/01/2021
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Solve Djikstra's algorithm 

 * Problem description
   -------------------
   * Problem statement:
      -> The below code solves the problem of single source
         shortest path using Djikstra's algorithm.
      -> The below code uses Disjoint set's to check whether
         we could apply djikstra's algorithm or not.
      -> The below code also prints the path that need to be
         taken in order to reach the destination.If it is not
         possible then the code output graphs are disjoint and
         outputs -1.
   
   * Input format:
      -> First line takes N no of testcases.
      -> First line of each test case takes number of edges E.
      -> Next E lines takes input in the form src,dest,weight.
      -> Last line contains src and destination whose path needs
         to be found out.

   * Output format:
      -> First line prints the path followed.If not possible then
         it prints The graphs are disjoint.
      -> Next line print total distance.If not possible it output's -1.
    
   * Data Structure's used:
      -> Graphs
      -> Disjoint sets and union

   * Time complexity analysis:
      -> O(ElogV) where E are edges and V are vertices.

   * Limitations:
  	  -> The limitation of the below code is that we are unable to work 
         with negetive edges.
      -> Another limitation is that it gives shortest path froma single source
         and if we need it from other source we need to recompute using djikstra 
         algorithm which inturn uncreases the time
  
   * How to test?
  	 -> Input all the testcases in the 01_input.txt and then compile and run
******************************************************/
#include <bits/stdc++.h>
