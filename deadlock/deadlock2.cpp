/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : deadlock2.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

long int videoFrame = 0;
long int audioFrame = 0;
mutex video;
mutex audio;
void streamLoader1()
{
    video.lock();
    audio.lock();
    
    videoFrame++;
    audioFrame++;
    
   
    audio.unlock();
    video.unlock();
}

void streamLoader2()
{
    audio.lock();
    video.lock();
    
    videoFrame++;
    audioFrame++;
    
    video.unlock();
    audio.unlock();
    
}

int main()
{
    thread t1(streamLoader1);
    thread t2(streamLoader2);

    t1.join();
    t2.join();


    return 0;
}