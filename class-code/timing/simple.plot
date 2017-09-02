set terminal postscript color
set output "output.ps"
set title "MY TITLE!"
set xlabel "size (N)"
set ylabel "time (seconds)"

plot [:][:] "data.out" with line
