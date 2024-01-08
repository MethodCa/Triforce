#version 400

in vec3 fragcolour;
//uniform float alpha;

void main (void)  
{     
   gl_FragColor = vec4(fragcolour, 1.0f);  
}