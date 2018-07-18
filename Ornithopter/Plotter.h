#ifndef Plotter_h
#define Plotter_h

class Plotter
{
  public:
    Plotter();
    void SETUP();
    void Smooth();
    void Printer();
    int currentAccel,              
    totalAccelX,                 
    averageAccelX;      
    //int current.accelY;
    int totalAccelY,
    averageAccelY;

};

extern Plotter Plot;
#endif
