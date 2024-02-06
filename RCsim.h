
#define RC_FILTER_H

typedef struct {

	float coeff[2];
	float out[2];

} rcSim;

void rcSim_Init(rcSim *filt, float cutoffFreqHz, float sampleTimeS);
float rcSim_Update(rcSim *filt, float inp);

