#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ___FILEBASENAME___App : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
	void keyDown( KeyEvent event );
	void update();
	void draw();
	
};

void ___FILEBASENAME___App::setup()
{
}

void ___FILEBASENAME___App::mouseDown( MouseEvent event )
{
}

void ___FILEBASENAME___App::keyDown( KeyEvent event )
{
	if ( event.getCode() == KeyEvent::KEY_f ){
		setFullScreen( !isFullScreen() );
	}
}

void ___FILEBASENAME___App::update()
{
}

void ___FILEBASENAME___App::draw()
{
	// clear out the window with black
	gl::clear( Color::black() ); 
}


CINDER_APP_BASIC( ___FILEBASENAME___App, RendererGl(0) )
