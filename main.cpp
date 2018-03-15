#include <iostream>
#include <stdlib.h>

using namespace std;
void fifo();

int frames=3 , pages = 7 , refString = 22;
int* frameArray ;
int* pageArray ;
int* refStringArray ;
int main()
{
    cout << "Enter no. of Frames   :  "; cin>>frames ;
    cout << "Enter no. of Pages    :  "; cin>>pages ;
    cout << "Enter no. of sequence :  "; cin>>refString ;


    /// initialize arrays -->>
    frameArray = new int[frames];
    for(int i=0;i<frames ; i++) frameArray[i]=99;

//   pageArray = new int[pages];
//  for(int i=0;i<pages ; i++) pageArray[i]=0;

    refStringArray = new int[refString];
    for(int i=0;i<refString ; i++) refStringArray[i]= (rand()%pages);

    cout<<"frame array :"; for(int i=0; i<frames ; i++) cout<<frameArray[i]<<"  "; cout<<endl;
    cout<<"sequence array :"; for(int i=0;i<refString ; i++) cout<<refStringArray[i]<<"  "; cout<<"\n\n\n";
    fifo();
    return 0;
}


///FiFo

void fifo(){
    int oldest=0 , missCount=0 , enter=0 , COUNTER=1 ,flag=0;
    do{

        for(int i=0;i<frames;i++){
            if(refStringArray[enter] == frameArray[i] ){
                    flag=1;
                    break;  // ifnum already exist continue
            }
        }
       if(flag==0){
            frameArray[oldest]=refStringArray[enter] ;
            oldest=(oldest+1)%frames;
            cout<<(COUNTER)<<"     "; for(int i=0;i<3;i++) cout<<frameArray[i]<<"  ";
            cout<<endl;
            missCount++;
        }
       else{
            cout<<(COUNTER)<<"     "<<endl;
        }

        COUNTER++;
        enter++;
        flag=0;
    }while(enter<refString);
    cout<<"miss count : "<<missCount<<endl;
}

