
uniform sampler2DRect tex0; // line image
uniform sampler2DRect tex1; // rock image

void main(void)
{
    vec2 st = gl_TexCoord[0].st;
    vec2 stOrig = st;
    
    //st *= vec2(0.5, 0.5);  // zooms in on the rock texture
    vec4 color = texture2DRect(tex1, st);
    
    // 5 = how much displacement, try 50 or 100, etc.  always use decimal nums (10.0, etc)
    vec2 st2 = stOrig + vec2( (color.x - 0.5) * 5.0, (color.z - 0.5) * 5.0);
    vec4 color2 = texture2DRect(tex0, st2);
    
	gl_FragColor = vec4(color2.x, color2.y, color2.z, 1.0);
}