#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

// calculate rmse
VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    VectorXd rmse(4);
    
    // initialize rmse
    rmse << 0, 0, 0, 0;
    
    // sanity check
    // check if estimation vector size is zero or equal to the ground truth's
    if (estimations.size() == 0 || estimations.size() != ground_truth.size()){
      cout<<"invalid inputs"<<endl;
      return rmse;
    }
    
    for (unsigned int i = 0; i < estimations.size(); i++){
      VectorXd diff = estimations[i] - ground_truth[i];
      diff = diff.array() * diff.array();
      rmse += diff;
    }
    
    //calculate the mean
    rmse = rmse / estimations.size();
    //calculate the squared root
    rmse = rmse.array().sqrt();
    //return result
    return rmse;
}

