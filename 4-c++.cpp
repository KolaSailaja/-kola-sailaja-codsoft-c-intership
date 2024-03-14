#include<graphics.h>
void selector(int,int,int);
void function_execution(int choice);
void multiplayer();
void restart_game();

//loading game

void loading_game(void){
    readimagefile("image/icon.jpg",280,180,420,300);
    rectangle(310,330,390,340);
    setcolor(CYAN);
    for(int i=0;i<=76;i++)
    {
        rectangle(310+i,332,310+i,338);
        delay(100);
    }
    cleardevice();
}

//Game animation menu

void menu(void){
    setbkcolor(Black);
    cleardevice();
    setcolor(4);
    settextstyle(3,HORIZ_DIR,1);
    outtextxy(10,575,"Warning:this game is only played with keyboard!");
    setcolor(3);
    settextstyle(3,HORIZ_DIR,5);
    outtextxy(260,250,"1");
    outtextxy(265,300,"2");
    outtextxy(275,350,"3");
    outtextxy(285,390,"4");
    outtextxy(295,450,"5");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,6);
    readimagefile("images/title.gif",30,30,660,150);
    readimagefile("images/singleplayer.gif",150,150,550,400);
    readimagefile("images/multiplayer.gif",150,200,550,450);
    readimagefile("images/controls.gif",150,250,550,500);
    readimagefile("images/about.gif",150,300,550,550);
    readimagefile("images/exit.gif",150,350,550,600);
    selector(250,1,1);
}

//menu selector

void selector(int h,int key,int choice)
{
    if(key==0){
        selector(BLACK);
    }else{
        selector(LIGHTRED);
    }
    int d=0;
    int g=0;
    if(choice==1){
        d=20;
        g=40;
    }
    if(choice==2){
        d=20;
        g=50;
    }
    if(choice==3){
        d=30;
        g=60;
    }
    if(choice==4){
        d=40;
        g=70;
    }
     if(choice==5){
        d=50;
        g=80;
    }
     if(choice==6){
        d=200;
        g=66;
    }
     if(choice==7){
        d=100;
        g=230;
    }
    char str1[]="<";
    char str2[]=">";
    settextstyle(0,HORIZ_DIR,5);
    outtextxy(200+d,h,str1);
    outtextxy(460+g,h,str2);
}
void selection(void){
int choice=1;
while(1){
    if(GetAsyncKeyState[VK_NUMPAD1]){
        selector(250,1,1);
        selector(300,0,2);
        selector(350,0,3);
        selector(400,0,4);
        selector(450,0,5);
        playSound(TEXT("sounds/selct_menu.wav"),NULL,SND_FILENAME);
        choice=1;
    }
    if(GetAsyncKeyState[VK_NUMPAD2]){
         selector(240,0,1);
        selector(300,1,2);
        selector(350,0,3);
        selector(400,0,4);
        selector(480,0,5);
         playSound(TEXT("sounds/selct_menu.wav"),NULL,SND_FILENAME);
        choice=2;
    }
    if(GetAsyncKeyState[VK_NUMPAD3]){
         selector(240,0,1);
        selector(300,0,2);
        selector(350,1,3);
        selector(400,0,4);
        selector(450,0,5);
         playSound(TEXT("sounds/selct_menu.wav"),NULL,SND_FILENAME);
        choice=3;
}
     if(GetAsyncKeyState[VK_NUMPAD4]){
         selector(240,0,1);
        selector(300,0,2);
        selector(350,0,3);
        selector(390,1,4);
        selector(450,0,5);
         playSound(TEXT("sounds/selct_menu.wav"),NULL,SND_FILENAME);
        choice=4;
}
    if(GetAsyncKeyState[VK_NUMPAD5]){
         selector(240,0,1);
        selector(300,0,2);
        selector(350,0,3);
        selector(400,0,4);
        selector(450,1,5);
         playSound(TEXT("sounds/selct_menu.wav"),NULL,SND_FILENAME);
        choice=5;
}
    if(GetAsyncKeyState[VK_RETURN]){
        function_execution(choice);
    }
    delay(10);
}
}
//Escape

void esc_theme(int option){
    while(1){
        if(GetAsyncKeyState[VK_ESCAPE]){
            cleardevice();
            menu();
            playSound(TEXT("sounds/esc.wav"),NULL,SND_FILENAME);
            selection();
            function_execution(option);
        }
    }
}

//Quit
void quit(){
    while(1){
        if(GetAsyncKeyState[VK_NUMPAD1]){
            selector(330,1,7);
            selector(330,0,6);
            playSound(TEXT("sounds/menu.wav"),NULL,SND_FILENAME);
            if(GetAsyncKeyState[VK_RETURN]){
                playSound(TEXT("sounds/enter.wav"),NULL,SND_FILENAME);
                closegrapgh();
            }
        }
        if(GetAsyncKeyState[VK_NUMPAD2]){
            selector(330,0,7);
            selector(330,1,6);
            playSound(TEXT("sounds/menu.wav"),NULL,SND_FILENAME);
            if(GetAsyncKeyState[VK_RETURN]){
                playSound(TEXT("sounds/enter.wav"),NULL,SND_FILENAME);
                menu();
                selection();
            }
        if(GetAsyncKeyState[VK_ESCAPE]){
            menu();
            playSound(TEXT("sounds/esc.wav"),NULL,SND_FILENAME);
            selection();
        }
    }
}
//Game interface
void game_intefcae(){
    int board_color,box_color;
    board_color=9;
    box_color=8;
    setcolor(board_color);
    for(int i=0;i<5;i++){
        //vertical
        line(148+i,75,145+i,125);
        line(298+i,75,298+i,525);
        //horizontal
        line(25,223+i,425,223+i);
        line(25,373+i,425,373+i);
    }
    setcolor(box_color);
    for(int i=0;i<5;i++){
        rectangle(450+i,25+i,575+i,675+i);
    }
        setcolor(8);
        settextstyle(3,HORIZ_DIR,10);
        outtextxy(50,85,"1");
        outtextxy(200,85,"2");
        outtextxy(350,85,"3");
        outtextxy(50,235,"4");
        outtextxy(200,235,"5");
        outtextxy(350,235,"6");
        outtextxy(50,385,"7");
        outtextxy(200,385,"8");
        readimagefile("images/turn.gif",0,1200,500);
        readimagefile("images/player1,jpg",500,120,620,200);
        readimagefile("images/winner.gif",0,50,1130,600);
        readimagefile("images/-.gif",120,0,1000,700);
        selector(RED);
        settextstyle(3,HORIZ_DIR,2);
        out(10,550,"press 'R' to restart the game!");
    }
//position of x_a
int p1=1,p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1;
int n=0;
int a[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int flag=0;
int j=1;
int k=1;
int x=0;
 void check_multi_winner(int);
 //x
 void x_o(int place){
     int l,t,r,b;
     char ch;
     if(a[place==1]==-1){
         if(n%2==0){
             readimagefile("images/player2.jpg",500,120,620,200);
         }else{
             readimagefile("images/player1.jpg",500,120,620,200);
         }
     }
     if(place==1&&p1==1){
         l=15;t=85;r=145;b=215;
         p1++;
         n++;
     }else if(place==2&&p2==1){
         l=160;t=85;r=290;b=215;
         p2++;
         n++;
     }else if(place==3&&p3==1){
         l=305;t=85;r=435;b=215;
         p3++;
         n++;
         
     }else if(place==4&&p4==1){
         l=15;t=235;r=145;b=365;
         p4++;
         n++;
     }else if(place==5&&p5==1){
         l=160;t=235;r=290;b=365;
         p5++;
         n++;
         
     }else if(place==6&&p6==1){
         l=305;t=235;r=435;b=365;
         p6++;
         n++;
     } else if(place==7&&p7==1){
         l=15;t=385;r=145;b=515;
         p7++;
         n++;
     } else if(place==8&&p8==1){
         l=160;t=385;r=290;b=515;
         p8++;
         n++;
     }else if(place==9&&p9==1){
         l=305;t=385;r=435;b=515;
         p9++;
         n++;
     }if(a[place-1]==-1){
         if(n%2==0){
             ch='o';
             j++;
         }else{
             ch="x";
             k++;
         }
     }
     if(ch=='o'){
         readimagefile("images/o.jpg",l,t,r,b);
         playSound(TEXT("sounds/oblue.wav"),NULL,SND_FILENAME);
     }else if(ch=='x'){
         readimagefile("images/x.jpg",l,t,r,b);
         playSound(TEXT("sounds/xblue.wav"),NULL,SND_FILENAME);
         
     }
     if(ch=='o'){
         a[place-1]=0;
         check_multi_winner(0);
         
     }
     if(ch=='x'){
         a[place-1]=1;
         check_multi_winner(1);
         
     }
     if(j>=5&&k>=6){
         j=1;
         k=1;
         check_multi_winner(2);
     }
}
//check winning

void check_multi_winner(int no){
    if(a[0]==no&&a[1]==no&&a[2]==no){
        flag++;
    }
     if(a[3]==no&&a[4]==no&&a[5]==no){
        flag++;
    }
     if(a[6]==no&&a[7]==no&&a[8]==no){
        flag++;
    }
      if(a[0]==no&&a[3]==no&&a[6]==no){
        flag++;
    }
    if(a[1]==no&&a[4]==no&&a[7]==no){
        flag++;
    }
    if(a[2]==no&&a[5]==no&&a[8]==no){
        flag++;
    }
     if(a[2]==no&&a[4]==no&&a[6]==no){
        flag++;
     }  
     if(a[0]==no&&a[4]==no&&a[8]==no){
        flag++; 
     }
     if(flag==1){
         if(no==0){
             readimagefile("images/player2.jpg",500,300,620,380);
             playSound(TEXT("sounds/winner.wav"),NULL,SND_FILENAME);
         } 
         if(no==1){
             readimagefile("images/player1.jpg",500,300,620,380);
             playSound(TEXT("sounds/winner.wav"),NULL,SND_FILENAME);
         }
         else if(flag==0&&no==2){
             readimagefile("images/noone.jpg",500,300,620,380);
             playSound(TEXT("sounds/noone.wav"),NULL,SND_FILENAME);
             x=2;
         }
         restart_game();
         }
     }
//restart game
void restart_game(){
    if(flag==1||(flag==0&&x==2)){
        setcolor(RED);
        settextstyle(3,HORIZ_DIR,2);
        outtextxy(490,430,"wait 5 seconds to");
        outtextxy(500,450,"restart game!");
        delay(5000);
        p1=1;p2=1;p3=1;p4=1;p5=1;p6=1;p7=1;p8=1;p9=1;
        n=0;
        flag=0;
        j=1;
        k=1;
        x=0;
        for(int i=0;i<9;i++){
            a[i]=-1;
        }
        function_execution(2);
        esc_theme(2);
    }
}

