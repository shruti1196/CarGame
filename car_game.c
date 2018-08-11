//~~~~~~~//~~~~~~//~~~~~~~//~~~<< BANG BANG >~~~~~//~~~~~//~~~~~~~~~~//~~~
//Move the car left by pressing 'a' and right by pressing 'd'.
//Exit the program by the escape key.

/*THE HEADER FILES INCLUDED*/
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

/*CONCEPT OF STRUCTURES USED*/
struct details        //structure to take player's details
{
  char name[20];
  int age;
  char gender;
}var;

/*CONCEPT OF FUNCTIONS and POINTERS USED*/
//All the functions used are declared here:-
void first_page();
void main_menu();
void control();
void details();
void story();
void loading();
void level();
void level1(int, int, int *, int *);
void level2(int, int, int, int *, int *);
void level3(int, int, int, int *, int *);
void gameover(int);
void scores(int);
void score1(int);
void credits();
void cracker(int);
void diamond(int);
void last_page();
void car(int, int);
void obstacle_car1(int, int);
void obstacle_car2(int, int);
void strip(int, int);
int s();

/*CONCEPT OF GRAPHICS USED*/
void main()
{
 int gd=DETECT, gm;
 int mx, my, x1, y1, score=0, l1_ox1, l2_ox1, l2_ox2, l3_ox1, l3_ox2;
 initgraph(&gd, &gm,"C:\\tc\\bgi");
 mx=getmaxx();
 my=getmaxy();
 x1=mx/2-25;
 y1=my-150;
 first_page();
 cleardevice();
 for(score=0; score<30; score=score+10)
 {
  l1_ox1=random(201)+200;
  level1(l1_ox1, score, &x1, &y1);
 }
 level();
 for(score=30; score<60; score=score+10)
 {
  l2_ox1=random(11)+200;
  //l2_ox2=random(21)+380;
  l2_ox2=random(141)+270;
  level2(l2_ox1, l2_ox2, score, &x1, &y1);
 }
 level();
 for(score=60; score<90; score=score+10)
 {
  l3_ox1=random(50)+200;
  l3_ox2=random(50)+300;
  level3(l3_ox1, l3_ox2, score, &x1, &y1);
 }
 cracker(score);
 last_page();
 getch();
 closegraph();
}

void strip(int sx, int sy)
{
 setcolor(15);
 setfillstyle(SOLID_FILL, 15);
 rectangle(sx, sy, sx+5, sy+40);
 floodfill(sx+1, sy+1, 15);
}

void car(int x1, int y1)
{
 setcolor(0);
 rectangle(x1, y1, x1+50, y1+100);
 setfillstyle(SOLID_FILL, 14);
 floodfill(x1+1, y1+1, 0);
 rectangle(x1+10, y1, x1+20, y1+5);
 setfillstyle(SOLID_FILL, 4);
 floodfill(x1+11, y1+1, 0);
 rectangle(x1+30, y1, x1+40, y1+5);
 //setfillstyle(SOLID_FILL, 4);
 floodfill(x1+31, y1+1, 0);
 rectangle(x1, y1+10, x1+5, y1+30);
 setfillstyle(SOLID_FILL, 8);
 floodfill(x1+1, y1+11, 0);
 rectangle(x1+45, y1+10, x1+50, y1+30);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+46, y1+11, 0);
 rectangle(x1, y1+70, x1+5, y1+90);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+1, y1+71, 0);
 rectangle(x1+45, y1+70, x1+50, y1+90);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+46, y1+71, 0);
 rectangle(x1+10, y1+20, x1+40, y1+40);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+11, y1+21, 0);
 rectangle(x1+10, y1+60, x1+40, y1+80);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+11, y1+61, 0);
}

void obstacle_car1(int x1, int y1)
{
 setcolor(8);
 rectangle(x1, y1, x1+50, y1+100);
 setfillstyle(SOLID_FILL, 11);
 floodfill(x1+1, y1+1, 8);
 rectangle(x1+10, y1, x1+20, y1+5);
 setfillstyle(SOLID_FILL, 4);
 floodfill(x1+11, y1+1, 8);
 rectangle(x1+30, y1, x1+40, y1+5);
 //setfillstyle(SOLID_FILL, 4);
 floodfill(x1+31, y1+1, 8);
 rectangle(x1, y1+10, x1+5, y1+30);
 setfillstyle(SOLID_FILL, 8);
 floodfill(x1+1, y1+11, 8);
 rectangle(x1+45, y1+10, x1+50, y1+30);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+46, y1+11, 8);
 rectangle(x1, y1+70, x1+5, y1+90);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+1, y1+71, 8);
 rectangle(x1+45, y1+70, x1+50, y1+90);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+46, y1+71, 8);
 rectangle(x1+10, y1+20, x1+40, y1+40);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+11, y1+21, 8);
 rectangle(x1+10, y1+60, x1+40, y1+80);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+11, y1+61, 8);
}

void obstacle_car2(int x1, int y1)
{
 setcolor(6);
 rectangle(x1, y1, x1+50, y1+100);
 setfillstyle(SOLID_FILL, 12);
 floodfill(x1+1, y1+1, 6);
 rectangle(x1+10, y1, x1+20, y1+5);
 setfillstyle(SOLID_FILL, 4);
 floodfill(x1+11, y1+1, 6);
 rectangle(x1+30, y1, x1+40, y1+5);
 //setfillstyle(SOLID_FILL, 4);
 floodfill(x1+31, y1+1, 6);
 rectangle(x1, y1+10, x1+5, y1+30);
 setfillstyle(SOLID_FILL, 8);
 floodfill(x1+1, y1+11, 6);
 rectangle(x1+45, y1+10, x1+50, y1+30);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+46, y1+11, 6);
 rectangle(x1, y1+70, x1+5, y1+90);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+1, y1+71, 6);
 rectangle(x1+45, y1+70, x1+50, y1+90);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+46, y1+71, 6);
 rectangle(x1+10, y1+20, x1+40, y1+40);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+11, y1+21, 6);
 rectangle(x1+10, y1+60, x1+40, y1+80);
 //setfillstyle(SOLID_FILL, 8);
 floodfill(x1+11, y1+61, 6);
}

void first_page()    //homepage function
{
 int poly[10],poly1[34];
 int x,y,i;
 setbkcolor(CYAN);
 for(i=30;i<=630&&(!kbhit());i+=15)          //car display
 {
 setcolor(RED);
 setfillstyle(SOLID_FILL,4);
 poly1[0]=300;
 poly1[1]=20;
 poly1[2]=350;
 poly1[3]=70;
 poly1[4]=400;
 poly1[5]=20;
 poly1[6]=450;
 poly1[7]=70;
 poly1[8]=500;
 poly1[9]=70;
 poly1[10]=450;
 poly1[11]=120;
 poly1[12]=500;
 poly1[13]=170;
 poly1[14]=450;
 poly1[15]=170;
 poly1[16]=400;
 poly1[17]=220;
 poly1[18]=350;
 poly1[19]=170;
 poly1[20]=300;
 poly1[21]=220;
 poly1[22]=250;
 poly1[23]=170;
 poly1[24]=200;
 poly1[25]=170;
 poly1[26]=250;
 poly1[27]=120;
 poly1[28]=200;
 poly1[29]=70;
 poly1[30]=250;
 poly1[31]=70;
 poly1[32]=poly1[0];
 poly1[33]=poly1[1];
 drawpoly(17,poly1);
 fillpoly(17,poly1);
 setcolor(YELLOW);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
 outtextxy(200,105,"BANG BANG!!");
 setcolor(RED);
 line(5,0,5,480);
 line(6,0,6,480);
 setcolor(BLUE);
 line(10,0,10,480);
 line(11,0,11,480);
 setcolor(WHITE);
 line(15,0,15,480);
 line(16,0,16,480);
 setcolor(GREEN);
 line(20,0,20,480);
 line(21,0,21,480);
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 rectangle(22,1,160,70);
 floodfill(23,35,WHITE);
 setcolor(BROWN);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy( 54,30,"START");
 setcolor(GREEN);
 setfillstyle(SOLID_FILL,2);
 rectangle(0,409,640,480);
 floodfill(30,410,2);
 setcolor(BLUE);
 setfillstyle(SOLID_FILL,1);
 poly[0]=i+20;    //point 1
 poly[1]=380;
 poly[2]=i+30;    //point2
 poly[3]=360;
 poly[4]=i+50;    //point 3
 poly[5]=360;
 poly[6]=i+60;    //point 4
 poly[7]=380;
 poly[8]=poly[0];
 poly[9]=poly[1];
 drawpoly(5,poly);
 fillpoly(5,poly);
 rectangle(i,380,i+90,400);
 floodfill(i+10,390,BLUE);
 setcolor(RED);
 circle(i+18,400,7);
 setfillstyle(SOLID_FILL, RED);
 floodfill(i+18,399,RED);
 circle(i+55,400,7);
 floodfill(i+55,399,RED);
 if(i==630)
 {
  i=30;
 }
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy(150,420,"PRESS ANY KEY TO CONTINUE");
 delay(50);
 cleardevice();
}
main_menu();
}

void main_menu()   //game menu
{
 int x=160,i;
 char a;
 int x1=23,y1=14;
 gotoxy(0,0);
 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 setcolor(RED);
 setfillstyle(9,RED);
 rectangle(0,0,640,150);
 floodfill(2,100,RED);
 setcolor(WHITE);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
 outtextxy(185,50,"GAME MENU");
 setcolor(RED);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy(x+35,210," NEW GAME ");
 outtextxy(x+35,240," CONTROLS  ");
 outtextxy(x+35,270," EXIT ");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 setcolor(BROWN);
 outtextxy(110,400,"# Navigate using w(up), s(down) and press Enter to select.");
 gotoxy(x1,y1);
 printf("-->>");
 delay(1000);
 for(i=1;i<=10000;i++)
 {
  a=getch();
  if(a=='w'||a=='W')
  {
    if(y1>=16&&y1<=18)
     {
       gotoxy(x1,y1);
       printf("    ");
       gotoxy(x1,y1-=2);
       printf("-->>");

     }
  }
  else if(a=='s'||a=='S')
  {
	if(y1>=14&&y1<=16)
       {
	gotoxy(x1,y1);
	printf("    ");
	gotoxy(x1,y1+=2);
	printf("-->>");

       }
  }
  else if(a==13)
  {
	 if (y1==14)
	 {
	  details();
	  break;
	 }
	 else if(y1==16)
	 {
	  control();
	  break;
	 }
	 else if(y1==18)
	 credits();
  }

 }
 getch();
 cleardevice();
}

void details()
{
char a;
gotoxy(0,0);
clrscr();
cleardevice();
setbkcolor(BROWN);
setcolor(WHITE);
settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
outtextxy(200,20,"Player Details");
gotoxy(25,5);
printf("\n PLAYER's NAME : ");
gotoxy(26,6);
scanf("%s",var.name);
gotoxy(25,7);
printf("\n PLAYER's AGE : ");
gotoxy(26,8);
scanf("%d",&var.age);
gotoxy(25,9);
printf("\n PLAYER's GENDER (M/F): ");
gotoxy(26,10);
scanf("%s",var.gender);
gotoxy(0,0);
L:
a=getch();
if (a==13)
story();
else
goto L;
}

void control()
{
  char c;
  gotoxy(0,0);
  clrscr();
  cleardevice();
  setbkcolor(BLACK);
  setcolor(RED);
  settextstyle(DEFAULT_FONT, HORIZ_DIR,5);
  outtextxy(185,5,"CONTROLS");
  setcolor(WHITE);
  settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
  outtextxy(90,65,"* YOU HAVE ONLY AND ONLY 1 LIFE ");
  outtextxy(90,95,"* THREE LEVELS TO CROSS ");
  outtextxy(90,125,"* SPEED AND OBSTACLES INCREASE WITH EACH LEVEL");
  outtextxy(90,155,"* CROSSING EACH OBSTACLE FETCHES YOU 10 POINTS");
  rectangle(91,185,130,225);
  settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
  outtextxy(104,200,"A");
  settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
  outtextxy(140,200, " TO MOVE THE CAR LEFT " );
  rectangle(91,255,130,295);
  settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
  outtextxy(104,270,"D");
  settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
  outtextxy(140,270, " TO MOVE THE CAR RIGHT " );
  outtextxy(50,400, "PRESS Backspace to go back to Main Menu and Esc to exit from the game " );
  c=getch();
  if(c==8)
  main_menu();
  else
  exit(1);
}

void story()
{
 gotoxy(0,0);
 clrscr();
 cleardevice();
 setbkcolor(RED);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(120,110,"You are a secret agent appointed by CBI. The");
 outtextxy(120,130,"Kohinoor Diamond has been stolen by you as a ");
 outtextxy(120,150,"a part of the plan. The police as well as the ");
 outtextxy(120,170,"underworld dons are behind you. Kohinoor is in ");
 outtextxy(120,190,"your car right now. Drive through the city to");
 outtextxy(120,210,"escape from the city.Beware of the cars coming");
 outtextxy(120,230,"towards you. It could be a TRAP! So drive carefully");
 outtextxy(120,250,"Country's pride depends on you. All the best.... " );
 delay(10000);
 outtextxy(120, 440, "PRESS ANY KEY TO CONTINUE...");
 getch();
 loading();
}


void loading()
{
 int i;
 gotoxy(0,0);
 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 setcolor(BLUE);
 setfillstyle(SOLID_FILL,BLUE);
 rectangle(0,150,640,310);
 floodfill(300,250,BLUE);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(220,180,"RELOADING FUEL...");
 delay(250);
 outtextxy(220,210,"CHECKING THE TYRES...");
 delay(350);
 outtextxy(220,240,"WEAR THE SEAT BELTS...");
 delay(450);
 setcolor(YELLOW);
 for(i=225;i<350;i++)
  {  delay(30);
    outtextxy(i,280,"|");
  }
  delay(10);
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
 setcolor(WHITE);
 outtextxy(220, 440, "ARE YOU READY?");
}

void level()
{
 cleardevice();
 setbkcolor(BLACK);
 setcolor(RED);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
 outtextxy(200,240,"NEXT LEVEL...");
 delay(500);
}

void level1(int l1_ox1, int score, int *x1, int *y1)
{
 int yy, l1_oy1;
 char c;
 int mx, my;

 mx=getmaxx();
 my=getmaxy();
 setcolor(15);

 for(yy=0; yy<=my; yy=yy+20)
 {
  setcolor(15);
  setfillstyle(SOLID_FILL, 10);
  floodfill(1, 1, 15);
  rectangle(190, 0, 460, 480);
  setfillstyle(SOLID_FILL, 7);
  floodfill(211, 1, 15);

  strip(270, yy);
  strip(270, yy+100);
  strip(270, yy+200);
  strip(270, yy+300);
  strip(270, yy+400);

  strip(270, yy-100);
  strip(270, yy-200);
  strip(270, yy-300);
  strip(270, yy-400);

  strip(365, yy);
  strip(365, yy+100);
  strip(365, yy+200);
  strip(365, yy+300);
  strip(365, yy+400);

  strip(365, yy-100);
  strip(365, yy-200);
  strip(365, yy-300);
  strip(365, yy-400);

  l1_oy1=yy;
  obstacle_car1(l1_ox1, l1_oy1);
  car(*x1, *y1);

  setcolor(0);
  rectangle(520, 30, 605, 50);
  setfillstyle(SOLID_FILL, 0);
  floodfill(521, 31, 0);
  setcolor(15);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  outtextxy(525, 27, "Score: ");
  gotoxy(586, 3);
  printf("%d", score);

  setcolor(0);
  rectangle(20, 30, 100, 50);
  setfillstyle(SOLID_FILL, 0);
  floodfill(21, 31, 0);
  setcolor(15);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  outtextxy(25, 27, "Level 1");

   if( (l1_ox1<=*x1&&*x1<=l1_ox1+50)&&(l1_oy1<=*y1&&*y1<=l1_oy1+100) ||
       (l1_ox1<=*x1+50&&*x1+50<=l1_ox1+50)&&(l1_oy1<=*y1&&*y1<=l1_oy1+100) ||
       (l1_ox1<=*x1&&*x1<=l1_ox1+50)&&(l1_oy1<=*y1+100&&*y1+100<=l1_oy1+100) ||
       (l1_ox1<=*x1+50&&*x1+50<=l1_ox1+50)&&(l1_oy1<=*y1+100&&*y1+100<=l1_oy1+100) )
    gameover(score);

 if(kbhit())
 {
  c=getch();
  if((c=='a')&&(*x1-10>190))  //left
  {
   setviewport(*x1, *y1, *x1+50, *y1+100, 1);
   clearviewport();
   setviewport(0, 0, mx, my, 1);
   setcolor(7);
   setfillstyle(SOLID_FILL, 7);
   rectangle(*x1, *y1, *x1+50, *y1+100);
   floodfill(*x1+1, *y1+1, 7);
   car(*x1=*x1-10, *y1);
  }
  if((c=='d')&&(*x1+10)<410)  //right
  {
   setviewport(*x1, *y1, *x1+50, *y1+100, 1);
   clearviewport();
   setviewport(0, 0, mx, my, 1);
   setcolor(7);
   setfillstyle(SOLID_FILL, 7);
   rectangle(*x1, *y1, *x1+50, *y1+100);
   floodfill(*x1+1, *y1+1, 7);
   car(*x1=*x1+10, *y1);
  }
  if(c==27) exit(0);
 }
  delay(120);
  cleardevice();
 }

}

void level2(int l2_ox1, int l2_ox2, int score, int *x1, int *y1)
{
 int yy, l2_oy1, l2_oy2;
 char c;
 int mx, my;

 mx=getmaxx();
 my=getmaxy();
 setcolor(15);

 for(yy=0; yy<=my; yy=yy+20)
 {
  setcolor(15);
  setfillstyle(SOLID_FILL, 10);
  floodfill(1, 1, 15);
  rectangle(190, 0, 460, 480);
  setfillstyle(SOLID_FILL, 7);
  floodfill(211, 1, 15);

  strip(270, yy);
  strip(270, yy+100);
  strip(270, yy+200);
  strip(270, yy+300);
  strip(270, yy+400);

  strip(270, yy-100);
  strip(270, yy-200);
  strip(270, yy-300);
  strip(270, yy-400);

  strip(365, yy);
  strip(365, yy+100);
  strip(365, yy+200);
  strip(365, yy+300);
  strip(365, yy+400);

  strip(365, yy-100);
  strip(365, yy-200);
  strip(365, yy-300);
  strip(365, yy-400);

  randomize();
  l2_oy1=yy;
  l2_oy2=yy;
  obstacle_car1(l2_ox1, l2_oy1);
  obstacle_car2(l2_ox2, l2_oy2);
  car(*x1, *y1);

  setcolor(0);
  rectangle(520, 30, 605, 50);
  setfillstyle(SOLID_FILL, 0);
  floodfill(521, 31, 0);
  setcolor(15);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  outtextxy(525, 27, "Score: ");
  gotoxy(586, 3);
  printf("%d", score);

  setcolor(0);
  rectangle(20, 30, 100, 50);
  setfillstyle(SOLID_FILL, 0);
  floodfill(21, 31, 0);
  setcolor(15);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  outtextxy(25, 27, "Level 2");

  if( (l2_ox1<=*x1&&*x1<=l2_ox1+50)&&(l2_oy1<=*y1&&*y1<=l2_oy1+100) ||
       (l2_ox1<=*x1+50&&*x1+50<=l2_ox1+50)&&(l2_oy1<=*y1&&*y1<=l2_oy1+100) ||
       (l2_ox1<=*x1&&*x1<=l2_ox1+50)&&(l2_oy1<=*y1+100&&*y1+100<=l2_oy1+100) ||
       (l2_ox1<=*x1+50&&*x1+50<=l2_ox1+50)&&(l2_oy1<=*y1+100&&*y1+100<=l2_oy1+100) )
   gameover(score);

  if( (l2_ox2<=*x1&&*x1<=l2_ox2+50)&&(l2_oy2<=*y1&&*y1<=l2_oy2+100) ||
       (l2_ox2<=*x1+50&&*x1+50<=l2_ox2+50)&&(l2_oy2<=*y1&&*y1<=l2_oy2+100) ||
       (l2_ox2<=*x1&&*x1<=l2_ox2+50)&&(l2_oy2<=*y1+100&&*y1+100<=l2_oy2+100) ||
       (l2_ox2<=*x1+50&&*x1+50<=l2_ox2+50)&&(l2_oy2<=*y1+100&&*y1+100<=l2_oy2+100) )
   gameover(score);

 if(kbhit())
 {
  c=getch();
  if((c=='a')&&(*x1-10>190))  //left
  {
   setviewport(*x1, *y1, *x1+50, *y1+100, 1);
   clearviewport();
   setviewport(0, 0, mx, my, 1);
   setcolor(7);
   setfillstyle(SOLID_FILL, 7);
   rectangle(*x1, *y1, *x1+50, *y1+100);
   floodfill(*x1+1, *y1+1, 7);
   car(*x1=*x1-10, *y1);
  }
  if((c=='d')&&(*x1+10)<410)  //right
  {
   setviewport(*x1, *y1, *x1+50, *y1+100, 1);
   clearviewport();
   setviewport(0, 0, mx, my, 1);
   setcolor(7);
   setfillstyle(SOLID_FILL, 7);
   rectangle(*x1, *y1, *x1+50, *y1+100);
   floodfill(*x1+1, *y1+1, 7);
   car(*x1=*x1+10, *y1);
  }
  if(c==27) exit(0);
 }
  delay(100);
  cleardevice();
 }

}

void level3(int l3_ox1, int l3_ox2, int score, int *x1, int *y1)
{
 int yy, l3_oy1, l3_oy2;
 char c;
 int mx, my;

 mx=getmaxx();
 my=getmaxy();
 setcolor(15);

 for(yy=0; yy<=my; yy=yy+20)
 {
  setcolor(15);
  setfillstyle(SOLID_FILL, 10);
  floodfill(1, 1, 15);
  rectangle(190, 0, 460, 480);
  setfillstyle(SOLID_FILL, 7);
  floodfill(211, 1, 15);

  strip(270, yy);
  strip(270, yy+100);
  strip(270, yy+200);
  strip(270, yy+300);
  strip(270, yy+400);

  strip(270, yy-100);
  strip(270, yy-200);
  strip(270, yy-300);
  strip(270, yy-400);

  strip(365, yy);
  strip(365, yy+100);
  strip(365, yy+200);
  strip(365, yy+300);
  strip(365, yy+400);

  strip(365, yy-100);
  strip(365, yy-200);
  strip(365, yy-300);
  strip(365, yy-400);

  randomize();
  l3_oy1=yy;
  l3_oy2=yy;
  obstacle_car1(l3_ox1, l3_oy1);
  obstacle_car2(l3_ox2, l3_oy2);
  car(*x1, *y1);

  setcolor(0);
  rectangle(520, 30, 605, 50);
  setfillstyle(SOLID_FILL, 0);
  floodfill(521, 31, 0);
  setcolor(15);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  outtextxy(525, 27, "Score: ");
  gotoxy(586, 3);
  printf("%d", score);

  setcolor(0);
  rectangle(20, 30, 100, 50);
  setfillstyle(SOLID_FILL, 0);
  floodfill(21, 31, 0);
  setcolor(15);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  outtextxy(25, 27, "Level 3");

  if( (l3_ox1<=*x1&&*x1<=l3_ox1+50)&&(l3_oy1<=*y1&&*y1<=l3_oy1+100) ||
       (l3_ox1<=*x1+50&&*x1+50<=l3_ox1+50)&&(l3_oy1<=*y1&&*y1<=l3_oy1+100) ||
       (l3_ox1<=*x1&&*x1<=l3_ox1+50)&&(l3_oy1<=*y1+100&&*y1+100<=l3_oy1+100) ||
       (l3_ox1<=*x1+50&&*x1+50<=l3_ox1+50)&&(l3_oy1<=*y1+100&&*y1+100<=l3_oy1+100) )
    gameover(score);

  if( (l3_ox2<=*x1&&*x1<=l3_ox2+50)&&(l3_oy2<=*y1&&*y1<=l3_oy2+100) ||
       (l3_ox2<=*x1+50&&*x1+50<=l3_ox2+50)&&(l3_oy2<=*y1&&*y1<=l3_oy2+100) ||
       (l3_ox2<=*x1&&*x1<=l3_ox2+50)&&(l3_oy2<=*y1+100&&*y1+100<=l3_oy2+100) ||
       (l3_ox2<=*x1+50&&*x1+50<=l3_ox2+50)&&(l3_oy2<=*y1+100&&*y1+100<=l3_oy2+100) )
    gameover(score);

 if(kbhit())
 {
  c=getch();
  if((c=='a')&&(*x1-10>190))  //left
  {
   setviewport(*x1, *y1, *x1+50, *y1+100, 1);
   clearviewport();
   setviewport(0, 0, mx, my, 1);
   setcolor(7);
   setfillstyle(SOLID_FILL, 7);
   rectangle(*x1, *y1, *x1+50, *y1+100);
   floodfill(*x1+1, *y1+1, 7);
   car(*x1=*x1-10, *y1);
  }
  if((c=='d')&&(*x1+10)<410)  //right
  {
   setviewport(*x1, *y1, *x1+50, *y1+100, 1);
   clearviewport();
   setviewport(0, 0, mx, my, 1);
   setcolor(7);
   setfillstyle(SOLID_FILL, 7);
   rectangle(*x1, *y1, *x1+50, *y1+100);
   floodfill(*x1+1, *y1+1, 7);
   car(*x1=*x1+10, *y1);
  }
  if(c==27) exit(0);
 }
  delay(80);
  cleardevice();
 }

}

void gameover(int score)
{
 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(100, 210," GAME  OVER !!!!");
 delay(2000);
 cleardevice();
 score1(score);
}

void scores(int score)
{
 setbkcolor(3);
 settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
 setcolor(WHITE);
 outtextxy(100,200,"Your SCORE is :  ");
 gotoxy(56, 15);
 printf("%d", score);
 setcolor(4);
 line(10,0,10,480);
 setcolor(5);
 line(20,0,20,300);
 setcolor(2);
 line(30,0,30,100);
 setcolor(4);
 line(0,10,640,10);
 setcolor(5);
 line(0,20,400,20);
 setcolor(2);
 line(0,30,140,30);
 delay(2000);
 cleardevice();
}

void score1(int score)
{
 scores(score);
 credits();
}

void credits()
{
 int j;
 setbkcolor(BLACK);
 for(j=0;j<300&&(!kbhit());j++)
 {
  setcolor(WHITE);
  settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
  outtextxy(120,300 - j," GAME  DEVELOPERS :");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,340 - j," MANASVI DUGGAL  14503003");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,380 - j," RIYU BANA  14503033");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,420 - j," SHRUTI SAHU  14503011");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,460 - j," AAYUSH GOEL  14503032");
  delay(40);
  cleardevice();
 }
 getch();
 exit(0);
}

void cracker(int score)
{
	int i,j,z,cir;

//======MOTION OF CAR FROM START TO CRACKER=====================================

	for(i=-60;i<210;i=i+5)
	{
		cleardevice();
		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(RED);                     //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle
		floodfill(112+i,419,RED);          //triangle color

		delay(50);
	}
	i=205;

//======MOTION FROM CRACKER TO BOOMS================================================

	for(j=0;j<=200;j=j+5)
	{
		cleardevice() ;
		circle(320,410-j,2);               //towards central boom point
		circle(320-j,410-j,2);             //towards left boom point
		circle(320+j,410-j,2);             //towards right boom point
		putpixel(320,210,10);
		putpixel(120,210,10);
		putpixel(520,210,10);

		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(YELLOW);                  //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle
		floodfill(112+i,419,YELLOW);       //triangle color

		delay(20);

	}
	j=200;

//======INITIAL BOOM OF THE CIRCLES WITH LESS DELAY===================================

	for(cir=0;cir<10;cir=cir+2)
	{
		cleardevice();
		setcolor(BLUE);
		circle(320,210,cir);               //altenate blue and red circles central boom
		circle(320-j,410-j,cir);           //altenate blue and red circles left boom
		circle(320+j,410-j,cir);           //altenate blue and red circles right boom
		setcolor(RED);
		circle(320,210,cir+2);             //altenate blue and red circles central boom
		circle(320-j,410-j,cir+2);         //altenate blue and red circles left boom
		circle(320+j,410-j,cir+2);         //altenate blue and red circles right boom

		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(YELLOW);                  //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle
		floodfill(112+i,419,YELLOW);       //triangle color

		delay(100);
	 }

//======BOOM OF CIRCLES WITH INCREASED DELAY=======================================

	for(cir=10;cir<20;cir=cir+2)
	{
		cleardevice();
		setcolor(BLUE);
		circle(320,210,cir);               //altenate blue and red circles central boom
		circle(320-j,410-j,cir);           //altenate blue and red circles left boom
		circle(320+j,410-j,cir);           //altenate blue and red circles right boom
		setcolor(RED);
		circle(320,210,cir+2);             //altenate blue and red circles central boom
		circle(320-j,410-j,cir+2);         //altenate blue and red circles left boom
		circle(320+j,410-j,cir+2);         //altenate blue and red circles right boom

		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(YELLOW);                  //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle

		floodfill(112+i,419,YELLOW);       //triangle color

		delay(150);

	}

//======BOOM OF CIRCLES WITH INCREASED DELAY=======================================

	for(cir=20;cir<30;cir=cir+2)
	{
		cleardevice();

		setcolor(BLUE);
		circle(320,210,cir);               //altenate blue and red circles central boom
		circle(320-j,410-j,cir);           //altenate blue and red circles left boom
		circle(320+j,410-j,cir);           //altenate blue and red circles right boom
		setcolor(RED);
		circle(320,210,cir+2);             //altenate blue and red circles central boom
		circle(320-j,410-j,cir+2);         //altenate blue and red circles left boom
		circle(320+j,410-j,cir+2);         //altenate blue and red circles right boom

		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(YELLOW);                  //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle

		floodfill(112+i,419,YELLOW);       //triangle color

		delay(200);

	}

//======BOOM OF CIRCLES WITH INCREASED DELAY=======================================

	for(cir=30;cir<40;cir=cir+2)
	{
		cleardevice();

		setcolor(BLUE);
		circle(320,210,cir);               //altenate blue and red circles central boom
		circle(320-j,410-j,cir);	   //altenate blue and red circles left boom
		circle(320+j,410-j,cir);           //altenate blue and red circles right boom
		setcolor(RED);
		circle(320,210,cir+2);             //altenate blue and red circles central boom
		circle(320-j,410-j,cir+2);         //altenate blue and red circles left boom
		circle(320+j,410-j,cir+2);         //altenate blue and red circles right boom

		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(YELLOW);                  //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle

		floodfill(112+i,419,YELLOW);       //triangle color

		delay(250);
	}

//======SPARKLING AND MOMENTS OF CIRCLES FROM BOOM TO OUTER SIDE======================

	for(z=0;z<180;z=z+5)
	{
		cleardevice();

	//======FROM CENTRAL BOOM TO OUTER SIDE=======================================

		setcolor(BLUE);
		circle(320,170-z,1);               //upper side circles
		setcolor(RED);
		circle(320,165-z,1);	           //upper side circles
		setcolor(BLUE);
		circle(320,160-z,1);               //upper side circles
		setcolor(RED);
		circle(320,155-z,1);               //upper side circles
		setcolor(BLUE);
		circle(320,150-z,1);               //upper side circles

		setcolor(BLUE);
		circle(320-z,170-z,1);             //upper left side circles
		setcolor(RED);
		circle(320-z-5,165-z,1);           //upper left side circles
		setcolor(BLUE);
		circle(320-z-10,160-z,1);          //upper left side circles
		setcolor(RED);
		circle(320-z-15,155-z,1);          //upper left side circles
		setcolor(BLUE);
		circle(320-z-20,150-z,1);          //upper left side circles

		setcolor(BLUE);
		circle(320+z,170-z,1);             //upper right side circles
		setcolor(RED);
		circle(320+z+5,165-z,1);           //upper right side circles
		setcolor(BLUE);
		circle(320+z+10,160-z,1);          //upper right side circles
		setcolor(RED);
		circle(320+z+15,155-z,1);          //upper right side circles
		setcolor(BLUE);
		circle(320+z+20,150-z,1);          //upper right side circles

		setcolor(BLUE);
		circle(280-z,210,1);               //left side circles
		setcolor(RED);
		circle(280-z-5,210,1);             //left side circles
		setcolor(BLUE);
		circle(280-z-10,210,1);            //left side circles
		setcolor(RED);
		circle(280-z-15,210,1);            //left side circles
		setcolor(BLUE);
		circle(280-z-20,210,1);            //left side circles

		setcolor(BLUE);
		circle(360+z,210,1);               //right side circles
		setcolor(RED);
		circle(360+z+5,210,1);             //right side circles
		setcolor(BLUE);
		circle(360+z+10,210,1);            //right side circles
		setcolor(RED);
		circle(360+z+15,210,1);            //right side circles
		setcolor(BLUE);
		circle(360+z+20,210,1);            //right side circles

		setcolor(BLUE);
		circle(320,250+z,1);               //lower side circles
		setcolor(RED);
		circle(320,255+z,1);               //lower side circles
		setcolor(BLUE);
		circle(320,260+z,1);               //lower side circles
		setcolor(RED);
		circle(320,265+z,1);               //lower side circles
		setcolor(BLUE);
		circle(320,270+z,1);               //lower side circles

		setcolor(BLUE);
		circle(320+z,250+z,1);             //lower right side circles
		setcolor(RED);
		circle(320+z+5,255+z,1);           //lower right side circles
		setcolor(BLUE);
		circle(320+z+10,260+z,1);          //lower right side circles
		setcolor(RED);
		circle(320+z+15,265+z,1);          //lower right side circles
		setcolor(BLUE);
		circle(320+z+20,270+z,1);          //lower right side circles

		setcolor(BLUE);
		circle(320-z,250+z,1);             //lower left side circles
		setcolor(RED);
		circle(320-z-5,255+z,1);           //lower left side circles
		setcolor(BLUE);
		circle(320-z-10,260+z,1);          //lower left side circles
		setcolor(RED);
		circle(320-z-15,265+z,1);          //lower left side circles
		setcolor(BLUE);
		circle(320-z-20,270+z,1);          //lower left side circles

	//======FROM LEFT BOOM TO OUTER SIDE=======================================

		setcolor(BLUE);
		circle(120,170-z,1);               //upper side circles
		setcolor(RED);
		circle(120,165-z,1);	           //upper side circles
		setcolor(BLUE);
		circle(120,160-z,1);               //upper side circles
		setcolor(RED);
		circle(120,155-z,1);               //upper side circles
		setcolor(BLUE);
		circle(120,150-z,1);               //upper side circles

		setcolor(BLUE);
		circle(120-z,170-z,1);             //upper left side circles
		setcolor(RED);
		circle(120-z-5,165-z,1);           //upper left side circles
		setcolor(BLUE);
		circle(120-z-10,160-z,1);          //upper left side circles
		setcolor(RED);
		circle(120-z-15,155-z,1);          //upper left side circles
		setcolor(BLUE);
		circle(120-z-20,150-z,1);          //upper left side circles

		setcolor(BLUE);
		circle(120+z,170-z,1);             //upper right side circles
		setcolor(RED);
		circle(120+z+5,165-z,1);           //upper right side circles
		setcolor(BLUE);
		circle(120+z+10,160-z,1);          //upper right side circles
		setcolor(RED);
		circle(120+z+15,155-z,1);          //upper right side circles
		setcolor(BLUE);
		circle(120+z+20,150-z,1);          //upper right side circles

		setcolor(BLUE);
		circle(80-z,210,1);                //left side circles
		setcolor(RED);
		circle(80-z-5,210,1);              //left side circles
		setcolor(BLUE);
		circle(80-z-10,210,1);             //left side circles
		setcolor(RED);
		circle(80-z-15,210,1);             //left side circles
		setcolor(BLUE);
		circle(80-z-20,210,1);             //left side circles

		setcolor(BLUE);
		circle(160+z,210,1);               //right side circles
		setcolor(RED);
		circle(160+z+5,210,1);             //right side circles
		setcolor(BLUE);
		circle(160+z+10,210,1);            //right side circles
		setcolor(RED);
		circle(160+z+15,210,1);            //right side circles
		setcolor(BLUE);
		circle(160+z+20,210,1);            //right side circles

		setcolor(BLUE);
		circle(120,250+z,1);               //lower side circles
		setcolor(RED);
		circle(120,255+z,1);               //lower side circles
		setcolor(BLUE);
		circle(120,260+z,1);               //lower side circles
		setcolor(RED);
		circle(120,265+z,1);               //lower side circles
		setcolor(BLUE);
		circle(120,270+z,1);               //lower side circles

		setcolor(BLUE);
		circle(120+z,250+z,1);             //lower right side circles
		setcolor(RED);
		circle(120+z+5,255+z,1);           //lower right side circles
		setcolor(BLUE);
		circle(120+z+10,260+z,1);          //lower right side circles
		setcolor(RED);
		circle(120+z+15,265+z,1);          //lower right side circles
		setcolor(BLUE);
		circle(120+z+20,270+z,1);          //lower right side circles

		setcolor(BLUE);
		circle(120-z,250+z,1);             //lower left side circles
		setcolor(RED);
		circle(120-z-5,255+z,1);           //lower left side circles
		setcolor(BLUE);
		circle(120-z-10,260+z,1);          //lower left side circles
		setcolor(RED);
		circle(120-z-15,265+z,1);          //lower left side circles
		setcolor(BLUE);
		circle(120-z-20,270+z,1);          //lower left side circles

	//======FROM RIGHT BOOM TO OUTER SIDE=======================================


		setcolor(BLUE);
		circle(320,170-z,1);               //upper side circles
		setcolor(RED);
		circle(520,165-z,1);	           //upper side circles
		setcolor(BLUE);
		circle(520,160-z,1);               //upper side circles
		setcolor(RED);
		circle(520,155-z,1);               //upper side circles
		setcolor(BLUE);
		circle(520,150-z,1);               //upper side circles

		setcolor(BLUE);
		circle(520-z,170-z,1);             //upper left side circles
		setcolor(RED);
		circle(520-z-5,165-z,1);           //upper left side circles
		setcolor(BLUE);
		circle(520-z-10,160-z,1);          //upper left side circles
		setcolor(RED);
		circle(520-z-15,155-z,1);          //upper left side circles
		setcolor(BLUE);
		circle(520-z-20,150-z,1);          //upper left side circles

		setcolor(BLUE);
		circle(520+z,170-z,1);             //upper right side circles
		setcolor(RED);
		circle(520+z+5,165-z,1);           //upper right side circles
		setcolor(BLUE);
		circle(520+z+10,160-z,1);          //upper right side circles
		setcolor(RED);
		circle(520+z+15,155-z,1);          //upper right side circles
		setcolor(BLUE);
		circle(520+z+20,150-z,1);          //upper right side circles

		setcolor(BLUE);
		circle(480-z,210,1);               //left side circles
		setcolor(RED);
		circle(480-z-5,210,1);             //left side circles
		setcolor(BLUE);
		circle(480-z-10,210,1);            //left side circles
		setcolor(RED);
		circle(480-z-15,210,1);            //left side circles
		setcolor(BLUE);
		circle(480-z-20,210,1);            //left side circles

		setcolor(BLUE);
		circle(560+z,210,1);               //right side circles
		setcolor(RED);
		circle(560+z+5,210,1);             //right side circles
		setcolor(BLUE);
		circle(560+z+10,210,1);            //right side circles
		setcolor(RED);
		circle(560+z+15,210,1);            //right side circles
		setcolor(BLUE);
		circle(560+z+20,210,1);            //right side circles

		setcolor(BLUE);
		circle(520,250+z,1);               //lower side circles
		setcolor(RED);
		circle(520,255+z,1);               //lower side circles
		setcolor(BLUE);
		circle(520,260+z,1);               //lower side circles
		setcolor(RED);
		circle(520,265+z,1);               //lower side circles
		setcolor(BLUE);
		circle(520,270+z,1);               //lower side circles

		setcolor(BLUE);
		circle(520+z,250+z,1);             //lower right side circles
		setcolor(RED);
		circle(520+z+5,255+z,1);           //lower right side circles
		setcolor(BLUE);
		circle(520+z+10,260+z,1);          //lower right side circles
		setcolor(RED);
		circle(520+z+15,265+z,1);          //lower right side circles
		setcolor(BLUE);
		circle(520+z+20,270+z,1);          //lower right side circles

		setcolor(BLUE);
		circle(520-z,250+z,1);             //lower left side circles
		setcolor(RED);
		circle(520-z-5,255+z,1);           //lower left side circles
		setcolor(BLUE);
		circle(520-z-10,260+z,1);          //lower left side circles
		setcolor(RED);
		circle(520-z-15,265+z,1);          //lower left side circles
		setcolor(BLUE);
		circle(520-z-20,270+z,1);          //lower left side circles

		setcolor(RED);                     //cracker color
		setfillstyle(XHATCH_FILL,RED);     //cracker color
		line(305,477,335,477);             //cracker
		line(305,430,335,430);             //cracker
		line(305,477,305,430);             //cracker
		line(335,477,335,430);             //cracker
		line(320,430,320,410);             //cracker
		floodfill(310,450,RED);            //cracker color

		setcolor(GREEN);                   //car color
		setfillstyle(HATCH_FILL,CYAN);     //car color

		line(15+i,420,80+i,420);           //car
		line(0+i,470,95+i,470);            //car
		line(15+i,420,0+i,470);            //car
		line(80+i,420,95+i,470);           //car
		line(15+i,420,110+i,420);          //stick ahead
		floodfill(20+i,450,GREEN);         //car color

		setcolor(WHITE);                   //tyre color
		setfillstyle(HATCH_FILL,WHITE);    //tyre color
		circle(25+i,470,7);                //tyre
		circle(70+i,470,7);                //tyre
		floodfill(25+i,471,WHITE);         //tyre color
		floodfill(70+i,471,WHITE);         //tyre color

		setcolor(BROWN);                   //road color
		setfillstyle(HATCH_FILL,BROWN);    //road color

		line(0,477,640,477);               //road
		line(0,479,640,479); 		   //road

		setcolor(YELLOW);                  //triangle color
		setfillstyle(SOLID_FILL,YELLOW);   //triangle color
		line(110+i,420,120+i,420);  	   //triangle base
		line(115+i,410,120+i,420); 	   //triangle
		line(110+i,420,115+i,410);         //triangle
		floodfill(112+i,419,YELLOW);       //triangle color

		delay(40);
		cleardevice();

	}
 diamond(score);
}

void diamond(int score)
{
  int poly2[12];
  setbkcolor(BLACK);
  poly2[0]=280;
  poly2[1]=185;
  poly2[2]=360;
  poly2[3]=185;
  poly2[4]=400;
  poly2[5]=205;
  poly2[6]=320;
  poly2[7]=335;
  poly2[8]=240;
  poly2[9]=205;
  poly2[10]=poly2[0];
  poly2[11]=poly2[1];
  setcolor(WHITE);
  setfillstyle(SOLID_FILL, 15);
  fillpoly(6, poly2);
  setcolor(WHITE);
  settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
  outtextxy(100, 75, "The Kohinoor is yours...");
  delay(2000);
  cleardevice();
  scores(score);
}

void last_page()
{
 int i,j,poly2[12];;
 setbkcolor(BLACK);
 setcolor(WHITE);
 for(i=0;i<300;i++)
 {
  settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
  outtextxy(25,100 - i," THANKS FOR PLAYING !!!!");
  poly2[0]=280;
  poly2[1]=250-i;
  poly2[2]=360;
  poly2[3]=250-i;
  poly2[4]=400;
  poly2[5]=270-i;
  poly2[6]=320;
  poly2[7]=400-i;
  poly2[8]=240;
  poly2[9]=270-i;
  poly2[10]=poly2[0];
  poly2[11]=poly2[1];
  setfillstyle(SOLID_FILL, 15);
  fillpoly(6, poly2);
  delay(20);
  cleardevice();
 }
 for(j=0;j<300;j++)
 {
  settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
  outtextxy(120,300 - j," GAME  DEVELOPERS :");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,340 - j," MANASVI DUGGAL  14503003");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,380 - j," RIYU BANA  14503033");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,420 - j," SHRUTI SAHU  14503011");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(120,460 - j," AAYUSH GOEL  14503032");
  delay(20);
  if(kbhit()) exit(0);
  cleardevice();
 }
}

int s()
{
 int a;
 for(a=200; a<=1000; a=a+20)
 {
  sound(a);
  delay(25);
 }
 nosound();
 return 0;
}

/*int color(int i)
{
 int z;
 switch(i)
 {
  case 1: z=4; return z;
  case 2: z=12; return z;
  case 3: z=14; return z;
  case 4: z=10; return z;
  case 5: z=2; return z;
  case 6: z=11; return z;
  case 7: z=3; return z;
  case 8: z=9; return z;
  case 9: z=1; return z;
  case 10: z=13; return z;
  case 11: z=5; return z;
  case 12: z=6; return z;
 }
}
*/