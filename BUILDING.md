## Prerequisites

* **python3** >= 3.8
* **conan** >= 1.44.0
* **cmake** >= 3.22
* **A working compiler supporting C++ 20 functions

### Conan

[The best way to install Conan is `pip`.](https://docs.conan.io/en/latest/installation.html)

To install Conan on **Windows**:

    $ pip install conan

To install Conan on macOS and **Linux**:

    $ sudo pip3 install conan

Alternatively, on **macOS**, Conan is available from `brew`.

**IMPORTANT!** At the time of writing the documentation, `wxWidgets` did not exist in the central [Conan Center](https://github.com/conan-io/conan-center-index) repository, so I used [Bincrafter](https://github.com/bincrafters/community) packages. Before building the project, you must add the following remote:

    $ conan remote add bincrafters https://bincrafters.jfrog.io/artifactory/api/conan/public-conan
	
Please note, that your Conan client also needs to have revisions enabled. You can do this via:

    $ conan config set general.revisions_enabled=1
	
#### *Troubleshooting*

Recipe for *wxWidgets* uses legacy GTK dependencies (in particular, *libwebkitgtk-dev* package is not available on Ubuntu 20.04). To fix this, you need to edit your `sources.list` with the following command:

    $ echo "deb http://cz.archive.ubuntu.com/ubuntu bionic main universe" | sudo tee -a /etc/apt/sources.list

### Cmake

On Windows, please use the [prebuilt binaries](https://cmake.org/download/). Ensure you select one of the options to add cmake to the system path.

On macOS, the easiest way to install CMake is `brew install cmake`.

On Linux, `cmake` is usually available from the system package manager. Alternatively, `sudo pip3 install cmake` can be used to install the latest version of CMake.

## Building

### Windows
I build using Microsoft Visual Studio 2019. However, it is likely possible to build it with Visual Studio 2022.

### macOS
I build using XCode version 11.7. However, it is likely possible to build it with XCode 12 or 13.

### Linux

I use GCC 9, but any compilers supporting C++ 20 functions should work.

On Debian or Ubuntu, you can install everything required using the following commands:

    $ sudo apt-get update
    $ sudo apt-get install -y build-essential cmake git python3-pip
    $ sudo pip3 install conan
	$ sudo apt-get update
    $ sudo apt install libgtk2.0-dev libgl-dev libwebkitgtk-dev
	
#### Building on Windows

1. Ensure the Python installer option `Add python to environment variables is checked`. Go to Windows Settings "Add or Remove Programs" and modify Python settings if required.
2. Clone this repository from GitHub project.

For example, in the git-bash run:

    git clone https://github.com/n0f4ph4mst3r/Fifteen

3. Configure project using CMake:

       $ mkdir build && cd build
       $ cmake .. -G "Visual Studio 16 2019"
    
4. Open Visual Studio project:

       $ .\\PuzzleProject.sln
    
    and build using the IDE.
	   

#### macOS

1. Clone repository from GitHub project.

       git clone https://github.com/n0f4ph4mst3r/Fifteen

2. Configure project using CMake:

       $ mkdir build && cd build
       $ cmake .. -G "Xcode"
    
3. Open XCode project:

       $ open PuzzleProject.xcodeproj
    
    and build using the IDE.

#### Linux & Other OS

1. Clone repository from GitHub project.

       git clone https://github.com/n0f4ph4mst3r/Fifteen
    
2. Configure project using CMake:

       $ mkdir build && cd build
       $ cmake .. -G "Unix Makefiles" 
	   
   `Ninja` generator working too:

       $ cmake .. -G "Ninja" 
	   
	Use `-DCMAKE_BUILD_TYPE=Debug` for debug configuration.
  
3. Install project
   
   Makefiles:

       $ make install
	   
   Ninja:
   
	   $ ninja install
    
4. Test the build:

       $ cd ../bin
       $ ./PuzzleApp