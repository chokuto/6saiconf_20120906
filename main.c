#include <stdio.h>
#include <math.h>

int main(void)
{
	int i, j;
	unsigned char header[44] = {0x52, 0x49, 0x46, 0x46, 0x34, 0xb1, 0x02, 0x00, 0x57, 0x41, 0x56, 0x45, 0x66, 0x6d, 0x74, 0x20, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x44, 0xac, 0x00, 0x00, 0x44, 0xac, 0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x64, 0x61, 0x74, 0x61, 0x10, 0xb1, 0x02, 0x00};
	FILE* fp = fopen("out.wav", "wb");
	double x = 0.0;
	fwrite(header, 1, 44, fp);
	for (i = 0; i < 16; i++)
	{
		int key;
		scanf("%d", &key);
		for (j = 0; j < 44100 / 4; j++)
		{
			unsigned char a = (unsigned char)(sin(x) * 127.0 + 128.0);
			fwrite(&a, 1, 1, fp);
			x += 441.0 * pow(2.0, (double)key / 12.0) * 2.0 * 3.14159265358979 / 44100.0;
		}
	}
	return 0;
}
