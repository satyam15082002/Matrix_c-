#pragma once
#include<iostream>
#include<chrono>
using namespace std::chrono_literals;
class Timer
{
    std::chrono::_V2::system_clock::time_point start,end;
    std::chrono::duration<float> duration;
    public:
        Timer()
        {
            start=std::chrono::high_resolution_clock::now();
        }
        ~Timer()
        {
            end=std::chrono::high_resolution_clock::now();
            duration=end-start;
            std::cout<<"\nTime ="<<duration.count()*1000.0f<<"ms"<<std::endl;
        }
};
