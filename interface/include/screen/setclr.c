//! Set Text Color
#include <errno.h>
int settextcolor(uint8_t color)
{
	//! Only for GFX Modes
	if (gfx_mode == false)
		{
			errno = ERRNO_ERROR;
			return -1;
		}
	else {
		screen_color = color;
		errno = ERRNO_OK;
		return 0;
	}
}