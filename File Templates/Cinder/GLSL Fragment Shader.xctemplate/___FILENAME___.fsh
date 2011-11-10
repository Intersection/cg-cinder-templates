uniform sampler2D tex;

void main( void )
{
	vec3 sample;
	vec2 st = gl_TexCoord[0].st;
	sample = texture2D( tex, st ).rgb;
	gl_FragColor = vec4( sample, 1.0 );
}

