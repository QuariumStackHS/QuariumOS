#include "structapp.h"
#include "utils.h"
#include "calc.h"
struct appstruct apps;
void addfunct(void (*functions),char* name ){
    apps.functions[strlen(apps.functions)+1]=functions;
    for(int i=0; i<strlen(name);i++){
    apps.functions_name[strlen(apps.functions_name)+1][i]=name[i];
    }

}
void add_allcommandes(){
    addfunct(calculus,"calculus");
}