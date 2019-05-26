

/* klib.asm */
  void	out_byte(u16 port, u8 value);
  u8	in_byte(u16 port);
  void	disp_str(char * info);
  void	disp_color_str(char * info, int color);

/* protect.c */
  void	init_prot();
  u32	seg2phys(u16 seg);

/* klib.c */
  void	delay(int time);

/* kernel.asm */
void restart();

/* main.c */
void TestA();
void TestB();
void TestC();

/* i8259.c */
  void put_irq_handler(int irq, irq_handler handler);
  void spurious_irq(int irq);

/* clock.c */
  void clock_handler(int irq);
  void init_clock();

/* keyboard.c */
  void init_keyboard();

/* tty.c */
  void task_tty();
void in_process(u32 key,char * keybuf);

/* 以下是系统调用相关 */

/* proc.c */
   int     sys_get_ticks();        /* sys_call */

/* syscall.asm */
   void    sys_call();             /* int_handler */
   int     get_ticks();

//hd.c
void hd_handler(int irq);
void hd_read();

//port
extern void port_write(u16 port, void* buf, int n);
extern  void port_read(u16 port, void* buf, int n);

//printl
void printl(char str);
void set_curous();

char *strcat(char *a, char *b);
int strcmp(char *s1, char *s2);
char *strcpy(char *s1, char *s2);
void command(char *src);
void cmd_help();
void getch(char *str);
void fucking_sick_shell();
void put_zero();
void cmd_reboot();//重启
void set_video_start_addr(u32 addr);
void cmd_clear();
void clear();
void cmd_os();
void cmd_hd();

u8 scan_code;