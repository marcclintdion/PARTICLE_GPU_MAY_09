uniform float counter1;
uniform float counter2;
uniform float counter3;
uniform float counter4;

varying vec4 position;

varying vec3 lightDir1;

varying float attenuation;

void main( void )
{
    gl_TexCoord[0]   =  gl_MultiTexCoord0;
    gl_TexCoord[1]   =  gl_MultiTexCoord1;
    
    position         =  gl_Vertex;

    //position       = mix(position, gl_TexCoord[1], counter1);
    
    position         = position * (1.0 - counter1) + gl_TexCoord[1] * counter1;
        
    position.y      += 1.0/cos( gl_TexCoord[1].x + counter1 * 1.0);
	position.y      += 1.0/sin( gl_TexCoord[1].z + counter1 * 1.0);    
    
   
    gl_Position      =  gl_ModelViewProjectionMatrix * position;

    lightDir1        =  normalize(gl_LightSource[0].position.xyz);
    attenuation      =  1.00 / (gl_LightSource[0].quadraticAttenuation);
}

