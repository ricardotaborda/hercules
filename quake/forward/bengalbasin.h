/*
 * bengalbasin.h
 *
 *  Created on: Mar 27, 2016
 *      Author: monsurul huda
 */

#ifndef BENGALBASIN_H_
#define BENGALBASIN_H_

typedef struct theprops_t {
    float Vp, Vs, rho;
} theprops_t;

int bengal_cvm_query(FILE *fp, float east_m, float north_m, float depth_m, theprops_t* result);

#endif /* BENGALBASIN_H_ */
