NEURON {
	SUFFIX xtra
	RANGE rx, is
	RANGE x
	RANGE DEDX
	NONSPECIFIC_CURRENT i_m
}

PARAMETER {
	x = 0 (1) : spatial coords
	DEDX=0  (mV/mm2)
}

ASSIGNED {
	rx  (milliamp/cm2)
	is  (1)
	i_m (milliamp/cm2)
}

INITIAL {
	i_m=0
}

BREAKPOINT{
	i_m=rx*is
}
