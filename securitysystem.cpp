

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
 
using namespace std;

int main()
{
     int a , i=0;
     string text , old , password1, password2 , password3, pass , name ,age , user, word, word1;
     string creds[2] , cp[2];
  
     cout<<"         SECURITY SYSTEM        "<<endl;
     cout<<"________________________________"<<endl<<endl;
     cout<<"|       1.REGISTER             |"<<endl;
     cout<<"|       2.LOGIN                |"<<endl;
     cout<<"|       3.CHANGES PASSWORD     |"<<endl;
     cout<<"|_______4.END PROGRAM__________|"<<endl<<endl;
      
    do {
          cout<<endl<<endl;
          cout<<"Enter your choice:-";
          cin>>a;
          switch(a)
          {

            case 1 :
            {
                cout<<"_______________________________"<<endl<<endl;
                cout<<"------------REGISTER-----------"<<endl<<endl;
                cout<<"_______________________________"<<endl<<endl;
                cout<<"Please enter username:-";
                cin>>name;
                cout<<"Please enter the password:-";
                cin>>password3;
                cout<<"Please enter your age:-";
                cin>>age;

             /*in order to store the above details we need some file handling operations and for that we create a class of ofstream*/   
   

            ofstream of1;
            of1.open("file.txt");
            if(of1.is_open()){
             of1<<name<<"\n";
             of1<<password3;
             cout<<"Registration successfull"<<endl;



            }

            break;


          }
   
      case 2 :
      {
         i=0;

         cout<<"___________________________________"<<endl<<endl;
         cout<<"|-------------LOGIN----------------|"<<endl;
         cout<<"|__________________________________|"<<endl<<endl;


         ifstream of2;
         of2.open("file.txt");
         cout<<"Please enter the username:-" ;
         cin>>user;
         cout<<"Please enter the password:-";
         cin>>pass;

         if(of2.is_open())
         {
             while(!of2.eof())
              {
                while(getline(of2, text)) {         //to read the file line by line
                  istringstream iss(text);         //to stream the string and store it using extraction operator
                  iss>>word;
                  creds[i]=word;
                  i++ ; 
                }
                if(user==creds[0] && pass==creds[1])
                {
                    cout<<"-------Log in successfully-----";
                    cout<<endl<<endl;

                    cout<<"Details :"<<endl;
                    cout<<"Username:"+ name<<endl;
                    cout<<"Password:"+ pass<<endl ; 
                    cout<<"Age:"+ age<<endl;

                }
                else {
                  cout<<endl<<endl;
                  cout<<"Incorrect Credentials"<<endl;
                  cout<<"|    1. Press 2 to Login                |"<<endl;
                  cout<<"|    2. Press 3 to change Password      |"<<endl;
                  break;
                }
                
                }
              }
              break ;
         }
          case  3: {
             i=0;
             cout<<"----------------Change Password----------------"<<endl;

             ifstream of0;
             of0.open("file.txt");
             cout<<"Enter the old Password:-";
             cin>>old;
             if(of0.is_open())
             {
              while(of0.eof())
               {
                while(getline(of0, text)){
                   istringstream iss(text);
                   iss>>word1;
                   cp[i]=word1;
                   i++ ;
                }
                if(old==cp[1])
                {
                  of0.close();
                   ofstream of1 ;
                   if(of1.is_open())
                   {
                     cout<<"Enter your new Password:- ";
                     cin>>password1;
                     cout<<"Enter your Password again:-";
                     cin>>password2;

                     if(password1==password2)
                     {
                      of1<<cp[0]<<"\n";
                      of1<<password1;
                      cout<<"Password changes Successfully"<<endl;

                     }
                      else{
                        of1<<cp[0]<<"\n";
                        of1<<old;
                        cout<<"Password do not match"<<endl;

                      }


                   }
                }
                else {
                  cout<<"Please enter a valid password"<<endl;
                  break;
                }
               }
             }
             break;

          }


          case 4:
          {
            cout<<"_________________Thank You_________________";
            break;

          }
          default:
          cout<<"Enter a valid choice";
      }


        }
        while(a!=4);

         return 0 ;
    }
    
