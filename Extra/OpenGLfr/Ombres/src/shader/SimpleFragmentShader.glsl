#version 330 core

// Interpolated values from the vertex shaders
in vec3 fragmentColor;
in vec3 fragmentNormal;
in vec3 Normal_cameraspace;
in vec3 LightDirection_cameraspace;
in vec3 Position_worldspace;

// Ouput data
out vec3 color;

//const
uniform vec3 LightPosition_worldspace;

void main(){

	float LightPower = 50.0;
	// Normal of the computed fragment, in camera space
	vec3 n = normalize( Normal_cameraspace );
	// Direction of the light (from the fragment to the light)
	vec3 l = normalize( LightDirection_cameraspace );

	float cosTheta = clamp(dot( n,l ),0,1);

	float dist = length( LightPosition_worldspace - Position_worldspace );

	vec3 LightColor = vec3(0.2,0.8,0.6);

	vec3 MaterialAmbientColor = vec3(0.2,0.2,0.2) * LightColor ;

	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
	color = MaterialAmbientColor + LightColor * LightPower * cosTheta / (dist*dist) ;

}