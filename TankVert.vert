attribute vec3 position;  // xyz coordinates
attribute vec3 normal;  // rgb color
uniform mat4 mMatrix;  // the final matrix
uniform mat4 pvMatrix;
varying vec3 vNormal;  // goes out of this shader and into the frag
varying vec3 vPosition;

attribute vec2 texCoords;
varying vec2 vTexCoords;

void main(void)
{
    vNormal = normal; // send interpolated color
    vPosition = vec3(mMatrix * vec4(position,1));
    vTexCoords = texCoords;
    gl_Position = pvMatrix * mMatrix * vec4(position, 1);
}
