
//Author: Damiano Vitulli <info@spacesimulator.net>
////__>>>output texture, normal and vertex arrays added by Marc Clint Dion, Cornwall, Ont, 2007
////__>>>output everything required for rendering with vertex + fragment shading as well as simple planer shadows: M.C.D. -> Dec 2010


#include <windows.h>


#include "glut.h"
#include "load_bmp.h"
#include "load_3ds.h"
#include "object.h"
#include "fstream.h"



int screen_width=640;
int screen_height=480;

double rotation_x=0, rotation_x_increment=0.2;
double rotation_y=0, rotation_y_increment=0.7;
double rotation_z=0, rotation_z_increment=0.0;
 
int filling=1; 

GLfloat light_ambient[]= { 0.1f, 0.1f, 0.1f, 0.1f };
GLfloat light_diffuse[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_position[]= { 100.0f, 0.0f, -10.0f, 1.0f };

GLfloat mat_ambient[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_diffuse[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat mat_shininess[]= { 1.0f };

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glViewport(0,0,screen_width,screen_height);  

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,0.0f,100.0f); 
   
	glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
    glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);

    glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
    glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);    

	glShadeModel(GL_SMOOTH);                            
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Texture mapping perspective correction (OpenGL... thank you so much!)
    glEnable(GL_TEXTURE_2D);                            // Texture mapping ON
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);         // Polygon rasterization mode (polygon filled)
	glEnable(GL_CULL_FACE);                             // Enable the back face culling
    glEnable(GL_DEPTH_TEST);                            // Enable the depth test (also called z buffer)

	
     ObjLoad ("particle_50mm_VELOCITY.3ds","skull.bmp");

      
     
      GLfloat textureMapID = 530;   
      GLuint  vboID        = 530;    
                
    

//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////

system("MKDIR particle_50mm_VELOCITY");

ofstream out_vboGlobals("particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboGlobals.cpp");
         out_vboGlobals << "GLuint particle_50mm_VELOCITY_vboID   =  " << vboID <<" ;"                                << "\n\n";
         out_vboGlobals << "GLuint particle_50mm_VELOCITY_SHADER;"                                                    << "\n";
         out_vboGlobals << "GLuint particle_50mm_VELOCITY_SHADER_Vertex;"                                             << "\n";
         out_vboGlobals << "GLuint particle_50mm_VELOCITY_SHADER_Fragment;"                                           << "\n\n";

         out_vboGlobals << "#include \"particle_50mm_VELOCITY_VERT.cpp\""                                             << "\n";         
         out_vboGlobals << "#include \"particle_50mm_VELOCITY_NORM.cpp\""                                             << "\n";
         out_vboGlobals << "#include \"particle_50mm_VELOCITY_TEX.cpp\""                                              << "\n";
         out_vboGlobals << "#include \"particle_50mm_VELOCITY_VELOCITY.cpp\""                                         << "\n\n";         
         
         out_vboGlobals << "GLfloat     lightPos_particle_50mm_VELOCITY[]           =  {-1.56117, 11.9431, 10.7077};" << "\n";        
         out_vboGlobals << "GLfloat     lightAttenuation_particle_50mm_VELOCITY     =   1.283;"                       << "\n\n";  
         out_vboGlobals << "GLfloat     MaterialShininess_particle_50mm_VELOCITY    =  360.816;"                      << "\n\n";          
         
         out_vboGlobals << "GLfloat     rotation_AXIS_particle_50mm_VELOCITY[]      =  {1.0, 1.0, 1.0, 0.0};"         << "\n";          
         out_vboGlobals << "GLfloat     particle_50mm_VELOCITY_POSITION[]           =  {0.0, 0.0, 0.0};"              << "\n";           
         
         out_vboGlobals << "GLfloat     particle_50mm_VELOCITY_counter1             =   0.0;"                         << "\n";           
         out_vboGlobals << "GLfloat     particle_50mm_VELOCITY_counter2             =   0.0;"                         << "\n";
         out_vboGlobals << "GLfloat     particle_50mm_VELOCITY_counter3             =   0.0;"                         << "\n";         
         out_vboGlobals << "GLfloat     particle_50mm_VELOCITY_counter4             =   0.0;"                         << "\n";         
                  
         out_vboGlobals << "GLuint      UNIFORM_counter1_particle_50mm_VELOCITY;"                                     << "\n\n"; 
         out_vboGlobals << "GLuint      UNIFORM_counter2_particle_50mm_VELOCITY;"                                     << "\n\n"; 
         out_vboGlobals << "GLuint      UNIFORM_counter3_particle_50mm_VELOCITY;"                                     << "\n\n";          
         out_vboGlobals << "GLuint      UNIFORM_counter4_particle_50mm_VELOCITY;"                                     << "\n\n";          
         
         out_vboGlobals << "GLfloat     LightAmbient_particle_50mm_VELOCITY[]        = { 1.0f, 1.0f, 1.0f, 1.0f};"    << "\n";
         out_vboGlobals << "GLfloat     LightDiffuse_particle_50mm_VELOCITY[]        = { 1.0f, 1.0f, 1.0f, 1.0f};"    << "\n";
         out_vboGlobals << "GLfloat     LightSpecular_particle_50mm_VELOCITY[]       = { 1.0f, 1.0f, 1.0f, 1.0f};"    << "\n";
         out_vboGlobals << "GLfloat     MaterialAmbient_particle_50mm_VELOCITY[]     = { 1.0f, 1.0f, 1.0f, 1.0f};"    << "\n";
         out_vboGlobals << "GLfloat     MaterialDiffuse_particle_50mm_VELOCITY[]     = { 1.0f, 1.0f, 1.0f, 1.0f};"    << "\n";
         out_vboGlobals << "GLfloat     MaterialEmission_particle_50mm_VELOCITY[]    = { 1.0f, 1.0f, 1.0f, 1.0f};"    << "\n";
         out_vboGlobals << "GLfloat     MaterialSpecular_particle_50mm_VELOCITY[]    = { 0.0, 0, 0};"                 << "\n";
         
                                        
         out_vboGlobals << "GLfloat     scaleparticle_50mm_VELOCITYShadowY[]         = {1.26801, 0.0, 1.26801};"  << "\n";
//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______GLOBALS_______///////////////////////////////////////////////////////////
                                         //---------------------------------------------                                                 
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////
ofstream out_vboInit("particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboInit.cpp");
         
         out_vboInit << "glGenBuffersARB(1, &particle_50mm_VELOCITY_vboID);" << "\n";
         out_vboInit << "glBindBufferARB(GL_ARRAY_BUFFER_ARB, particle_50mm_VELOCITY_vboID);" << "\n";
         out_vboInit << "glBufferDataARB(GL_ARRAY_BUFFER_ARB,       sizeof(particle_50mm_VELOCITY_VERT) + sizeof(particle_50mm_VELOCITY_NORM) + sizeof(particle_50mm_VELOCITY_TEX) + sizeof(particle_50mm_VELOCITY_VELOCITY), 0, GL_STATIC_DRAW_ARB);" << "\n";
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0,                                                                                        sizeof(particle_50mm_VELOCITY_VERT), particle_50mm_VELOCITY_VERT);"         << "\n"; 
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(particle_50mm_VELOCITY_VERT),                                                           sizeof(particle_50mm_VELOCITY_NORM), particle_50mm_VELOCITY_NORM);"         << "\n";
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(particle_50mm_VELOCITY_VERT) + sizeof(particle_50mm_VELOCITY_NORM),                             sizeof(particle_50mm_VELOCITY_TEX),  particle_50mm_VELOCITY_TEX);"          << "\n";
         out_vboInit << "glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,    sizeof(particle_50mm_VELOCITY_VERT) + sizeof(particle_50mm_VELOCITY_NORM)+ sizeof(particle_50mm_VELOCITY_TEX), sizeof(particle_50mm_VELOCITY_VELOCITY), particle_50mm_VELOCITY_VELOCITY);" << "\n";         
        
        
         out_vboInit << "    loadTexture(\"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_DOT3.bmp\",   normalMap["   << textureMapID << "]);"   << "\n";
         out_vboInit << "    loadTexture(\"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY.jpg\",        textureMap["  << textureMapID << "]);"   << "\n";
         out_vboInit << "    //loadTexture(\"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_BUMP.jpg\", specularMap[" << textureMapID << "]);"   << "\n";
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////________INIT_______///////////////////////////////////////////////////////////                                        
                                         //---------------------------------------------
                                        //--------------------------------------------- 
/////////////////////////////////////////////////////_____SHADER_SETUP_____//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////_____SHADER_SETUP_____////////////////////////////////////////////////////////// 
ofstream out_SHADER_INIT("particle_50mm_VELOCITY/particle_50mm_VELOCITY_shaderInit.cpp");         

         out_SHADER_INIT << "    const char *particle_50mm_VELOCITY_SHADER_VertexStrings[1];" << "\n";
         out_SHADER_INIT << "    const char *particle_50mm_VELOCITY_SHADER_FragmentStrings[1];" << "\n\n";
   
         out_SHADER_INIT << "    particle_50mm_VELOCITY_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );" << "\n\n";    

         out_SHADER_INIT << "	 unsigned char *particle_50mm_VELOCITY_SHADER_VertexAssembly = readShaderFile( \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY.vert\" );" << "\n";
         out_SHADER_INIT << "    particle_50mm_VELOCITY_SHADER_VertexStrings[0] = (char*)particle_50mm_VELOCITY_SHADER_VertexAssembly;" << "\n";
         out_SHADER_INIT << "    glShaderSourceARB( particle_50mm_VELOCITY_SHADER_Vertex, 1, particle_50mm_VELOCITY_SHADER_VertexStrings, NULL );" << "\n";
         out_SHADER_INIT << "    glCompileShaderARB( particle_50mm_VELOCITY_SHADER_Vertex);" << "\n";
         out_SHADER_INIT << "    delete particle_50mm_VELOCITY_SHADER_VertexAssembly;" << "\n\n";

         out_SHADER_INIT << "    particle_50mm_VELOCITY_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );" << "\n\n";

         out_SHADER_INIT << "    unsigned char *particle_50mm_VELOCITY_SHADER_FragmentAssembly = readShaderFile( \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY.frag\" );" << "\n";
         out_SHADER_INIT << "    particle_50mm_VELOCITY_SHADER_FragmentStrings[0] = (char*)particle_50mm_VELOCITY_SHADER_FragmentAssembly;" << "\n";
         out_SHADER_INIT << "    glShaderSourceARB( particle_50mm_VELOCITY_SHADER_Fragment, 1, particle_50mm_VELOCITY_SHADER_FragmentStrings, NULL );" << "\n";
         out_SHADER_INIT << "    glCompileShaderARB(particle_50mm_VELOCITY_SHADER_Fragment );" << "\n\n";
    
         out_SHADER_INIT << "    delete particle_50mm_VELOCITY_SHADER_FragmentAssembly;" << "\n\n";

         out_SHADER_INIT << "	 particle_50mm_VELOCITY_SHADER = glCreateProgramObjectARB();" << "\n\n";
         out_SHADER_INIT << "    glAttachObjectARB( particle_50mm_VELOCITY_SHADER, particle_50mm_VELOCITY_SHADER_Vertex );" << "\n";
         out_SHADER_INIT << "    glAttachObjectARB( particle_50mm_VELOCITY_SHADER, particle_50mm_VELOCITY_SHADER_Fragment );" << "\n\n";

         out_SHADER_INIT << "    glLinkProgramARB(particle_50mm_VELOCITY_SHADER); " << "\n\n";  

         out_SHADER_INIT << "    UNIFORM_counter1_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, \"counter1\" );" << "\n\n";
         out_SHADER_INIT << "    UNIFORM_counter2_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, \"counter2\" );" << "\n\n";
         out_SHADER_INIT << "    UNIFORM_counter3_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, \"counter3\" );" << "\n\n";
         out_SHADER_INIT << "    UNIFORM_counter4_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, \"counter4\" );" << "\n\n";
         
/////////////////////////////////////////////////////_____SHADER_SETUP_____//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////_____SHADER_SETUP_____////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////
ofstream out_vertexShader("particle_50mm_VELOCITY/particle_50mm_VELOCITY.vert");
         out_vertexShader << "uniform float counter1;"                                                                                           << "\n";         
         out_vertexShader << "uniform float counter2;"                                                                                           << "\n";          
         out_vertexShader << "uniform float counter3;"                                                                                           << "\n";          
         out_vertexShader << "uniform float counter4;"                                                                                           << "\n\n";          
         
         out_vertexShader << "varying vec4 position;"                                                                                           << "\n\n";

         out_vertexShader << "varying vec3 lightDir1;"                                                                                          << "\n\n";

         out_vertexShader << "varying float attenuation;"                                                                                       << "\n\n";

         out_vertexShader << "void main( void )"                                                                                                << "\n";
         out_vertexShader << "{"                                                                                                                << "\n";
         out_vertexShader << "    gl_TexCoord[0]   = gl_MultiTexCoord0;"                                                                        << "\n";
         out_vertexShader << "    gl_TexCoord[1]   = gl_MultiTexCoord1;"                                                                        << "\n\n";
    
         out_vertexShader << "    position         = gl_Vertex;"                                                                                << "\n\n";
    
         out_vertexShader << "    position.x      += gl_TexCoord[1].x * counter1;"                                                              << "\n";
         out_vertexShader << "    position.y      += (gl_TexCoord[1].y + 4.0) * counter1 -4.9 * counter1 * counter1;"                           << "\n";
         out_vertexShader << "    position.z      += gl_TexCoord[1].z * counter1;"                                                              << "\n\n"; 
    
         out_vertexShader << "    gl_Position      = gl_ModelViewProjectionMatrix * position;"                                                  << "\n\n";
    
         out_vertexShader << "    lightDir1        =  normalize(gl_LightSource[0].position.xyz - position.xyz);"                                << "\n";
         out_vertexShader << "    attenuation      =  1.00 / (gl_LightSource[0].quadraticAttenuation);"                                         << "\n";
         out_vertexShader << "}" << "\n\n";
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_______VERTEX_SHADER______//////////////////////////////////////////////////////
                                         //---------------------------------------------
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////
ofstream out_fragmentShader("particle_50mm_VELOCITY/particle_50mm_VELOCITY.frag");
         
         out_fragmentShader << "uniform float counter1;"                                                                                         << "\n";         
         out_fragmentShader << "uniform float counter2;"                                                                                         << "\n";          
         out_fragmentShader << "uniform float counter3;"                                                                                         << "\n";          
         out_fragmentShader << "uniform float counter4;"                                                                                         << "\n\n";          
         
         out_fragmentShader << "varying vec4 position;"                                                                                         << "\n\n";

         out_fragmentShader << "float distance;  "                                                                                              << "\n";
         out_fragmentShader << "varying float attenuation;"                                                                                     << "\n\n";
         
         out_fragmentShader << "vec3 normal;"                                                                                                   << "\n";
         out_fragmentShader << "vec4 finalcolor;"                                                                                               << "\n\n";
         out_fragmentShader << "//vec4 greyScaleTexture;"                                                                                       << "\n";

         out_fragmentShader << "varying vec3 lightDir1;"                                                                                        << "\n\n";

         out_fragmentShader << "float NdotL1;"                                                                                                  << "\n\n";
        
         out_fragmentShader << "uniform sampler2D NormalMap;"                                                                                   << "\n";
         out_fragmentShader << "uniform sampler2D Texture1;"                                                                                    << "\n";
         out_fragmentShader << "//uniform sampler2D SpecularMap;"                                                                               << "\n\n";
         
         out_fragmentShader << "void main( void )"                                                                                              << "\n";
         out_fragmentShader << "{"                                                                                                              << "\n";
         
         out_fragmentShader << "    vec3 NormalTex   =  texture2D(NormalMap,  gl_TexCoord[0].st).xyz;"                                          << "\n";
         out_fragmentShader << "    NormalTex        = (NormalTex - 0.5) * 2.0;"                                                                << "\n";
         out_fragmentShader << "	normal           =  normalize(NormalTex);"                                                                  << "\n\n";         
         
         out_fragmentShader << "    NdotL1           =  dot(normal,lightDir1);"                                                                 << "\n\n";        
         
         out_fragmentShader << "    finalcolor       =  texture2D(Texture1,gl_TexCoord[0].xy);"                                                 << "\n";
         
         out_fragmentShader << "    //greyScaleTexture =  texture2D(SpecularMap,  gl_TexCoord[0].st);"                                          << "\n";
         
         out_fragmentShader << "    if(NdotL1 > 0.0)"                                                                                           << "\n";
         out_fragmentShader << "    {"                                                                                                          << "\n";
         out_fragmentShader << "         float specularLight  = pow(max(NdotL1, 0.0), gl_FrontMaterial.shininess);  "                           << "\n";        
         out_fragmentShader << "         finalcolor          += specularLight;"                                                                 << "\n";
         out_fragmentShader << "         //finalcolor        += specularLight * finalcolor;"                                                    << "\n";        
         out_fragmentShader << "    }    "                                                                                                      << "\n\n";     
         
         out_fragmentShader << "    finalcolor      *=  attenuation * NdotL1 * NdotL1 * 2.2; "                                                  << "\n\n";         
         
         out_fragmentShader << "    gl_FragColor              =  finalcolor;"                                                                   << "\n\n";
         out_fragmentShader << "}"                                                                                                              << "\n";
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____FRAGMENT_SHADER_____//////////////////////////////////////////////////////
                                        //---------------------------------------------
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////
ofstream out_vboRender("particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboRender.cpp");
         out_vboRender << "//glPushMatrix();"                                                                                                                 << "\n";    
         out_vboRender << "              glTranslatef(particle_50mm_VELOCITY_POSITION[0], particle_50mm_VELOCITY_POSITION[1], particle_50mm_VELOCITY_POSITION[2]);"                   << "\n";       
         out_vboRender << "              glRotatef(rotation_AXIS_particle_50mm_VELOCITY[3]++,rotation_AXIS_particle_50mm_VELOCITY[0], rotation_AXIS_particle_50mm_VELOCITY[1], rotation_AXIS_particle_50mm_VELOCITY[2]);" << "\n\n";          
         out_vboRender << "              glRotatef(180, 0, 1, 0);//__RECTIFIES_LIGHTWAVE_Z-AXIS_TO_THIS_SETUP_WHICH_IS_Z_POSITIVE_TOWARDS_VIEWER "            << "\n";        
         
         out_vboRender << "              glPushMatrix();"                                                                                                     << "\n";         
         out_vboRender << "                   glLoadIdentity();"                                                                                              << "\n";          
         out_vboRender << "                //_ADDITIONAL_ROTATIONS_GO_HERE"                                                                                   << "\n";         
         out_vboRender << "                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);"                                                                         << "\n";        
         out_vboRender << "                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);"                                                 << "\n";           
         out_vboRender << "                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm_VELOCITY);"                                                      << "\n";
         out_vboRender << "                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm_VELOCITY);"                               << "\n";
         out_vboRender << "              glPopMatrix();"                                                                                                      << "\n\n";           
         out_vboRender << "//glPopMatrix();"                                                                                                                  << "\n\n";           
         
         
         out_vboRender << "              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_particle_50mm_VELOCITY);"                                                  << "\n";
         out_vboRender << "              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_particle_50mm_VELOCITY);"                                                  << "\n";
         out_vboRender << "              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_particle_50mm_VELOCITY);"                                                 << "\n";
         out_vboRender << "              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_particle_50mm_VELOCITY);"                                               << "\n";
         out_vboRender << "              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_particle_50mm_VELOCITY);"                                               << "\n";
         out_vboRender << "              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_particle_50mm_VELOCITY);"                                              << "\n";
         out_vboRender << "              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_particle_50mm_VELOCITY);"                                              << "\n";
         out_vboRender << "              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_particle_50mm_VELOCITY);"                                             << "\n\n";         
         
         out_vboRender << "              glUseProgramObjectARB(particle_50mm_VELOCITY_SHADER);"                                                                       << "\n\n\n";     
         
         
         
         out_vboRender << "              glUniform1fARB( UNIFORM_counter1_particle_50mm_VELOCITY, particle_50mm_VELOCITY_counter1);"                                          << "\n";
         out_vboRender << "              glUniform1fARB( UNIFORM_counter2_particle_50mm_VELOCITY, particle_50mm_VELOCITY_counter2);"                                          << "\n";
         out_vboRender << "              glUniform1fARB( UNIFORM_counter3_particle_50mm_VELOCITY, particle_50mm_VELOCITY_counter3);"                                          << "\n";         
         out_vboRender << "              glUniform1fARB( UNIFORM_counter4_particle_50mm_VELOCITY, particle_50mm_VELOCITY_counter4);"                                          << "\n\n\n";          
         
         
         
         out_vboRender << "              glBindBufferARB(GL_ARRAY_BUFFER_ARB, particle_50mm_VELOCITY_vboID);"                                                         << "\n\n\n";
         
         
         
         out_vboRender << "              //------------------------------------------------------------------------------------------------------------"      << "\n";  
         out_vboRender << "              glClientActiveTextureARB(GL_TEXTURE1);//__VELOCITY "                                                                 << "\n";   
         out_vboRender << "              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(particle_50mm_VELOCITY_VERT) + sizeof(particle_50mm_VELOCITY_NORM)+ sizeof(particle_50mm_VELOCITY_TEX)));" << "\n";              
         out_vboRender << "              glEnableClientState(GL_TEXTURE_COORD_ARRAY);"                                                                        << "\n";           
         out_vboRender << "              //------------------------------------------"                                                                        << "\n";           
         out_vboRender << "              glClientActiveTextureARB(GL_TEXTURE0);"                                                                              << "\n";   
         out_vboRender << "              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(particle_50mm_VELOCITY_VERT) + sizeof(particle_50mm_VELOCITY_NORM)));"              << "\n";              
         out_vboRender << "              glEnableClientState(GL_TEXTURE_COORD_ARRAY);"                                                                        << "\n";         
         out_vboRender << "              //------------------------------------------------------------------------------------------------------------"      << "\n";          
         out_vboRender << "              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(particle_50mm_VELOCITY_VERT));"                                                   << "\n";
         out_vboRender << "              glEnableClientState(GL_NORMAL_ARRAY);"                                                                               << "\n";         
         out_vboRender << "              //------------------------------------------------------------------------------------------------------------"      << "\n";          
         out_vboRender << "              glVertexPointer(3, GL_FLOAT, 0, 0);"                                                                                 << "\n";
         out_vboRender << "              glEnableClientState(GL_VERTEX_ARRAY);"                                                                               << "\n";
         out_vboRender << "              //------------------------------------------------------------------------------------------------------------"      << "\n\n\n";          
         
         
         
         out_vboRender << "            //SPECULAR_textureID;"                                                                                                 << "\n";
         out_vboRender << "            //SPECULAR_textureID = glGetUniformLocationARB(particle_50mm_VELOCITY_SHADER,\"SpecularMap\");"                                << "\n";
         out_vboRender << "            //glUniform1iARB(SPECULAR_textureID, 2);"                                                                              << "\n";
         out_vboRender << "            //glActiveTextureARB(GL_TEXTURE2_ARB);"                                                                                << "\n";
         out_vboRender << "            //glBindTexture(GL_TEXTURE_2D,  specularMap[" << textureMapID << "]);"                                                 << "\n\n"; 

         out_vboRender << "              textureID;"                                                                                                          << "\n"; 
         out_vboRender << "              textureID     = glGetUniformLocationARB(particle_50mm_VELOCITY_SHADER,\"Texture1\");"                                        << "\n";
         out_vboRender << "              glUniform1iARB(textureID, 1);"                                                                                       << "\n"; 
         out_vboRender << "              glActiveTextureARB(GL_TEXTURE1_ARB);"                                                                                << "\n";
         out_vboRender << "              glBindTexture(GL_TEXTURE_2D, textureMap["   << textureMapID << "]);"                                                 << "\n\n";
         
         out_vboRender << "              DOT3_textureID;"                                                                                                     << "\n"; 
         out_vboRender << "              DOT3_textureID     = glGetUniformLocationARB(particle_50mm_VELOCITY_SHADER,\"NormalMap\");"                                  << "\n"; 
         out_vboRender << "              glUniform1iARB(DOT3_textureID, 0);"                                                                                  << "\n"; 
         out_vboRender << "              glActiveTextureARB(GL_TEXTURE0_ARB);"                                                                                << "\n"; 
         out_vboRender << "              glBindTexture(GL_TEXTURE_2D,  normalMap["   << textureMapID << "]);"                                                 << "\n\n\n"; 
         
         
         out_vboRender << "              glDrawArrays(GL_TRIANGLES, 0, " << object.polygons_qty*3 << ");"                                                     << "\n\n\n";
                            
         
         out_vboRender << "              glDisableClientState(GL_VERTEX_ARRAY);"                                                                              << "\n"; 
         out_vboRender << "              glDisableClientState(GL_NORMAL_ARRAY);"                                                                              << "\n";
         out_vboRender << "              glDisableClientState(GL_TEXTURE_COORD_ARRAY);"                                                                       << "\n\n";

         out_vboRender << "              glUseProgramObjectARB(0);"                                                                                           << "\n\n";
         
         
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////_______RENDER_______///////////////////////////////////////////////////////////

                                         //---------------------------------------------
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////	
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////                                         
/*
ofstream out_shadows("particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboShadow.cpp");         
         
         out_shadows << "   glScalef(scaleparticle_50mm_VELOCITYShadowY[0],0,scaleparticle_50mm_VELOCITYShadowY[2]); "                                      << "\n";
         out_shadows << "   glBindBufferARB(GL_ARRAY_BUFFER_ARB, particle_50mm_VELOCITY_vboID);"                                                    << "\n\n";

         out_shadows << "   glEnableClientState(GL_TEXTURE_COORD_ARRAY );"                                                                  << "\n";
         out_shadows << "   glEnableClientState(GL_NORMAL_ARRAY);"                                                                          << "\n";
         out_shadows << "   glEnableClientState(GL_VERTEX_ARRAY);"                                                                          << "\n";
         out_shadows << "   glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(particle_50mm_VELOCITY_VERT) + sizeof(particle_50mm_VELOCITY_NORM)));"         << "\n";
         out_shadows << "   glNormalPointer(GL_FLOAT, 0, (void*)sizeof(particle_50mm_VELOCITY_VERT));"                                              << "\n";
         out_shadows << "   glVertexPointer(3, GL_FLOAT, 0, 0);"                                                                            << "\n\n";

         out_shadows << "   glPushMatrix();"                                                                                                << "\n";              
         out_shadows << "   glDisable(GL_TEXTURE_2D);"                                                                                      << "\n";
         out_shadows << "   glDisable(GL_DEPTH_TEST);"                                                                                      << "\n";
         out_shadows << "   glEnable(GL_BLEND);"                                                                                            << "\n";
         out_shadows << "   glColor4f(0.0, 0.0, 0.0, 0.3);"                                                                                 << "\n\n";  

         out_shadows << "   glDrawArrays(GL_TRIANGLES, 0, " << object.polygons_qty*3 << ");"                                                << "\n";
         out_shadows << "   glColor4f(1.0, 1.0, 1.0, 1.0);"                                                                                 << "\n";                
         out_shadows << "   glDisable(GL_BLEND);"                                                                                           << "\n";
         out_shadows << "   glEnable(GL_DEPTH_TEST);"                                                                                       << "\n";
         out_shadows << "   glEnable(GL_TEXTURE_2D);"                                                                                       << "\n";
         out_shadows << "   glPopMatrix();"                                                                                                 << "\n\n";

         out_shadows << "   glDisableClientState(GL_VERTEX_ARRAY);"                                                                         << "\n";
         out_shadows << "   glDisableClientState(GL_NORMAL_ARRAY);"                                                                         << "\n";
         out_shadows << "   glDisableClientState(GL_TEXTURE_COORD_ARRAY);"                                                                  << "\n\n";
*/
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////	
////////////////////////////////////////////////////________SHADOWS___________//////////////////////////////////////////////////////                                         
                                         //---------------------------------------------
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////
ofstream out_LOCATION_STRINGS("particle_50mm_VELOCITY/_LOCATION_STRINGS.cpp");
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboGlobals.cpp\"  //vboID = " << "" << vboID <<"\n";                                              
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboRender.cpp\"   //vboID = " << "" << vboID <<"\n";
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboInit.cpp\"     //vboID = " << "" << vboID <<"\n";         
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_shaderInit.cpp\"  //vboID = " << "" << vboID <<"\n";         
         //out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY_vboShadow.cpp\" //vboID = " << "" << vboID <<"\n";         
   

////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////	
////////////////////////////////////////////////////_____LOCATION_STRINGS_____//////////////////////////////////////////////////////
}
void display(void)
{
    glDisable(GL_LIGHTING);
   
    ofstream outVELOCITY( "particle_50mm_VELOCITY/particle_50mm_VELOCITY_VELOCITY.cpp");   
    
    ofstream outTexture( "particle_50mm_VELOCITY/particle_50mm_VELOCITY_TEX.cpp" );
    ofstream outNormal(  "particle_50mm_VELOCITY/particle_50mm_VELOCITY_NORM.cpp");
    ofstream outVertices("particle_50mm_VELOCITY/particle_50mm_VELOCITY_VERT.cpp");
    int j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // This clear the background color to dark blue
    glMatrixMode(GL_MODELVIEW); // Modeling transformation
    glLoadIdentity(); // Initialize the model matrix as identity
    glTranslatef(0.0,0.0,-5); // We move the object forward (the model matrix is multiplied by the translation matrix)
    rotation_x = rotation_x + rotation_x_increment;
    rotation_y = rotation_y + rotation_y_increment;
    rotation_z = rotation_z + rotation_z_increment;
    if (rotation_x > 359) rotation_x = 0;
    if (rotation_y > 359) rotation_y = 0;
    if (rotation_z > 359) rotation_z = 0;
    glRotatef(rotation_x,1.0,0.0,0.0); // Rotations of the object (the model matrix is multiplied by the rotation matrices)
    glRotatef(rotation_y,0.0,1.0,0.0);
    glRotatef(rotation_z,0.0,0.0,1.0);
    
    if (object.id_texture!=-1) 
	{
		glBindTexture(GL_TEXTURE_2D, object.id_texture); // We set the active texture 
	    glEnable(GL_TEXTURE_2D); // Texture mapping ON
	}
	else
	    glDisable(GL_TEXTURE_2D); // Texture mapping OFF

outVELOCITY  << "GLfloat particle_50mm_VELOCITY_VELOCITY[]   = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";

outTexture   << "GLfloat particle_50mm_VELOCITY_TEX[]        = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";
outNormal    << "GLfloat particle_50mm_VELOCITY_NORM[]       = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";	
outVertices  << "GLfloat particle_50mm_VELOCITY_VERT[]       = \n" << "{\n"    << "  //number of vertices = " << object.polygons_qty*3 << "\n\n";
    
    glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
	for (j=0;j<object.polygons_qty;j++)
	{
		glTexCoord2f( object.mapcoord[ object.polygon[j].a ].u, object.mapcoord[ object.polygon[j].a ].v);
        outTexture << "" << object.mapcoord[ object.polygon[j].a ].u << ", ";
        outTexture << object.mapcoord[ object.polygon[j].a ].v << ", 1.0,\n";
        
        glNormal3f( object.normal[ object.polygon[j].a ].x, object.normal[ object.polygon[j].a ].y, object.normal[ object.polygon[j].a ].z);
        outNormal << "" << object.normal[ object.polygon[j].a ].x << ", ";
        outNormal << object.normal[ object.polygon[j].a ].y << ", ";
        outNormal << object.normal[ object.polygon[j].a ].z <<  ",\n";
		
		glVertex3f( object.vertex[ object.polygon[j].a ].x, object.vertex[ object.polygon[j].a ].y, object.vertex[ object.polygon[j].a ].z);

        outVertices << "" << object.vertex[ object.polygon[j].a ].x << ", ";
        outVertices << object.vertex[ object.polygon[j].a ].y << ", ";
        outVertices << object.vertex[ object.polygon[j].a ].z << ",\n";
	
        
        glTexCoord2f( object.mapcoord[ object.polygon[j].b ].u, object.mapcoord[ object.polygon[j].b ].v);
		outTexture << "" << object.mapcoord[ object.polygon[j].b ].u << ", ";
        outTexture << object.mapcoord[ object.polygon[j].b ].v << ", 1.0,\n";
        
        glNormal3f( object.normal[ object.polygon[j].b ].x, object.normal[ object.polygon[j].b ].y, object.normal[ object.polygon[j].b ].z);

        outNormal << "" << object.normal[ object.polygon[j].b ].x << ", ";
        outNormal << object.normal[ object.polygon[j].b ].y << ", ";
        outNormal << object.normal[ object.polygon[j].b ].z << ",\n";					

        glVertex3f( object.vertex[ object.polygon[j].b ].x, object.vertex[ object.polygon[j].b ].y, object.vertex[ object.polygon[j].b ].z);
					
        outVertices << "" << object.vertex[ object.polygon[j].b ].x << ", ";
        outVertices << object.vertex[ object.polygon[j].b ].y << ", ";
        outVertices << object.vertex[ object.polygon[j].b ].z << ",\n";					
        
		
        
        glTexCoord2f( object.mapcoord[ object.polygon[j].c ].u, object.mapcoord[ object.polygon[j].c ].v);
	    outTexture << "" << object.mapcoord[ object.polygon[j].c ].u << ", ";
        outTexture << object.mapcoord[ object.polygon[j].c ].v << ", 1.0,\n\n";
    	
        //Normal coordinates of the third vertex
		glNormal3f( object.normal[ object.polygon[j].c ].x, object.normal[ object.polygon[j].c ].y, object.normal[ object.polygon[j].c ].z);
  
        outNormal << "" << object.normal[ object.polygon[j].c ].x << ", ";
        outNormal << object.normal[ object.polygon[j].c ].y << ", ";
        outNormal << object.normal[ object.polygon[j].c ].z << ",\n\n";

		
        glVertex3f( object.vertex[ object.polygon[j].c ].x, object.vertex[ object.polygon[j].c ].y, object.vertex[ object.polygon[j].c ].z);
					
        outVertices << "" << object.vertex[ object.polygon[j].c ].x << ", ";
        outVertices << object.vertex[ object.polygon[j].c ].y << ", ";
        outVertices << object.vertex[ object.polygon[j].c ].z << ",\n\n";
  					
	}
	
outTexture << "};\n";
outNormal << "};\n";
outVertices << "};\n";	
	
 glEnd();    
  
   
    
    //glmDraw(couch, GLM_NONE);
    
    
    glFlush(); // This force the execution of OpenGL commands
    glutSwapBuffers(); // In double buffered mode we invert the positions of the visible buffer and the writing buffer
}
void resize (int p_width, int p_height)
{
	if (screen_width==0 && screen_height==0) exit(0);
    screen_width=p_width; // We obtain the new screen width values and store it
    screen_height=p_height; // Height value

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // We clear both the color and the depth buffer so to draw the next frame
    glViewport(0,0,screen_width,screen_height); // Viewport transformation

    glMatrixMode(GL_PROJECTION); // Projection transformation
    glLoadIdentity(); // We initialize the projection matrix as identity
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,0.1f,100.0f);
glutPostRedisplay (); // This command redraw the scene (it calls the same routine of glutDisplayFunc)
}

void keyboard(unsigned char p_key, int p_x, int p_y)
{  
    switch (p_key)
    {
        case ' ':
            rotation_x_increment=0;
            rotation_y_increment=0;
            rotation_z_increment=0;
        break;
		case 'r': case 'R':
            if (filling==0)
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
                filling=1;
            }   
            else 
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)
                filling=0;
            }
        break;
		case 27:
			exit(0);
		break;
    }
}
void keyboard_s (int p_key, int p_x, int py)
{
    switch (p_key)
    {
        case GLUT_KEY_UP:
            rotation_x_increment = rotation_x_increment +0.005;
        break;
        case GLUT_KEY_DOWN:
            rotation_x_increment = rotation_x_increment -0.005;
        break;
        case GLUT_KEY_LEFT:
            rotation_y_increment = rotation_y_increment +0.005;
        break;
        case GLUT_KEY_RIGHT:
            rotation_y_increment = rotation_y_increment -0.005;
        break;
    }
}
/**********************************************************
 *
 * The main routine
 * 
 *********************************************************/

int main(int argc, char **argv)
{
    // We use the GLUT utility to initialize the window, to handle the input and to interact with the windows system
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screen_width,screen_height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("www.spacesimulator.net - 3d engine tutorials - To exit press ESC");    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc (resize);
    glutKeyboardFunc (keyboard);
    glutSpecialFunc (keyboard_s);
    init();
    glutMainLoop();

    return(0);    
}
