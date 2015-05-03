    const char *particle_50mm_VELOCITY_SHADER_VertexStrings[1];
    const char *particle_50mm_VELOCITY_SHADER_FragmentStrings[1];

    particle_50mm_VELOCITY_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *particle_50mm_VELOCITY_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY.vert" );
    particle_50mm_VELOCITY_SHADER_VertexStrings[0] = (char*)particle_50mm_VELOCITY_SHADER_VertexAssembly;
    glShaderSourceARB( particle_50mm_VELOCITY_SHADER_Vertex, 1, particle_50mm_VELOCITY_SHADER_VertexStrings, NULL );
    glCompileShaderARB( particle_50mm_VELOCITY_SHADER_Vertex);
    delete particle_50mm_VELOCITY_SHADER_VertexAssembly;

    particle_50mm_VELOCITY_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *particle_50mm_VELOCITY_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/particle_50mm_VELOCITY/particle_50mm_VELOCITY.frag" );
    particle_50mm_VELOCITY_SHADER_FragmentStrings[0] = (char*)particle_50mm_VELOCITY_SHADER_FragmentAssembly;
    glShaderSourceARB( particle_50mm_VELOCITY_SHADER_Fragment, 1, particle_50mm_VELOCITY_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(particle_50mm_VELOCITY_SHADER_Fragment );

    delete particle_50mm_VELOCITY_SHADER_FragmentAssembly;

	 particle_50mm_VELOCITY_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( particle_50mm_VELOCITY_SHADER, particle_50mm_VELOCITY_SHADER_Vertex );
    glAttachObjectARB( particle_50mm_VELOCITY_SHADER, particle_50mm_VELOCITY_SHADER_Fragment );

    glLinkProgramARB(particle_50mm_VELOCITY_SHADER); 

    UNIFORM_counter1_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, "counter1" );

    UNIFORM_counter2_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, "counter2" );

    UNIFORM_counter3_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, "counter3" );

    UNIFORM_counter4_particle_50mm_VELOCITY = glGetUniformLocationARB( particle_50mm_VELOCITY_SHADER, "counter4" );

