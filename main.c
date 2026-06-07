```c
#include<stdio.h>
#include<math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas(){

int i,j;

for(i=0;i<ROWS;i++){

for(j=0;j<COLS;j++){

canvas[i][j]='_';
}
}
}

void displayCanvas(){

int i,j;

printf("\nCURRENT CANVAS:\n\n");

for(i=0;i<ROWS;i++){

for(j=0;j<COLS;j++){

printf("%c ",canvas[i][j]);
}

printf("\n");
}
}

void drawRectangle(int row,int col,int height,int width){

int i,j;

for(i=row;i<row+height;i++){

for(j=col;j<col+width;j++){

if(i>=0&&i<ROWS&&j>=0&&j<COLS){

canvas[i][j]='*';
}
}
}
}

void drawLine(int row1,int col1,int row2,int col2){

int i;

if(row1==row2){

if(col1>col2){

int temp=col1;
col1=col2;
col2=temp;
}

for(i=col1;i<=col2;i++){

if(i>=0&&i<COLS){

canvas[row1][i]='*';
}
}
}

else if(col1==col2){

if(row1>row2){

int temp=row1;
row1=row2;
row2=temp;
}

for(i=row1;i<=row2;i++){

if(i>=0&&i<ROWS){

canvas[i][col1]='*';
}
}
}

else{

printf("Only horizontal and vertical lines are supported!\n");
}
}

void drawTriangle(int row,int col,int height){

int i,j;

for(i=0;i<height;i++){

for(j=0;j<=i;j++){

if(row+i<ROWS&&col+j<COLS){

canvas[row+i][col+j]='*';
}
}
}
}

void drawCircle(int centerRow,int centerCol,int radius){

int i,j;

for(i=0;i<ROWS;i++){

for(j=0;j<COLS;j++){

int dx=i-centerRow;
int dy=j-centerCol;

if(dx*dx+dy*dy<=radius*radius){

canvas[i][j]='*';
}
}
}
}

void deleteArea(int row,int col,int height,int width){

int i,j;

for(i=row;i<row+height;i++){

for(j=col;j<col+width;j++){

if(i>=0&&i<ROWS&&j>=0&&j<COLS){

canvas[i][j]='_';
}
}
}
}

int main(){

int choice;

int row,col,height,width;
int row1,col1,row2,col2;
int radius;

initializeCanvas();

while(1){

printf("\n===== 2D GRAPHICS EDITOR =====\n");

printf("1.Display Canvas\n");
printf("2.Draw Rectangle\n");
printf("3.Draw Line\n");
printf("4.Draw Triangle\n");
printf("5.Draw Circle\n");
printf("6.Delete Area\n");
printf("7.Clear Canvas\n");
printf("8.Exit\n");

printf("Enter your choice: ");
scanf("%d",&choice);

switch(choice){

case 1:

displayCanvas();
break;

case 2:

printf("Enter row column height width: ");
scanf("%d%d%d%d",&row,&col,&height,&width);

drawRectangle(row,col,height,width);
break;

case 3:

printf("Enter row1 col1 row2 col2: ");
scanf("%d%d%d%d",&row1,&col1,&row2,&col2);

drawLine(row1,col1,row2,col2);
break;

case 4:

printf("Enter row column height: ");
scanf("%d%d%d",&row,&col,&height);

drawTriangle(row,col,height);
break;

case 5:

printf("Enter centerRow centerCol radius: ");
scanf("%d%d%d",&row,&col,&radius);

drawCircle(row,col,radius);
break;

case 6:

printf("Enter row column height width to delete: ");
scanf("%d%d%d%d",&row,&col,&height,&width);

deleteArea(row,col,height,width);
break;

case 7:

initializeCanvas();

printf("Canvas Cleared!\n");
break;

case 8:

printf("Exiting Program...\n");
return 0;

default:

printf("Invalid Choice!\n");
}
}

return 0;
}
```
