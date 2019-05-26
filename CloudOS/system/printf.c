#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"
#include "hd.h"

void printf(char *  str){
		disp_str(str);
		set_curous();
}