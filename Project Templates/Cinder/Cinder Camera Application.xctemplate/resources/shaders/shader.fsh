uniform sampler2D tex;

void main()
{
	vec2 st = gl_TexCoord[0].st;
	vec4 sample = texture2D( tex, st );
	gl_FragColor = sample;
}

