#include <cstdlib>
#include <iostream>
#include <fstream.h>
#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <sys/stat.h>

using namespace std;




int main(int argc, char *argv[])
{
             ofstream out_RENDER_MANY_ROCKS("RENDER_MANY_ROCKS.cpp");


        for(int i = 0; i < 100; i++)
        {    
              out_RENDER_MANY_ROCKS << "    //------------------------------------------------------------------------------------------- "       << "\n";                
              
              out_RENDER_MANY_ROCKS << "              glPushMatrix();                                                                     "       << "\n"; 
              
              out_RENDER_MANY_ROCKS << "                   glScalef(" << (1+(float(rand()%100))/100)  << ", " << (1+(float(rand()%100))/100)  << ", " << (1+(float(rand()%100))/100)<< "); "  << "\n";               
              
              out_RENDER_MANY_ROCKS << "                   glTranslatef(" << ((float(rand()%100))-50)/10 << ", 0.0," <<((float(rand()%100))-50)/10<< ");                    "       << "\n"; 
              //out_RENDER_MANY_ROCKS << "                   glRotatef(" <<float(rand()%360)<< ", 0.0, 1.0, 0.0);                           "       << "\n"; 

              out_RENDER_MANY_ROCKS << "                   glDrawArrays(GL_TRIANGLES, 0, 390);                                            "       << "\n"; 
              out_RENDER_MANY_ROCKS << "              glPopMatrix();                                                                      "       << "\n"; 
              
              out_RENDER_MANY_ROCKS << "    //------------------------------------------------------------------------------------------- "       << "\n";               
        }
        
        

              return 0;
}








