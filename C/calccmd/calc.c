#include "calc.h"
#include "utils.h"
#include "structapp.h"
#include "kernel.h"
void calculus(){
    struct app calculus_app;
    calculus_app.backcolor=BRIGHT_GREEN;
    //strcpystruct(calculus_app.name,"calculus");
    //print_new_line();
    //print_int(strlen(calculus_app.name));
    for (int i=0;i<11;i++){
        calculus_app.name[i]="calculus: "[i];
    }
    for (int i=0;i<6;i++){calculus_app.version[i]="1.0.1"[i];}
    
    //for(int i=-99999999;i<__INT64_MAX__;i++){}
    clear_FC(calculus_app);
    while (TRUE)
    {
        print_char(get_input_keycodemath());
    }
    
    
}