#include "RCsim.h"

void rcSim_Init(rcSim *filt, float cutoffFreqH, float sampleTimeS) {

	
	float RC = 1.0f / (6.28318530f * cutoffFreqH); // Compute equivalent 'RC' constant from cut-off frequency 

	
	filt->coeff[0] = sampleTimeS / (sampleTimeS + RC); //Pre-compute filter coefficients for first-order low-pass filter 
	filt->coeff[1] = RC / (sampleTimeS + RC);

	
	filt->out[0] = 0.0f;      // Clear output buffer 
	filt->out[1] = 0.0f;

}

float rcSim_Update(rcSim *filt, float inp) {

	/* Shift output samples */
	filt->out[1] = filt->out[0];

	/* Compute new output sample */
	filt->out[0] = filt->coeff[0] * inp + filt->coeff[1] * filt->out[1]; // Discretizing using Backward Euler for simplicity

	/* Return filtered sample */
	return (filt->out[0]);

}