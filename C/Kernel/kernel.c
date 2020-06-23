#include "kernel.h"
#include "utils.h"
#include "keyboard.h"
#include "str.h"
#include "box.h"

char VERSION[]="0.0.1";
uint32 vga_index;
static uint32 next_line_index = 1;
uint8 g_fore_color = WHITE, g_back_color = BLUE;
int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color)
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color)
{
  uint32 i;
  for (i = 0; i < BUFSIZE; i++)
  {
    (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
  }
  next_line_index = 1;
  vga_index = 0;
}

void init_vga(uint8 fore_color, uint8 back_color)
{
  vga_buffer = (uint16 *)VGA_ADDRESS;
  clear_vga_buffer(&vga_buffer, fore_color, back_color);
  g_fore_color = fore_color;
  g_back_color = back_color;
}

void clear_screen(uint8 fore_color, uint8 back_color)
{
  clear_vga_buffer(&vga_buffer, fore_color, back_color);
}
void clear_F(){
  clear_screen(g_fore_color,g_back_color);
  gotoxy(1,1);
  char strs[]="                        QuariumOS version: ";

  print_string(strs);
  print_string(VERSION);

  
  draw_box(BOX_DOUBLELINE,0,0,78,1,g_fore_color,g_back_color);
  

  print_new_line();print_new_line();print_new_line();
}
void print_new_line()
{
  if (next_line_index >= 55)
  {
    next_line_index = 0;
    clear_vga_buffer(&vga_buffer, g_fore_color, g_back_color);
  }
  vga_index = 80 * next_line_index;
  next_line_index++;
}

void print_char(char ch)
{
  vga_buffer[vga_index] = vga_entry(ch, g_fore_color, g_back_color);
  vga_index++;
}

void print_string(char *str)
{
  uint32 index = 0;
  while (str[index])
  {
    print_char(str[index]);
    index++;
  }
}

void print_color_string(char *str, uint8 fore_color, uint8 back_color)
{
  uint32 index = 0;
  uint8 fc, bc;
  fc = g_fore_color;
  bc = g_back_color;
  g_fore_color = fore_color;
  g_back_color = back_color;
  while (str[index])
  {
    print_char(str[index]);
    index++;
  }
  g_fore_color = fc;
  g_back_color = bc;
}

void print_int(int num)
{
  char str_num[digit_count(num) + 1];
  itoa(num, str_num);
  print_string(str_num);
}

uint8 inb(uint16 port)
{
  uint8 ret;
  asm volatile("inb %1, %0"
               : "=a"(ret)
               : "d"(port));
  return ret;
}

void outb(uint16 port, uint8 data)
{
  asm volatile("outb %0, %1"
               : "=a"(data)
               : "d"(port));
}

byte get_input_keycode()
{
  uint16 oldvgai = vga_index;
  int curs = 0;
  int a = 0;
  int j=0;
  byte keycode = 0;
  print_color_string("_", WHITE, BLACK);
  while ((keycode = inb(KEYBOARD_PORT)) != 0)
  {
    vga_index = oldvgai;
    if (keycode > 0){
      a = 1;}

      if (j==200000/10){print_color_string("_", WHITE, BLACK);j=0;}
      if (j==100000/10){print_color_string("_", BLACK, BLACK);}
      j++;

      if (a)
      {
        print_color_string("_", BLACK, BLACK);
        vga_index=oldvgai;
        return keycode;
      }
    
  }
  return keycode;
}

/*
keep the cpu busy for doing nothing(nop)
so that io port will not be processed by cpu
here timer can also be used, but lets do this in looping counter
*/
void wait_for_io(uint32 timer_count)
{
  while (1)
  {
    asm volatile("nop");
    timer_count--;
    if (timer_count <= 0)
      break;
  }
}

void sleep(uint32 timer_count)
{
  wait_for_io(timer_count);
}

void gotoxy(uint16 x, uint16 y)
{
  vga_index = 80 * y;
  vga_index += x;
}
char get_char(byte c)
{
  if (c == KEY_A)
  {
    return 'a';
  }
  else if (c == KEY_B)
  {
    return 'b';
  }
  else if (c == KEY_C)
  {
    return 'c';
  }
  else if (c == KEY_D)
  {
    return 'd';
  }
  else if (c == KEY_E)
  {
    return 'e';
  }
  else if (c == KEY_F)
  {
    return 'f';
  }
  else if (c == KEY_G)
  {
    return 'g';
  }
  else if (c == KEY_ENTER)
  {
    return '\n';
  }
  else if (c == KEY_H)
  {
    return 'h';
  }
  else if (c==KEY_I)
  {
    return 'i';
  }
  else if (c==KEY_J)
  {
    return 'j';
  }
  else if (c==KEY_F12)
  {
    return (char) 28;
  }
  else if (c==KEY_BACKSPACE)
  {
    return (char) 8;
  }
  
  
  
  else
  {
    return '\0';
  }
}
void kernel_entry()
{
  byte ans = KEY_Y;
  init_vga(WHITE, BLACK);
  clear_screen(WHITE, BLACK);
  int size=0;
  char line[] = "";
  char abc[] = "abc";
  int l = 0;
  int z = 3; //X
  int v = 0; //Y
  vga_index=2200;
  if (BUFSIZE-200<=vga_index){clear_screen(WHITE,BLACK); gotoxy(0,0);}
  draw_box(BOX_SINGLELINE, z, v, 15, 7, BLUE, BRIGHT_CYAN);
  gotoxy(z + 1, v + 1);
  print_string("    QUARIUM    ");
  gotoxy(z + 1, v + 2);
  print_string("      OS       ");
  gotoxy(z + 1, v + 3);
  print_string("               ");
  gotoxy(z + 1, v + 4);
  print_string("Kernel Version:");
  gotoxy(z + 1, v + 5);
  print_string("     -0.0.1    ");
  gotoxy(z + 1, v + 6);
  print_string("               ");
  gotoxy(z + 1, v + 7);
  print_string("BY Slow_Riding ");

  sleep(9999999999);
  clear_F();
  //clear_screen(WHITE, BLACK);
  while (1)
  {
    

    ans = get_input_keycode();
    //gotoxy(x, y);
    if ((int)(get_char(ans)) == 28)
    {
      break;
    }
    else if (ans == KEY_ENTER)
    {print_new_line();
      
      if (strbegw("abc", line))
      {
        
        print_string("welcome ABCP");
        //x+=12;
        print_new_line();
        //y+2
      }
      int ia = 0;
      line[0]='\0';
      l = 0;
    
    }
    else if (get_char(ans)=='\0')
    {
      
    }
    else if (get_char(ans)==(char)8)
    {
      size = strlen(line);
      
      
      line[size-1] = 0;
      vga_index=vga_index-1;
      print_new_line();
      print_string(line);
    }
    
    
    else
    {
      line[l] = get_char(ans);
      l++;
      print_char(get_char(ans));

      //x++;
    }
    sleep(29304890 * 5);
    sleep(39304890);
    if (BUFSIZE-200<=vga_index){clear_F(); gotoxy(0,3);}
    //print_int(vga_index);
  }
}
