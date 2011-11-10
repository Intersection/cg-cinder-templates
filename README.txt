Cinder templates for Xcode 4. 

These are based on a set of stylistic conventions we use at Control Group, which are based very closely to Andrew Bell's style.

Obviously, this is only for Mac (soon, iOS) development with Cinder.

Clone this repo to ~/Library/Developer/Xcode/Templates/ - this will likely cause conflicts with any other templates you have created in that location - untested.

NOTE ON KINECT TEMPLATE: The Kinect.cpp file has been included in this distro from the block source at http://github.com/cinder/Cinder-Kinect

There is a risk of version drift if that project moves forward. If anyone knows how to add it as a Source file at project-creation time (as CINDER_PATH is a derived value, and not absolute, it's hard), please push a change.

