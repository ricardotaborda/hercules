#include <stdio.h>

double bilinear(double x, double y, 
        double x1, double y1, double x2, double y2, 
        double q11, double q21, double q12, double q22)
{
    double p = (x2 - x1) * (y2 - y1);
    double f1 = (q11 / p) * (x2 - x) * (y2 - y);
    double f2 = (q21 / p) * (x - x1) * (y2 - y);
    double f3 = (q12 / p) * (x2 - x) * (y - y1);
    double f4 = (q22 / p) * (x - x1) * (y - y1);
    return f1 + f2 + f3 + f4;
}


double get_lat(double x, double y, double x_north_len, double y_east_len,double lat_lower_left, double lat_lower_right, double lat_upper_left, double lat_upper_right) 
{
    
    // Latitudes of ShakeOut region corners   # first value is along long (horizental direction 6000) and second value is along lat (3000) 
    return bilinear(x,y,
            0, 0, x_north_len, y_east_len,          
            lat_lower_left, lat_lower_right, 
            lat_upper_left, lat_upper_right);

// double get_lat(double x, double y) {
    
//     // Latitudes of ShakeOut region corners   # first value is along long (horizental direction 6000) and second value is along lat (3000) 
//     return bilinear(x,y,
//             0, 0, 10000, 10000,          
//             -43.80, -43.80, 
//             -43.70, -43.70);


}

double get_lon(double x, double y, double x_north_len, double y_east_len, double lon_lower_left, double lon_lower_right, double lon_upper_left, double lon_upper_right ) {
    
    return bilinear(x,y,
            0, 0, x_north_len, y_east_len,          
            lon_lower_left, lon_lower_right, 
            lon_upper_left, lon_upper_right);

    //Longitudes of ShakeOut region corners
    // return bilinear(x,y,
    //         0, 0, 10000, 10000, 
    //         172.20, 172.30, 
    //         172.20, 172.30);
        // double x_north_len;            
        // double y_east_len;
        // double long_east_1;
        // double long_east_2;
        // double long_west;
        // double long_west_2;


        // return bilinear(x,y,
        //     0, 0, x_north, y_east, 
        //     long_east, long_west, 
        //     long_east, long_west);
}


int convert(double x, double y) {
    
  double lat, lon;
//     // double  theSurfaceCornersLong[4];
//     // double  theSurfaceCornersLat[4];
//     FILE  *ifp;
//     char *mode = "r";
//     char outputFilename[] = "out.list";

//     ifp = fopen("parameters.in", mode);

// if (ifp == NULL) {
//   fprintf(stderr, "Can't open input file in.list!\n");
//   exit(1);
// }



    // double *auxiliar;
    // FILE*  fp;
    
    // fp = fopen ( 'parameters.in', "r");  

    // auxiliar = (double *)malloc(sizeof(double)*8);

    // if (parsedarray( fp, "domain_surface_corners", 8, auxiliar ) != 0) 
    // {
    // fprintf(stderr, "Can not find the domain_surface_corners,  \n" );
    // }

    // fprintf(stderr, "Can not find the domain_surface_corners %lf\n" , theSurfaceCornersLong[0]);
    // 600km in x direction
    if(x<0 || x>600000){
        fprintf(stderr,"Invalid x, value must be between 0 and 600000: %lf\n",x);
        return 1;
    }

    // 300km in y direction
    if(y<0 || y>300000){
        fprintf(stderr,"Invalid y, value must be between 0 and 300000: %lf\n",y);
        return 1;
    }

    // lat = get_lat(x,y);
    // lon = get_lon(x,y);

    // printf("%.11lf %.11lf\n",lat,lon);

    return 0;
}

void convert_program(double x,double y)
{
//int main(int argc, char **argv) {

    
//    double x, y;
    int res;
    char fname;


    // if(argc!=3 && argc!=1 && argc!=2) {
    //     fprintf(stderr,"Usage: %s [x y]\n\n"
    //             "x = x coordinate in meters\n"
    //             "y = y coordinate in meters\n\n"
    //             "Convert ShakeOut x,y coordinates to lat,lon using "
    //             "bilinear projection\n"
    //             "If 1 argument, it is file name N followed by N-pairs\n"
    //             "If no arguments are provided, input lines are read "
    //             "from stdin in \"x y\" format.\n",argv[0]);
    //     return 1;
    // }

    // // Use arguments if specified
    // if(argc==3){
    //     if(sscanf(argv[1],"%lf",&x)!=1) {
    //         fprintf(stderr,"Invalid x coordinate: %s\n",argv[1]);
    //         return 1;
    //     }

        // if(sscanf(argv[2],"%lf",&y)!=1) {
        //     fprintf(stderr,"Invalid y coordinate: %s\n",argv[2]);
        //     return 1;
        // }

    convert(x,y);
    // }

    // if (argc==2) {
    //     if(sscanf(argv[1],"%s",fname)!=1) {
    //         fprintf(stderr,"Input file problem");
    //         return 1;
    //     }
        
        
    // }
    
    // // Use stdin by default
    // while((res=fscanf(stdin,"%lf %lf",&x,&y))==2) {
    //     if(convert(x,y)>0) return 1;
    // }

    // if(res!=EOF && res<1) {
    //     fprintf(stderr,"Error reading input\n");
    //     if(res!=0) perror("fscanff");
    //     return 1;
    // }

//    return 0;
}
