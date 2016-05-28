int namematch(char* ,char*);
void printString(char*);
void readString(char*);
void readSector(char* , int );
int div(int ,int );
int mod(int ,int );
 handleInterrupt21(int,int,int,int);
void readfile(char*,char*);
void executeProgram(char* , int );
void terminate();
void writeSector(char*, int);
void deleteFile(char*);
void writeFile(char*, char* , int );
void main(){
 //  char line[80];
 // printString("Enter a line: \0");
 // readString(line);
 // printString(line);
// char buffer[512];
// readSector(buffer, 30);
// printString(buffer);
 // makeInterrupt21();
 // interrupt(0x21,0,0,0,0);
//  char line[80];
 makeInterrupt21();
 interrupt(0x21,4,"shell\0",0x2000,0);
  // interrupt(0x21,7,"messag\0",0,0);
// interrupt(0x21,1,line,0,0);
// interrupt(0x21,0,line,0,0);
//   char buffer[13312] ;/*this is the maximum size of a file*/
// makeInterrupt21();
 //  char buffer [512];
 // interrupt(0x21, 6, "messag\0", 15, 0);
 //  interrupt(0x21, 2, buffer, 15, 0);
 //  interrupt(0x21,0,buffer,0,0);
  /*read the file into buffer*/
// interrupt(0x21, 0, buffer, 0, 0); /*print out the file*/
// while(1); /*hang up*/
//   int i=0;
// char buffer1[13312];
// char buffer2[13312];
// buffer2[0]='h'; buffer2[1]='e'; buffer2[2]='l';
// buffer2[4]='o';
// buffer2[3]='l';
// for(i=5; i<13312; i++) buffer2[i]=0x0;
// makeInterrupt21();
// interrupt(0x21,8, "testW\0", buffer2, 1); //write file testW
// interrupt(0x21,3, "testw\0", buffer1, 0); //read file testW
// interrupt(0x21,0, buffer1, 0, 0); // print out contents of testW

while(1);
}
void readfile(char* s,char* result){
	char directory[512] ;
	int j = 0;
	 int k = 0;
	 int p=0;
    readSector(directory,2);

    while(j<16){
    	p = 0;
    	k=j*32;
         while(p<6){
         	if(s[p]!=directory[k+p])
         		break ;
         	
         	  	
         	p++;	          
         }
         j++;
         while(p>=6){
         	 if(directory[k+p]==0)
         	return;
           readSector(result,directory[k+p]);
            result+=512;
         if(p==31)
         	return;
         p++;
         }
         
    	}
    	
    }

void printString(char* s){
for(;*(s)!='\0';s++){
	interrupt(0x10, 0xE*256+*(s), 0, 0, 0);
}

}

void readString(char* s){
	  
	do{
char  typed = interrupt(0x16,0,0,0,0);
if(typed==0xd)
{
   *(s)=0xa;
   s++;
   *(s)=0x0;
   return ;

}
if(typed==0x8){
	interrupt(0x10, 0xE*256+0x8, 0, 0, 0);
s--;
interrupt(0x10, 0xE*256+0x0, 0, 0, 0);
interrupt(0x10, 0xE*256+0x8, 0, 0, 0);

}
else{
*(s)=typed;
s++;
interrupt(0x10, 0xE*256+typed, 0, 0, 0);
}

}while(1);
}
int div(int n ,int d) {
	int result = 0 ;
	while (n>d){
  n = n- d;
  result++;
}
return result ;
}

int mod(int n ,int d) {
	int i = n-(div(n,d)*d);

return i;
}

void readSector(char* buffer, int sector){
	int ah = 2;
	int al = 1;
	int cl = mod(sector,18)+ 1;
    char* bx = buffer;
	int dh =  mod(div(sector , 18),2);
	int ch  = div(sector,36);
	int dl = 0;
	int cx=ch*256+cl ;
	int dx=dh*256+dl ;
	int ax=ah*256 + al;
	
	buffer = interrupt(0x13,ax,bx,cx,dx);
}


void writeSector(char* buffer, long sector){
	int ah = 3;
	int al = 1;
	int cl = mod(sector,18)+ 1;
  char* bx = buffer;
	int dh =  mod(div(sector , 18),2);
	int ch  = div(sector,36);
	int dl = 0;
	int cx=ch*256+cl ;
	int dx=dh*256+dl ;
	int ax=ah*256 + al;
	
  interrupt(0x13,ax,bx,cx,dx);
}
void executeProgram(char* name, int segment){
	int counter= 0;
	int index = 0x0000;
	char buffer [13312];
	readfile(name, buffer);
	while(counter < 13312){
		putInMemory(segment, index++, buffer[counter]);
		 counter++;
		
	}
	launchProgram(segment);
	
}
void terminate(){
    char shell[6];
    shell[0]='s';
    shell[1]='h';
    shell[2]='e';
    shell[3]='l';
    shell[4]='l';
    shell[5]='\0';
   interrupt(0x21,4,shell,0x2000,0);
    while(1);
	
}

void deleteFile(char* name){
		int i = 0;
    int j = 0;//number of records in directory 
	    int k = 0; // index in directory 
	    int p = 0;// parse each record
	    int mapindex=0;
	    char directory[512];
   		char map[512];
		readSector(directory,2);
		readSector(map,1);
		while(j<16){
    	 p = 0;
    	 k=j*32;
         while(p<6){
         	if(name[p]!=directory[k+p])
         		break ;
         	  	
         	p++;	          
         }
         
         if(p==6)
         	directory[k]=0x00;

            while(p>=6){
            	mapindex=directory[k+p]-1;
            map[mapindex]=0x00;
               if(p==31)
          break;
             p++;
         }
        if(p==31)
          break;
         j++;
      
 }
 writeSector(map,1);
 writeSector(directory,2);
 }

void writeFile(char* name, char* buffer, int secNum){
   char directory[512];
   char map [512];
   int i = 0;
   int n= 0;//name 
   int secto = 0;//sector
   int pointer = 6;
   int temp;
   char tempbuffer [512];
   int tempcounter = 0;
   readSector(map,1);
   readSector(directory,2);
   for(;i<16;i++){
    
     n=0;
     secto=0;
    if(directory[(i*32)]==0x00){
      while(name[n]!='\0'&&n<6){
         temp=(i*32)+n;
        directory[temp]=name[n];
        n++;
      }
       if(n<6)
        directory[temp+1]='\0';
      temp = (i*32)+6;
      while(secto<256) 
      {
         
        if(secNum==0){
          return;

        }
           n=6;
       if(map[secto-1]==0x00)
       {
         tempcounter = 0;
        while(tempcounter<512){
          tempbuffer[tempcounter] = *(buffer);
          tempcounter++;
          buffer++;
          if(*(buffer)==0)
            break;
        }
         writeSector(tempbuffer,secto);
         map[secto-1]=0xFF;
         directory[temp]=secto;
         temp++;
         n++;       
        secNum--;
       } 
       if(secNum==0)
        break;

      secto++;
      }
      if(secNum!=0){
      printString("error no free space");
      return;
    }
    temp = (i*32)+n;
      while(n<32){
        directory[temp++]=0x00;
        if(n==31){
          writeSector(map,1);
         writeSector(directory,2);
        return ;
        }
        n++;
      } 

    }
   }
   printString("Error no free space");
   return;

}

printInt(char* number1,int numb){
    int mod1 ;
    int num ; 
     mod1=  mod(numb,10);
     num = div(numb,10);
    number1[1] = mod1+'0';
    number1[0]= num+'0';
}
handleInterrupt21(int ax, int bx, int cx, int dx){
   if(ax==0)
   	printString(bx);
   if(ax==1)
   	readString(bx);
   if(ax==2)
   	readSector(bx,cx);
   if(ax==3)
   	readfile(bx,cx);
    if(ax==4)
     executeProgram(bx,cx);
   if(ax==5)
   	terminate();
   if(ax==6)
    writeSector(bx,cx);
   if(ax==7)
   	deleteFile(bx);
   if(ax==8)
   	 writeFile(bx,cx,dx);
   if(ax>=9)
   	printString("Error");
 }
