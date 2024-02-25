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
       
    cout<<"\n Sender Side:\n\n";
    
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

    cout << "\n\n Receiver side :\n ";
    cout << "\n Received Data: ";
    
    for (i = 0; i < flen; i++)
         cout << td[i]<<" ";
    
    for (i = 0; i < flen; i++)
        temp[i] = td[i];

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
    cout << "\n Remainder: ";
    int rrem[15];
    for (i = dlen, j = 0; i < flen; i++, j++)
        rrem[j] = temp[i];

    for (i = 0; i < deg; i++)
        cout << rrem[i]<<" ";

    int flag = 0;
    for (i = 0; i < deg; i++)
        if (rrem[i] != 0)
            flag = 1;

    if (flag == 0)
    {
        cout << "\n Since Remainder is 0,the Message Transmitted from Sender to Receiver is Correct";
    }
    else
    {
        cout << "\n Since Remainder is not 0, the Message Transmitted from Sender to Receiver contains Error";
     }
     
    return 0;
}#include<iostream>
using namespace std;

int main()
{
    int data[20],dlen,glen,gx[10],temp[20],deg,i,j,k,td[20],flag=0;
    
    cout<<" Enter the length of the data : ";
    cin>>dlen;
    
    cout<<" Enter the data transmitted from sender to receiver(separated by space) : ";
    for( i=0;i<dlen;i++)
       cin>>data[i];
       
    cout<<" Enter the length of generator : ";
    cin>>glen;
    cout<<" Enter the key of the generating polynomial : ";
    for(i=0;i<glen;i++)
       cin>>gx[i];
       
    deg=glen-1;
       
    for(i = 0; i < dlen; i++)
    {
        j = 0;
        k = i;
        //check whether it is divisible or not
        if (data[k] >= gx[j])
        {
            for (j = 0, k = i; j < glen; j++, k++)
            {
                if ((data[k] == 1 && gx[j] == 1) || (data[k] == 0 && gx[j] == 0))
                     data[k] = 0;
                else
                     data[k] = 1;
                
            }
        }
    }

    //CRC
    int rem[15];
    for (i = dlen-deg, j = 0; i < dlen; i++, j++)
        rem[i] = data[j];

    cout << "\n Remainder : ";
    for (i = 0; i < deg; i++)
         cout << rem[i];

    for (i = 0; i < deg; i++)
    {
        if (rem[i] != 0)
           flag = 1;
    }
    if (flag == 0)
    {
             cout << "\n Since Remainder is 0,"
              " \nMessage transmitted from Sender to Receiver is Correct";
    }
    else
    {
             cout << "\n Since Remainder is not 0,"
             "\n hence the Message transmitted from Sender to Receiver contains Error";
    }

       
    return 0;
       
}#include<iostream>
using namespace std;

int main()
{
    int data[20],dlen,glen,flen,gx[10],temp[20],deg,i,j,k,td[20],flag=0;
    
    cout<<" Enter the length of the data : ";
    cin>>dlen;
    
    cout<<" Enter the data transmitted from sender to receiver(separated by space) : ";
    for( i=0;i<dlen;i++)
       cin>>data[i];
       
    cout<<" Enter the length of generator : ";
    cin>>glen;
    cout<<" Enter the key of the generating polynomial : ";
    for(i=0;i<glen;i++)
       cin>>gx[i];
       
    deg=glen-1;
    flen=dlen+deg;
       
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

    for (i = 0; i < deg; i++)
    {
        if (rem[i] != 0)
           flag = 1;
    }
    if (flag == 0)
    {
             cout << "\n Since Remainder is 0,"
              " \nMessage transmitted from Sender to Receiver is Correct";
    }
    else
    {
             cout << "\n Since Remainder is not 0,"
             "\n hence the Message transmitted from Sender to Receiver contains Error";
    }

       
    return 0;
       
}