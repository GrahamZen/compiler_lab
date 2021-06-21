/** this is a comment line in the sample program **/
 INT f2(INT x, REAL y ) 
 BEGIN 
    INT z;
    z := x*x - y*y;
    RETURN z; 
 END 

 INT MAIN f1() 
 BEGIN
    INT x:=3;
    REAL y:=-333.33;
    WHILE(x<3 && y>3) READ(x, "A41.input");
    INT z;
    IF(x-y<3)
        READ(y, "A42.input");
    IF(x-y<3)
        READ(y, "A42.input");
        WRITE (z, "A4.output"); 
    z := f2(x,y) + f2(x,y);
 END