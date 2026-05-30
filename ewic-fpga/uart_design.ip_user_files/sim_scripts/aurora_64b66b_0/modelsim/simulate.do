onbreak {quit -f}
onerror {quit -f}

vsim -voptargs="+acc"  -L xpm -L gtwizard_ultrascale_v1_7_17 -L xil_defaultlib -L fifo_generator_v13_2_9 -L unisims_ver -L unimacro_ver -L secureip -lib xil_defaultlib xil_defaultlib.aurora_64b66b_0 xil_defaultlib.glbl

set NumericStdNoWarnings 1
set StdArithNoWarnings 1

do {wave.do}

view wave
view structure
view signals

do {aurora_64b66b_0.udo}

run 1000ns

quit -force
