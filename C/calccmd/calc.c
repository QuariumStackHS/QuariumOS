#include "calc.h"
#include "utils.h"
#include "structapp.h"
extern void clear_FC();
extern void print_int(int);
extern void print_new_line();
void calculus(){
    struct app calculus_app;
    calculus_app.backcolor=BRIGHT_GREEN;
    //strcpystruct(calculus_app.name,"calculus");
    //print_new_line();
    //print_int(strlen(calculus_app.name));
    for (int i=0;i<11;i++){
        calculus_app.name[i]="calculus: "[i];
    }
    for (int i=0;i<6;i++){
    calculus_app.version[i]="0.0.1"[i];}
    
    //for(int i=-99999999;i<__INT64_MAX__;i++){}
    clear_FC(calculus_app);
    print_int(strlen(calculus_app.version));
    print_int(strlen(calculus_app.name));
}