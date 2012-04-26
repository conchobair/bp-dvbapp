#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "info.h"

eSystemInfo *eSystemInfo::instance = 0;

eSystemInfo::eSystemInfo()
{
	instance = this;

	char *model = NULL; 

	char buf[20]={0,};

	int fd;

	if ( 0 < (fd = open("/proc/stb/info/hwmodel",O_RDONLY)))
	{
		read(fd,buf,20);
		close(fd);
	}
	else
	{
		printf("File Open Error");
		close(fd);
	}

	if(strstr(buf,"TMTWIN-OE") != NULL)
	{
		hwtype=TMTWIN;
		modelstr="TMTWIN-OE";
		hasrfmod=1;
		hasvcr=1;
		hasmicom=1;
		haslnbchk=0;
	}
	else if(strstr(buf,"IOS-100HD") !=NULL)
	{
		hwtype=TMTWIN;
		modelstr="IOS-100HD";
		hasrfmod=1;
		hasvcr=1;
		hasmicom=1;
		haslnbchk=0;
	}
	else
	{
		hwtype=TMTWIN;
		modelstr="TMTWIN-OE";
		hasrfmod=1;
		hasvcr=1;
		hasmicom=1;
		haslnbchk=0;
	}
}
