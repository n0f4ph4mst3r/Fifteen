####Prerequisites

* **python3** >= 3.8
* **conan** >= 1.42.2 
* **cmake** >= 3.22
* **A working compiler supporting c ++ 20 functions

###Conan

[The best way to install Conan is `pip`.](https://docs.conan.io/en/latest/installation.html)

To install Conan on Windows:

    $ pip install conan

To install Conan on macOS and Linux:

    $ sudo pip3 install conan

Alternatively, on macOS, Conan is available from `brew`.

###Cmake

On Windows, please use the [prebuilt binaries](https://cmake.org/download/). Ensure you select one of the options to add cmake to the system path.

On macOS, the easiest way to install CMake is `brew install cmake`.

On Linux, `cmake` is usually available from the system package manager. Alternatively, `sudo pip3 install cmake` can be used to install the latest version of CMake.

###Windows
I build using Microsoft Visual Studio 2019. However, it is likely possible to build it with Visual Studio 2022.

###macOS
I build using XCode version 11.7. However, it is likely possible to build it with XCode 12 or 13.

###Linux

I use GCC 9, but any compilers supporting c ++ 20 functions should work.

On Debian or Ubuntu, you can install everything required using the following commands:

    $ sudo apt-get update
    $ sudo apt-get install -y build-essential cmake git python3-pip
    $ sudo pip3 install conan
	
####Building on Windows

1. Ensure the Python installer option `Add python to environment variables is checked`. Go to Windows Settings "Add or Remove Programs" and modify Python settings if required.
2. Clone this repository from GitHub project.

For example, in the git-bash run:

    git clone https://github.com/n0f4ph4mst3r/Fifteen

3. Open CMake GUI.

Set the *Where is the source code* to the location where repository was cloned.

Set *Where to build the binaries* to the location you want to place your build in. It is preferred that this location is not within the directory with the source code.

4. Press Configure. You can choose which version of Visual Studio to use and the platform to build for in the pop-up. The x64 platform is a default option. Press Finish to start the configuration process.

5. After successful configuration, you will see `Configuring don`e in the last line of the log. Press *Generate* to generate the Visual Studio project.

6. After you see "Generating done", press *Open Project* to open the project in Visual Studio.

7. Select "Build -> Build Solution".

####macOS

1. Clone repository from GitHub project.

   git clone https://github.com/n0f4ph4mst3r/Fifteen

2. Configure project using CMake:

   $ mkdir build && cd build
   $ cmake .. -G "Xcode"
   
3. Open XCode project:

   $ open PuzzleApp.xcodeproj
   
   and build using the IDE.

####Linux & Other OS

1. Clone repository from GitHub project.

   git clone https://github.com/n0f4ph4mst3r/Fifteen
   
2. Configure project using CMake:

   $ mkdir build && cd build
   $ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
   
3. Build project

   $ make
   
4. Test the build

   $ cd PuzzleApp
   $ sudo make install
