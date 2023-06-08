/**
Copyright 2023  
Author : PJX
Date : Wed 31 May 2023 08:16:59 PM 
Last Edit time : Wed 31 May 2023 08:16:59 PM 
Description : The program could not run in the period of running time
              shouldn't be put in the running period
*/


#include<eigen3/Eigen/Eigen>
#include<fmt/color.h>
#include<iostream>

int main(){


// 1. The first example
// Due to we set the matrix rows and cols ahead
// So we can say the matrix size is predefined in the compiling time
#if 1
    Eigen::Matrix<double, 3, 2>  m1;
    
    Eigen::Matrix<double, 2, 4> m2;
    
    Eigen::Matrix<double,3,4> y = m1 * m2;
    
    std::cout << y << '\n';
#endif 


// 2. Matrix's size is known at the running time
#if 1

    Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> a1;
    a1.resize(3,2);

    
    Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> a2;
    a2.resize(2,4);

    Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> a3 = a1 * a2;
    std::cout << a3;
#endif



    return 0;
}