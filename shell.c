clearBuffer(char* );
void getSectors(char*,int);     
int main(){
	int i = 0;
	int flag = 0;
	char * view ="view";
	char* execute = "execute";
	char* delet = "delete";
    char* copy = "copy";
    char* dir = "dir";
    char* create = "create";
    int sectors = 0;
     char viewfile[6];
    int sectorscounter=0;
    char directory[512];
    char entry [6];
    int direct =0;
    char* command ;
    char filename[6] ;
    char newfilename[6];
    int directin = 0;
    char buffer [512];
    char size [2];
    int charachtersize = 0;
    char buffercreate[13312];    
    char buffercreate2[13312];
	while(1){
	flag=0;
	i=0;
	interrupt(0x21,0,"LOAY>",0,0);
	interrupt(0x21,1,command,0,0);
    interrupt(0x10,0xE*256+0xd,0,0,0);  
    interrupt(0x10,0xE*256+0xa,0,0,0);
    interrupt(0x10,0xE*256+0x0,0,0,0);  
 //    while(i<4){
	// 	if(command[i]!=view[i]){
	// 		flag = 0;
	// 		break;
 //         	}
 //     flag = 1;
 //     i++;
	// }
 //    i++;
 //    if(flag==1){
 //         while(i< 11){
 //        viewfile[i-5] =command[i];
 //        i++;
 //    }
 //         interrupt(0x21,0,viewfile,0,0); 
 //        interrupt(0x21,3,viewfile,buffer,0); 
 //        //review
 //        interrupt(0x21,0,buffer,0,0); 
 //        clearBuffer(buffer);
 //  }
// }
// }
//      if(flag==0){

//      i=0;
//         while(i<6){
//      if(command[i]!=delet[i]){
//          flag = 0;
//          break;
//              }
//      flag = 1;
//      i++;
//  }  if(flag==1){
//          interrupt(0x21,0,"hered2",0,0);
//      command +=7;
//          i=0;
//         interrupt(0x21,7,command,0,0);
    
// }
// }
// }
// }
   
//     if(flag==1){
//          interrupt(0x21,0,"hered2",0,0);
//      command +=7;
//          i=0;
//         interrupt(0x21,7,command,0,0);
    
// }
// }
if(flag==0){
        i=0;
        while(i<4){
        if(command[i]!=copy[i]){
            flag = 0;
            break;
            }
     flag = 1;
     i++;
    }
    i++;
     
    if(flag==1){
        sectors=0;
        while(i<11)
        {    
            filename[i-5]=command[i];
            if(command[i]=='\0')
                break;
             i++;

        }

        i++;
        while(i<18){
            newfilename[i-12]=command[i];
            i++;
        }
            filename[6]='\0';
       interrupt(0x21,3,filename,buffer,0);
       while(buffer[sectors*512]!=0){
        sectors++;
        }
        newfilename[6]='\0';
        // interrupt(0x21,0,newfilename,0,0); 
       interrupt(0x21,8,newfilename,buffer,sectors+1);
        
     clearBuffer(buffer);
    
    }
}
}
}
// if(flag==0){
//         i=0;
//         while(i<6){
//         if(command[i]!=create[i]){
//             flag = 0;
//             break;
//             }
//      flag = 1;
//      i++;
//     }
//     i++;
//      command+=i;
//     if(flag==1){
//         sectors=0;
//         interrupt(0x21,1,buffercreate,0,0);
//         while(buffercreate[0]!=0xa){
//             i=0;
//          while(buffercreate[i]!=0)
//          { 
//             buffercreate2[charachtersize]=buffercreate[i];
//             buffercreate[i]=0;
//             charachtersize++;
//             i++;
            
//          }
//          interrupt(0x21,1, buffercreate,0,0);
//     }
//      interrupt(0x21,0,buffercreate2,0,0);

//      sectors = div(charachtersize,512);
//      sectors++;if(flag==0){
//         i=0;
//         while(i<6){
//         if(command[i]!=create[i]){
//             flag = 0;
//             break;
//             }
//      flag = 1;
//      i++;
//     }
//     i++;
//      command+=i;
//     if(flag==1){
//         sectors=0;
//         interrupt(0x21,1,buffercreate,0,0);
//         while(buffercreate[0]!=0xa){
//             i=0;
//          while(buffercreate[i]!=0)
//          { 
//             buffercreate2[charachtersize]=buffercreate[i];
//             buffercreate[i]=0;
//             charachtersize++;
//             i++;
            
//          }
//          interrupt(0x21,1, buffercreate,0,0);
//     }
//      interrupt(0x21,0,buffercreate2,0,0);

//      sectors = div(charachtersize,512);
//      sectors++;
//      printInt(size,sectors);
//      interrupt(0x21,0,size,0,0);
//      interrupt(0x21,8,command,buffercreate2,sectors);
//         }
// }

//      printInt(size,sectors);
//      interrupt(0x21,0,size,0,0);
//      interrupt(0x21,8,command,buffercreate2,sectors);
//         }
// }
// }
// }

//     if(flag==0){
//     	i=0;
//         while(i<7){
// 		if(command[i]!=execute[i]){
// 			flag = 0;
// 			break;
//          	}
//      flag = 1;
//      i++;
// 	}
//     if(flag==1){
//     	command +=8;
//         interrupt(0x21,4,command,0x2000,0);
//         }
//     }
//   }
// }

//     if(flag==0){

//     	i=0;
//         while(i<6){
// 		if(command[i]!=delet[i]){
// 			flag = 0;
// 			break;
//          	}
//      flag = 1;
//      i++;
// 	}
   
//     if(flag==1){
//     	command +=7;
//          i=0;
//         interrupt(0x21,7,command,0,0);
    
// }
// }
//  if(flag==0){
//         i=0;
//         while(i<3){
//         if(command[i]!=dir[i]){
//             flag = 0;
//             break;
//             }
//             i++;
//      flag = 1;
//     }
//     if(flag==1){
//         interrupt(0x21,0,"hered",0,0);
//          direct = 0;
//          interrupt(0x21,2,directory,2,0);
//           while(direct<16){
//            if(directory[direct*32]!=0)
//            {    
//             directin= 0;
//              while(directin<6){
                
//                 entry[directin]=directory[(direct*32)+directin];
//                 interrupt(0x10,0xE*256+directory[(direct*32)+directin],0,0,0); 
//                   directin++;
//              }
           
//              sectors = 0;
//              while(directin<32)
//                    {
//                      if(directory[(direct*32)+directin]==0)
//                         break;
                    
//                      sectors++;
//                      directin++;
//                    } 
//                    printInt(size,sectors);
//                    // interrupt(0x10,0,entry,0,0);   
//                    interrupt(0x21,0,size,0,0); 
                   
//                    interrupt(0x10,0xE*256+0xd,0,0,0);  
//                    interrupt(0x10,0xE*256+0xa,0,0,0);
//                    interrupt(0x10,0xE*256+0x0,0,0,0);  
//            }
//        direct++;

//          }
//         i=0;
//              }
    
//    }

 
  
//      }
// }      
  
clearBuffer(char* buffer){
	int i = 0 ;
	while(i<512){
		buffer[i]=0;
	i++;
}
 
}
printInt(char* number1,int numb){
    int mod1 ;
    int num ; 
     mod1=  mod(numb,10);
     num = div(numb,10);
    number1[1] = mod1+'0';
    number1[0]= num+'0';
}
int div(int n,int d){
    int result = 0 ;
    while (n>=d){
  n = n- d;
  result++;
}
return result ;
}

int mod(int n ,int d){
    int i = n-(div(n,d)*d);

return i;
}

