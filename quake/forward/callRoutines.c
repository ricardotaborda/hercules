
//  callRoutines.c
//  UCVM-Integration
//
//  Created by Ethan Thomson on 10/07/16.
//  Copyright © 2016 Dept. Civil Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include "omp.h"

#include "constants.h"
#include "structs.h"
#include "functions.h"




void runGenerateMultipleVSonGrid(global_model_parameters *GLOBAL_MODEL_PARAMETERS ,velo_mod_1d_data *VELO_MOD_1D_DATA, nz_tomography_data *NZ_TOMOGRAPHY_DATA,global_surfaces *GLOBAL_SURFACES,basin_data *BASIN_DATA, char *OUTPUT_DIR, gen_extract_multi_gridpoint_vs_call GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, calculation_log *CALCULATION_LOG, double lat, double lon, double depth, qualities_vector *QUALITIES_VECTOR)
{
//void runGenerateMultipleVSonGrid(char *MODEL_VERSION, char *OUTPUT_DIR, gen_extract_multi_gridpoint_vs_call GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, calculation_log *CALCULATION_LOG)
//{
    // Read in text file with parameters

    multi_gridpoint_parameters  MULTI_GRIDPOINT_PARAMETERS;
    // MULTI_GRIDPOINT_PARAMETERS = malloc(sizeof(multi_gridpoint_parameters));
    // if (MULTI_GRIDPOINT_PARAMETERS == NULL)
    // {
    //     printf("Memory allocation of MULTI_GRIDPOINT_PARAMETERS failed.\n");
    //     exit(EXIT_FAILURE);
    // }
    MULTI_GRIDPOINT_PARAMETERS.nPts = 1;
//
    variable_depth_points *VARIABLE_DEPTH_POINTS;


// ********************************************************************************************************
    // test of the input parameters 

    //printf( "This is total number of points %d\n", MULTI_GRIDPOINT_PARAMETERS.nPts );
    //printf( "This is the lat long value, %lf %lf %lf", MULTI_GRIDPOINT_PARAMETERS->lat[0], MULTI_GRIDPOINT_PARAMETERS->lon[0], MULTI_GRIDPOINT_PARAMETERS->dep[0] );
   // printf( "This is total number of points, %d\n",&MULTI_GRIDPOINT_PARAMETERS->nPts );



// ******************************************************************************************************


    mesh_vector MESH_VECTOR;
    // MESH_VECTOR = malloc(sizeof(mesh_vector));
    // if (MESH_VECTOR == NULL)
    // {
    //     printf("Memory allocation of MESH_VECTOR failed.\n");
    //     exit(EXIT_FAILURE);
    // }






//*******************************************************************************************************
   // loading input data from the desk 
    // MULTI_GRIDPOINT_PARAMETERS.nPts= 1;
//    MULTI_GRIDPOINT_PARAMETERS->lat[0]= -43.00;
    MULTI_GRIDPOINT_PARAMETERS.lat[0]= lat;
//    MULTI_GRIDPOINT_PARAMETERS->lon[0]= 172.00;
    MULTI_GRIDPOINT_PARAMETERS.lon[0]= lon;
//    MULTI_GRIDPOINT_PARAMETERS->dep[0]= -2000.0;
    MULTI_GRIDPOINT_PARAMETERS.dep[0]= depth;
    MULTI_GRIDPOINT_PARAMETERS.nGroupings= 1;  
    int grdPtsCount = 0;

   //printf( "This is the lat long value coming from call routine%lf %lf %lf\n", MULTI_GRIDPOINT_PARAMETERS.lat[0], MULTI_GRIDPOINT_PARAMETERS.lon[0], MULTI_GRIDPOINT_PARAMETERS.dep[0] );


//*******************************************************************************************************    
    // loop over gridpoints
//    for( int i = 0; i < MULTI_GRIDPOINT_PARAMETERS->nGroupings; i++ )
//    {
        int i=0;
        MESH_VECTOR.nZ = 0;
        //while (MULTI_GRIDPOINT_PARAMETERS.grouping[grdPtsCount] == i)
        //{
            MESH_VECTOR.Z[0] = MULTI_GRIDPOINT_PARAMETERS.dep[0] ;
            MESH_VECTOR.Z[1]= 0.000;
            MESH_VECTOR.nZ += 1;
            grdPtsCount += 1;
        //}
        MESH_VECTOR.Lat = &MULTI_GRIDPOINT_PARAMETERS.lat[i];
        MESH_VECTOR.Lon = &MULTI_GRIDPOINT_PARAMETERS.lon[i];
       // printf( "This is the lat long value coming from call routine in mesh_vector %lf,%lf,%lf, %d\n", *MESH_VECTOR.Lat, *MESH_VECTOR.Lat, MESH_VECTOR.Z[0], MESH_VECTOR.nZ);


        in_basin *IN_BASIN;
        IN_BASIN = malloc(sizeof(in_basin));
        if (IN_BASIN == NULL) {
            printf("Memory allocation of IN_BASIN failed.\n");
            exit(EXIT_FAILURE);
        }

        partial_global_surface_depths *PARTIAL_GLOBAL_SURFACE_DEPTHS;
        PARTIAL_GLOBAL_SURFACE_DEPTHS = malloc(sizeof(partial_global_surface_depths));
        if (PARTIAL_GLOBAL_SURFACE_DEPTHS == NULL) {
            printf("Memory allocation of PARTIAL_GLOBAL_SURFACE_DEPTHS failed.\n");
            exit(EXIT_FAILURE);
        }

        partial_basin_surface_depths *PARTIAL_BASIN_SURFACE_DEPTHS;
        PARTIAL_BASIN_SURFACE_DEPTHS = malloc(sizeof(partial_basin_surface_depths));
        if (PARTIAL_BASIN_SURFACE_DEPTHS == NULL) {
            printf("Memory allocation of PARTIAL_BASIN_SURFACE_DEPTHS failed.\n");
            exit(EXIT_FAILURE);
        }

        // qualities_vector *QUALITIES_VECTOR;
        // QUALITIES_VECTOR = malloc(sizeof(qualities_vector));
        // if (QUALITIES_VECTOR == NULL) {
        //     printf("Memory allocation of QUALITIES_VECTOR failed.\n");
        //     exit(EXIT_FAILURE);
        // }
        assignQualities(GLOBAL_MODEL_PARAMETERS, VELO_MOD_1D_DATA, NZ_TOMOGRAPHY_DATA, GLOBAL_SURFACES, BASIN_DATA,
                        MESH_VECTOR, PARTIAL_GLOBAL_SURFACE_DEPTHS, PARTIAL_BASIN_SURFACE_DEPTHS, IN_BASIN,
                        QUALITIES_VECTOR, CALCULATION_LOG, GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL.TOPO_TYPE);
        

        //printf( "The qualities_vector, %lf %lf %lf", QUALITIES_VECTOR->Vp[0], QUALITIES_VECTOR->Vs[0], QUALITIES_VECTOR->Rho[0] );
        //printf("Hello test the grouping loop .\n");
        //writeGridpointVelocities(QUALITIES_VECTOR, GEN_EXTRACT_MULTI_GRIDPOINT_VS_CALL, MESH_VECTOR, OUTPUT_DIR, CALCULATION_LOG, i);

        //printf("Gridpoint lat-lon %i of %i complete.\n", i + 1, MULTI_GRIDPOINT_PARAMETERS->nGroupings);

        // double foo= 15.0;
        // MESH_VECTOR->Lat= &(foo);
        // MESH_VECTOR->Lon= &(foo);
        free(IN_BASIN);
        free(PARTIAL_BASIN_SURFACE_DEPTHS);
        free(PARTIAL_GLOBAL_SURFACE_DEPTHS);
     //   free(MESH_VECTOR);

        //free(QUALITIES_VECTOR);
//    }
//    free(VELO_MOD_1D_DATA);
//    freeEPtomoSurfaceData(NZ_TOMOGRAPHY_DATA);
//    free(NZ_TOMOGRAPHY_DATA);
//    free(GLOBAL_SURFACES);
//    freeGlobalSurfaceData(GLOBAL_SURFACES, GLOBAL_MODEL_PARAMETERS);
//    freeAllBasinSurfaces(BASIN_DATA, GLOBAL_MODEL_PARAMETERS);
//    free(BASIN_DATA);
//
      // fr ee(MULTI_GRIDPOINT_PARAMETERS);
}
