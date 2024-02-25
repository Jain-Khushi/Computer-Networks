#include<iostream>
using namespace std;

int main()
{
    int data[20],dlen,glen,gx[10],temp[20],deg,flen,i,j,k,td[20];
    
    cout<<" Enter length of the data : ";
    cin>>dlen;
    if(dlen>8)
    {
        cout<<" Invalid input";
        return 0;
    }
    cout<<" Enter the data(separated by space) : ";
    for( i=0;i<dlen;i++)
       cin>>data[i];
       
    for(i=0 ; i<dlen; i++)
       temp[i]=data[i];
       
    cout<<" Enter the length of generator : ";
    cin>>glen;
    cout<<" Enter the key of the generating polynomial : ";
    for(i=0;i<glen;i++)
       cin>>gx[i];
       
    cout<<"\n Sender Side:\n";
    
    deg=glen-1;
    cout<<" Degree of the polynomial is : "<<deg<<endl;
    
    flen=dlen+deg;
    
    for(i=dlen;i<flen;i++)      //appending 0's
       temp[i]=0;
    
    cout<<" Final data is : ";   
    for(i=0;i<flen;i++)
       cout<<temp[i]<<" ";
       
       
    for(i = 0; i < dlen; i++)
    {
        j = 0;
        k = i;
        //check whether it is divisible or not
        if (temp[k] >= gx[j])
        {
            for (j = 0, k = i; j < glen; j++, k++)
            {
                if ((temp[k] == 1 && gx[j] == 1) || (temp[k] == 0 && gx[j] == 0))
                     temp[k] = 0;
                else
                     temp[k] = 1;
                
            }
        }
    }

    //CRC
    int rem[15];
    for (i = 0, j = dlen; i < deg; i++, j++)
        rem[i] = temp[j];

    cout << "\n Remainder : ";
    for (i = 0; i < deg; i++)
         cout << rem[i];
         
    cout << "\n Transmitted Data: ";
    
    for (i = 0; i < flen; i++)
        td[i] = data[i];
        
    for (i = dlen, j = 0; i < flen; i++, j++)
        td[i] = rem[j];
        
    for (i = 0; i < flen; i++)
        cout << td[i]<<" ";

       
    return 0;
       
}