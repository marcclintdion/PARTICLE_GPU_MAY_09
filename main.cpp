#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream.h>

//using namespace std; //___used for string object

#include <GL/glu.h>
#include <GL/gl.h>

#include "headerFiles/glaux.h"
#include <fstream.h>
#include "headerFiles/glut.h"

#include "headerFiles/tga.h"

#include <math.h>

GLfloat changeValue = 0.993601;
GLint   shinyPlasticDial;

bool keys[256], keypressed[256];
bool active=TRUE;
bool fullscreen=TRUE;

float screenWidth  = 1600;
float screenHeight = 1200;

#include "headerFiles/glext.h" 

#include "headerFiles/FreeImage.h"
#include "cpp/freeImage.cpp"

#include <math.h>

#include "headerFiles/VSync.h"
                                                        
                                                        
                                                         #include "headerFiles/al.h"
                                                         #include "headerFiles/alc.h"
                                                         #include "headerFiles/alut.c"

                                                         #include "AUDIO/dungeonWAV_INIT.c"
                                                         
                    

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



const       int TEXTURE_WIDTH  = 2048;
const       int TEXTURE_HEIGHT = 2048;
GLuint      fboId; 

GLuint      textureMap[1000];
GLuint      tangentMap[1000];
GLuint      normalMap[1000];
GLuint      specularMap[1000];

GLuint      SECOND_TEXTURE_textureID;
GLuint          SHADOW_MAP_textureID;
GLuint            SPECULAR_textureID;
GLuint                SPEC_textureID;
GLuint                DOT3_textureID;
GLuint                     textureID;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







double screenSpin        =  0.0f;

bool over = false;
GLuint    g_textureID    =  0;
GLuint    g_textureID_02 =  1;



float eyePosition[]      = {0.0, -0.160003, -8.2};
float look_LEFT_RIGHT    =  0;
float look_UP_DOWN       =  0;



float spinFloat = 0.0f;



                   GLfloat lightPos_Sphere_02[] =  {8.08997, 123.23, -528.222};
                   GLfloat quadraticAttenuation_Sphere_02 =   1.9e-005;     
                  
                   GLfloat lightPos[] =  {0, 0, 0};
                   GLfloat quadraticAttenuation = 1.9e-005;                      
                   


GLhandleARB tiles_FBO_shadows;
GLhandleARB tiles_FBO_shadows_Vertex;
GLhandleARB tiles_FBO_shadows_Fragment;  



///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\                                 
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\                                 
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\                                 
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
///______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\______//////______\\\\\\
                     
/////////////--------------------------------------------------


HDC	hDC = NULL;
  HGLRC hRC = NULL;
    HWND hWnd = NULL;
      HINSTANCE hInstance = NULL;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, int nCmdShow);
   LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

      void render  (void);
        void Init    (void);
          void shutDown(void);
            unsigned char *readShaderFile(const char *fileName);
              void initShader(void);
                void ProcessKeyboard();
                 
                   int LoadGLTextureTGA(char *textureFileName, GLuint &textureMapID);
                     int LoadGLTextureTGA(char *textureFileName, char *normalMapFileName, GLuint &textureMapID, GLuint &normalMapID) ;  
                           void readstr(FILE *f,char *string);
                           void setShaderConstants(void);

void Dot3shader( void );
  void CollisionCheck_LEFT(float X1, float Y1, float X2, float Y2);
   void CollisionCheck_RIGHT(float X1, float Y1, float X2, float Y2);
     void CollisionCheck_UP(float X1, float Y1, float X2, float Y2);
       void CollisionCheck_DOWN(float X1, float Y1, float X2, float Y2);

              void LoadTiles_00_09(void);
              void LoadTileModels_00_100(void);
              void LoadGeodTiles(void);
              void LoadAnisoTGA(void);
              int  LoadTexture(char *texture_name,GLuint *texture);	
              int  LoadGLTexture_JPG(char *texture_name,GLuint *texture);		
              
                             static void setBrassMaterial(void); 
                             static void setRedPlasticMaterial(void);                          
//---------------------------------------------------------------------------------------------------------------------------------------------

GLfloat movePiece[]  = {0,0,0};
GLfloat moveModel[]  = {0,0,0};
GLfloat moveObject[] = {0,0,0};  

                                                            GLfloat moveSet[] = {0.0, 0.0, 0.0}; 
                                                            GLfloat frameRateAdjustment = 1.0; 

GLfloat    positionY = 0.0;
GLfloat    positionX = 0.0;                                  

GLfloat    boundingBox_MAIN_CHARACTER_left_edge  = -0.179;      
GLfloat    boundingBox_MAIN_CHARACTER_right_edge =  0.179; 
GLfloat    boundingBox_MAIN_CHARACTER_lower_edge =  0.01;
GLfloat    boundingBox_MAIN_CHARACTER_upper_edge =  1.253;
GLfloat    boundingBox_MAIN_CHARACTER_near_edge  =  0.179;     
GLfloat    boundingBox_MAIN_CHARACTER_far_edge   = -0.179;

int        numberOfCollisionObjects = 5;

GLfloat    left_edge_SecondaryObjects[500];
GLfloat    right_edge_SecondaryObjects[500];
GLfloat    lower_edge_SecondaryObjects[500];
GLfloat    upper_edge_SecondaryObjects[500];
GLfloat    near_edge_SecondaryObjects[500];
GLfloat    far_edge_SecondaryObjects[500];

bool       RIGHT = true;
bool       LEFT  = true;                                      
bool       UP    = true;
bool       DOWN  = true;

GLfloat    scaleCollisionBlock                     = 0.179;

bool       showCollisionBlocks                     = true;
bool       resetKey_C                              = true;

bool       spikyBall_mainCharacterHit              = false;
               
               
GLfloat    spikyBallAddsMomentumToMainCharacter[]  = {0.0, 0.0, 0.0};
 
GLuint     collisionHitDrawnOut                    = 0;

GLuint     objectNumber;

GLfloat    crossHairPosition[]                     = {0.0, 0.0, 0.0};


#include  "collisionBlocks.cpp"                                                                
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL        
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL         

//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL         
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL 
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL         
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL        
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL                                                     
//__________________________________________________________LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL  
                            
                            
                             void deleteVBO(const GLuint vboId);////_________________VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO
                             PFNGLGENBUFFERSARBPROC    glGenBuffersARB    = 0;////___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO                    
                             PFNGLBINDBUFFERARBPROC    glBindBufferARB    = 0;////___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO                  
                             PFNGLBUFFERDATAARBPROC    glBufferDataARB    = 0;////___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO               
                             PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB = 0;////___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO           
                             PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = 0;////___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO___VBO
                             
                             //------------------------------------------------------------------------------------------------------------------------        
                             //========================================================================================================================
                             //------------------------------------------------------------------------------------------------------------------------
                             
                           
                             GLfloat    lightPos_treeBarkPath[]           =  {1.93441, 50.04, -10.8981};
                             GLfloat    lightAttenuation_treeBarkPath     =   0.134731;
                             //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                             GLfloat    shininess_treeBarkPath            = 199.733;
                             GLuint     UNIFORM_shininess_treeBarkPath;  
                             //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   
                             GLfloat    shadowsOffsetAdjuster             =  -2.0;         
                             
                             #include "_MODEL_FOLDERS_/treeBarkPath/treeBarkPath_vboGlobals.cpp"//vboID = 400                           
                           
                             //------------------------------------------------------------------------------------------------------------------------                           
                             
                             GLfloat    lightPos_particle_50mm[]             =  {0.209, 0.200301, 10.76};
                             GLfloat    lightAttenuation_particle_50mm       =   0.99702;

                             GLfloat     MaterialShininess_particle_50mm     =  360.816;

                             GLfloat     rotation_AXIS_particle_50mm[]       =   {0.0, 1.0, 0.0, 0.01};
                             GLfloat     particle_50mm_POSITION[]            =   {0.0, 0.0, 0.0};                             

                             GLfloat     particle_50mm_counter1              =    5.5;
                             GLfloat     particle_50mm_counter2              =    0.0;
                             GLfloat     particle_50mm_counter3              =    0.0;
                             GLfloat     particle_50mm_counter4              =    0.0;         
                             
                             GLfloat     particle_50mm_counter1_ACCELERATION =    0.01;                   
                             GLfloat     particle_50mm_counter2_ACCELERATION =    0.01;      
                             GLfloat     particle_50mm_counter3_ACCELERATION =    0.01;                                                       
                             
                             
                             GLfloat     particle_50mm_counter1_FORWARD      = 1.0;
                             
                             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboGlobals.cpp"  //vboID = 530
                             
                             //------------------------------------------------------------------------------------------------------------------------
      
       
        #include "SHADERtech.cpp"
        #include "cpp/winInit.cpp"


bool reset_R_KEY = true;

//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________

//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________
//_______________________________________________________________CG_PARTICLES______________________________


GLfloat MixCounter = 0.0;
bool    MixCounterForward = true;
GLfloat MixCounterAcceleration = 0.03;


float   rotateScene             = 0;

GLfloat mainPosition[]        = {0,0,0};

GLfloat moveModelVelocity[]   = {0,0,0};

DWORD   currentTime          = 0;
DWORD   previousTimeFinished = 0;
DWORD   timeElasped          = 0;


bool    RESET_VK_PRIOR = true;
bool    RESET_VK_NEXT  = true;


void render(void)//////////////////////_______RENDER_____RENDER____RENDER_______RENDER_____RENDER____RENDER_______RENDER_____RENDER____RENDER
{      

//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________________FRAMEBUFFER_SHADOWS_BEGINS_HERE________                              
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
                              glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
                              glMatrixMode(GL_PROJECTION);
                              glLoadIdentity();
                              
                              gluPerspective(45.0f, (float)(TEXTURE_WIDTH) / TEXTURE_HEIGHT, 1.0f, 1000.0f);
                          
                              glMatrixMode(GL_MODELVIEW);
 
         
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fboId);//--------------------------------F.B.O.

                              glClearColor(1, 1, 1, 0);
                              glClear (GL_COLOR_BUFFER_BIT);          

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////                                        
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        
        
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); //-----------------------F.B.O.
       
                                                 //glBindTexture(GL_TEXTURE_2D, textureMap[299]);
                                                 //glGenerateMipmapEXT(GL_TEXTURE_2D);
                                                 //glBindTexture(GL_TEXTURE_2D, 0); 
      
             
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                              
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________
///////////////________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________________FRAMEBUFFER_SHADOWS_ENDS_HERE________                              
//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================  

                                    
                              
                              
                              
                              
                              glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
                              glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    
                              glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
                              glEnable(GL_LINE_SMOOTH);                             
                              glViewport(0, 0, GLint(screenWidth), GLint(screenHeight));
                              glMatrixMode( GL_PROJECTION );
                              glLoadIdentity();
                              gluPerspective( 45.24, screenWidth / screenHeight, 0.1, 1000);
                              
                              glTranslatef(eyePosition[0], eyePosition[1], eyePosition[2]);//glTranslatef(eyePosition[0],eyePosition[1],eyePosition[2]);
                              glRotatef(look_UP_DOWN, 1, 0, 0); 
                              glRotatef(look_LEFT_RIGHT, 0, 1, 0);
                              
                              glMatrixMode( GL_MODELVIEW );
                                                               
                                                           
//==========================================================================================================================================================  
    
                                                                 


//------------------------------------------------------------------------------------------------------------------------------------------------- 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

glEnable(GL_BLEND);
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------                                                  
    glEnable( GL_DEPTH_TEST );
    glDepthMask( GL_FALSE );
    glPointSize(10);
    glEnable(GL_POINT_SPRITE_ARB);
    glTexEnvf( GL_POINT_SPRITE_ARB, GL_COORD_REPLACE_ARB, GL_TRUE );

                                          //-----------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////                                                   glBlendFunc( GL_DST_ALPHA, GL_ONE );
     
     
     if(particle_50mm_counter1_FORWARD == 1.0)
     {
          particle_50mm_counter1 += particle_50mm_counter1_ACCELERATION;
     }
     if(particle_50mm_counter1_FORWARD == 0.0)
     {
          particle_50mm_counter1 -= particle_50mm_counter1_ACCELERATION;
     }     
     //----------------------------------------------------------------
           if(particle_50mm_counter1 >= 20.5)  
           {
                 particle_50mm_counter1_FORWARD = 0.0;
           }
           if(particle_50mm_counter1 <= 5.5)  
           {
                 particle_50mm_counter1_FORWARD = 1.0;
           }     
     
//------------------------------------------------------------------------------------------------------------------------------------


glPushMatrix();
glTranslatef(0.0, 0.0, 0.0);

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1]+1, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

              #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();


//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
     
     
 //------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();    

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
glPopMatrix();



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 




glPushMatrix();
glTranslatef(2.0, 0.0, 0.0);

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1]+1, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

              #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();


//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
     
     
 //------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();    

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
glPopMatrix();




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 




glPushMatrix();
glTranslatef(-2.0, 0.0, 0.0);

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1]+1, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

              #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();


//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
     
     
 //------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();    

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 




glPushMatrix();
glTranslatef(0.0, 0.0, 2.0);

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1]+1, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

              #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();


//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
     
     
 //------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();    

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 




glPushMatrix();
glTranslatef(2.0, 0.0, 2.0);

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1]+1, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

              #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();


//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
     
     
 //------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();    

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 




glPushMatrix();
glTranslatef(-2.0, 0.0, -2.0);

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1]+1, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

              #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();


//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]+2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
     
     
 //------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]-1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();    

//------------------------------------------------------------------------------------------------------------------------------------

     glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0]+1.0, particle_50mm_POSITION[1]-2.0, particle_50mm_POSITION[2]);
              
              glRotatef(rotation_AXIS_particle_50mm[3],rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

             #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboRender.cpp"   //vboID = 530
     glPopMatrix();
glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          //-----------------------------
                                                  glLoadIdentity();
                                          //-----------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////// 


glDisable(GL_BLEND);
glDepthMask(GL_TRUE);





//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//        
               
               //#include "AUDIO/dungeonWAV_RENDER.c"
   
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//
//----------==============================================__PLAY_AUDIO   PLAY_AUDIO__==============================================----------//





SwapBuffers( hDC );

}

/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////
/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////
/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////
/////////////_____ProcessKeyboard()________ProcessKeyboard()_________ProcessKeyboard()______ProcessKeyboard()___////////////////

bool H_isPressed = false;

void ProcessKeyboard()								
{
//////////////////////////////////////_______________LIGHT_POS   
   
   
//moveModel[0], moveModel[1], moveModel[2]   


    if (!keys['H']) 			
	{
          H_isPressed = false;
    }
    if (keys['H'] && !H_isPressed) 			
    {
          H_isPressed           =  true;

          alSourcef (Source_dungeonWAV, AL_GAIN, dungeonWAV_volume);
          alGetSourcei(Source_dungeonWAV, AL_SOURCE_STATE, &state_dungeonWAV);		
          if(state_dungeonWAV != AL_PLAYING)
          {
                alSourcePlay(Source_dungeonWAV);
          }      
    } 
    
//--------------------------------------------------------      
    
    if (keys['R'] && reset_R_KEY) 			
    {
          reset_R_KEY            = false;
          
          particle_50mm_counter1  =  0.0;
          particle_50mm_counter2  =  0.0;
          particle_50mm_counter3  =  0.0;                    
    }
    if (!keys['R']) 			
    {
          
          reset_R_KEY            = true;
    }    
/*    
    if (keys['P'] && reset_P_KEY)
	{
          reset_P_KEY               = false;          
          
          if(particleGenerators && reset_R_KEY)
          {      
                 particleGenerators  = false;
          }
          else
          {      
                 particleGenerators     = true; 
          }                      
    }
    if (!keys['P'])
	{
          reset_P_KEY            = true;
    }   
*/    
    
    
//

if (keys['J'])
{
          lightPos_particle_50mm[0]     -=  1.1011;
}	
if (keys['L'])
{
          lightPos_particle_50mm[0]     +=  1.1011;
} 
if (keys['I'])
{
          lightPos_particle_50mm[1]     +=  1.1011;
}	
if (keys['K'])
{
          lightPos_particle_50mm[1]     -=  1.1011;
}     
if (keys['O'])
{
          lightPos_particle_50mm[2]     +=  1.1011;
}	
if (keys['U'])
{
          lightPos_particle_50mm[2]     -=  1.1011;
} 

//--------------------------------------------------------
if (keys['N'])
{
          lightAttenuation_particle_50mm     += 0.01;
}	
if (keys['M'])
{
          lightAttenuation_particle_50mm     -= 0.01;
}
//--------------------------------------------------------


if (keys['X'] &! keys[VK_SHIFT])
{
          MaterialShininess_particle_50mm               += 1.01;
}	
if (keys['Z'] &! keys[VK_SHIFT])
{
          MaterialShininess_particle_50mm               -= 1.01;
}

/*
if (keys['X'] && keys[VK_SHIFT])
{
          waterLayer_00_counter_01               += .001;
}	
if (keys['Z'] && keys[VK_SHIFT])
{
          waterLayer_00_counter_01               -= .001;
}

*/
//--------------------------------------------------------    
//////////////////////////////////////___________LIGHT_POS 
    if (keys[VK_F8]) 			
	{
        ofstream out("lightPosition.cpp");
        
        out << "                             GLfloat    lightPos_particle_50mm[]             =  {"   << lightPos_particle_50mm[0]      
                                                                                                      << ", " << lightPos_particle_50mm[1] 
                                                                                                      << ", " << lightPos_particle_50mm[2]  << "};\n";
        
        out << "                             GLfloat    lightAttenuation_particle_50mm       =   "   << lightAttenuation_particle_50mm  << ";\n"; 
      
        out << "                             GLfloat    MaterialShininess_particle_50mm       =   "   << MaterialShininess_particle_50mm  << ";\n"; 

        //-------------------------------------------------------------------------------------------------------------
       
        // out << "   GLfloat marcModelPosition[] =  {"  << marcModelPosition[0] << ", " << marcModelPosition[1] << ", " << marcModelPosition[2] << "};\n\n";                
        
        // out << "   shadows_offset_X  = " << shadows_offset_X  << ";\n"; 
        // out << "   shadows_offset_Y  = " << shadows_offset_Y  << ";\n\n";         
        
        
        
        //--------------------------------------------------------------------------------------        
        out << " //--------------------------------------------------------------------------------------"<< ";\n";    
        out << "   look_LEFT_RIGHT = "  << look_LEFT_RIGHT   << ";\n";
        out << "   look_UP_DOWN    = "  << look_UP_DOWN      << ";\n";
        out << "   eyePosition[0]  = "  << eyePosition[0]    << ";\n";
        out << "   eyePosition[1]  = "  << eyePosition[1]    << ";\n";
        out << "   eyePosition[2]  = "  << eyePosition[2]    << ";\n";
        //--------------------------------------------------------------------------------------          

    
    
    
    }
 

//-------------------------------------------------------------------------------------------------------------------  
    

//-------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------
    if (!keys[VK_PRIOR])
	{
          RESET_VK_PRIOR       = true;
    }
    //----------------    
    if (!keys[VK_NEXT])
	{
          RESET_VK_NEXT        = true;
    }

//--------------------------------------------------------------------
    
    
    
    
    if (keys['9'])
	{
          eyePosition[0]    = -300.05f;
    }
    if (keys['0'])
	{
          eyePosition[0]    = 0.0f;
    }
    
    if (keys['A'])
	{
          eyePosition[0]    += .05;
    }	
    if (keys['D'])
	{
          eyePosition[0]    -= .05;
    }
    if (keys['C'])
	{
          rotateScene      += .2;
          //eyePosition[0] += .2;
    }	
    if (keys['Z'])
	{
          rotateScene      -= .2;
          //eyePosition[0] -= .2;
	}
    if (keys['W'])
	{
          eyePosition[2] += .05;
    }
          if (keys['W'] && keys[VK_SHIFT])
	      {
                eyePosition[2] += 0.5;
          
          }    
	if (keys['S'])
	{
          eyePosition[2] -= .05;       
    }    
	      if (keys['S'] && keys[VK_SHIFT])
	      {
                eyePosition[2] -= 0.5;      
          }	
    
    if (keys['E'])
	{
          eyePosition[1] -= 0.05;
    }
	if (keys['Q'])
	{
          eyePosition[1] += 0.05;      
    }    
    
    if (keys['Z'])
	{
          rotateScene -= 1.5;
    }
	if (keys['C'])
	{
          rotateScene += 1.5;      
    }     
    
   
//if (keys['E']) quadraticAttenuation += 0.05f;				
//if (keys['Q']) quadraticAttenuation -= 0.05f;				

}
void Init( void )
{
	GLuint PixelFormat;
	
    PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW |PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    //pfd.iPixelType = PFD_TYPE_RGBA;
    //pfd.cColorBits = 32;
    //pfd.cDepthBits = 32;
	
	hDC = GetDC( hWnd );
	PixelFormat = ChoosePixelFormat( hDC, &pfd );
	SetPixelFormat( hDC, PixelFormat, &pfd);
	hRC = wglCreateContext( hDC );
	wglMakeCurrent( hDC, hRC );

	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );
    glDepthFunc(GL_LEQUAL);	
	
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

                  glMatrixMode( GL_PROJECTION );
                  glLoadIdentity();
                  gluPerspective( 45.24, screenWidth / screenHeight, 0.1, 1000);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER,0.1f);
                             
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);   

    GLfloat spot_direction[] = {0.0, 0.0, 0.0 };//////////////////_______LIGHT0
     glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, (float)0.007);////_______LIGHT0
      glLightf (GL_LIGHT0, GL_LINEAR_ATTENUATION, (float)0.01);//////_______LIGHT0
       glLightf (GL_LIGHT0, GL_CONSTANT_ATTENUATION,(float).003);/////_______LIGHT0
                 

glEnable(GL_LIGHT0);


//////////////////////////////////////////////////////////////////////////////////////////////////////////
     glGenBuffersARB    = (PFNGLGENBUFFERSARBPROC)   wglGetProcAddress("glGenBuffersARB");
     glBindBufferARB    = (PFNGLBINDBUFFERARBPROC)   wglGetProcAddress("glBindBufferARB");
     glBufferDataARB    = (PFNGLBUFFERDATAARBPROC)   wglGetProcAddress("glBufferDataARB");
     glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC)wglGetProcAddress("glBufferSubDataARB");
     glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)wglGetProcAddress("glDeleteBuffersARB");
//////////////////////////////////////////////////////////////////////////////////////////////////////////

 
                             GLfloat    rocks_00_Shadow_00_Scale                =   1.25301;

 
 //--------------------------------------------------------------------------------------;
   look_LEFT_RIGHT = 0;
   look_UP_DOWN    = 42.2;
   eyePosition[0]  = 0.1;
   eyePosition[1]  = -0.15;
   eyePosition[2]  = -6.00001;
 //--------------------------------------------------------------------------------------;


//------------------------------------------------------------------------------------------------------------------------
 
#include "_MODEL_FOLDERS_/treeBarkPath/treeBarkPath_vboInit.cpp" //vboID = 400
    
    
    loadTexture("_MODEL_FOLDERS_/treeBarkPath/treeBarkPath_1/treeBarkPath_1.jpg",      textureMap[400]);
    loadTexture("_MODEL_FOLDERS_/treeBarkPath/treeBarkPath_1/treeBarkPath_1_DOT3.bmp", normalMap[400]);
    

//------------------------------------------------------------------------------------------------------------------------

 #include "_MODEL_FOLDERS_/particle_50mm/particle_50mm_vboInit.cpp"     //vboID = 530
     

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------      
//-------------------------------------------------------------------=====================================================
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------  
    
    
    
    glGenTextures(1, &textureMap[299]);
    glBindTexture(GL_TEXTURE_2D, textureMap[299]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
  //glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP,    GL_TRUE);// automatic mipmap generation included in OpenGL v1.4
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);
    glBindTexture(GL_TEXTURE_2D, 0);    
    

        glGenFramebuffersEXT                     = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
        glDeleteFramebuffersEXT                  = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
        glBindFramebufferEXT                     = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
        glCheckFramebufferStatusEXT              = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
        glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
        glGenerateMipmapEXT                      = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmapEXT");
        glFramebufferTexture2DEXT                = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
        glFramebufferRenderbufferEXT             = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
        glGenRenderbuffersEXT                    = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
        glDeleteRenderbuffersEXT                 = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
        glBindRenderbufferEXT                    = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
        glRenderbufferStorageEXT                 = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");
        

        glGenFramebuffersEXT(1, &fboId);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fboId);
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, textureMap[299], 0);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    alutInit(NULL, 0);
	alGetError();
	LoadALData();
    atexit(KillALData);


SetVSyncState(true);

}
