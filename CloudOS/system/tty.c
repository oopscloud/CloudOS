


#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "keyboard.h"
int src_pos=0;
char src[512];

int i=1;
PUBLIC void task_tty()
{
	
	while (1) {
		keyboard_read();
		
	
	}
}
void fucking_sick_shell(){
	
	printf("\n====================Welcome To The Fucking sick Shell!!!!!!!====================");
	char shell_buf[512];
	while(1){
		if(disp_pos==4000){
			clear();
		}
		printf("\nCommand>");
		
		getch(shell_buf);
		
		command(shell_buf);
		
	}
	
		
	
}

PUBLIC void in_process(u32 key,char keybuf[512])
{		
		
		
        char output[2] = {'\0', '\0'};
		
        if (!(key & FLAG_EXT)) {
                output[0] = key & 0xFF;
                disp_str(output);
				strcat(src,output);
				set_curous();
				
				src_pos++;
				
		}
		
        
        else {
				if(scan_code==0x1c){
					disp_str("\n");
					
					strcpy(keybuf,src);//将src赋值给keybuf全局变量                  
					memset(src, 0, sizeof(src)); 
					set_curous();
					i=0;
					
					
					
					src_pos=0;
					
					
				}else{
					if(scan_code==0x0e){
						if(src_pos!=0){
							src_pos--;
							src[src_pos]=0;
						
							disp_pos=disp_pos-2;
						
							//put_zero();
							//display_buf[disp_pos]=' ' & 0xFF;
						
							printf(" ");
						
							disp_pos=disp_pos-2;
						
						
							set_curous();
						}
						
						
						
					}
				}
        }
}
void set_curous(){
		disable_int();
		out_byte(CRTC_ADDR_REG, CURSOR_H);
		out_byte(CRTC_DATA_REG, ((disp_pos/2)>>8)&0xFF);
		out_byte(CRTC_ADDR_REG, CURSOR_L);
		out_byte(CRTC_DATA_REG, (disp_pos/2)&0xFF);
		enable_int();
}
void command(char *src){
	if(strcmp(src,"reboot")==0){
			cmd_reboot();
	}else{
		if(strcmp(src,"clear")==0){
		cmd_clear();
	}else{
		if(strcmp(src,"help")==0){
		cmd_help();
		}else{
			if(strcmp(src,"hd")==0){
				cmd_hd();
			}else{
				if(strcmp(src,"os")==0){
					cmd_os();
				}else{
					if(strcmp(src,"")==0){
					return;
				}else{
					printf("Unknown Command");
					}
					}
				}
			
			}
		}
	
	
	
	
		
		
			
			
		    
		}
		
		
	}
	

void cmd_help(){
	printf("CloudOS  Command List:\n");
	printf("Help:Display This Text\n");
	printf("Reboot:Reboot This System\n");
	printf("OS: OS Infomation\n");
	printf("HD: Display HD information\n");
	printf("Clear:Clear The Screen\n");
	printf("======================");
	
}
void cmd_reboot(){
	//printf("reboot");
	
		out_byte(0x64, 0xfe);
	
	
}
void cmd_clear(){
	disp_pos = 0;
	for(i=0;i<80*25;i++){
		disp_str(" ");
	}
	disp_pos = 0;
}
void cmd_os(){
	printf("CloudOS v1.6\n");
	printf("Devlopers:Nora\n");
	printf("Powered by Orange's");
}
void cmd_hd(){
	hd_ide(0);
}
void getch(char *str){
	while(i!=0){
		//等待回车
		
		
	}
	
	strcpy(str,keybuf);
	
	i=1;
		
}
void set_video_start_addr(u32 addr){
	disable_int();
	out_byte(CRTC_ADDR_REG, START_ADDR_H);
	out_byte(CRTC_DATA_REG, (addr >> 8) & 0xFF);
	out_byte(CRTC_ADDR_REG, START_ADDR_L);
	out_byte(CRTC_DATA_REG, addr & 0xFF);
	enable_int();
}
void clear(){
	disp_pos = 0;
	for(i=0;i<80*25;i++){
		disp_str(" ");
	}
	disp_pos = 0;
	memset(src, 0, sizeof(src));
}
