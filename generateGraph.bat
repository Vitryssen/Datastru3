set  terminal  pdf  font "cmr"
set  output  "seqSearch.pdf"
#set  size 1,2
set  key box
#set  samples 50, 50
#set  style  data  lines
set  title "Sequential Search -- Prime series"
set  xlabel "N elements"
set  ylabel "t [ms]"
x = 0
f(x) = a*(x/2)
f1(x) = a1*x*log(x)/log(2)
fit [1000:100000][0:2000] f(x) "seqSearch.data" via a
plot "seqSearch.data" title "Prime input" with  errorbars , f(x) smooth  csplines t "Fit O(N/2)"
#close  output  file
set  output
set  terminal  pop