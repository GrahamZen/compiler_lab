/** this is a comment line in the sample program **/
 INT f2(INT x, REAL y ) 
 BEGIN 
    INT z;
    z := x*x - y*y;
    RETURN z; 
 END 
 INT MAIN f1() 
 BEGIN
    INT x:=-333.33;
    REAL y:=x;
    WHILE(x<3 && y>3) READ(x, "A41.input");
    READ(y, "A42.input");
    INT z;
    z := f2(x,y) + f2(x,y);
    WRITE (z, "A4.output"); 
 END