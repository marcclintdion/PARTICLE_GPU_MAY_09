GLuint particle_50mm_vboID   =  530 ;

GLuint particle_50mm_SHADER;
GLuint particle_50mm_SHADER_Vertex;
GLuint particle_50mm_SHADER_Fragment;

#include "particle_50mm_VERT.cpp"
#include "particle_50mm_NORM.cpp"
#include "particle_50mm_TEX.cpp"
#include "particle_50mm_VELOCITY.cpp"
           

GLuint      UNIFORM_counter1_particle_50mm;

GLuint      UNIFORM_counter2_particle_50mm;

GLuint      UNIFORM_counter3_particle_50mm;

GLuint      UNIFORM_counter4_particle_50mm;

GLfloat     LightAmbient_particle_50mm[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_particle_50mm[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_particle_50mm[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_particle_50mm[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_particle_50mm[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_particle_50mm[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_particle_50mm[]    = { 0.0, 0, 0};
GLfloat     scaleparticle_50mmShadowY[]         = {1.26801, 0.0, 1.26801};
