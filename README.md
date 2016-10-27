# Nanpy firmware v0.9.6

[![Travis](http://img.shields.io/travis/nanpy/nanpy-firmware.svg)] (https://travis-ci.org/nanpy/nanpy-firmware)

Firmware for Nanpy, a library to use your Arduino board with Python. Read more on Nanpy at https://github.com/nanpy

## How to configure

	$ cd firmware
	$ ./configure.sh

You can use Nanpy/cfg.h generated file to configure your Nanpy firmware, selecting the features you want to include and the baud rate.

## How to build and install

Copy Nanpy directory under your "sketchbook" directory, start your Arduino IDE, open Sketchbook/Nanpy, select "Upload".


## How to build and install from command line

1. From your firmware directory copy  sample_Makefile to Nanpy directory

		$ cp sample_Makefile Nanpy/Makefile
	
2. Edit the new Makefile to configure the board you want to connect to.

		$ vi Nanpy/Makefile
		
3. Edit cfg.h file to select firmware you want to enable on the board.

		$ vi Nanpy/cfg.h

4. Build and upload the firmware:

		$ cd Nanpy
		$ make
		$ make upload
		
Tip: For every board you connect to USB, make a copy of the Nanpy directory.

## License

This software is released under MIT License. Copyright (c) 2012-2015 Andrea Stagi <stagi.andrea@gmail.com>
