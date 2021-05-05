set  terminal  pdf  font "cmr"
set  output  "binSearch.pdf"
#set  size 1,2
set  key box
#set  samples 50, 50
#set  style  data  lines
set  title "Binary Search -- Prime series"
set  xlabel "N elements"
set  ylabel "t [ms]"
x = 0
f(x) = a*log(x)
f1(x) = a1*x*log(x)/log(2)
fit [1000:100000][0:2000] f(x) "binSearch.data" via a
plot "binSearch.data" title "Prime input" with  errorbars , f(x) smooth  csplines t "Fit O(log N)"
#close  output  file
set  output
set  terminal  pop