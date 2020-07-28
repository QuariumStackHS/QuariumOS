#include "calc.h"
#include "utils.h"
#include "structapp.h"
extern void clear_FC();
extern void print_int(int);
void calculus(){
    struct app calculus_app;
    calculus_app.backcolor=BRIGHT_GREEN;
    strcpystruct(calculus_app.name,"calculus");
    strcpystruct(calculus_app.version,"0.0.1");
    clear_FC(calculus_app);
    print_int(strlen(calculus_app.name));
}