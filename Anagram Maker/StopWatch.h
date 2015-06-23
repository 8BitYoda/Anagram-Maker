#pragma once
//This class comes from David Bolton,
//http://cplus.about.com/od/howtodothingsi2/a/timing.htm   
//C version is at http://cplus.about.com/od/howtodothingsin1/a/timing.htm
//supposed to be accurate to microsecond
//possible dual core issues, 
//but this code won't run on multiple cores simultaneously anyway
#include <windows.h>

typedef struct {
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
} stopWatch;

class CStopWatch {

private:
    stopWatch timer;
    LARGE_INTEGER frequency;
    double LIToSecs( LARGE_INTEGER & L) ;
public:
    CStopWatch() ;
    void startTimer( ) ;
    void stopTimer( ) ;
    double getElapsedTime() ;
};