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
    int currentAccel;              
    int totalAccelX,                 
    averageAccelX;      
    int totalAccelY,
    averageAccelY;
    int totalAccelZ,
    averageAccelZ;
    int counter;
    

};

extern Plotter Plot;
#endif
