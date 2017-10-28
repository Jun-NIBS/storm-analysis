/*
 * FFT PSF fitting API.
 *
 * Hazen 10/17
 */

#ifndef FFT_FIT_H
#define FFT_FIT_H

#include "psf_fft.h"
#include "../sa_library/multi_fit.h"

/* Structures */
typedef struct psfFFTPeak
{
  double dx;      /* Peak delta x (difference between actual and integer position). */
  double dy;      /* Peak delta y (difference between actual and integer position). */
  double dz;      /* Peak delta z (difference between actual and integer position). */
  
  double *psf;    /* The current peak shape. */
} psfFFTPeak;

  
typedef struct psfFFTFit
{
  int psf_x;             /* The size in X of the PSF. */
  int psf_y;             /* The size in Y of the PSF. */
  int psf_z;             /* The size in Z of the PSF. */

  double *dx;            /* Temporary storage of the PSF derivative in x. */
  double *dy;            /* Temporary storage of the PSF derivative in y. */
  double *dz;            /* Temporary storage of the PSF derivative in z. */
  
  psfFFT *psf_fft_data;  /* PSF FFT data structure. */
} psfFFTFit;

void ftFitAddPeak(fitData *);
void ftFitCalcJH3D(fitData *, double *, double *);
void ftFitCleanup(fitData *);
void ftFitCopyPeak(peakData *, peakData *);
fitData* ftFitInitialize(psfFFT *, double *, double *, double, int, int);
void ftFitNewPeaks(fitData *, double *, int);
void ftFitSubtractPeak(fitData *);
void ftFitUpdate3D(fitData *, double *);
void ftFitZRangeCheck(fitData *);

#endif
