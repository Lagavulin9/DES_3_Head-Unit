#ifndef CAN_MOVING_AVERAGE_FILTER_HPP
#define CAN_MOVING_AVERAGE_FILTER_HPP

#include <vector>
#include <queue>
#include <cstdlib>


class MovingAverageFilter{
public:
    MovingAverageFilter(size_t size, size_t discardSize);
    double filter(double new_value);


private:
    size_t size_;
    size_t discardSize_;
    std::queue<double> values_;
    double sum_;
};


#endif   //  CAN_MOVING_AVERAGE_FILTER_HPP

