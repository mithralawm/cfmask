#ifndef CAL_H
#define CAL_H

#include "lndcal.h"
#include "bool.h"
#include "lut.h"
#include "input.h"
static const int FILL_VAL[6]={65384,65252,65419,65385,65499,65521};
static const int FILL_VAL6= 123;
static const int SATU_VAL[7]={255,255,255,255,255,255,255};
static const int SATU_VAL6= 254;

typedef struct {
  bool first[NBAND_REFL_MAX];
  unsigned char idn_min[NBAND_REFL_MAX];
  unsigned char idn_max[NBAND_REFL_MAX];
  float rad_min[NBAND_REFL_MAX];
  float rad_max[NBAND_REFL_MAX];
  float ref_min[NBAND_REFL_MAX];
  float ref_max[NBAND_REFL_MAX];
  int iref_min[NBAND_REFL_MAX];
  int iref_max[NBAND_REFL_MAX];
  long nfill[NBAND_REFL_MAX];
  long nvalid[NBAND_REFL_MAX];
} Cal_stats_t;

typedef struct {
  bool first;
  unsigned char idn_min;
  unsigned char idn_max;
  float rad_min;
  float rad_max;
  float temp_min;
  float temp_max;
  int itemp_min;
  int itemp_max;
  long nfill;
  long nvalid;
} Cal_stats6_t;

bool dn_to_bt(Input_t *input, unsigned char *line_in, int *line_out);
bool dn_to_toa(Input_t *input, int ib, unsigned char *line_in, int *line_out);

bool Cal(Lut_t *lut, int iband, Input_t *input, unsigned char *line_in, 
         int *line_out, int *line_out_qa, int iy);

bool Cal6(Lut_t *lut, Input_t *input, unsigned char *line_in, 
         int *line_out, int *line_out_qa, int iy);

int getValue(unsigned char* line_in, int ind, int short_flag, int swap_flag);
bool computeBounds(Geo_bounds_t *bounds, Geo_coord_t *ul_corner,
    Geo_coord_t *lr_corner, Space_t *space, int nps, int nls);
#endif
