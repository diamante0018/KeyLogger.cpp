# include "stdafx.h"
# include <conio.h>
# include <process.h>
# include <iostream>
# include <stdio.h>
# include <io.h>
# include <windows.h>
# include <winuser.h>
using namespace std;

int main(void)
{
	int k;
	k = _spawnl(P_DETACH, "C:/temp/keylogger.exe", "C:/temp/keylogger.exe", NULL);
	printf("esito=%d,    errno=%d\n", k, errno);

}



