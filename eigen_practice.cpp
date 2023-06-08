/**
Copyright 2023  
Author : PJX
Date : Tuesday 1 June 2023 08:16:59 PM 
Last Edit time : Tuesday 1 June 2023 08:16:59 PM 
Description : Show the different examples of using Eigen geometry packages
*/
#include<iostream>
#include<cmath>

#include<Eigen/Core>  /* Providing rotation and translation manipulation*/
#include<Eigen/Geometry>

int main(int argc, char** argv){

    /* In 3d, taking Matrix3d or matrix3f as rotation matrix*/
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();

    /* Rotated vector, we use AngleAxisd*/
    Eigen::AngleAxisd rotatin_vector(M_PI / 3, Eigen::Vector3d(0,0,1)); /* Rotating 60 degrees along the z axis*/
    std::cout.precision(3);
    
    std::cout << "rotation matrix:\n" << rotatin_vector.matrix() << '\n'; /* Utilizing matrix to convert or assign directly below*/
    rotation_matrix = rotatin_vector.toRotationMatrix();

    /* Utlizing AngleAxix type to achieve corridnate translation. */
    Eigen::Vector3d v(1,0,0);
    Eigen::Vector3d v_rotated = rotatin_vector * v;
    std::cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << '\n';
    v_rotated = rotation_matrix * v;
    std::cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << '\n';

    /* Euler angle: We can convert rotatin matrinx into euler angle*/
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); /* Sequence: ZYX, that is yaw, pitch, roll*/

    std::cout << "yaw pitch roll = " << euler_angles.transpose() << '\n';

    /* For Euler convertion matrix, we use type: Eigen::Isometry */
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); /* 4 * 4 matrix in nature, since normalized*/
    T.rotate(rotatin_vector);
    T.pretranslate(Eigen::Vector3d(1,3,4)); /* Set translating vector as (1,3,4).*/
    std::cout << "Transform matrix = '\n'" << T.matrix() << '\n';

    /* Utilizing transformed matrix to achieve cooridinate convertion*/
    Eigen::Vector3d v_transformed = T * v;
    std::cout << "v_transformed = " << v_transformed.transpose() << '\n';

    /* Quaternion, we can assign AngleAxis value to quaternion and vice versa.*/
    Eigen::Quaterniond q = Eigen::Quaterniond(rotatin_vector);

    /* Sequence: x,y,z,w*/
    std::cout << "Quaternion from rotation vector = " << q.coeffs().transpose() << '\n';

    /* Convertion from rotation matrix into quaternion.*/
    q = Eigen::Quaterniond(rotation_matrix);

    std::cout << "Quaternion from rotation matrix = " << q.coeffs().transpose() << '\n';

    /* Rotate a vector by quaternion in cpp, u just need multiply due to operation reloading.*/
    v_rotated = q * v; /* q *v * q^-1 actually*/
    
    std::cout << " (1,0,0) after rotation = " << v_rotated.transpose() << '\n';
    
    /* The normalized expression.*/
    std::cout << " Result above should be equal to this one : " << (q * Eigen::Quaterniond(0,1,0,0) * q.inverse()) .coeffs().transpose() << '\n';

    

    return 0;
}