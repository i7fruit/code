/**
 * Use === and !== for comparison
 * as opposed to == and != (like in C)
 */
 x = 2;
 y = "23";

 z = (y == 23); // "23" is a string, not an integer

 a = (y === 23); // Will return false

 if (z)
 {
     document.write('y == 23 will return ' + z);
     document.write("<br />");
     document.write('but should be false because y is actually \"23\" which is\
     a string and not the integer 23' + "<br />");
 }

 if (!a)
 {
     document.write("<br />");
     document.write('y === 23 will return ' + a);
     document.write("<br />");
     document.write('because y is actually the string \"23\"');
 }
