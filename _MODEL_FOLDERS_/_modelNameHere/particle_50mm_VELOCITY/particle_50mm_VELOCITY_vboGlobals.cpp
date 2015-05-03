GLuint particle_50mm_VELOCITY_vboID   =  530 ;

GLuint particle_50mm_VELOCITY_SHADER;
GLuint particle_50mm_VELOCITY_SHADER_Vertex;
GLuint particle_50mm_VELOCITY_SHADER_Fragment;

#include "particle_50mm_VELOCITY_VERT.cpp"
#include "particle_50mm_VELOCITY_NORM.cpp"
#include "particle_50mm_VELOCITY_TEX.cpp"
#include "particle_50mm_VELOCITY_VELOCITY.cpp"

GLfloat     lightPos_particle_50mm_VELOCITY[]           =  {-1.56117, 11.9431, 10.7077};
GLfloat     lightAttenuation_particle_50mm_VELOCITY     =   1.283;

GLfloat     MaterialShininess_particle_50mm_VELOCITY    =  360.816;

GLfloat     rotation_AXIS_particle_50mm_VELOCITY[]      =  {1.0, 1.0, 1.0, 0.0};
GLfloat     particle_50mm_VELOCITY_POSITION[]           =  {0.0, 0.0, 0.0};
GLfloat     particle_50mm_VELOCITY_counter1             =   0.0;
GLfloat     particle_50mm_VELOCITY_counter2             =   0.0;
GLfloat     particle_50mm_VELOCITY_counter3             =   0.0;
GLfloat     particle_50mm_VELOCITY_counter4             =   0.0;
GLuint      UNIFORM_counter1_particle_50mm_VELOCITY;

GLuint      UNIFORM_counter2_particle_50mm_VELOCITY;

GLuint      UNIFORM_counter3_particle_50mm_VELOCITY;

GLuint      UNIFORM_counter4_particle_50mm_VELOCITY;

GLfloat     LightAmbient_particle_50mm_VELOCITY[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_particle_50mm_VELOCITY[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_particle_50mm_VELOCITY[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_particle_50mm_VELOCITY[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_particle_50mm_VELOCITY[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_particle_50mm_VELOCITY[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_particle_50mm_VELOCITY[]    = { 0.0, 0, 0};
GLfloat     scaleparticle_50mm_VELOCITYShadowY[]         = {1.26801, 0.0, 1.26801};
