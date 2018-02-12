unset key
set xrange [-2.40:2.40]  
set yrange [-1.20:1.20] 
set xzeroaxis lt -1 lw +1.5 
set arrow from 0,0 to 0,1.20  lw +1.5 
set arrow from 0,0 to 0,-1.20  lw +1.5 
set arrow from -2.00,0 to -2.00,1.00 nohead lw +1.5  linecolor rgb 'red'  
set arrow from 2.00,0 to 2.00,-1.00 nohead lw +1.5  linecolor rgb 'blue' 
set arrow from -2.00,1.00 to 0,0  nohead lw +1.5  linecolor rgb 'green' 
set arrow from 0,0 to 2.00,-1.00  nohead lw +1.5  linecolor rgb 'green' 
set arrow from -2.00,1.00 to  0,1.00    nohead lw +1.5  linecolor rgb 'green' 
set arrow from 0,1.00    to  2.00,-1.00    nohead lw +1.5  linecolor rgb 'green' 
set label 1 'F1'  at -1.00,-0.2 
set label 2 'F2' at 1.00,-0.2 
set label 3 '' at -1.00,0.0 point pointtype 2 
set label 4 '' at 1.00,0.0 point pointtype 2 
set label 'A1'  at -1.90,-0.2 
set label 'A2'  at 2.10,-0.2  
set label 'B1'   at  -1.90,1.00 
set label 'B2' at  2.10,-1.00 
set grid 
plot 0 with lines lw +1.5  linecolor rgb 'black' 
pause -1 
