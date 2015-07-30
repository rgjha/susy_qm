
#include "uti.h"


void sparse_matrix_transpose(double x[], double MV[], double MMV[])
{
int i;

    for ( i = 0 ; i < L ; i++)
    {
        MMV[i] = (m + 3*g*x[i]*x[i])*MV[i] -MV[(i+1)%L]+MV[i] ;
    }

return;
}

