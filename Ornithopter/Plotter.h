#ifndef Plotter_h
#define Plotter_h

class Plotter
{
  public:
    Plotter();
    void SETUP();
    void Smooth();
    void Printer();
  private:
    int currentAccel,              
    totalAccelX,                 
    averageAccelX;      
    //int current.accelY;
    int totalAccelY,
    averageAccelY;

};

extern Plotter Plot;
#endif
