#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"
#include "hd.h"
void print_identify_info(u16* hdinfo);
u8	hd_status;
int	msg;

void cmd_out(struct hd_cmd* cmd);





void init_hd(){
	
	
	
	put_irq_handler(AT_WINI_IRQ, hd_handler);
	enable_irq(CASCADE_IRQ);
	enable_irq(AT_WINI_IRQ);
	
	
	
}
void hd_ide(int drive){
	u8 * hd_drivers=(u8*) (0x475);
	printf("Number of HardDisks:");
	disp_int(*hd_drivers);
	printf("\n");
	struct	hd_cmd cmd;
	cmd.device=MAKE_DEVICE_REG(0 , drive , 0);
	cmd.command = 0xEC;
	cmd_out(&cmd);
	
	waitfor(STATUS_BSY, 0, HD_TIMEOUT);
	port_read(REG_DATA, hdbuf, SECTOR_SIZE);
	print_identify_info((u16*)hdbuf);
	
	
	
	 
	 
}
void cmd_out(struct hd_cmd* cmd){
	out_byte(REG_DEV_CTRL, 0);
	/* Load required parameters in the Command Block Registers */
	out_byte(REG_FEATURES, cmd->features);
	out_byte(REG_NSECTOR,  cmd->count);
	out_byte(REG_LBA_LOW,  cmd->lba_low);
	out_byte(REG_LBA_MID,  cmd->lba_mid);
	out_byte(REG_LBA_HIGH, cmd->lba_high);
	out_byte(REG_DEVICE,   cmd->device);
	/* Write the command code to the Command Register */
	out_byte(REG_CMD,     cmd->command);
	
}




PUBLIC void hd_handler(int irq){
		msg=0;
		
		
}
		

		


	
void print_identify_info(u16* hdinfo){
	int size;
	int i, k;
	char s[64];

	struct iden_info_ascii {
		int idx;
		int len;
		char * desc;
	} iinfo[] = {{10, 20, "HD SN"}, /* Serial number in ASCII */
		     {27, 40, "HD Model"} /* Model number in ASCII */ };

	for (k = 0; k < sizeof(iinfo)/sizeof(iinfo[0]); k++) {
		char * p = (char*)&hdinfo[iinfo[k].idx];
		for (i = 0; i < iinfo[k].len/2; i++) {
			s[i*2+1] = *p++;
			s[i*2] = *p++;
		}
		s[i*2] = 0;
		printf(iinfo[k].desc);
		printf(":" );
		printf(s);
		printf("\n");
	}

	

	int sectors = ((int)hdinfo[61] << 16) + hdinfo[60];
	size=sectors*512;
	int hd_size;
	hd_size=size/1024;
	hd_size=hd_size/1024;
	

	
	printf("HD size:");
	disp_int(hd_size);
	printf("MB\n");
	
}
void hd_read(int lba,int drive,u8* buf){
		
		out_byte(REG_DEV_CTRL, 0);	//Active disk int
		
		//Set command info
		out_byte(REG_FEATURES, -1);
		out_byte(REG_NSECTOR, 1);
		out_byte(REG_LBA_LOW, lba);
		out_byte(REG_LBA_MID, lba>>8);
		out_byte(REG_LBA_HIGH, lba>>16);
		out_byte(REG_DEVICE, MAKE_DEVICE_REG(1, drive , (lba >> 24) & 0xF));
		
		out_byte(REG_CMD, ATA_READ);	//Send read command
		waitfor(STATUS_BSY, 0, HD_TIMEOUT);
		port_read(REG_DATA, buf, SECTOR_SIZE);
		
		
}
void hd_write(int lba, int drive, u8* buf){
		out_byte(REG_DEV_CTRL, 0);	//Active disk int
		
		//Set command info
		out_byte(REG_FEATURES, -1);
		out_byte(REG_NSECTOR, 1);
		out_byte(REG_LBA_LOW, lba);
		out_byte(REG_LBA_MID, lba>>8);
		out_byte(REG_LBA_HIGH, lba>>16);
		out_byte(REG_DEVICE, MAKE_DEVICE_REG(1, drive , (lba >> 24) & 0xF));
		
		out_byte(REG_CMD, ATA_WRITE);	//Send read command
		waitfor(STATUS_BSY, 0, HD_TIMEOUT);
		port_write(REG_DATA, buf, SECTOR_SIZE);
}
int waitfor(int mask, int val, int timeout)
{
	int t = get_ticks();

	while(((get_ticks() - t) * 1000 / HZ) < timeout)
		if ((in_byte(REG_STATUS) & mask) == val)
			return 1;

	return 0;
}

