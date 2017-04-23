#include <iostream>

int main()
{
	unsigned int N = 10;
	for(unsigned int i = 0; i < N; ++i)
	{
		unsigned int iy = i;

		// Invert bit order.
		iy = (iy & 0x55555555) <<  1 | (iy & 0xAAAAAAAA)  >>  1;
		iy = (iy & 0x33333333) <<  2 | (iy & 0xCCCCCCCC)  >>  2;
		iy = (iy & 0x0F0F0F0F) <<  4 | (iy & 0xF0F0F0F0)  >>  4;
		iy = (iy & 0x00FF00FF) <<  8 | (iy & 0xFF00FF00)  >>  8;
		iy = (iy             ) << 16 | (iy             )  >> 16;

		// Build IEEE floating point bits.
		float ffy = float(iy) * 2.3283064365386963e-10;
		// iy = ((126 - n0) << 23) | (iy >> 9);
		float fy = *reinterpret_cast<float*>(&iy);
		float fx = (float)i / N;
		std::cout  << " " << ffy << std::endl;
	}
	return 0;
}
