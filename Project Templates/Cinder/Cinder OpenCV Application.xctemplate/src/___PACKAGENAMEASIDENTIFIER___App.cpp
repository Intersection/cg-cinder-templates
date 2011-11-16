#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Fbo.h"
#include "cinder/Surface.h"
#include "cinder/Capture.h"

#include "CinderOpenCV.h"

#include "Resources.h"
#include "Constants.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ___PACKAGENAMEASIDENTIFIER___App : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
	void keyDown( KeyEvent event );
	void resize( ResizeEvent event );
	void update();
	void draw();
	
	Capture			mCapture;
	gl::Texture		mTexture;
	gl::GlslProg	mShader;
	gl::Fbo			mFbo;
	
};

void ___PACKAGENAMEASIDENTIFIER___App::setup()
{
	try {
		mCapture = Capture( kCaptureWidth, kCaptureHeight );
		mCapture.start();
	} catch ( ... ) {
		console() << "Error with capture device." << std::endl;
		exit(1);
	}
	
	try {
		mShader = gl::GlslProg( loadResource( RES_SHADER_PASSTHRU ), loadResource( RES_SHADER_FRAGMENT ) );
	} catch ( gl::GlslProgCompileExc &exc ) {
		console() << "Cannot compile shader: " << exc.what() << std::endl;
		exit(1);
	}catch ( Exception &exc ){
		console() << "Cannot load shader: " << exc.what() << std::endl;
		exit(1);
	}
	
	mFbo = gl::Fbo( kCaptureWidth, kCaptureHeight );
}

void ___PACKAGENAMEASIDENTIFIER___App::mouseDown( MouseEvent event )
{
}

void ___PACKAGENAMEASIDENTIFIER___App::keyDown( KeyEvent event )
{
	if (event.getCode() == KeyEvent::KEY_f ){
		setFullScreen( !isFullScreen() );
	}
}

void ___PACKAGENAMEASIDENTIFIER___App::resize( ResizeEvent event )
{
	mFbo = gl::Fbo( getWindowWidth(), getWindowHeight() );
}


void ___PACKAGENAMEASIDENTIFIER___App::update()
{
	if( mCapture && mCapture.checkNewFrame() ) mTexture = gl::Texture( mCapture.getSurface() );
}

void ___PACKAGENAMEASIDENTIFIER___App::draw()
{
	// clear out the window with black
	gl::clear( kClearColor ); 
	
	if( !mTexture ) return;
	mFbo.bindFramebuffer();
	mTexture.enableAndBind();
	mShader.bind();
	mShader.uniform( "tex", 0 );
	mShader.uniform( "mixColor", Vec3d( 1.0, 0.5, -0.25 ) );
	gl::drawSolidRect( getWindowBounds() );
	mTexture.unbind();
	mShader.unbind();
	mFbo.unbindFramebuffer();
	
	gl::Texture fboTexture = mFbo.getTexture();
	fboTexture.setFlipped();
	gl::draw( fboTexture );
	
}


CINDER_APP_BASIC( ___PACKAGENAMEASIDENTIFIER___App, RendererGl(0) )