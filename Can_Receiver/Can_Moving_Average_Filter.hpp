#ifndef CAN_MOVING_AVERAGE_FILTER_HPP
#define CAN_MOVING_AVERAGE_FILTER_HPP

#include <vector>
#include <queue>
#include <stdlib.h>


class Moving_Average_Filter{
public:
    Moving_Average_Filter(size_t size);
    double filter(double new_value);


private:
    size_t size_;
    std::queue<double> values_;
    double sum_;
};


#endif   //  CAN_MOVING_AVERAGE_FILTER_HPP