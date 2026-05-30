transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+aurora_64b66b_0  -L xpm -L gtwizard_ultrascale_v1_7_17 -L xil_defaultlib -L fifo_generator_v13_2_9 -L unisims_ver -L unimacro_ver -L secureip -O2 xil_defaultlib.aurora_64b66b_0 xil_defaultlib.glbl

do {aurora_64b66b_0.udo}

run

endsim

quit -force
