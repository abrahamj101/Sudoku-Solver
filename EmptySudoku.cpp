//Joshua Abraham
//CSCE 222-502
//02/15/2023
//Sudoku Puzzle in C++

#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

  int main() {
      
      //variables generation
      for(int i=1; i<=9; i++) {
          for(int j=1; j<=9; j++) {
              for(int n=1; n<=9; n++) {
                  cout<<"(declare-const P_" << i << "_" << j << "_" << n << " Bool)\n";
              }
          }
      }
      //Row rules generation
      for(int i=1; i<=9; i++) {
          for(int n=1; n<=9; n++) {
              cout<< "(assert (or";
              for(int j=1; j<=9; j++) {
                  cout<< " " << "P_" << i << "_" << j <<"_" << n;
              }
              cout<< "))\n";
          }
      }
      //Column rules generation
      for(int j=1; j<=9; j++) {
          for(int n=1; n<=9; n++) {
              cout<<"(assert (or";
              for(int i=1; i<=9; i++) {
                  cout<< " " << "P_" << i << "_" << j <<"_" << n;
              }
              cout<< "))\n";
          }
      }
      //Block rules generation
      for(int r=0; r<=2; r++) {
          for(int c=0; c<=2; c++) {
              for(int n=1; n<=9; n++) {
                cout<<"(assert (or";
                  for(int i=1; i<=3; i++) {
                      for(int j=1; j<=3; j++) {
                        cout<<" " << "P_" << (3*r+i) << "_" << (3*c+j) <<"_" << n;
                      }
                  }
                  cout<< "))\n"; 
              }
          }
      }
      //Cell rules generation
      for(int i=1; i<=9; i++) {
          for(int j=1; j<=9; j++) {
              for(int n=1; n<=9; n++) {
                  cout<<"(assert (or (not " << "P_" << i << "_" << j << "_" << n <<  ") (not (or";
                  for(int n1=1; n1<=9; n1++) {
                      if(n==n1)
                          continue;
                      cout<< " " << "P_" << i << "_" << j <<"_" << n1;
                  }
                  cout<<"))))\n";
              }
          }
      }
      cout<<"(check-sat)\n";
      cout<<"(get-model)";

      return 0;
  } 

/*
; Sudoku puzzle in SMT-LIB language
; Solves a 4x4 Sudoku puzzle

(set-option :produce-models true)

; variables generation
(forall ((i Int) (j Int) (n Int))
  (when (and (>= i 1) (<= i 4) (>= j 1) (<= j 4) (>= n 1) (<= n 4))
    (declare-const (str.++ "p_" (int.to.str i) "_" (int.to.str j) "_" (int.to.str n)) Bool)
  )
)

; Row rules generation
(assert (forall ((i Int) (n Int))
  (when (and (>= i 1) (<= i 4) (>= n 1) (<= n 4))
    (or
      (str.++ "p_" (int.to.str i) "_1_" (int.to.str n))
      (str.++ "p_" (int.to.str i) "_2_" (int.to.str n))
      (str.++ "p_" (int.to.str i) "_3_" (int.to.str n))
      (str.++ "p_" (int.to.str i) "_4_" (int.to.str n))
    )
  )
))

; Column rules generation
(assert (forall ((j Int) (n Int))
  (when (and (>= j 1) (<= j 4) (>= n 1) (<= n 4))
    (or
      (str.++ "p_1_" (int.to.str j) "_" (int.to.str n))
      (str.++ "p_2_" (int.to.str j) "_" (int.to.str n))
      (str.++ "p_3_" (int.to.str j) "_" (int.to.str n))
      (str.++ "p_4_" (int.to.str j) "_" (int.to.str n))
    )
  )
))

; Block rules generation
(assert (forall ((r Int) (c Int) (n Int))
  (when (and (>= r 0) (<= r 1) (>= c 0) (<= c 1) (>= n 1) (<= n 4))
    (or
      (str.++ "p_" (int.to.str (+ (* 2 r) 1)) (int.to.str (+ (* 2 c) 1)) "_" (int.to.str n))
      (str.++ "p_" (int.to.str (+ (* 2 r) 1)) (int.to.str (+ (* 2 c) 2)) "_" (int.to.str n))
      (str.++ "p_" (int.to.str (+ (* 2 r) 2)) (int.to.str (+ (* 2 c) 1)) "_" (int.to.str n))
      (str.++ "p_" (int.to.str (+ (* 2 r) 2)) (int.to.str (+ (* 2 c) 2)) "_" (int.to.str n))
    )
  )
))

; Cell rules generation
(assert (forall ((i Int) (j Int) (n Int))
  (when (and (>= i 1) (<= i 4) (>= j 1) (<= j 4) (>= n 1) (<= n 4))
    (or (not (str.++ "p_" (int.to.str i) "_" (int.to.str j
*/