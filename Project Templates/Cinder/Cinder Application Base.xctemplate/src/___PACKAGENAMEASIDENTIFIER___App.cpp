#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

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
	void update();
	void draw();
	
};

void ___PACKAGENAMEASIDENTIFIER___App::setup()
{
}

void ___PACKAGENAMEASIDENTIFIER___App::mouseDown( MouseEvent event )
{
}

void ___PACKAGENAMEASIDENTIFIER___App::keyDown( KeyEvent event )
{
	setFullScreen( !isFullScreen() );
}

void ___PACKAGENAMEASIDENTIFIER___App::update()
{
}

void ___PACKAGENAMEASIDENTIFIER___App::draw()
{
	// clear out the window with black
	gl::clear( kClearColor ); 
}


CINDER_APP_BASIC( ___PACKAGENAMEASIDENTIFIER___App, RendererGl(0) )
