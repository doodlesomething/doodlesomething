/*-------------------------------------------------------------------
	* file:test.c -->test file fot MazePath.c
	* date:23-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:迷宫问题求解
--------------------------------------------------------------------*/
#include <stdio.h>
#include "mazepath.h"

int main(int argc,char *argv[]){
	MazeType mz;
	SqStack S;
	PosType start,end;

	start.x = 0;
	start.y = 1;
	end.x = 8;
	end.y = 9;

	InitMaze(&mz);
	PrintMaze(&mz);
	if(MazePath(mz,&S,start,end)) {
		printf("此迷宫有解：\n");
		PrintFoot(S,&mz);
	}
	else 
		printf("无路可走\n");

	/*
	测试用例结果:
	# ########
	#  #   # #
	#  #   # #
	#    ##  #
	# ###    #
	#   # # ##
	# #   #  #
	# ### ## #
	##        
	##########
	此迷宫有解：
	1000000000
	0100000000
	0100000000
	0100000000
	0100000000
	0111000000
	0001110000
	0000010000
	0000011111
	0000000000

	*/


}
