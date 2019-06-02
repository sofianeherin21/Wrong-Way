
#include "iGraphics.h"
#include <vector>
using namespace std;


char str2[100], str3[100];
int len;
int mode;

void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(347, 161, 250, 30);
}


int carposX=550,carposY=0;//main car position
int x=440,x2=540,x3=700,x4=630;//x co-ordinates of opposite cars
int y=560,y2=379,y3=180,y4=50;//y co-ordinates of opposite directions
int line1y1=25, line1y2=225 ,line2y1=475,line2y2=675;//line3y1=325,line3y2=425,line4y1=475,line4y2=575;//line5y1=425,line5y2=475;
int dy=3;//car change
int t,t1,t2;
long game=0;
int score=0;
int life=6;
int Pause=0;
char totalscore[100],str[100],str1[100];//,name[100];
int menu=0,i,place=500;


struct data{
	char Name[100];
	int Score;
};

//high score

void highscore(){

	struct data user[11],temp;
	int j,min,flag=0;

	FILE *fp;
	fp=fopen("E:\\igraphics\\iGraphic1.2VS10\\iGraphic1.2VS10\\HighScore.txt","r");
	if(fp==NULL){
       printf("Error!");
       exit(1);
	}

   for(j=0;j<10;j++)
   {

       fscanf(fp,"%s %d",&user[j].Name,&user[j].Score);
   }
   fclose(fp);
    
    while(!flag)
   {
    flag = 1;    //detect when no more swaps are being made
    for(j=0;j<10;j++) 
	{
      if(user[j].Score < user[j+1].Score)
	  {
        flag = 0;   //not sorted yet
        temp=user[j];    //out of order, so swap structs
        user[j] = user[j+1];
        user[j+1] = temp;
      }
    }
  }
	//display high score
   if(menu==5)
   {
	   for(j=0;j<10;j++)
	   {  
		   
		      sprintf(totalscore,"%d",user[j].Score);
				iText(200,place,user[j].Name);
				iText(300,place,totalscore);
				place-=40;

            }
		 place=450;
   }
   else{
    
	   strcpy(user[10].Name,str3);
       user[10].Score=score;
  
          
    //set up the while loop to start and to
    flag=0;
	 while(!flag)
   {
    flag = 1;    //detect when no more swaps are being made
    for(j=0;j<10;j++) 
	{
      if(user[j].Score < user[j+1].Score)
	  {
        flag = 0;   //not sorted yet
        temp=user[j];    //out of order, so swap structs
        user[j] = user[j+1];
        user[j+1] = temp;
      }
    }
  }

    for(j=0;j<10;j++)
     {   
	   
	   printf("%s %d\n",user[j].Name,user[j].Score);
     }
  
	 fp=fopen("E:\\igraphics\\iGraphic1.2VS10\\iGraphic1.2VS10\\HighScore.txt","w");
	 for(j=0;j<10;j++)
       {

       fprintf(fp,"%s %d\n",user[j].Name,user[j].Score);
        }
	 fprintf(fp,"\n");
      fclose(fp);
		 
   }
   
  
}


//speed
void changespeed()
{
	if(dy<=10)
	dy++;
	
}

void restart()
{
 carposX=550,carposY=100;//main car position
 x=440,x2=540,x3=700,x4=630;//x co-ordinates of opposite cars
 y=540,y2=379,y3=180,y4=50;//y co-ordinates of opposite directions
 line1y1=25, line1y2=225 ,line2y1=475,line2y2=675;//line3y1=325,line3y2=425,line4y1=475,line4y2=575;//line5y1=425,line5y2=475;
 dy=4;//car change
 game=0;
 score=0;
 life=6;
 Pause=0;


}



//Menu

void Menu(){

	iShowBMP(0,0,"game\\Menu.bmp");
	
}



//background

void background()
{
        iSetColor(255,255,255);
	    iShowBMP(0,0,"game\\background1.bmp");
        iLine(500,line2y1,500,line2y2);
	    iLine(500,line1y1,500,line1y2);
		iLine(695,(line2y1+50),695,(line2y2+50));
	    iLine(695,(line1y1+50),695,(line1y2+50));
        iShowBMP2(carposX,carposY,"game\\main car2.bmp",16777215);
	    iShowBMP2(x,y,"game\\car2 - Copy.bmp",16777215);
	    iShowBMP2(x2,y2,"game\\blue car1.bmp",16777215);
		iShowBMP2(x3,y3,"game\\yellow car2.bmp",16777215);
		iShowBMP2(x4,y4,"game\\skyblue.bmp",16777215);
	
}





//background reset

void ResetBackground()
{
	if(carposY==600)
	{
		carposY=0;
	}
}


//change


void change()
{
	//car1
	
	if(y<=600)
	{
		y-=dy;
	}
	if((y+64)<=0)
	{  
		if(game==0)
			score+=1;
		x=rand()%350+410;
		y=600;
		game=0;
	}

	//car2

	if(y2<=600)
	{
		y2-=dy;
	}
	if((y2+64)<=0)
	{
		if(game==0)
			score+=1;
		x2=rand()%350+410;
		y2=600;
		game=0;
	}

	//car3

	if(y3<=600)
	{
		y3-=dy;
	}
	if((y3+64)<=0)
	{
		if(game==0)
			score+=1;
		x3=rand()%350+410;
		y3=600;
		game=0;
	}

	//car4
	
	if(y4<=600)
	{
		y4-=dy;
	}
	if((y4+64)<=0)
	{
		if(game==0)
			score+=1;
		x4=rand()%350+410;
		y4=600;
		game=0;
	}

	//backgroundchange

	if(line1y2>0||line2y2>0)
	{
		line1y1-=dy;
	    line1y2-=dy; 
	    line2y1-=dy;
	    line2y2-=dy;
	   
	}
	if(line1y2<=0)
		{
			line1y1=600;
			line1y2=800;
		}
		if(line2y2<=0)
		{
			line2y1=600;
			line2y2=800;
		}
		

		
}





//collision

void collision()
{

	if(carposX>=x&&carposX<=(x+35)&&(carposY+70)>=y&&(carposY+70)<=(y+70)||(carposX+35)>=x&&(carposX+35)<=(x+35)&&(carposY+70)>=y&&(carposY+70)<=(y+70))
	{
		if(life>0)
		{
			y=-10;
		    y2=y2-10;
	    	y3=y3-10;
		    y4=y4-10;
			iShowBMP(carposX,carposY+72,"game\\bam.bmp");//,16777215);
		    life--;
			
		    
		
		
		    //Sleep(800);
		     game=1;
		}
		
	}
	if(carposX>=x2&&carposX<=(x2+35)&&(carposY+70)>=y2&&(carposY+70)<=(y2+70)||(carposX+35)>=x2&&(carposX+35)<=(x2+35)&&(carposY+70)>=y2&&(carposY+70)<=(y2+70))
	{
		if(life>0)
		{
			y2=-10;
		y=y-10;
		y3=y3-10;
		y4=y4-10;

	    iShowBMP2(carposX,carposY+72,"game\\boom.bmp",16777215);
		
		//Sleep(800);
		game =1;
		life--;}
		
	}
	
		if(carposX>=x3&&carposX<=(x3+35)&&(carposY+70)>=y3&&(carposY+70)<=(y3+70)||(carposX+35)>=x3&&(carposX+35)<=(x3+35)&&(carposY+70)>=y3&&(carposY+70)<=(y3+70))
		{
			if(life>0)
			{
				iShowBMP2(carposX,carposY+72,"game\\boom.bmp",16777215);
				
		    y3=-10;
			y2=y2-10;
		    y4=y4-10;
			y=y-10;
			//Sleep(800);
		    game =1;
			life--;}
			
			
	    }
	

	
	if(carposX>=x4&&carposX<=(x4+35)&&(carposY+70)>=y4&&(carposY+70)<=(y4+70)||(carposX+35)>=x4&&(carposX+35)<=(x4+35)&&(carposY+70)>=y4&&(carposY+70)<=(y4+70))
	{
		if(life>0)
		{
			iShowBMP2(carposX,carposY+72,"game\\boom.bmp",16777215);
		//iShowBMP(carposX,carposY+72,"game\\boom.bmp");
		y4=-10;
		y3=y3-10;
		y2=y2-10;
		y=y-10;
			
		//Sleep(800);
		game =1;
		life--;}
	}
	
}



 
   void iDraw()
{
	//place your drawing codes here	
	iClear();
	if(menu==0)//frontpage
	{
		iShowBMP(0,0,"game\\Frontpage.bmp");
		iShowBMP2(850,150,"game\\frontcar.bmp",16777215);
	}
	if(menu==1)//menu page
	{
		Menu();
	}
	else if(menu==2)//play
	{
		background();
	//score print
        iSetColor(255,255,255);
        iText( 1037, 553, "SCORE:", GLUT_BITMAP_HELVETICA_18);
        sprintf( str, "%d", score );
        iText( 1137, 553, str, GLUT_BITMAP_HELVETICA_18);
	  //life print
		iText( 1037, 500, "LIFE:", GLUT_BITMAP_HELVETICA_18);
        sprintf( str1, "%d", life );
        iText( 1137, 500, str1, GLUT_BITMAP_HELVETICA_18);
		
	
   
	if(life==0)
	{
		iShowBMP(0,0,"game\\GAMEOVER.bmp");
	    highscore();
		drawTextBox(); 
	    if(mode == 1)
	    {
		iSetColor(255, 255, 255);
		iText(352, 165, str2);
	    }

	    iText(347, 150, "Please Enter Your Name");
		
	    iPauseTimer(t);
		iPauseTimer(t1);
		
	}
}
	else if(menu==3)
		iShowBMP(0,0,"game\\HELP1.bmp");
	else if(menu==4)
		exit(0);
	if(menu==5)
		highscore();

}





void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=506&&mx<=667&&my>=435&&my<=470)//play
			menu=2;
		if(mx>=506&&mx<=667&&my>=330&&my<=386)//help
			menu=3;
		if(mx>=506&&mx<=650&&my>=109&&my<=160)//quit
			menu=4;
		if(mx>=430&&mx<=770&&my>=220&&my<=273)//highscore
			menu=5;


		if(mx >= 347 && mx <= 597 && my >= 161 && my <= 191 && mode == 0)
		{
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
	}
}





void iKeyboard(unsigned char key)
{
	if(key == 'p'||key=='P')//Pause
	{
		Pause=1;
		iPauseTimer(t);
		iPauseTimer(t1);
		iPauseTimer(t2);
		
	}
	if(key == 'b'||key== 'B')//Back to menu
	{
		
		menu = 1;
		restart();
		iResumeTimer(t);
		iResumeTimer(t1);
		iResumeTimer(t2);
		
	}
	if(key == 'r'||'R')//Resume
	{
		Pause=0;
		iResumeTimer(t);
		iResumeTimer(t1);
		iResumeTimer(t2);
	}

		if(key ==' ')
	   {
		menu=1;
		
       }
		 
	//for name input
	if(mode == 1)
	{
		if(key == '\r')
		{
			menu=1;
			mode = 0;
			strcpy(str3, str2);
			printf("%s\n", str3);
			for(i = 0; i < len; i++)
				str2[i] = 0;
			len = 0;
		}
		else
		{
			str2[len] = key;
			len++;
		}
	}

	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
}

	
	

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	if(Pause!=1)
 {
	
	if(key == GLUT_KEY_RIGHT)
	{
		if(carposX<=760)
		{
			carposX+=dy;
		}	
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(carposX>=410)
		{
			
			carposX-=dy;
		}
	}
	
	
	if(key == GLUT_KEY_DOWN)
	{
		if(carposY!=0)
		{
			carposY-=dy;
			if(carposY<0)
				carposY=0;
		}
 	}
	/*if(key == GLUT_KEY_UP)
	{
		if(carposY>=0||carposY<0)
		{
			carposY+=10;
		}
		
 	}*/


}
	


	
}




int main()
{

	len = 0;
	mode = 0;
	str2[0]= 0;
	//PlaySound("vehicle037",NULL,SND_ASYNC);
	t=iSetTimer(5,change);
	t1=iSetTimer(300,changespeed);
	t2=iSetTimer(30,collision);
	iInitialize(1200, 600, "Wrong Way");
	return 0;
}	