INT MAIN f1() 
BEGIN
   INT x;
   READ(x, "A41.input");
   INT y;
   READ(y, "A42.input");
   INT z;
   z := f2(x,y) + f2(y,x);
   WRITE (z, "A4.output"); 
END