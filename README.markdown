Cinder templates for Xcode 4
=============================

TinderBox is a great tool for creating Cinder projects, but the template choices are somewhat limited at the moment. Rather than add templates to the TinderBox project, I decided to create native Xcode templates, as it's more in line with how I, and my company, work.

This project augments the built-in Xcode 4 templates for projects and files.

It currently includes project types for:

* Basic Cinder app with Constants and Resources files, plus (theoretical) support for (Cocoa) internationalization.
* Basic app with Capture (ie, webcam) support, along with a simple GLSL shader set.
* Basic app with Kinect support, along with a simple GLSL shader set.


File templates exist for:

* AppBasic subclass for creating raw Cinder projects.
* Constants.h file with some simple conventional values
* Resources.h file
* GLSL fragment shader
* GLSL vertex shader


These are based on a set of stylistic conventions we use at Control Group, which track the Cinder community at large.

Obviously, this is only for Mac (soon, iOS) development with Cinder.

Clone this repo to ~/Library/Developer/Xcode/Templates/ - this will likely cause conflicts with any other templates you have created in that location - untested.

NOTE ON KINECT TEMPLATE
--------------------------

The Kinect.cpp file has been included in this distro from the block source at http://github.com/cinder/Cinder-Kinect - you have to install the block before creating a Kinect project. 

You can do so by:

	cd (YOUR_CINDER_DIR)/blocks
	git clone https://github.com/cinder/Cinder-Kinect.git

There is a risk of version drift if that project moves forward, after your project is created. You can always manually copy an updated version.
If anyone knows how to add it as a (linked) source file at project-creation time (as CINDER_PATH is a derived value, and not absolute, it's hard), please push a change.

Alternately, copying it at build-time would be ideal...