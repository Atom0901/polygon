# Polygon
------------
Thanks for choosing Polygon class. 

The repo has 4 different components. All .xcodeproject files are usefull only on Mac OS with Xcode. 

- All sources are in:
    - polygon – main class. Contains polygon.cpp & polygon.hpp. Needs to build. Code made cross-platfom so I think it won't be any problems to build it on Windows.
    - polygon-testing – Google Unit Tests
    - polygon-dialog – a dialog testing programme. Just to see all functionality of class
    - dialog – contains some functions for menu. Needed for polygon-dialog

It has many usefull methods, so here they are.

FOR ANY QUESTIONS PLEASE WRITE TO [ME](https://vk.com/meyakovenkoj)

# Idea 
------------
This class can create polygons. 
THE LAST VERSION IS MADE ACCORDING 3rd PARAGRAPH

1. Develop a polygon class in accordance with the following definition: 
    - State of a class: 
    A shape is determined by the number of vertices and an array of vertex coordinates on a plane (float). To describe a vertex, it is advisable to use a structure. Memory for an array of vertices is statically allocated, during compilation, and specified by an array of fixed limit size. 
    - Class protocol:
    Defines the possibilities of creating and initializing class instances and the rules for their use (class methods).
    - a blank constructor for initializing instances and arrays of instances of a class by default; 
    - creating instances of a class with initialization by the value of a single vertex ("point"); 
    - creating instances of a class with initialization by the number of vertices and an array of vertex coordinates; 
    - entering instances of the class from the input stream and outputting (( *) of a pseudo-graphic pattern) in the output stream (using overloaded operators)
    - determining the "center of gravity" of the polygon
    - adding the vertex of the polygon (using the overloaded operator += )
    - getting polygon vertex coordinates, a predetermined number (via overloaded operator []) 
    - performing polygon rotation operation according to given point and given by a certain angle counterclockwise 
    -  moving a polygon ((*) with the help of an overloaded operator (vector value, built from {0,0} to the given point.) in the direction and to G.) 

2. It is recommended to start designing a class with a view of the state of the class, taking into account the specified operations, and then the constructors and an overloaded output operator could, and exhaustive testing of other methods of the developed class, implement dialogs about the program that allows you to enter parameters, debugged methods, and how to solve the error systems mechanism of exceptional situations. 

3. Repeat class development, provided that the memory for the array of structures of the required length is allocated dynamically during program execution (using the new operator, the memory is set to a pointer to the structure in the class state). 
    Add the following class interface:
    - an instance of a class with its initialization by another instance of a class (copy constructor); 
    - overriding an instance of a class (using an overloaded assignment operator). 
4. Write an application program using the developed class. Note: task items marked with (*) are optional.

# Constructors
------------
1. Polygon () is an empty constructor.
2. Polygon (point one) - constructor from point
3. Polygon (point * m, int s) - constructor from an array of points
4. Polygon (const Polygon &) - copy constructor
5. Polygon (Polygon &&) - relocation constructor

~ Polygon () - destructor
# Methods
------------
1. Polygon & operator = (const Polygon &) - overloaded assignment operator
2. Polygon & operator = (Polygon &&);
3. Polygon & operator + = (point ne) - operator for adding a point
4. Polygon & operator () (int alfa, point x) - operator of rotation of a polygon by angle alpha relative to point x
5. Polygon & operator () (point x) - operator of displacement of a polygon by vector x from the origin
6. point operator [] (int a) - operator for obtaining the coordinates of a point

7. point gravity () - calculation of the center of gravity

8. std :: ostream & print (std :: ostream & s) - output a polygon by the list

9. friend std :: istream & operator >> (std :: istream &, Polygon &) - input polygon
10. friend std :: ostream & operator << (std :: ostream & s, Polygon & r) - output a polygon by points

11. int check (int i, int l) - check for belonging to vertices

