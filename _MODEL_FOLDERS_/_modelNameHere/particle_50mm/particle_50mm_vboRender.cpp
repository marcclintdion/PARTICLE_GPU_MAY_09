//glPushMatrix();
              glTranslatef(particle_50mm_POSITION[0], particle_50mm_POSITION[1], particle_50mm_POSITION[2]);
              glRotatef(rotation_AXIS_particle_50mm[3]++,rotation_AXIS_particle_50mm[0], rotation_AXIS_particle_50mm[1], rotation_AXIS_particle_50mm[2]);

              glRotatef(180, 0, 1, 0);//__RECTIFIES_LIGHTWAVE_Z-AXIS_TO_THIS_SETUP_WHICH_IS_Z_POSITIVE_TOWARDS_VIEWER 
              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_particle_50mm);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_particle_50mm);
              glPopMatrix();

//glPopMatrix();

              glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_particle_50mm);
              glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_particle_50mm);
              glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_particle_50mm);
              glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_particle_50mm);
              glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_particle_50mm);
              glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_particle_50mm);
              glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_particle_50mm);
              glMaterialf(GL_FRONT, GL_SHININESS,  MaterialShininess_particle_50mm);

              glUseProgramObjectARB(particle_50mm_SHADER);


              glUniform1fARB( UNIFORM_counter1_particle_50mm, particle_50mm_counter1);
              glUniform1fARB( UNIFORM_counter2_particle_50mm, particle_50mm_counter2);
              glUniform1fARB( UNIFORM_counter3_particle_50mm, particle_50mm_counter3);
              glUniform1fARB( UNIFORM_counter4_particle_50mm, particle_50mm_counter4);


              glBindBufferARB(GL_ARRAY_BUFFER_ARB, particle_50mm_vboID);


              //------------------------------------------------------------------------------------------------------------
              glClientActiveTextureARB(GL_TEXTURE1);//__VELOCITY 
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(particle_50mm_VERT) + sizeof(particle_50mm_NORM)+ sizeof(particle_50mm_TEX)));
              glEnableClientState(GL_TEXTURE_COORD_ARRAY);
              //------------------------------------------
              glClientActiveTextureARB(GL_TEXTURE0);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(particle_50mm_VERT) + sizeof(particle_50mm_NORM)));
              glEnableClientState(GL_TEXTURE_COORD_ARRAY);
              //------------------------------------------------------------------------------------------------------------
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(particle_50mm_VERT));
              glEnableClientState(GL_NORMAL_ARRAY);
              //------------------------------------------------------------------------------------------------------------
              glVertexPointer(3, GL_FLOAT, 0, 0);
              glEnableClientState(GL_VERTEX_ARRAY);
              //------------------------------------------------------------------------------------------------------------


            //SPECULAR_textureID;
            //SPECULAR_textureID = glGetUniformLocationARB(particle_50mm_SHADER,"SpecularMap");
            //glUniform1iARB(SPECULAR_textureID, 2);
            //glActiveTextureARB(GL_TEXTURE2_ARB);
            //glBindTexture(GL_TEXTURE_2D,  specularMap[530]);

              textureID;
              textureID     = glGetUniformLocationARB(particle_50mm_SHADER,"Texture1");
              glUniform1iARB(textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[530]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(particle_50mm_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[530]);


              glDrawArrays(GL_TRIANGLES, 0, 1584);


              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

