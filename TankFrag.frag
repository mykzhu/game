// This is the interpolated value
uniform vec3 color;
uniform vec3 shadowColor;
uniform vec3 lightPos;
varying vec3 vNormal;  // same name and type
varying vec3 vPosition;

uniform sampler2D sampler;
varying vec2 vTexCoords;

void main(void)
{
    float light = dot(normalize(lightPos - vPosition), normalize(vNormal));
    light = (light + 1.0) / 2.0;
    vec3 finalColor = mix(shadowColor, color, light * light * light);
    // set pixel color
    gl_FragColor = texture2D(sampler, vTexCoords);
}

