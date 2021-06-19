/** this is a comment line in the sample program **/
 INT f2(INT x, INT y ) 
 BEGIN 
    INT z;
    z := x*x - y*y;
    RETURN z; 
 END 
 INT MAIN f1() 
 BEGIN
    INT x:=-333.33;
    REAL y:=2112;
    WHILE(x<3 || y>3) READ(x, "A41.input");
    IF(x==3) y := x;
    ELSE 
        IF(x==3) y := x + 2;
            y :=x + 1;
    READ(y, "A42.input");

 END