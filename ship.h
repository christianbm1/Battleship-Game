class ship
{
public:
       
ship();
ship(int);//contructore with paramets, sets ships to a certain size
~ship();
int setx();// randomize the x coordinate.
int sety();//randomize the y coordinate.
int getsize();//returns the size of ship. default is 3 for submarine... rest is contructor with parametsrs
int setHV();//randomize number for either vertical or horizontal placing of ship

private:
int shipx;//ship x coordinate
int shipy;   //ship y coordinate
int size;   // ship size
int shipHV;         // ship either horizontal or vertical
};
