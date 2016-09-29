#include<stdio.h>
#include<stdint.h>

uint8_t clz(uint32_t x)
{
	/* shift upper half down, rest is filled up with 0s */
	uint16_t upper = (x >> 16); 
	// mask upper half away
	uint16_t lower = (x & 0xFFFF);
	return  upper ? (clz(upper) - 16) : lower ? clz(lower>>1)-1 : 32 ;
}


int main()
{
	int a = 20;
	uint32_t b = 1 << 16;
	while(b)
	{scanf("%d",&b);
	printf("b = %d,clz(b)=%d\n", b ,clz(b));}
	return 0;
}
