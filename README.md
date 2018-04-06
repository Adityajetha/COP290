# COP290
# EDTool :
This repository holds the assignment allotted as a part of course COP290(design practices), IIT Delhi. It is used to make a 3D object from it's orthographic projections and projection of 3D object on a plane.

# Aim :
The package has following functionalities :
1. Able to interactively input or read from a file either i) an isometric drawing and a 3D object model or ii) projections on to any cross section.
2. Given the 3D model description we should be able to generate projections on to any cross section or cutting plane.
3. Given two or more projections we should be able to interactively recover the 3D description and produce an isometric drawing from any view direction.

# Organisation of the code :
Following is the description of the directories:
1. **build** : The executable and dependent files/binaries </br>
2. **doc** : Documentation and related files </br>
i) *doc* : Source files for doxygen </br>
ii) *doxygen* : Doxygen generated documentation and class structure of the software. Also contains inital source files for documentation.</br>
iii) *latex* : Mathematical model description</br>
iv) *Functional Description* : StarUML functional description of all the features and parts of the software.</br>
3. **bin** : .o files 
4. **src** : source (C++) files developed for the software</br>
5. **include** : some exemplar files (.txt) used for testing</br>


# GTKMM :

The project makes use of the GTKmm libraries for C++.
Hence this package is needed to be installed before running the software package.
Use the following command:
```
sudo apt-get install libgtkmm-3.0-dev
```
The above command installs the requisite packages. Now the software package can be built and used.

# Compilation and execution instructions :

Enter the project directory and run the following command
```
make
```
Then cd into the build folder and run the following
```
./main
```

# Assumptions :

Given in the design document. 

# Things that has been deleted/changed since the last submission : 

Some of the functions have been deleted and incorporated in the main file. Files like hidden.cpp have been combined with the code and the structure of individual classes and header files have been somewhat changed on the suggestion of TA and the professor. New features like the hidden lines that have been mentioned in design document have been built upon and executed. 



