// How deep to recurse the fractal
depth = 2;

// Size of the fractal bounding box
edge = 128;

// Defines the fractal stencil to be a cube of this size
stencilSize = 4;

// Following taken from the Tips & Tricks page
function CountVals(i,arr) = len( [for (x=arr) if(x==i) x ]);

/*
  Define the fractal
  This function gets called with arguments in the
  range
  0 <= arg < stencilSize
  to see if the recursion should continue. Changing
  this function will change the generated fractal
*/
function CheckStencil(rx,ry,rz) = 
    let( count1 = CountVals(1,[rx,ry,rz]) )
    let( count2 = CountVals(2,[rx,ry,rz]) )
    (count1+count2) < 2;

/*
  Draws the fractal. If the maximum depth
  has been reached, draw a cube at the indicated
  location. Otherwise, split the cube up by
  stencilSize, and use CheckStencil to see if
  recusion should be continued into each sub-cube
*/
module DrawFractal(currentDepth,x,y,z,scale) {
    if( currentDepth==0 ) {
        translate([x,y,z])
            cube(scale*stencilSize);
    }
    else {
        for( i=[0:stencilSize-1],
             j=[0:stencilSize-1],
             k=[0:stencilSize-1] ) {
            if( CheckStencil(i,j,k) ) {
                DrawFractal(currentDepth-1,
                            x + i*scale,
                            y + j*scale,
                            z + k*scale,
                            scale/stencilSize);
            }
        }
    }
}

// Drive the entire program
DrawFractal(depth,0,0,0,edge/stencilSize);
