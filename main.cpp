#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstdio>
void dispfor()
{
    printf("\n  a*f(b)-b*f(a)");
    printf("\n=  -------------");
    printf("\n    f(b)-f(a)");
}
float functionval(float x)
{
    float a=(x*exp(x))-(cos(x*0.0174533));
    return a;
}
float calx(float a, float b){
    float x;
    x=((a*functionval(b))-(b*functionval(a)))/(functionval(b)-functionval(a));
    return x;
}
void method(float a, float b, float  iter){
    float x[10];
    _Bool g=1,br=0;
    int i;
    for(i=1;i<=iter+1;i++)
    {
        if(!g)
        printf("\n");
        printf("\nhere f(%f)>0 and f(%f)<0\nhence root lies between %f and %f",a,b,a,b);
        if(g)
            printf("\nBy Regula-Falsi Method: \n");
        if(br)
        break;
        printf("\nx%d=\t",i);
        if(g){
        dispfor();
        g=0;
        }
        printf("\n      (%f*%f)-(%f*%f)",a,functionval(b),b,functionval(a));
        printf("\n=\t   -------------------------");
        printf("\n\t\t(f(%f)-f(%f)",b,a);

        x[i]=calx(a,b);
        if(functionval(x[i])<0)
        a=x[i];
        if(functionval(x[i])>0)
        b=x[i];
        if(i==iter)
        br=1;
    }
    printf("\n\n\nHence approximate root is %f",x[i-1]);
}
int main(){
    method(0,1,4);
    return 0;
}