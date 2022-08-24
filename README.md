# Catmull-Rom
A handy Centripetal Catmull-Rom spline generator.

Generates a Catmull-Rom spline by four specified control points.

Branches in this repo:
Main -- contains the raw spline generator. You can use it if you already 
have the rest of the framework to do what you want. In this case, you can
make a lib out of the code in Main branch or make some minor changes to 
the source code and use it as module for you convenience.

GUI -- speaks for itself. It is a window extension of the raw generator
from the Main branch. Features GUI with a in interactive UI, where the 
user can define the control points by clicking on a specified pixel. 
