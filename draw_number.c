
#include "draw_number.h"

#include <amlib.h>
#include <agdraw.h>

#include "export.h"



void drawNumberGraph(int number ,int x, int y, int size_x, int size_y , int order ,void* DBuf) 
{
	int i, n;
	int draw_x;
	int id[10] = {	AG_CG_NUMBER_0, 
					AG_CG_NUMBER_1, 
					AG_CG_NUMBER_2,
					AG_CG_NUMBER_3,
					AG_CG_NUMBER_4,
					AG_CG_NUMBER_5,
					AG_CG_NUMBER_6,
					AG_CG_NUMBER_7,
					AG_CG_NUMBER_8,
					AG_CG_NUMBER_9 };
					
	draw_x = x + (order-1)*size_x;

	for(i=0;i<order;i++) {
		n = number%10;
		agDrawSETFCOLOR( (AGDrawBuffer *)DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( (AGDrawBuffer *)DBuf, id[n], 0, NULL, NULL );
		agDrawSETDBMODE( (AGDrawBuffer *)DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE( (AGDrawBuffer *)DBuf, 1, draw_x, y, draw_x+size_x, y+size_y );
		number /= 10;
		draw_x -= size_x;
	}
}