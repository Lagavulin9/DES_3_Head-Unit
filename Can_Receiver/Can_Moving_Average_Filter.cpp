#include "CAN_Moving_Average_Filter.hpp"


Moving_Average_Filter::Moving_Average_Filter(size_t size) : size_(size), sum_(0) {}


double Moving_Average_Filter::filter(double new_value){
    if(values_.size() == size_){
        sum_ -= values_.front();
        values_.pop();
    }

    values_.push(new_value);
    sum_ += new_value;


    return sum_ / values_.size();
}