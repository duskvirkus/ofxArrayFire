# https://github.com/openframeworks/ofxAddonTemplate/blob/master/addon_config.mk

meta:
	ADDON_NAME = ofxArrayFire
	ADDON_DESCRIPTION = Addon for with pre-compiled binaries of ArrayFire. ArrayFire is a general-purpose library that simplifies the process of developing software that targets parallel and massively-parallel architectures including CPUs, GPUs, and other hardware acceleration devices.
	ADDON_AUTHOR = duskvirkus
	ADDON_TAGS = "computer vision" "algorthms" "utilities"
	ADDON_URL = http://github.com/duskvirkus/ofxArrayFire

common:
	
linux64:
	
linux:
	
win_cb:

vs:
	# For Version 3.8.0 Uncomment in this section

	# ADDON_LIBS += libs/arrayfire-3-8-0/windows/lib/af.lib

	# uncomment to generate a project targeting cpu (don't forget to comment out cuda and opencl)
	# ADDON_LIBS += libs/arrayfire-3-8-0/windows/lib/afcpu.lib

	# uncomment to generate a project targeting cuda (don't forget to comment out cpu and opencl)
	# ADDON_LIBS += libs/arrayfire-3-8-0/windows/lib/afcuda.lib

	# uncomment to generate a project targeting opencl (don't forget to comment out cpu and cuda)
	# ADDON_LIBS += libs/arrayfire-3-8-0/windows/lib/afopencl.lib


	# For Version 3.7.3 Uncomment in this section

	ADDON_LIBS += libs/arrayfire-3-7-3/windows/lib/af.lib

	# uncomment to generate a project targeting cpu (don't forget to comment out cuda and opencl)
	# ADDON_LIBS += libs/arrayfire-3-7-3/windows/lib/afcpu.lib

	# uncomment to generate a project targeting cuda (don't forget to comment out cpu and opencl)
	ADDON_LIBS += libs/arrayfire-3-7-3/windows/lib/afcuda.lib

	# uncomment to generate a project targeting opencl (don't forget to comment out cpu and cuda)
	# ADDON_LIBS += libs/arrayfire-3-7-3/windows/lib/afopencl.lib
	
linuxarmv6l:
	
linuxarmv7l:

android/armeabi:	
	
android/armeabi-v7a:	

osx:
    
ios:
