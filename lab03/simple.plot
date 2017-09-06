set terminal postscript color
set output "Problem4.ps"
set title "OPTIMIZATION X-TREME"
set xlabel "size (N)"
set ylabel "time (seconds)"

plot [:][:] "data.out" with line
