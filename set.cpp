#include<iostream>
#include<cstring>
using namespace std;
int main(){
    float i,j;
    char canvas[1760];//canvas 80*22
    char brightness[12]={'.',',','-','~',':',';','!','=','$','&','#','@'};
        memset(canvas,32,1760);//32 for blank space and 1760 is size
        /**change the range to get more wider view 
         *decrease the increment in looping variable to get accuracy(take 15-20 min to execute if <=0.0001)
         **/ 
        for(j=-2.5;j<2.5;j+=0.001)
       {
            for(i=-2.5;i<2.5;i+=0.001)
            {
            float a=i,b=j;
                    int n=0;
                    while(n<100)
	             {
	               float aa=(a*a)-(b*b);
	               float bb=2*a*b;
	               a=aa+i;
	               b=bb+j;
	               if(int(a+b)>16)
	               break;
	               n++;	               
		         }
                 //mapping 80,22 to -2.5,2.5
                    int x=40+i*16;
                    int y= 11+j*4.4;
                    int o=x+80*y;
                    //mapping 0,100 to 0,11 that is  setting brightness according to number of iterations n
                    int e=n/9.09;
                    if(22>y&&y>0&&x>0&&80>x)
                    canvas[o]=brightness[e];
        }
        }
        //printing characters
        for(int k=0;k<1761;k++)
        {
            putchar(k%80!=0?canvas[k]:10);//10 is ASCII for line feed
        }   
    return 0;
}
