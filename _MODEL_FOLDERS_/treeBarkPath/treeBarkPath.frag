uniform float counter;

varying vec4 position;

float distance;  
varying float attenuation;

vec4 finalcolor;


vec3 normal;
varying vec3 lightDir1;

float NdotL1;

uniform sampler2D Texture1;
uniform sampler2D Texture2;
uniform sampler2D NormalMap;
uniform sampler2D ShadowMap;

vec4 shadowTexture;

vec4 secondTexture;

float specularLight;

uniform float shiny;

void main( void )
{
    vec3 NormalTex                 =   texture2D(NormalMap,  gl_TexCoord[0].st).xyz;
    NormalTex                      =  (NormalTex - 0.5) * 2.0;
	normal                         =   normalize(NormalTex);

    NdotL1                         =   dot(normal,lightDir1);    
    
    shadowTexture                  =   texture2D(ShadowMap,  gl_TexCoord[1].st);
   
    finalcolor                     =   texture2D(Texture1, gl_TexCoord[0].xy)*shadowTexture;    
    
    
         specularLight             =   pow(NdotL1, shiny);
         finalcolor               +=  (finalcolor * specularLight);
    
    
    
    finalcolor                    *=   attenuation * NdotL1; 
    
    gl_FragColor                   =  (finalcolor * shadowTexture);

}










//-------------------------------------------------------------------------------------------------------------------------------------
	     //float diffuse = saturate(dot(lightDir1, normal));//_________________________________________from_ATI_parallax_shader
         //float specular = pow(saturate(dot(normal, lightDir1)), gl_FrontMaterial.shininess); //______from_ATI_parallax_shader
         //finalcolor += finalcolor *specular;//_______________________________________________________from_ATI_parallax_shader
//-------------------------------------------------------------------------------------------------------------------------------------
