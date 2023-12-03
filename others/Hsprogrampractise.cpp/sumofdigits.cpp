// write a program in c++ to finf out the summation of given integer using class 
 
 #include<iostream>

 using namespace std;
 class sumofdigits{
     public:
     void digitsum(int x ){
     int s=0,digit;
     while(x>0)
     {
         digit= x%10;
          s= s*10+digit;
          x=x/10;
     }
     std::cout << "sum of digits is " <<s<< std::endl;


        
     }
 };
int main ()
{
    int num ;
    std::cout << "enter the digit " << std::endl;
    cin>> num;
    sumofdigits sd1;
    sd1.digitsum(num);
}