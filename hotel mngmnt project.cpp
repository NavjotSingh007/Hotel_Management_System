#include<iostream>
#include<string>
#include<fstream>
using namespace std;

char choice;
string tname;
int tnights,troom,tphno;

int etnights,etroom,etphno;
string etname;

int ntnights,ntroom,ntphno;
string ntname;


char menu();
void view();
void insertion();
void editing();


//////////////////////////////////////////////main
int main()
{
    while (choice != 'q')
    {
       choice = menu();
       switch (choice)
       {
          case ('v') : view();
                       break;

          case ('i') : insertion();
                        break;

          case ('e') : editing();
                        break;

       }



    }
     return 0;

}

////////////////////////////////////////////////menu
char menu()
{
    cout << endl << endl << "v -- view tenants list \n";
    cout  << "i -- insert new tenant \n";
    cout  << "e -- edit a tenant record \n";
    cout  << "d -- delete a tenant record \n";
    cout  << "q -- quit program \n";
    cout  << "your choice :- ";
    cin >> choice ;
    return choice;
}

//////////////////////////////////////////////////view
void view()
{

   const int N=1000;
   char line[N];

  ifstream fread;
    fread.open("hotel.txt");
    while(fread)
    {
     cout << endl;
     fread.getline(line, N);

     cout << line;
    }
    fread.close();
    cout << endl;
}

/////////////////////////////////insertion
void insertion()
{
    ofstream fwrite;
    fwrite.open("hotel.txt" , ios::app);

                //  ----  SHORT METHOD  -----
    cout << " \n \n press 'CTRL + Z' when finished \n";
    cout << "enter tenant_name <space> no. of nights <space> room no. <space> mobile_no. <enter> \n";

    while(cin >> tname >> tnights >> troom >> tphno)
    {
        fwrite << tname << ' ' << tnights << ' ' << troom << ' ' << tphno << endl;
    }
    cin.clear();
    fwrite.close();

    cout << "\n data added successfully !!! \n\n";




                                                        // IMP :---cin.ignore();  getline(cin,tname);



}

///////////////////////////////////editing
void editing()
{
    ifstream fread("hotel.txt");
    cout <<endl<< "enter room no. of tenant to edit :- ";
    cin >> etroom;
    while(fread >> tname >> tnights >> troom >> tphno)
    {
       if (etroom == troom)
       {

            cout << tname << ' ' << tnights << ' ' << troom << ' ' << tphno << endl;
            while(choice!='n')
        {
        ofstream fwite("hotel.txt" , ios::app );


            cout << "wanna edit name ?(y/n) \n";
            cin >> choice;
            switch (choice)
            {
                     case ('y') : cout << "enter new name to replace :- ";
                                  cin.ignore(); getline(cin,etname);
                                  while(fread >> tname >> tnights >> troom >> tphno )
                                  {

                                      tname = etname;
                                      fwrite << tname;

                                  }


                                  break;
                     case ('n') : break;

            }
        }

       }



    }
    fread.close();





}


