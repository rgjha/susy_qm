#include "uti.h"
#include "sparse_matrix.h"
#include "sparse_matrix_transpose.h"

#define MinResidue 0.0000001
#define MAX_ITR 100

int CG_ITS = 0; 

void cg(double x[], double Phi[], double s[])
{
double r[L],p_res[L],MV[L],MMV[L];
double beta1,rsold,rsnew,alpha1,denom;

int i,l;
    
    for (i=0 ; i < L ; i++)
    {
        s[i] = 0.0;  // initial guess
    }
   
//return;
 
    sparse_matrix(x,s,MV);
    sparse_matrix_transpose(x,MV,MMV);
    
    
    for(i=0; i<L; i++)
    {
        
        r[i] = Phi[i] - MMV[i];
        p_res[i] = r[i];
    }
    
    rsold=0.0; 
        for(i=0; i<L; i++)
      {
        rsold += r[i]*r[i];  
      }

    
    for(l=0; l<MAX_ITR; l++)
    {
        
        CG_ITS++ ; 
        sparse_matrix(x,p_res,MV);
        sparse_matrix_transpose(x,MV,MMV);
        
        denom=0.0;
        for(i=0; i<L; i++)
        {
            denom += p_res[i]*MMV[i];
        }
        
        alpha1 = rsold/denom;
        
        for(i=0; i<L; i++)
        {
            s[i] = s[i] + alpha1*p_res[i];
            r[i] = r[i] - alpha1*MMV[i];
        }
        rsnew = 0;
        for(i=0; i<L; i++)
        {
            rsnew += r[i]*r[i];
        }
        beta1 = rsnew / rsold ;
        //std::cout << "Residue_New :  " << rsnew << std::endl ;
    
        for(i=0; i<L; i++)
        { p_res[i] = r[i] + beta1*p_res[i]; }
        rsold = rsnew;
        
        if(sqrt(rsnew) < MinResidue)   {
        //std::cout << " CG_ITERATIONS** :  " << CG_ITS << std::endl ;
        return;
        }

    }
    
    std::cout << "CG did not converge : Res is " << sqrt(rsnew) << " " << std::endl; // This should ideally be never printed //
    return;
}
