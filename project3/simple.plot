set terminal postscript color
set output "avl.ps"
set title "OPTIMIZATION X-TREME"
set xlabel "size (N)"
set ylabel "time (seconds)"

plot [:][:] "data.out" with line
