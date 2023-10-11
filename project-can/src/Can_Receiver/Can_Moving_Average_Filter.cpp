#include "Can_Moving_Average_Filter.hpp"


MovingAverageFilter::MovingAverageFilter(size_t size, size_t discardSize)
    : size_(size), discardSize_(discardSize), sum_(0) {}


double MovingAverageFilter::filter(double new_value){
    if(values_.size() == size_){
        for(size_t i = 0 ; i < discardSize_; ++i){
            sum_ -= values_.front();
            values_.pop();
        }      
    }

    values_.push(new_value);
    sum_ += new_value;


    return sum_ / values_.size();
}

