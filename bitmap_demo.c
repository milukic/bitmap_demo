#include "../RSZDMK-TFT/TFT.h"
#include <avr/pgmspace.h>
#include <util/delay.h>

extern prog_uint16_t TUX[0x1000] PROGMEM;

int main()
{
	TFT_Init();

	while (1)
	{
		TFT_clrScr();
		TFT_drawBitmap(0, 0, 64, 64, TUX, 1);
		TFT_drawBitmap(64, 0, 64, 64, TUX, 1);
		TFT_drawBitmap(0, 64, 64, 64, TUX, 1);
		TFT_drawBitmap(64, 64, 64, 64, TUX, 1);
		_delay_ms(3000);

		TFT_clrScr();
		TFT_drawBitmap(0, 0, 64, 64, TUX, 2);
		_delay_ms(3000);

		for (int deg = 0; deg <= 360; deg +=30)
		{
			TFT_clrScr();
			TFT_drawBitmap2(64, 64, 64, 64, TUX, deg);
		}
	}
	return 0;
}
