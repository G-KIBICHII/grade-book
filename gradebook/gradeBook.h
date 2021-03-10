#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class GradeBook
{
public:
    static const int gradesize =10;
    int grades[gradesize];

  void setcoursename(string name)
  {
      if (name.length()>25)
      {
          courseName=name;
      }
      else
          courseName = name.substr(0,25);

  }
  string getcourseName()
  {
      return courseName;
  }
  void displaymessage( )
  {
      cout<<"welcome to gradebook for "<<getcourseName()<<endl;
  }
  void getGrades()
  {
      cout<<"enter grades\n ";
      for (int i = 0; i < gradesize; i++)
      {
       cin>>grades[i];
      }
      cout<<getAverage()<<" average\n";
      cout<<"smallest is "<<getminimum();
      cout<<"\n highest is "<<getmaximum();
      cout<<"\nsorted data in array \n\n";


  }
 double getAverage()
  {
      int total =0;
      double average;
      for(int i=0;i<gradesize;i++)
      {
          total +=grades[i];
      }
      cout<<setprecision(3)<<fixed;
      average= static_cast<double>(total)/gradesize;

      return average;
  }
  int getminimum ()
  {
      int smallest =100;
      for (int i = 0; i < gradesize; i++)
      {
       if(grades[i]<smallest)
           smallest=grades[i];
      }
      return smallest;
  }
  int getmaximum()
  {
      int highest =0;
      for(int j=0; j<gradesize;j++)
      {
          if (highest<grades[j])
              highest= grades[j];
      }
      return highest;
  }
  void barchart()
  {
      const int frequencysize =11;
      int frequency[frequencysize] ={};
      for (int student=0;student<gradesize;student++)
      {
          frequency[grades[student]/gradesize]++;
      }
      for (int count=0; count< frequencysize; count++)
      {
          if(count==0)
              cout<<"0-9 : ";
          else if (count==10)
              cout<<"100";
          else
              cout<<count*10<<"-"<<count*10+9<<": ";
          for (int star=0;star<frequency[count];star++)
              cout<<"*";
          cout<<endl;
      }

  }
  void process()
  {

      barchart();
  }

private:
    string courseName;




};