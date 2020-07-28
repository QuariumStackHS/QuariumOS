extern void addfunct(void (*functions),char* name );
extern void add_allcommandes();
enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};


struct app 
{
            char name[9];
            char version[4];
            int backcolor;
};
struct appstruct{
 void (*functions[256])();
 char functions_name[256][24];
};
//extern struct appstruct apps;
